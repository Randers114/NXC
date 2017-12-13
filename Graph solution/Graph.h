#include "CheckCase.h"

#define BOUND 3
#define HIGHEST_HEURISTIC_VALUE 12
#define GRAPH_SIZE 10
#define WORST_NUMBER_OF_CASES 4 
#define NUMBER_OF_MOVES_IN_CASE 7

#define RIGHT 1
#define INVERTEDRIGHT 2
#define LEFT 3
#define INVERTEDLEFT 4
#define TOP 5
#define INVERTEDTOP 6
#define BOTTOM 7
#define INVERTEDBOTTOM 8
#define FRONT 9
#define INVERTEDFRONT 10
#define BACK 11
#define INVERTEDBACK 12

typedef struct Node 
{
	int heuristicValue;
	int move;
	char cube[6][10];
} Node;

typedef struct Values
{
	int upperHeuristic;
	int currentPosition; 
	int layer;
	int currentArrayPosition;
	int bound;
	int lowerHeuristicInFullTreeSearch;
	Node blank;
	Node tempRootNode;
} Values;

void ConstructNode(int currentPosition, int move, int upperHeuristic);
void ConstructNodeChildren(Values *values);
int CheckBottomLayerLeaves(Values *values);
int CheckHeuristic(Values *values);
void PrepareNewTree(Values *values);
int SaveThePath(int currentArrayPosition, int currentPosition, int layer);
void ResetValues(Values *values);
int MoveUpInLayers(Values *values);
void PrintCube(int currentPosition);
void PrintMoves(int currentArrayPosition);
void CaseFix(Values *values);

Node Graph[GRAPH_SIZE];

int Path[HIGHEST_HEURISTIC_VALUE * GRAPH_SIZE + WORST_NUMBER_OF_CASES * NUMBER_OF_MOVES_IN_CASE];
int TempPath[GRAPH_SIZE];
int ChildNumber[GRAPH_SIZE];

void MainGraphConstruction()
{
	int movingUp;
	
	Values values = { .upperHeuristic = HIGHEST_HEURISTIC_VALUE, .currentPosition = 0, .layer = 0, .currentArrayPosition = 0, .bound = BOUND, .lowerHeuristicInFullTreeSearch = 0};
	
	// Constructing root node
	ConstructNode(values.currentPosition - 1 , 0, HIGHEST_HEURISTIC_VALUE);
	
	// Setting the upper heuristic to the starting nodes heuristic
	values.upperHeuristic = Graph[0].heuristicValue;
	
	printf("Start Heuristic value %d\n", values.upperHeuristic);
	
	CaseFix(&values);
	
	while(values.upperHeuristic != 0)
	{
		// Runs in loop to construct all nodes on the way down
		ConstructNodeChildren(&values);		
		
		// Checks all leafs on the bottom node to child number 12
		movingUp = CheckBottomLayerLeaves(&values);
		
		// When 12's child is reached the movingUpInLayers will move up two layers
		while(movingUp)
		{
			movingUp = MoveUpInLayers(&values);
			// Have to set the layer after moving up
			values.layer--;
			
			// Security check so layer can't move below zero
			if(values.layer < 0)
			{
				values.layer = 0;
			}
		}
	}	
	
	printf("Done \n");
	
	PrintCube(values.currentPosition);
	
	PrintMoves(values.currentArrayPosition);
}

void ConstructNode(int currentPosition, int move, int upperHeuristic)
{	
	// Put the child after the parent
	currentPosition++;

	Node node;
	
	// Copy myCube into the node
	memcpy(node.cube, myCube, sizeof myCube);
	
	// Choose which heuristic function to use, first white cross, then white face, lastly centerlayers
	if(upperHeuristic > 8)
	{
		node.heuristicValue = HeuristicValueWhiteCross();
		upperHeuristic = node.heuristicValue;
	}
	if(upperHeuristic > 4 && upperHeuristic <= 8)
	{
		node.heuristicValue = HeuristicValueWhiteFace();
		upperHeuristic = node.heuristicValue;
	} 
	if(upperHeuristic <= 4) 
	{
		node.heuristicValue = HeuristicValueCenterLayer();
	}
	
	node.move = move;
	
	Graph[currentPosition] = node;
}


