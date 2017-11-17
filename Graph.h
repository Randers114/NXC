#include "Heuristic.h"

#define BOUND 8
#define HIGHEST_HEURISTIC_VALUE 12
#define GRAPH_SIZE 120

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

int Path[BOUND * HIGHEST_HEURISTIC_VALUE];


void ConstructNode(int currentPosition, int parent, int move)
{
	Node node;
	memcpy(node.cube, myCube, sizeof myCube);
	node.parent = parent;
	node.heuristicValue = HeuristicValue();
	node.move = move;
	Graph[currentPosition] = node;
}


void ConstructNodeChildren(int &currentPosition, int &layer)
{	
	int parent = currentPosition;
	char rubix[6][10];
	
	// ClearScreen();
	// TextOut(0, LCD_LINE1, "args");
	// NumOut(0, LCD_LINE2, layer);
	// NumOut(0, LCD_LINE3, currentPosition);
	// Wait(SEC_2);
	// ClearScreen();
	
	memcpy(rubix, myCube, sizeof myCube);
	
	for(int move = 1; move < 13; move++)
	{
		currentPosition++;
		if(layer >= 6)
		{
			int ps, ds;
			TextOut(0, LCD_LINE1, "args");
			NumOut(0, LCD_LINE2, currentPosition);
			NumOut(0, LCD_LINE3, move);
			Wait(SEC_2);
	 		ClearScreen();
			
			int result = GetMemoryInfo(true, ps, ds);
			NumOut(0, LCD_LINE1, ps);
			NumOut(0, LCD_LINE2, ds);
			Wait(SEC_5);
			ClearScreen();
			Wait(SEC_1);
		}
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
		}
		ConstructNode(currentPosition, parent, move);
		
		memcpy(myCube, rubix, sizeof rubix);
	}	
	ClearScreen();
	NumOut(0, LCD_LINE1, layer);
	layer++;
	NumOut(0, LCD_LINE2, layer);
	Wait(SEC_2);
	ClearScreen();
}

int SaveThePath(int currentArrayPosition, int currentPosition, int layer)
{
	int tempPath[BOUND];
	
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
	
	for(int leaf = 0; leaf < 12; leaf++)
	{
		if(Graph[currentPosition + leaf].heuristicValue < upperHeuristic)
		{
			// NumOut(0, LCD_LINE2, Graph[currentPosition + leaf].heuristicValue);
			// NumOut(0, LCD_LINE3, upperHeuristic);
			// NumOut(0, LCD_LINE4, Graph[currentPosition + leaf].move);
			TextOut(0, LCD_LINE1, "Win5");
			Wait(SEC_2);
			ClearScreen();
			currentPosition = currentPosition + leaf;
			
			PrepareNewTree(upperHeuristic, currentPosition, layer, childChoose, currentArrayPosition);
			
			break;
			
		} else
		{
			if(leaf == 11)
			{
				TextOut(0, LCD_LINE1, "Win");
				Wait(SEC_2);
				ClearScreen();
				currentPosition = Graph[currentPosition + leaf].parent;
				lastLeaf = true;
				
				NumOut(0, LCD_LINE1, currentPosition);
				NumOut(0, LCD_LINE2, layer);
				Wait(SEC_2);
				ClearScreen();
			} 
			
			//Delete the node
			Graph[previousPosition + leaf] = NULL;
			
		}
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
		if(Graph[currentPosition].move != 12)
		{
			Graph[currentPosition] = NULL;
			currentPosition++;
			
			// Refactor array
			for(int i = currentPosition; i < currentPosition + (12 - Graph[currentPosition].move); i++)
			{
				tempNode = Graph[i];
				
				Graph[i - 1] = tempNode;
				
				Graph[i] = NULL;
			}
		} else 
		{
			movingUp = true;
			tempPosition = currentPosition;
			
			currentPosition = Graph[currentPosition].parent;
			
			Graph[tempPosition] = NULL;			
		}
	}
	
	return movingUp;
}

void MainGraphConstruction()
{
	int currentPosition = 0, layer = 0, childChoose = 0, upperHeuristic = HIGHEST_HEURISTIC_VALUE, currentArrayPosition = 0;
	int counter = 0, uu = 0;
	
	bool lastLeafReached; 
	
	
	ConstructNode(currentPosition, -1, 0);
	
	
	upperHeuristic = Graph[0].heuristicValue;	
	
		
	while(upperHeuristic != 0)
	{
		for(layer; layer < BOUND;)
		{
			NumOut(0, LCD_LINE1, Graph[childChoose].move);
			NumOut(0, LCD_LINE3, FreeMemory());
			NumOut(0, LCD_LINE2, layer);
			Wait(SEC_2);
			ClearScreen();
			
			Node newParent = Graph[childChoose];
			
			childChoose = layer * 12 + 1;
			
			memcpy(myCube, newParent.cube, sizeof newParent.cube);
			ConstructNodeChildren(currentPosition, layer);
			
			NumOut(0, LCD_LINE5, layer);
		}
		
		TextOut(0, LCD_LINE1, "All children constructed");
		// NumOut(0, LCD_LINE2, childChoose);
		// NumOut(0, LCD_LINE3, counter);
		// NumOut(0, LCD_LINE4, layer);
		Wait(SEC_2);
		ClearScreen();
		
		lastLeafReached = CheckBottomLayerLeaves(upperHeuristic, currentPosition, layer, childChoose, currentArrayPosition);
		
		
		
		if(lastLeafReached)
		{
			TextOut(0, LCD_LINE1, "Movup");
			Wait(SEC_2);
			ClearScreen();
			bool movingUp = true;
			
			while(movingUp)
			{
				movingUp = MoveUpInLayers(upperHeuristic, currentPosition, layer, childChoose, currentArrayPosition);
				layer--;
			}
			
			//delete the parent node
			//refactor array
		}
		
		counter++;
	}
	
	PlaySound(SOUND_UP);
	
	// NumOut(0, LCD_LINE1, Path[0]);
	// NumOut(0, LCD_LINE2, Path[1]);
	// NumOut(0, LCD_LINE3, Path[2]);
	
		
	// Problems
	// How to move several layers up at a time (possibly solved) (loop in loop maybe impossible)
	// How to refactor the array (use - move) 
	
	
}



