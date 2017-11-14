#define SIZEOFCUBE 54
#include "Heuristic.h"

struct Node 
{
	char cube[6][10];
	int heuristicValue;
	int parent;
};

//char graph[1][6][9];

Node Graph[100];


void ConstructNode(int currentPosition, int parent)
{
	Node node;
	memcpy(myCube, node.cube, sizeof myCube);
	node.parent = parent;
	node.heuristicValue = HeuristicValue();
	Graph[currentPosition] = node;
}


void ConstructNodeChildren(int &currentPosition, int &layer)
{
	int parent = currentPosition;
	currentPosition++;
	RightOperation();
	ConstructNode(currentPosition, parent);
	
	currentPosition++;
	InvertedRightOperation();
	ConstructNode(currentPosition, parent);
	
	currentPosition++;
	LeftOperation();
	ConstructNode(currentPosition, parent);
	
	currentPosition++;
	InvertedLeftOperation();
	ConstructNode(currentPosition, parent);
	
	currentPosition++;
	TopOperation();
	ConstructNode(currentPosition, parent);
	
	currentPosition++;
	InvertedTopOperation();
	ConstructNode(currentPosition, parent);
	
	currentPosition++;
	BottomOperation();
	ConstructNode(currentPosition, parent);
	
	currentPosition++;
	InvertedBottomOperation();
	ConstructNode(currentPosition, parent);
	
	currentPosition++;
	FrontOperation();
	ConstructNode(currentPosition, parent);
	
	currentPosition++;
	InvertedFrontOperation();
	ConstructNode(currentPosition, parent);
	
	currentPosition++;
	BackOperation();
	ConstructNode(currentPosition, parent);
	
	currentPosition++;
	InvertedBackOperation();
	ConstructNode(currentPosition, parent);
	
	layer++;
	currentPosition;
}

void MainGraphConstruction()
{
	int currentPosition = 0, layer = 0;
	ConstructNode(currentPosition, -1);
	ConstructNodeChildren(currentPosition, layer);
	
	
	
	
	
	
}



