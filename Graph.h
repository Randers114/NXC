#define SIZEOFCUBE 54
#include "Heuristic.h"

struct Node 
{
	char cube[6][10];
	int heuristicValue;
	int parent;
	int move;
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
	char rubix[6][10];
	memcpy(myCube, rubix, sizeof myCube);
	
	currentPosition++;
	RightOperation();
	ConstructNode(currentPosition, parent);
	Graph[currentPosition].move = 1;
	memcpy(rubix, myCube, sizeof rubix);
	
	currentPosition++;
	InvertedRightOperation();
	ConstructNode(currentPosition, parent);
	Graph[currentPosition].move = 2;
	memcpy(rubix, myCube, sizeof rubix);
	
	currentPosition++;
	LeftOperation();
	ConstructNode(currentPosition, parent);
	Graph[currentPosition].move = 3;
	memcpy(rubix, myCube, sizeof rubix);
	
	currentPosition++;
	InvertedLeftOperation();
	ConstructNode(currentPosition, parent);
	Graph[currentPosition].move = 4;
	memcpy(rubix, myCube, sizeof rubix);
	
	currentPosition++;
	TopOperation();
	ConstructNode(currentPosition, parent);
	Graph[currentPosition].move = 5;
	memcpy(rubix, myCube, sizeof rubix);
	
	currentPosition++;
	InvertedTopOperation();
	ConstructNode(currentPosition, parent);
	Graph[currentPosition].move = 6;
	memcpy(rubix, myCube, sizeof rubix);
	
	currentPosition++;
	BottomOperation();
	ConstructNode(currentPosition, parent);
	Graph[currentPosition].move = 7;
	memcpy(rubix, myCube, sizeof rubix);
	
	currentPosition++;
	InvertedBottomOperation();
	ConstructNode(currentPosition, parent);
	Graph[currentPosition].move = 8;
	memcpy(rubix, myCube, sizeof rubix);
	
	currentPosition++;
	FrontOperation();
	ConstructNode(currentPosition, parent);
	Graph[currentPosition].move = 9;
	memcpy(rubix, myCube, sizeof rubix);
	
	currentPosition++;
	InvertedFrontOperation();
	ConstructNode(currentPosition, parent);
	Graph[currentPosition].move = 10;
	memcpy(rubix, myCube, sizeof rubix);
	
	currentPosition++;
	BackOperation();
	ConstructNode(currentPosition, parent);
	Graph[currentPosition].move = 11;
	memcpy(rubix, myCube, sizeof rubix);
	
	currentPosition++;
	InvertedBackOperation();
	ConstructNode(currentPosition, parent);
	Graph[currentPosition].move = 12;
	memcpy(rubix, myCube, sizeof rubix);
	
	layer++;
}

void MainGraphConstruction()
{
	int currentPosition = 0, layer = 0, bound = 8, childChoose = 0;
	ConstructNode(currentPosition, -1);
	ConstructNodeChildren(currentPosition, layer);
	
	for(layer; layer <= bound;)
	{
		Node newParent = Graph[childChoose];
		
		childChoose = layer * (12 - newParent.move) + 1;
		
		memcpy(newParent.cube, myCube, sizeof newParent.cube);
		ConstructNodeChildren(currentPosition, layer);
		
		
	}
	
	
	
	
	
	
}



