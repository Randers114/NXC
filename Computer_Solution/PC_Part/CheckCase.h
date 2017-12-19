#include "Heuristic.h"

void IncrementColors(int face, int piece, int *red, int *green, int *orange, int *blue);
void CheckPieces(int face, int centerLayerPiece, int *red, int *green, int *orange, int *blue);
char FindCaseFrontColour();


int CheckForCase(int heuristicValue)
{
	int red = 0, green = 0, orange = 0, blue = 0;
	int whiteFace;
	int face, oppositeFace, centerLayerPiece, centerLayerPiece2, caseBool = 0;
	
	whiteFace = FindWhiteFace();
	
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
	
	CheckPieces(face, centerLayerPiece, &red, &green, &orange, &blue);
	CheckPieces(face, centerLayerPiece2, &red, &green, &orange, &blue);
	CheckPieces(oppositeFace, centerLayerPiece, &red, &green, &orange, &blue);
	CheckPieces(oppositeFace, centerLayerPiece2, &red, &green, &orange, &blue);
	
	if((red + green + orange + blue) == 8 && heuristicValue > 0 && heuristicValue <= 4 && HeuristicValueWhiteFace() == 4)
	{
		caseBool = 1;
	}
	
	return caseBool;
}


void CheckPieces(int face, int centerLayerPiece, int *red, int *green, int *orange, int *blue)
{
	int complementingFace, complementingPiece;
	
	FindComplementingEdge(face, centerLayerPiece, &complementingFace, &complementingPiece);
	
	IncrementColors(face, centerLayerPiece, red, green, orange, blue);
	IncrementColors(complementingFace, complementingPiece, red, green, orange, blue);
}

void IncrementColors(int face, int piece, int *red, int *green, int *orange, int *blue)
{
	switch(myCube[face][piece])
	{
		case 'r':
			++*red;
			break;
		case 'g':
			++*green;
			break;
		case 'o':
			++*orange;
			break;
		case 'b':
			++*blue;
			break;
	}
}

void FixCase(int path[], int *currentArrayPosition)
{
	char colourTop = 'y';
	char colourFront;
	
	/* Turn to the requested colour, given by the two characters of colourFront and colourTop. */
	int topFacePosition = 0;

	for (int i = 0; i < 6; i++)
	{
		if (myCube[i][4] == colourTop)
		{
			topFacePosition = i;
			break;
		}
	}

	switch(topFacePosition) /* Places the requested colourTop on the top layer. */
	{
		case 0: /* top */
			break;

		case 1: /* right */
			TurnCubeOperation();
			ClawPullOperation();
			ClawPullOperation();
			ClawPullOperation();
			
			path[*currentArrayPosition] = 13;
			++*currentArrayPosition;
			path[*currentArrayPosition] = 14;
			++*currentArrayPosition;
			path[*currentArrayPosition] = 14;
			++*currentArrayPosition;
			path[*currentArrayPosition] = 14;
			++*currentArrayPosition;
			break;

		case 2: /* front */
			ClawPullOperation();
			
			path[*currentArrayPosition] = 14;
			++*currentArrayPosition;
			break;

		case 3: /* back */
			ClawPullOperation();
			ClawPullOperation();
			ClawPullOperation();
		
			path[*currentArrayPosition] = 14;
			++*currentArrayPosition;
			path[*currentArrayPosition] = 14;
			++*currentArrayPosition;
			path[*currentArrayPosition] = 14;
			++*currentArrayPosition;
			break;

		case 4: /* left */
			TurnCubeOperation();
			ClawPullOperation();
			
			path[*currentArrayPosition] = 13;
			++*currentArrayPosition;
			path[*currentArrayPosition] = 14;
			++*currentArrayPosition;
			break;

		case 5: /* bottom */
			ClawPullOperation();
			ClawPullOperation();
			
			path[*currentArrayPosition] = 14;
			++*currentArrayPosition;
			path[*currentArrayPosition] = 14;
			++*currentArrayPosition;
			break;
	}

	int frontFacePosition = 0;
	
	colourFront = FindCaseFrontColour();
	
	for (int j = 1; j < 5; j++)
	{
		if (myCube[j][4] == colourFront)
		{
			frontFacePosition = j;
			break;
		}
	}

	switch(frontFacePosition) /* Places the wanted front face correctly, now that we know that the top is correct. TurnCubeRight turns the cube counter-clockwise*/
	{
		case 1: /* right */
			TurnCubeOperation();
			TurnCubeOperation();
			TurnCubeOperation();
			
			path[*currentArrayPosition] = 13;
			++*currentArrayPosition;
			path[*currentArrayPosition] = 13;
			++*currentArrayPosition;
			path[*currentArrayPosition] = 13;
			++*currentArrayPosition;
			break;

		case 2: /* front */
			break;

		case 3: /* back */
			TurnCubeOperation();
			TurnCubeOperation();
			
			path[*currentArrayPosition] = 13;
			++*currentArrayPosition;
			path[*currentArrayPosition] = 13;
			++*currentArrayPosition;
			break;

		case 4: /* left */
			TurnCubeOperation();
			
			path[*currentArrayPosition] = 13;
			++*currentArrayPosition;
			break;

	}
	
	RightOperation();
	InvertedBackOperation();
	InvertedFrontOperation();
	InvertedBackOperation();
	InvertedRightOperation();
	FrontOperation();
	BackOperation();
	
	path[*currentArrayPosition] = 1;
	++*currentArrayPosition;
	path[*currentArrayPosition] = 12;
	++*currentArrayPosition;
	path[*currentArrayPosition] = 10;
	++*currentArrayPosition;
	path[*currentArrayPosition] = 12;
	++*currentArrayPosition;
	path[*currentArrayPosition] = 2;
	++*currentArrayPosition;
	path[*currentArrayPosition] = 9;
	++*currentArrayPosition;
	path[*currentArrayPosition] = 11;
	++*currentArrayPosition;
}

char FindCaseFrontColour()
{
	for(int i = 1; i < 5; i++)
	{
		if(myCube[i][5] != myCube[i][CENTER_PIECE])
		{
			switch(i)
			{
				case 1:
				case 2: 
					return myCube[FRONT_FACE][CENTER_PIECE];
					break;
				case 3:
					return myCube[RIGHT_FACE][CENTER_PIECE];
					break;
				case 4:
					return myCube[LEFT_FACE][CENTER_PIECE];
					break;
			}
			
		} else if(myCube[i][3] != myCube[i][CENTER_PIECE])
		{
			switch(i)
			{
				case 1:
					return myCube[RIGHT_FACE][CENTER_PIECE];
					break;
				case 2: 
					return myCube[LEFT_FACE][CENTER_PIECE];
					break;
				case 3:
				case 4:
					return myCube[BACK_FACE][CENTER_PIECE];
					break;
			}
		}
	}
}