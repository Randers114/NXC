#include "CheckCase.h"

#define BOUND 3
#define HIGHEST_HEURISTIC_VALUE 12
#define GRAPH_SIZE 10
#define WORST_NUMBER_OF_CASES 4 
#define NUMBER_OF_MOVES_IN_CASE 7

struct Node 
{
	int heuristicValue;
	int move;
	char cube[6][10];
};

struct Values
{
	int upperHeuristic;
	int currentPosition; 
	int layer;
	int currentArrayPosition;
};

Node Blank;
Node TempRootNode;
Node Graph[GRAPH_SIZE];

int Bound;
int Flag;	
int TempPath[GRAPH_SIZE];
int Path[HIGHEST_HEURISTIC_VALUE * GRAPH_SIZE + WORST_NUMBER_OF_CASES * NUMBER_OF_MOVES_IN_CASE];
int ChildNumber[GRAPH_SIZE];
int nodeCount = 0;

void CaseFix(Values &values)
{
	Node tempNode = Graph[0];
	
	memcpy(myCube, tempNode.cube, sizeof myCube);
	
	// After we have made a new root to the new tree we check that this root is not one of our cases.
	if(CheckForCase(values.upperHeuristic))
	{
		TextOut(0, LCD_LINE1, "Case hit");
		Wait(1000);
		
		FixCase(Path, values.currentArrayPosition);
		
		memcpy(tempNode.cube, myCube, sizeof myCube);
		Graph[0] = tempNode;
	}
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


void ConstructNodeChildren(Values &values)
{	
	int move;
	
	for(values.layer; values.layer < Bound; ++values.currentPosition)
	{		
		Node newParent = Graph[values.currentPosition];
		
		memcpy(myCube, newParent.cube, sizeof newParent.cube);
		
		// If childnumber hits 12 resets the value to zero
		if(ChildNumber[values.layer] == 12)
		{
			ChildNumber[values.layer] = 0;
		}
		
		ChildNumber[values.layer] += 1;
		
		// ChildNumber decides the move
		move = ChildNumber[values.layer];
		
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
		
		ConstructNode(values.currentPosition, move, values.upperHeuristic);
		
		++values.layer;
		
		memcpy(myCube, newParent.cube, sizeof newParent.cube);
	}
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

void ResetValues(Values &values)
{
	values.upperHeuristic = Graph[values.currentPosition].heuristicValue;
	values.currentPosition = 0;
	values.layer = 0;
	TempRootNode.move = 0;
}

void PrepareNewTree(Values &values)
{
	if(Flag)
	{		
		for(int i = 0; i < GRAPH_SIZE; i++)
		{
			if(TempPath[i] != 0)
			{
				Path[values.currentArrayPosition] = TempPath[i];
			
				++values.currentArrayPosition;
			}
		}
		
		//Resets all values to initial 
		values.upperHeuristic = TempRootNode.heuristicValue;
		values.currentPosition = 0;
		values.layer = 0;
		TempRootNode.move = 0;
		Flag = 0;
		
		for(int index = 0; index <= GRAPH_SIZE; index++)
		{
			Graph[index] = Blank;
		}
		
		Graph[values.currentPosition] = TempRootNode;
		
		
	} else
	{
		TempRootNode = Graph[values.currentPosition];
		
		values.currentArrayPosition = SaveThePath(values.currentArrayPosition, values.currentPosition, values.layer);

		//Resets all values to initial 
		ResetValues(values);

		for(int index = 0; index <= GRAPH_SIZE; index++)
		{
			Graph[index] = Blank;
		}

		//Appoints a new root for the new tree
		Graph[values.currentPosition] = TempRootNode;
	}

}

int CheckHeuristic(Values &values)
{
	int heuristicIsLower = 0;
	
	if(Graph[values.currentPosition].heuristicValue < values.upperHeuristic || (Graph[values.currentPosition].move == 12 && values.layer == 1))
	{	
		if(values.upperHeuristic > 4 && !(Graph[values.currentPosition].move == 12 && values.layer == 1))
		{
			Flag = 1;			
			
			TempRootNode = Graph[values.currentPosition];
			
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
			if(TempRootNode.heuristicValue != 0)
			{
				values.upperHeuristic = TempRootNode.heuristicValue;
			} else 
			{
				values.upperHeuristic = TempRootNode.heuristicValue;
				PrepareNewTree(values);
				heuristicIsLower = 1;
			}
		} else if(Flag || Graph[values.currentPosition].heuristicValue < values.upperHeuristic)
		{
			PrepareNewTree(values);
		
			heuristicIsLower = 1;
			
			Bound = BOUND;
			
			CaseFix(values);

		} else 
		{
			if(Bound >= 9)
			{
				StopAllTasks();
			} else 
			{
				Bound++;
				values.currentPosition = 1;
				values.layer = 0;
				
				for(int index = 1; index < GRAPH_SIZE; index++)
				{
					Graph[index] = Blank;
				}
			}
		}
		
		
	}
	
	return heuristicIsLower;
}

int CheckBottomLayerLeaves(Values &values)
{
	int lastLeaf = 0;

	if(!CheckHeuristic(values))
	{
		lastLeaf = 1;
	}
	return lastLeaf;
}



int MoveUpInLayers(Values &values)
{
	int movingUp = 0;
	int tempPosition;

	if(!CheckHeuristic(values))
	{

		if(Graph[values.currentPosition].move == 12)
		{
			movingUp = 1;
		}
		
		tempPosition = values.currentPosition;
		
		if(!values.currentPosition <= 0)
		{
			--values.currentPosition;
		}
		
		Graph[tempPosition] = Blank;
	}
	
	return movingUp;
}

void MainGraphConstruction()
{
	int movingUp, lastLeafReached;
	
	Values values;
	
	values.upperHeuristic = HIGHEST_HEURISTIC_VALUE;
	values.currentPosition = 0;
	values.layer = 0;
	values.currentArrayPosition = 0;
	
	
	Flag = 0;
	
	ConstructNode(values.currentPosition - 1 , 0, HIGHEST_HEURISTIC_VALUE);
	
	values.upperHeuristic = Graph[0].heuristicValue;
	
	TextOut(0, LCD_LINE1, "Start Heuristic value ");
	NumOut(0, LCD_LINE2, values.upperHeuristic);
	Wait(1000);
	ClearScreen();
	Bound = BOUND;
	
	CaseFix(values);
		
	while(values.upperHeuristic != 0)
	{
		ConstructNodeChildren(values);
		
		movingUp = CheckBottomLayerLeaves(values);
		
		while(movingUp)
		{
			movingUp = MoveUpInLayers(values);
			values.layer--;
			
			if(values.layer < 0)
			{
				values.layer = 0;
			}
		}
	}	
	ClearScreen();
	TextOut(0, LCD_LINE1, "Done ");
	
	Node root = Graph[0];
		
	memcpy(myCube, root.cube, sizeof root.cube);
	
	Wait(1000);
}



