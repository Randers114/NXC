#include "Heuristic.h"

#define BOUND 8
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


struct Node 
{
	int heuristicValue;
	int parent;
	int move;
	char cube[6][10];
};

struct Values
{
	int upperHeuristic;
	int currentPosition; 
	int layer;
	int childChoose;
	int currentArrayPosition;
};

Node Graph[GRAPH_SIZE];

int Path[];
int ChildNumber[];


void ConstructNode(int currentPosition, int parent, int move)
{
	Node node;
	memcpy(node.cube, myCube, sizeof myCube);
	node.parent = parent;
	node.heuristicValue = HeuristicValue();
	node.move = move;
	Graph[currentPosition] = node;
}


void ConstructNodeChildren(int &currentPosition, int &layer, int counter)
{	
	int parent = currentPosition, move;
	char rubix[6][10];
	
	memcpy(rubix, myCube, sizeof myCube);
	currentPosition++;
	
	if(ChildNumber[layer] == 12)
	{
		ChildNumber[layer] = 0;
	}
	
	// if(layer == 6)
	// {
		// NumOut(0, LCD_LINE4, ChildNumber[layer]);
		// Wait(SEC_3);
		// ClearScreen();
	// }
	ChildNumber[layer] += 1;
	
	move = ChildNumber[layer];
	
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
			ClearScreen();
			TextOut(0, LCD_LINE1, "ERROR BITCH");
			Wait(SEC_3);
			Stop(true);
	}
	ConstructNode(currentPosition, parent, move);
	
	memcpy(myCube, rubix, sizeof rubix);
	
	// NumOut(0, LCD_LINE1, layer);
	// TextOut(0, LCD_LINE2, "on");
	// NumOut(0, LCD_LINE3, currentPosition);
	// Wait(SEC_1);
	// ClearScreen();
	
	
	layer++;
}

int SaveThePath(int currentArrayPosition, int currentPosition, int layer)
{
	int tempPath[20];
	// Temp array is to reverse the moveset in the path array
	for(int i = 0; i < layer; i++)
	{
		tempPath[i] = Graph[currentPosition].move;
		
		currentPosition = Graph[currentPosition].parent;
	}
	
	// Temp array is assigned to path
	for(int i = layer; i > 0; i--)
	{
		Path[currentArrayPosition] = tempPath[i];
		
		currentArrayPosition++;
	}
	
	return currentArrayPosition;
}

void ResetValues(int &upperHeuristic, int &currentPosition, int &layer, int &childChoose)
{
	upperHeuristic = Graph[currentPosition].heuristicValue;
	currentPosition = 0;
	layer = 0;
	childChoose = 0;
}

void PrepareNewTree(int &upperHeuristic, int &currentPosition, int &layer, int &childChoose, int &currentArrayPosition)
{
	PlaySound(SOUND_UP);
	NumOut(0, LCD_LINE1, upperHeuristic);
	NumOut(0, LCD_LINE2, Graph[currentPosition].heuristicValue);
	TextOut(0, LCD_LINE3, "You can do it");
	Wait(SEC_1);
	ClearScreen();
	
	Node newRoot = Graph[currentPosition];

	currentArrayPosition = SaveThePath(currentArrayPosition, currentPosition, layer);
	

	//Resets all values to initial 
	ResetValues(upperHeuristic, currentPosition, layer, childChoose);

	for(int index = 0; index < GRAPH_SIZE; index++)
	{
		Graph[index] = NULL;
	}

	//Appoints a new root for the new tree
	Graph[currentPosition] = newRoot;
}

bool CheckBottomLayerLeaves(int &upperHeuristic, int &currentPosition, int &layer, int &childChoose, int &currentArrayPosition)
{
	bool lastLeaf = false;
	
	// Set current position to leftmost lowest leaf
	currentPosition = childChoose;
	
	int previousPosition = currentPosition;
	
	if(Graph[currentPosition].heuristicValue < upperHeuristic)
	{		
		PrepareNewTree(upperHeuristic, currentPosition, layer, childChoose, currentArrayPosition);
		
	} else
	{
		lastLeaf = true;
	}
	
	
	return lastLeaf;
}