void ConstructNodeChildren(Values *values)
{	
	int move;
	Node newParent;
	
	// For loop to move down to the leafs in the bound layer
	for(values->layer; values->layer < values->bound; ++values->currentPosition)
	{
		newParent = Graph[values->currentPosition];
		
		memcpy(myCube, newParent.cube, sizeof newParent.cube);
		
		// If childnumber hits 12 resets the value to zero
		if(ChildNumber[values->layer] == 12)
		{
			ChildNumber[values->layer] = 0;
		}
		
		ChildNumber[values->layer] += 1;
		
		// ChildNumber decides the move
		move = ChildNumber[values->layer];
		
		// Choose the operation for the node from childnumber
		switch(move)
		{
			case RIGHT:
				RightOperation();
				break;
			case INVERTEDRIGHT:
				InvertedRightOperation();
				break;
			case LEFT:
				LeftOperation();
				break;
			case INVERTEDLEFT:
				InvertedLeftOperation();
				break;
			case TOP:
				TopOperation();
				break;
			case INVERTEDTOP:
				InvertedTopOperation();
				break;
			case BOTTOM:
				BottomOperation();
				break;
			case INVERTEDBOTTOM:
				InvertedBottomOperation();
				break;
			case FRONT:
				FrontOperation();
				break;
			case INVERTEDFRONT:
				InvertedFrontOperation();
				break;
			case BACK:
				BackOperation();
				break;
			case INVERTEDBACK:
				InvertedBackOperation();
				break;
			default:
				break;
		}
		
		ConstructNode(values->currentPosition, move, values->upperHeuristic);
		
		++values->layer;
		
		// Resets myCube after move has been made on the cube
		memcpy(myCube, newParent.cube, sizeof newParent.cube);
	}
}

int CheckBottomLayerLeaves(Values *values)
{
	int lastLeaf = 0;

	if(!CheckHeuristic(values))
	{
		lastLeaf = 1;
	}
	return lastLeaf;
}

int CheckHeuristic(Values *values)
{
	int heuristicIsLower = 0;
	
	if(Graph[values->currentPosition].heuristicValue < values->upperHeuristic || (Graph[values->currentPosition].move == 12 && values->layer == 1))
	{	
		if(values->upperHeuristic > 4 && !(Graph[values->currentPosition].move == 12 && values->layer == 1))
		{
			values->lowerHeuristicInFullTreeSearch = 1;
			
			values->tempRootNode = Graph[values->currentPosition];
			
			for(int i = 0; i < GRAPH_SIZE; i++)
			{
				TempPath[i] = 0;
			}
			
			for(int i = 0; i < GRAPH_SIZE; i++)
			{
				if(Graph[i].move != 0)
				{
					TempPath[i] = Graph[i].move;
				}
			}		

			if(values->tempRootNode->heuristicValue != 0)
			{
				values->upperHeuristic = values->tempRootNode->heuristicValue;
			} else 
			{
				values->upperHeuristic = values->tempRootNode->heuristicValue;
				PrepareNewTree(values);
				heuristicIsLower = 1;
			}
			
		} else if(values->lowerHeuristicInFullTreeSearch || Graph[values->currentPosition].heuristicValue < values->upperHeuristic)
		{
			PrepareNewTree(values);
			
			heuristicIsLower = 1;
			
			values->bound = BOUND;
			
			CaseFix(values);
			
		} else 
		{
			if(values->bound >= 9)
			{
				printf("Last node in max bound reached. \n");
				exit(0);
			} else 
			{
				++values->bound;
				values->currentPosition = 1;
				values->layer = 0;
				
				for(int index = 1; index < GRAPH_SIZE; index++)
				{
					Graph[index] = values->blank;
				}
			}
		}		
	}
	
	return heuristicIsLower;
}

