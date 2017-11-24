#include "Heuristic.h"
#include <Windows.h>

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

int Path[200];
int ChildNumber[20];
int nodeCount = 0; 
int Bound;

void clrscr()
{
    system("@cls||clear");
}

void ConstructNode(int currentPosition, int move)
{
	nodeCount++;
	
	currentPosition++;

	Node node;
	
	memcpy(node.cube, myCube, sizeof myCube);
	
	node.heuristicValue = HeuristicValue();
	
	node.move = move;
	
	Graph[currentPosition] = node;
}


void ConstructNodeChildren(int *currentPosition, int *layer)
{	
	int move;
	
	for(*layer; *layer < Bound; ++*currentPosition)
	{
		Node newParent = Graph[*currentPosition];
		
		memcpy(myCube, newParent.cube, sizeof newParent.cube);
		
		if(ChildNumber[*layer] == 12)
		{
			ChildNumber[*layer] = 0;
		}
		
		ChildNumber[*layer] += 1;
		
		move = ChildNumber[*layer];
		
		
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
		
		ConstructNode(*currentPosition, move);
		
		++*layer;
		
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

void ResetValues(int ****upperHeuristic, int ****currentPosition, int ****layer)
{
	****upperHeuristic = Graph[****currentPosition].heuristicValue;
	****currentPosition = 0;
	****layer = 0;
	nodeCount = 0;
}

void PrepareNewTree(int ***upperHeuristic, int ***currentPosition, int ***layer, int ***currentArrayPosition)
{
	Node newRoot = Graph[***currentPosition];
	
	printf("Heuristica %d \n", newRoot.heuristicValue);
	
	***currentArrayPosition = SaveThePath(***currentArrayPosition, ***currentPosition, ***layer);
	

	//Resets all values to initial 
	ResetValues(&upperHeuristic, &currentPosition, &layer);

	for(int index = 0; index < GRAPH_SIZE; index++)
	{
		Graph[index] = Blank;
	}

	//Appoints a new root for the new tree
	Graph[***currentPosition] = newRoot;
}

int CheckHeuristic(int **upperHeuristic, int **currentPosition, int **layer, int **currentArrayPosition)
{
	int heuristicIsLower = 0;
	
	if(Graph[**currentPosition].heuristicValue < **upperHeuristic)
	{		
		for(int i = 0; i < 6; i++)
		{
			printf("Face %d \n", i + 1);
			for(int q = 0; q < 9; q++)
			{
				printf("graph: %c \n", Graph[**currentPosition].cube[i][q]);
			}
		}
		PrepareNewTree(&upperHeuristic, &currentPosition, &layer, &currentArrayPosition);
		
		heuristicIsLower = 1;
		
		if(**upperHeuristic <= 12 && **upperHeuristic >= 11)
		{
			Bound = 2;
		} else if(**upperHeuristic <= 10 && **upperHeuristic >= 9)
		{
			Bound = 3;
		} else if(**upperHeuristic <= 8 && **upperHeuristic >= 7)
		{
			Bound = 4;
		} else if(**upperHeuristic == 6) 
		{
			Bound = 6;
		} else if(**upperHeuristic <= 5 && **upperHeuristic >= 4)
		{
			Bound = 6;
		} else if(**upperHeuristic == 3)
		{
			Bound = 7;
		} else 
		{
			Bound = 10;
		}
	}
	
	return heuristicIsLower;
}

int CheckBottomLayerLeaves(int *upperHeuristic, int *currentPosition, int *layer, int *currentArrayPosition)
{
	int lastLeaf = 0;
	
	int previousPosition = *currentPosition;

	if(!CheckHeuristic(&upperHeuristic, &currentPosition, &layer, &currentArrayPosition))
	{
		lastLeaf = 1;
	}
	return lastLeaf;
}



int MoveUpInLayers(int *upperHeuristic, int *currentPosition, int *layer, int *currentArrayPosition)
{
	int movingUp = 0;
	int tempPosition;
	Node tempNode;
	
	if(!CheckHeuristic(&upperHeuristic, &currentPosition, &layer, &currentArrayPosition))
	{		
		if(Graph[*currentPosition].move == 12)
		{
			movingUp = 1;
		}
		
		tempPosition = *currentPosition;
		
		--*currentPosition;
			
		Graph[tempPosition] = Blank;
	}
	
	return movingUp;
}

void MainGraphConstruction()
{
	int currentPosition = 0, layer = 0, upperHeuristic = HIGHEST_HEURISTIC_VALUE, currentArrayPosition = 0, movingUp;
	
	int lastLeafReached; 
	
	ConstructNode(currentPosition - 1 , 0);
	
	upperHeuristic = Graph[0].heuristicValue;
	
	printf("%d\n", upperHeuristic);
	Sleep(3000);
	
	if(upperHeuristic <= 12 && upperHeuristic >= 9)
	{
		Bound = 2;
	} else if(upperHeuristic <= 8 && upperHeuristic >= 6)
	{
		Bound = 5;
	} else if(upperHeuristic <= 5 && upperHeuristic >= 4)
	{
		Bound = 6;
	} else
	{
		Bound = 9;
	} 
		
	while(upperHeuristic != 0)
	{
		ConstructNodeChildren(&currentPosition, &layer);
		
		
		if(nodeCount % 100000000 == 0)
		{
			printf("%d\n", nodeCount);
		}
		

		movingUp = CheckBottomLayerLeaves(&upperHeuristic, &currentPosition, &layer, &currentArrayPosition);

		
		while(movingUp)
		{
			movingUp = MoveUpInLayers(&upperHeuristic, &currentPosition, &layer, &currentArrayPosition);
			layer--;
		}

	}	
	
	printf("Done \n");
	
	for(int i = 0; i < currentArrayPosition; i++)
	{
		printf("Move ");
		
		switch(Path[i])
		{
			case RIGHT:
				printf("R");
				break;
			case INVERTEDRIGHT:
				printf("Ri");
				break;
			case LEFT:
				printf("L");
				break;
			case INVERTEDLEFT:
				printf("Li");
				break;
			case TOP:
				printf("T");
				break;
			case INVERTEDTOP:
				printf("Ti");
				break;
			case BOTTOM:
				printf("D");
				break;
			case INVERTEDBOTTOM:
				printf("Di");
				break;
			case FRONT:
				printf("F");
				break;
			case INVERTEDFRONT:
				printf("Fi");
				break;
			case BACK:
				printf("B");
				break;
			case INVERTEDBACK:
				printf("Bi");
				break;
			default:
				break;
		}
		
		printf("\n");
	}
}