bool CheckHeuristic(int &upperHeuristic, int &currentPosition, int &layer, int &childChoose, int &currentArrayPosition)
{
	bool heuristicIsLower = false;
	if(Graph[currentPosition].heuristicValue < upperHeuristic)
	{
		PrepareNewTree(upperHeuristic, currentPosition, layer, childChoose, currentArrayPosition);
		
		heuristicIsLower = true;
	}
	
	return heuristicIsLower;
}

bool MoveUpInLayers(int &upperHeuristic, int &currentPosition, int &layer, int &childChoose, int &currentArrayPosition)
{
	bool movingUp = false;
	int tempPosition;
	Node tempNode;
	
	if(!CheckHeuristic(upperHeuristic, currentPosition, layer, childChoose, currentArrayPosition))
	{		
		if(Graph[currentPosition].move == 12)
		{
			movingUp = true;
		}
		
		tempPosition = currentPosition;
			
		currentPosition = Graph[currentPosition].parent;
			
		Graph[tempPosition] = NULL;
	}
	
	return movingUp;
}

void MainGraphConstruction()
{
	int currentPosition = 0, layer = 0, childChoose = 0, upperHeuristic = HIGHEST_HEURISTIC_VALUE, currentArrayPosition = 0;
	int counter = 1, uu = BOUND * HIGHEST_HEURISTIC_VALUE;
	
	bool lastLeafReached; 
	
	ArrayInit(ChildNumber, 0, 10);
	ArrayInit(Path, 0, uu);
	
	ConstructNode(currentPosition, -1, 0);
	
	
	upperHeuristic = Graph[0].heuristicValue;	
	
		
	while(upperHeuristic != 0)
	{
		for(layer; layer < BOUND; counter++)
		{			
			Node newParent = Graph[childChoose];
			
			childChoose = currentPosition + 1;
			
			memcpy(myCube, newParent.cube, sizeof newParent.cube);
			
			ConstructNodeChildren(currentPosition, layer, counter);
			
		}
		
		// if(Graph[5].move == 2)
		// {
			// PlaySound(SOUND_UP);
		// }
		// TextOut(0, LCD_LINE1, "All children constructed");
		// NumOut(0, LCD_LINE2, ChildNumber[7]);
		// NumOut(0, LCD_LINE3, ChildNumber[6]);
		// NumOut(0, LCD_LINE4, ChildNumber[5]);
		// NumOut(0, LCD_LINE5, Graph[6].move);
		//ClearScreen();
		// NumOut(0, LCD_LINE5, ChildNumber[4]);
		// Wait(500);
		// ClearScreen();
		
		
		lastLeafReached = CheckBottomLayerLeaves(upperHeuristic, currentPosition, layer, childChoose, currentArrayPosition);
		
		
		
		if(lastLeafReached)
		{
			bool movingUp = true;
			
			while(movingUp)
			{
				movingUp = MoveUpInLayers(upperHeuristic, currentPosition, layer, childChoose, currentArrayPosition);
				layer--;
			}
			
			//delete the parent node
		}
		
		
	}
	
	PlaySound(SOUND_UP);
	TextOut(0, LCD_LINE1, "Ddu har vundet livet");
	Wait(SEC_3);
	ClearScreen();
	
	for(int jj = 0; jj < BOUND * HIGHEST_HEURISTIC_VALUE; jj = jj + 5)
	{
		NumOut(0, LCD_LINE1, Path[jj]);
		NumOut(0, LCD_LINE2, Path[jj + 1]);
		NumOut(0, LCD_LINE3, Path[jj + 2]);
		NumOut(0, LCD_LINE2, Path[jj + 3]);
		NumOut(0, LCD_LINE3, Path[jj + 4]);
		Wait(SEC_5);
		ClearScreen();
		if(jj == 0)
		{
			break;
		}
	}
	
	
	
		
	// Problems
	// How to move several layers up at a time (possibly solved) (loop in loop maybe impossible)
	// How to refactor the array (use - move) 
	
	
}



