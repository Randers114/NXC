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
	int heuristicValue = 0, complementingPiece = 0, complementingFace = 0;
	
	for(i = 1; i < 8; i = i + 2)
	{
		if(myCube[whiteFace][i] = 'w')
		{
			FindComplementingEdge(whiteFace, i, &complementingFace, &complementingPiece);
			
			if(!(myCube[complementingFace][CENTER_PIECE] == myCube[complementingFace][complementingPiece]))
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

int CheckWhiteCorner(int whiteFace)
{
	int heuristicValue = 0, complementingPiece = 0, complementingFace = 0, complementingPiece2 = 0, complementingFace2 = 0;
	
	for(i = 0; i < 9; i = i + 2)
	{
		if(myCube[whiteFace][i] = 'w')
		{
			FindComplementingCorners(whiteFace, i, &complementingFace, &complementingPiece, &complementingFace2, &complementingPiece2);
			
			if(!(myCube[complementingFace][CENTER_PIECE] == myCube[complementingFace][complementingPiece]))
			{
				heuristicValue++;
			} 
			else if(!(myCube[complementingFace2][CENTER_PIECE] == myCube[complementingFace2][complementingPiece2]))
			{
				heuristicValue++;
			}
		} else
		{
			heuristicValue++;
		}
		
		if(i == 2)
		{
			i = i + 4;
		}
	}
	
	return heuristicValue;
}

int CheckCenterLayerEdges(int whiteFace)
{
	int face, oppositeFace, centerlayerpiece, centerLayerPiece2, complementingFace, complementingPiece, heuristicValue = 0;
	switch(whiteFace)
	{
		case TOP_FACE:
		case BOTTOM_FACE:
			face = FRONT_FACE;
			oppositeFace = BACK_FACE;
			centerlayerpiece = 4;
			centerLayerPiece2 = 6;
		break;
		
		case RIGHT_FACE:
		case LEFT_FACE:
			face = TOP_FACE;
			oppositeFace = BOTTOM_FACE;
			centerlayerpiece = 2;
			centerLayerPiece2 = 8;
		break;
		
		case FRONT_FACE:
		case BACK_FACE:
			face = TOP_FACE;
			oppositeFace = BOTTOM_FACE;
			centerlayerpiece = 4;
			centerLayerPiece2 = 6;
		break;
	}
	
	if(myCube[face][centerlayerpiece] == myCube[face][CENTER_PIECE])
	{
		FindComplementingEdge(face, centerlayerpiece, &complementingFace, &complementingPiece)
		if(!(myCube[complementingFace][CENTER_PIECE] == myCube[complementingFace][complementingPiece]))
		{
			heuristicValue++;
		}
	} else 
	{
		heuristicValue++;
	}
	
	if(myCube[oppositeFace][centerlayerpiece2] == myCube[oppositeFace][CENTER_PIECE])
	{
		FindComplementingEdge(face, centerlayerpiece2, &complementingFace, &complementingPiece)
		if(!(myCube[complementingFace][CENTER_PIECE] == myCube[complementingFace][complementingPiece]))
		{
			heuristicValue++;
		}
	} else 
	{
		heuristicValue++;
	}
	
	return heuristicValue;
	
}


int HeuristicValue()
{
	int whiteFace, heuristicValue = 0;
	
	whiteFace = FindWhiteFace();
	
	heuristicValue += CheckWhiteEdges(whiteFace);
	
	heuristicValue += CheckWhiteCorner(whiteFace);
	
	heuristicValue += CheckCenterLayerEdges();
	
	return heuristicValue;
}