void PrepareNewTree(Values *values)
{
	if(values->lowerHeuristicInFullTreeSearch)
	{
		printf("Heuristic %d \n", values->tempRootNode.heuristicValue);
		
		for(int i = 0; i < GRAPH_SIZE; i++)
		{
			if(TempPath[i] != 0)
			{
				Path[values->currentArrayPosition] = TempPath[i];
			
				++values->currentArrayPosition;
			}
		}		
	} else
	{
		values->tempRootNode = Graph[values->currentPosition];
	
		printf("Heuristic %d \n", values->tempRootNode.heuristicValue);
		
		values->currentArrayPosition = SaveThePath(values->currentArrayPosition, values->currentPosition, values->layer);
	}
	
	//Resets all values to initial and appoints new root 
	ResetValues(values);
}

int SaveThePath(int currentArrayPosition, int currentPosition, int layer)
{
	for(int i = 0; i <= GRAPH_SIZE; i++)
	{
		if(Graph[i].move != 0)
		{	
			Path[currentArrayPosition] = Graph[i].move;
		
			currentArrayPosition++;
		}
	}
	
	return currentArrayPosition;
}

void ResetValues(Values *values)
{
	values->upperHeuristic = values->tempRootNode.heuristicValue;
	values->currentPosition = 0;
	values->layer = 0;
	values->tempRootNode.move = 0;
	values->lowerHeuristicInFullTreeSearch = 0;
	
	for(int index = 0; index <= GRAPH_SIZE; index++)
	{
		Graph[index] = values->blank;
	}

	//Appoints a new root for the new tree
	Graph[values->currentPosition] = values->tempRootNode;
}

void CaseFix(Values *values)
{
	memcpy(myCube, Graph[0].cube, sizeof myCube);
	
	// After we have made a new root to the new tree we check that this root is not one of our cases.
	if(CheckForCase(values->upperHeuristic))
	{
		printf("Case hit \n");
		
		FixCase(Path, &values->currentArrayPosition);
		
		memcpy(Graph[0].cube, myCube, sizeof myCube);
	}
}

int MoveUpInLayers(Values *values)
{
	int movingUp = 0;
	int tempPosition;

	if(!CheckHeuristic(values))
	{
		if(Graph[values->currentPosition].move == 12)
		{
			movingUp = 1;
		}
		
		tempPosition = values->currentPosition;
		
		if(!values->currentPosition <= 0)
		{
			--values->currentPosition;
		}

		Graph[tempPosition] = values->blank;
	}
	
	return movingUp;
}

void PrintCube(int currentPosition)
{
	for(int i = 0; i < 6; i++)
	{
		printf("Face %d \n", i + 1);
		for(int q = 0; q < 9; q++)
		{
			printf("%c ", Graph[currentPosition].cube[i][q]);
			if(q % 3 == 2)
			{
				printf("\n");
			}
		}
	}
}

void PrintMoves(int currentArrayPosition)
{
	for(int i = 0; i < currentArrayPosition; i++)
	{
		printf("Move ");
		
		switch(Path[i])
		{
			case RIGHT:
				printf("R ");
				break;
			case INVERTEDRIGHT:
				printf("Ri");
				break;
			case LEFT:
				printf("L ");
				break;
			case INVERTEDLEFT:
				printf("Li");
				break;
			case TOP:
				printf("T ");
				break;
			case INVERTEDTOP:
				printf("Ti");
				break;
			case BOTTOM:
				printf("D ");
				break;
			case INVERTEDBOTTOM:
				printf("Di");
				break;
			case FRONT:
				printf("F ");
				break;
			case INVERTEDFRONT:
				printf("Fi");
				break;
			case BACK:
				printf("B ");
				break;
			case INVERTEDBACK:
				printf("Bi");
				break;
			case 13:
				printf("Turn Cube");
				break;
			case 14:
				printf("Flip Cube");
				break;
			default:
				break;
		}
		
		printf(" %5d \n", i + 1);
	}
}


