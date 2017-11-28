#include "Heuristic.h"

#define BOUND 3
#define HIGHEST_HEURISTIC_VALUE 12
#define GRAPH_SIZE 12

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
} Values;

Node Graph[GRAPH_SIZE];
Node Blank;
Node TempRootNode;

int Path[200];
int TempPath[200];
int ChildNumber[20];
int nodeCount = 0; 
int Bound;
int Flag;

void clrscr()
{
    system("@cls||clear");
}

void ConstructNode(int currentPosition, int move, int upperHeuristic)
{
	nodeCount++;
	
	currentPosition++;

	Node node;
	
	memcpy(node.cube, myCube, sizeof myCube);
	
	if(upperHeuristic > 8)
	{
		node.heuristicValue = HeuristicValueWhiteCross();
	}
	else if(upperHeuristic > 4)
	{
		node.heuristicValue = HeuristicValueWhiteFace();
	} else
	{
		node.heuristicValue = HeuristicValueCenterLayer();
	}
	
	node.move = move;
	
	Graph[currentPosition] = node;
}


void ConstructNodeChildren(Values *values)
{	
	int move;
	
	for(values->layer; values->layer < Bound; ++values->currentPosition)
	{
		Node newParent = Graph[values->currentPosition];
		
		memcpy(myCube, newParent.cube, sizeof newParent.cube);
		
		if(ChildNumber[values->layer] == 12)
		{
			ChildNumber[values->layer] = 0;
		}
		
		ChildNumber[values->layer] += 1;
		
		move = ChildNumber[values->layer];
		
		
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
		
		memcpy(myCube, newParent.cube, sizeof newParent.cube);
	}
}

int SaveThePath(int currentArrayPosition, int currentPosition, int layer)
{
	for(int i = 0; i < Bound; i++)
	{
		if(Graph[i].move != 0)
		{
			Path[currentArrayPosition] = Graph[i].move;
		
			currentArrayPosition++;
		}
	}
	
	return currentArrayPosition;
}

void ResetValues(Values ****values)
{
	(*(*(*values)))->upperHeuristic = Graph[(*(*(*values)))->currentPosition].heuristicValue;
	(*(*(*values)))->currentPosition = 0;
	(*(*(*values)))->layer = 0;
	//nodeCount = 0;
}

void PrepareNewTree(Values ***values)
{
	if(Flag)
	{
		printf("Heuristic %d \n", TempRootNode.heuristicValue);
		
		for(int i = 0; i < Bound; i++)
		{
			if(TempPath[i] != 0)
			{
				Path[(*(*values))->currentArrayPosition] = TempPath[i];
			
				++(*(*values))->currentArrayPosition;
			}
		}
		
		//Resets all values to initial 
		(*(*values))->upperHeuristic = TempRootNode.heuristicValue;
		(*(*values))->currentPosition = 0;
		(*(*values))->layer = 0;
		//nodeCount = 0;
		Flag = 0;
		
		for(int index = 0; index < GRAPH_SIZE; index++)
		{
			Graph[index] = Blank;
		}
		
		Graph[(*(*values))->currentPosition] = TempRootNode;
		
		
	} else
	{
		TempRootNode = Graph[(*(*values))->currentPosition];
	
		printf("Heuristic %d \n", TempRootNode.heuristicValue);
		
		(*(*values))->currentArrayPosition = SaveThePath((*(*values))->currentArrayPosition, (*(*values))->currentPosition, (*(*values))->layer);
		

		//Resets all values to initial 
		ResetValues(&values);

		for(int index = 0; index < GRAPH_SIZE; index++)
		{
			Graph[index] = Blank;
		}

		//Appoints a new root for the new tree
		Graph[(*(*values))->currentPosition] = TempRootNode;
	}

}

int CheckHeuristic(Values **values)
{
	int heuristicIsLower = 0;
	
	if(Graph[(*values)->currentPosition].heuristicValue < (*values)->upperHeuristic || (Graph[(*values)->currentPosition].move == 12 && (*values)->layer == 1))
	{	
		if((*values)->upperHeuristic > 4 && !(Graph[(*values)->currentPosition].move == 12 && (*values)->layer == 1))
		{
			Flag = 1;
			
			TempRootNode = Blank;
			
			
			TempRootNode = Graph[(*values)->currentPosition];
			
			for(int i = 0; i <= Bound; i++)
			{
				if(Graph[i].move != 0)
				{
					TempPath[i] = Graph[i].move;
				}
			}		

			(*values)->upperHeuristic = TempRootNode.heuristicValue;
			
		} else if(Flag || Graph[(*values)->currentPosition].heuristicValue < (*values)->upperHeuristic)
		{
			PrepareNewTree(&values);
		
			heuristicIsLower = 1;
			
			
			Bound = BOUND;

		} else 
		{
			if(Bound >= 9)
			{
				printf("Solution not reachable in appropriate time.. \n");
				exit(0);
			} else 
			{
				Bound++;
				(*values)->currentPosition = 1;
				(*values)->layer = 0;
				
				for(int index = 1; index < GRAPH_SIZE; index++)
				{
					Graph[index] = Blank;
				}
			}
		}
		
		
	}
	
	return heuristicIsLower;
}

int CheckBottomLayerLeaves(Values *values)
{
	int lastLeaf = 0;

	if(!CheckHeuristic(&values))
	{
		lastLeaf = 1;
	}
	return lastLeaf;
}



int MoveUpInLayers(Values *values)
{
	int movingUp = 0;
	int tempPosition;

	if(!CheckHeuristic(&values))
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
		

			
		Graph[tempPosition] = Blank;
	}
	
	return movingUp;
}

void MainGraphConstruction()
{
	int movingUp, lastLeafReached;
	
	Values values = { .upperHeuristic = HIGHEST_HEURISTIC_VALUE, .currentPosition = 0, .layer = 0, .currentArrayPosition = 0};
	
	Flag = 0;
	
	ConstructNode(values.currentPosition - 1 , 0, HIGHEST_HEURISTIC_VALUE);
	
	values.upperHeuristic = Graph[0].heuristicValue;
	
	printf("Start Heuristic value %d\n", values.upperHeuristic);
	
	Bound = BOUND;
		
	while(values.upperHeuristic != 0)
	{
		ConstructNodeChildren(&values);
		
		
		if(nodeCount % 100000000 == 0)
		{
			printf("%d\n", nodeCount);
		}
		
		
		movingUp = CheckBottomLayerLeaves(&values);

		
		while(movingUp)
		{
			movingUp = MoveUpInLayers(&values);
			values.layer--;
			
			if(values.layer < 0)
			{
				values.layer = 0;
			}
		}
	}	
	
	printf("Done \n");
	
	// for(int i = 0; i < 6; i++)
	// {
		// printf("Face %d \n", i + 1);
		// for(int q = 0; q < 9; q++)
		// {
			// printf("%c ", Graph[values.currentPosition].cube[i][q]);
			// if(q % 3 == 2)
			// {
				// printf("\n");
			// }
		// }
	// }
	
	for(int i = 0; i < values.currentArrayPosition; i++)
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
			default:
				break;
		}
		
		printf(" %5d \n", i + 1);
	}
	
	printf("Total Nodecount %d \n", nodeCount / 1000);
}



