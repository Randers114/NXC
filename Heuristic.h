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
	
	for(int i = 1; i < 8; i = i + 2)
	{
		if(myCube[whiteFace][i] == 'w')
		{
			FindComplementingEdge(whiteFace, i, complementingFace, complementingPiece);
			
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
	
	for(int i = 0; i < 9; i = i + 2)
	{
		if(myCube[whiteFace][i] == 'w')
		{
			FindComplementingCorners(whiteFace, i, complementingFace, complementingPiece, complementingFace2, complementingPiece2);
			
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
			i = i + 2;
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
			heuristicValue++;
		}
	}
    else
	{
		heuristicValue++;
	}
	
	//NumOut(0, LCD_LINE2, heuristicValue);
	//Wait(SEC_3);
	//ClearScreen();
	//Wait(SEC_3);
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


int HeuristicValue()
{
	int whiteFace, heuristicValue = 0;
	
	whiteFace = FindWhiteFace();
	
	heuristicValue += CheckWhiteEdges(whiteFace);
	NumOut(0, LCD_LINE2, heuristicValue);
	Wait(SEC_3);
	
	heuristicValue += CheckWhiteCorner(whiteFace);
	NumOut(0, LCD_LINE3, heuristicValue);
	Wait(SEC_3);
	
	heuristicValue += CheckCenterLayerEdges(whiteFace);
	NumOut(0, LCD_LINE4, heuristicValue);
	Wait(SEC_3);
	
	return heuristicValue;
}










