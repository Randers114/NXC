#include "CubeOperations.h"

int FindWhiteFace()
{
	int whiteFace;
	
	for(int face = 0; face < 6; face++)
	{
		if(myCube[face][CENTER_PIECE] == 'w')
		{
			whiteFace = face;
		}
	}
	
	return whiteFace;
}

int CheckWhiteEdges(int whiteFace)
{
	int heuristicValue = 0, complementingPiece = 0, complementingFace = 0;
	
	for(int piece = 1; piece < 8; piece = piece + 2)
	{
		if(myCube[whiteFace][piece] == 'w')
		{
			FindComplementingEdge(whiteFace, piece, complementingFace, complementingPiece);
			
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
	
	for(int piece = 0; piece < 9; piece = piece + 2)
	{
		if(myCube[whiteFace][piece] == 'w')
		{
			FindComplementingCorners(whiteFace, piece, complementingFace, complementingPiece, complementingFace2, complementingPiece2);
			
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
		
		if(piece == 2)
		{
			piece += 2;
		}
	}
	
	return heuristicValue;
}

void IndividualEdgePieceCheck(int face, int centerLayerPiece, int &heuristicValue)
{
	int complementingFace, complementingPiece;
	
	if(myCube[face][centerLayerPiece] == myCube[face][CENTER_PIECE])
	{
		FindComplementingEdge(face, centerLayerPiece, complementingFace, complementingPiece);
		
		if(!(myCube[complementingFace][CENTER_PIECE] == myCube[complementingFace][complementingPiece]))
		{
			++heuristicValue;
		}
	}
    else
	{
		++heuristicValue;
	}
}

int CheckCenterLayerEdges(int whiteFace)
{
	int face, oppositeFace, centerLayerPiece, centerLayerPiece2, heuristicValue = 0;
	switch(whiteFace)
	{
		case TOP_FACE:
		case BOTTOM_FACE:
			face = FRONT_FACE;
			oppositeFace = BACK_FACE;
			centerLayerPiece = 3;
			centerLayerPiece2 = 5;
		break;
		
		case RIGHT_FACE:
		case LEFT_FACE:
			face = TOP_FACE;
			oppositeFace = BOTTOM_FACE;
			centerLayerPiece = 1;
			centerLayerPiece2 = 7;
		break;
		
		case FRONT_FACE:
		case BACK_FACE:
			face = TOP_FACE;
			oppositeFace = BOTTOM_FACE;
			centerLayerPiece = 3;
			centerLayerPiece2 = 5;
		break;
	}
	
	IndividualEdgePieceCheck(face, centerLayerPiece, heuristicValue);
	IndividualEdgePieceCheck(face, centerLayerPiece2, heuristicValue);
	IndividualEdgePieceCheck(oppositeFace, centerLayerPiece, heuristicValue);
	IndividualEdgePieceCheck(oppositeFace, centerLayerPiece2, heuristicValue);
	
	return heuristicValue;
	
}

int HeuristicValueWhiteCross()
{
	int whiteFace, heuristicValue = 8;
	
	whiteFace = FindWhiteFace();
	
	heuristicValue += CheckWhiteEdges(whiteFace);
	
	return heuristicValue;
}


int HeuristicValueWhiteFace()
{
	int whiteFace, heuristicValue = 4;
	
	whiteFace = FindWhiteFace();
	
	heuristicValue += CheckWhiteEdges(whiteFace);
	
	heuristicValue += CheckWhiteCorner(whiteFace);
	
	return heuristicValue;
}

int HeuristicValueCenterLayer()
{
	int whiteFace, heuristicValue = 0;
	
	whiteFace = FindWhiteFace();
	
	heuristicValue += CheckWhiteEdges(whiteFace);
	
	heuristicValue += CheckWhiteCorner(whiteFace);
	
	heuristicValue += CheckCenterLayerEdges(whiteFace);

	return heuristicValue;
}











