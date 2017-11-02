#include "CubeOperations.h"

int FindWhiteFace()
{
	int whiteFace;
	
	for(int i = 0; i < 6; i++)
	{
		if(myCube[i][4] == 'w')
		{
			whiteFace = i;
		}
	}
	
	return whiteFace;
}

int CheckWhiteEdges(int whiteFace)
{
	int heuristicValue, complementingPiece = 0, complementingFace = 0, centerPiece = 4;
	
	for(i = 1; i < 8; i = i + 2)
	{
		if(myCube[whiteFace][i] = 'w')
		{
			FindComplementingEdge(whiteFace, i, &complementingFace, &complementingPiece);
			
			if(!(myCube[complementingFace][centerPiece] == myCube[complementingFace][complementingPiece]))
			{
				heuristicValue++;
			}
		} else
		{
			heuristicValue++;
		}
	}
	
	return heuristicValue;
}




int HeuristicValue()
{
	int whiteFace, heuristicValue = 0;
	
	whiteFace = FindWhiteFace();
	
	heuristicValue += CheckWhiteEdges(whiteFace);
	
	heuristicValue += CheckWhiteCorner();
	
	heuristicValue += CheckCenterLayerEdges();
	
	return heuristicValue;
}










