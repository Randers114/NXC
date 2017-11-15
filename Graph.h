#include "Heuristic.h"

#define NUM_OF_FACES 6
#define NUM_OF_SQUARES_ON_FACE 10
#define NUM_OF_CHILDREN 12



struct Node
{
	char cube[NUM_OF_FACES][NUM_OF_SQUARES_ON_FACE];
	int heuristicValue;
	int layer;
	bool visited = FALSE;

};

Node Graph[104];

// HVORFOR ER DET [6][10] OG IKKE [6][9]? FÅ DET HER PÅ PLADS.

void ConstructRootNode()
{
	Node node;
	memcpy(myCube, node.cube, sizeof myCube);
	node.heuristicValue = HeuristicValue();
	node.layer = -1;

	Graph[0] = node;
}

void ConstructNode(int position, int layer)
{
	Node node;
	memcpy(myCube, node.cube, sizeof myCube);
	node.heuristicValue = HeuristicValue();
	node.layer = layer;

	int positionInGraph = position;
	Graph[positionInGraph] = node;
}


int ConstructChildren(int parentIndex)
{
	// Layer 0 is the layer where the children of the rootnode are situated.

	Node parentNode = Graph[parentIndex];
	int childPosition, currentLayer = parentNode.layer + 1;

	memcpy(parentNode.cube, myCube, sizeof parentNode.cube);


	for (childPosition = 1; childPosition < 13; childPosition++)
	{
		switch (childPosition)
		{
			case 1:
				RightOperation();
				break;

			case 2:
				InvertedRightOperation();
				break;

			case 3:
				LeftOperation();
				break;

			case 4:
				InvertedLeftOperation();
				break;

			case 5:
				TopOperation();
				break;

			case 6:
				InvertedTopOperation();
				break;

			case 7:
				BottomOperation();
				break;

			case 8:
				InvertedBottomOperation();
				break;

			case 9:
				FrontOperation();
				break;

			case 10:
				InvertedFrontOperation();
				break;

			case 11:
				BackOperation();
				break;

			case 12:
				InvertedBackOperation();
				break;

			default:
				break;

		}

		ConstructNode(parentIndex + childPosition, currentLayer);
		memcpy(parentNode.cube, myCube, sizeof parentNode.cube);
	}

	return childPosition;
}


void GraphConstruction()
{
	int nextParentNode = 1;
	ConstructRootNode();
	ConstructChildren(0);

	while(!lowerHeuristic)
	{
		nextParentNode += ConstructChildren(nextParentNode);
		
	}



}


while (!Graph[index].lowerHeuristic)
{
	DO ConstructChildren ON LEFTMOST Node
	EVALUATE HeuristicValue

	IF lowerHeuristic = FALSE
		Continue

	IF lowerHeuristic = TRUE
		myCube = Graph[index].cube 
		Delete elements in Graph[]
}