#include "Heuristic.h"

#define NUM_OF_FACES 6
#define NUM_OF_SQUARES_ON_FACE 10



struct Node
{
	char cube[NUM_OF_FACES][NUM_OF_SQUARES_ON_FACE];
	int heuristicValue;
	int layer;

};

Node Graph[104];

// HVORFOR ER DET [6][10] OG IKKE [6][9]? FÅ DET HER PÅ PLADS.

void ConstructRootNode()
{
	Node node;
	memcpy(myCube, node.cube, sizeof myCube);
	node.heuristicValue = HeuristicValue();

	Graph[0] = node;
}

void ConstructNode(int position, int layer, int parent)
{
	Node node;
	memcpy(myCube, node.cube, sizeof myCube);
	node.heuristicValue = HeuristicValue();
	node.layer = layer;

	int positionInGraph = (layer * 12) + position;
	Graph[positionInGraph] = node;
}


void ConstructChildren(int parentIndex)
{
	// Layer 0 is the layer where the children of the rootnode are situated.

	Node parentNode = Graph[parentIndex];
	int childPosition, currentLayer = parentNode.layer + 1;

	memcpy(myCube, parentCube, sizeof myCube);


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

		ConstructNode(childPosition, currentLayer);
		memcpy(parentCube, myCube, sizeof parentCube);
	}

	currentLayer++;

}


void GraphConstruction()
{
	ConstructRootNode();

	
	ConstructChildren();



}
