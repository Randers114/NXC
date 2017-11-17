
#include "Heuristic.h"

#define NUM_OF_FACES 6
#define NUM_OF_SQUARES_ON_FACE 10
#define NUM_OF_CHILDREN 12

#define LAST_IN_LAYER_1 12
#define LAST_IN_LAYER_2 24
#define LAST_IN_LAYER_3 36
#define LAST_IN_LAYER_4	48
#define LAST_IN_LAYER_5 60
#define LAST_IN_LAYER_6 72
#define LAST_IN_LAYER_7 84
#define LAST_IN_LAYER_8 96

#define MOVE_A_LAYER_UP 2 * NUM_OF_CHILDREN

struct Node
{
	char cube[NUM_OF_FACES][NUM_OF_SQUARES_ON_FACE];
	int heuristicValue;
	int layer;
};

Node Graph[104];

// HVORFOR ER DET [6][10] OG IKKE [6][9]? FÅ DET HER PÅ PLADS.

int ConstructRootNode()
{
	Node node;
	memcpy(node.Cube, myCube, sizeof myCube);
	node.heuristicValue = HeuristicValue();
	node.layer = 0;

	Graph[0] = node;

	return node.heuristicValue;
}

int ConstructNode(int position, int layer)
{
	Node node;
	memcpy(node.Cube, myCube, sizeof myCube);
	node.heuristicValue = HeuristicValue();
	node.layer = layer;

	int positionInGraph = position;
	Graph[positionInGraph] = node;

	return node.heuristicValue;
}


int ConstructChildren(int parentIndex, int heuristicValue[], int &currentLayer)
{
	// Layer 0 is the layer where the children of the rootnode are situated.

	Node parentNode = Graph[parentIndex];
	int childPosition, currentLayer = parentNode.layer + 1;

	memcpy(myCube, parentNode.cube, sizeof parentNode.cube);


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

		heuristicValue[childPosition -1] = ConstructNode((parentNode.layer * NUM_OF_CHILDREN) + childPosition, currentLayer);  // Construct the child-node.
		memcpy(myCube, parentNode.cube, sizeof parentNode.cube);  // Reset the parent-node.
	}

	return childPosition;
}


void GraphConstruction()
{
	int nextParentNode = 0, nextIn7Layer = 1, nextIn6Layer = 1, nextIn5Layer = 1 , nextIn4Layer = 1, nextIn3Layer = 1, nextIn2Layer = 1, nextIn1Layer = 1;
	const int resetLayerPosition = 1;
    int heuristicRootValue, currentLayer;
	int heuristicValue[];
	bool lowerHeuristic = FALSE;
	int path[];
	heuristicRootValue = ConstructRootNode();
	path[0] = 1;

	while(!lowerHeuristic)
	{
		// moving to the next node in 7 layer
		if(nextParentNode > LAST_IN_LAYER_8)
		{
			nextParentNode -= (MOVE_A_LAYER_UP - nextIn7Layer);
			nextIn7Layer++;

			// moving to the next node in 6 layer
			if(nextParentNode > LAST_IN_LAYER_7)
			{
				nextIn7Layer = resetLayerPosition;
				nextParentNode -= (MOVE_A_LAYER_UP - nextIn6Layer);
				nextIn6Layer++;

				// moving to the next node in 5 layer
				if(nextParentNode > LAST_IN_LAYER_6)
				{
					nextIn6Layer = resetLayerPosition;
					nextParentNode -= (MOVE_A_LAYER_UP - nextIn5Layer);
					nextIn5Layer++;

					// moving to the next node in 4 layer
					if(nextParentNode > LAST_IN_LAYER_5)
					{
						nextIn5Layer = resetLayerPosition;
						nextParentNode -= (MOVE_A_LAYER_UP - nextIn4Layer);
						nextIn4Layer++;

						// moving to the next node in 3 layer
						if (nextParentNode > LAST_IN_LAYER_4)
						{
							 nextIn4Layer = resetLayerPosition;
							 nextParentNode -= (MOVE_A_LAYER_UP - nextIn3Layer);
							 nextIn3Layer++;

							 // moving to the next node in 2 layer
							 if(nextParentNode > LAST_IN_LAYER_3)
							 {
							 	nextIn3Layer = resetLayerPosition;
							 	nextParentNode -= (MOVE_A_LAYER_UP - nextIn2Layer);
							 	nextIn2Layer++;

							 	// move to the next node in 1 layer
							 	if(nextParentNode > LAST_IN_LAYER_2)
							 	{
							 		nextIn2Layer = resetLayerPosition;
							 		nextParentNode -= (MOVE_A_LAYER_UP - nextIn1Layer);
							 		nextIn1Layer++;
							 	}
							 }

						}
					}
				}
			}

		}
		// the final path when the while loop is done
		path[0] = nextIn1Layer;
		path[1] = nextIn2Layer;
		path[2] = nextIn3Layer;
		path[3] = nextIn4Layer;
		path[4] = nextIn5Layer;
		path[5] = nextIn6Layer;
		path[6] = nextIn7Layer;
		if (nextParentNode == 0)
		{
			ConstructChildren(nextParentNode, heuristicValue, currentLayer);
			nextParentNode++;
		}
		else
		{
			nextParentNode += ConstructChildren(nextParentNode, heuristicValue, currentLayer);
		}
		// checks if every child heuristic value is lower than the root value
		for (int i = 0; i < NUM_OF_CHILDREN; ++i)
		{
			if(heuristicRootValue > heuristicValue[i])
			{
				path[currentLayer - 1] = i+1;
				path[currentLayer] = 
				lowerHeuristic = TRUE;
			}
		}
    }
}
