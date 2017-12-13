#include "RobotMoves.h"

char myCube[6][10];
#define TOP_FACE 0
#define RIGHT_FACE 1
#define FRONT_FACE 2
#define BACK_FACE 3
#define LEFT_FACE 4
#define BOTTOM_FACE 5
#define CENTER_PIECE 4

#define EMPTY_SPACE 15

#define RIGHT 1
#define INVERTEDRIGHT 2
#define LEFT 3
#define INVERTEDLEFT 4
#define TOP 5
#define INVERTEDTOP 6
#define BOTTOM 7
#define INVERTEDBOTTOM 8
#define FRONT 9
#define INVERTEDFRONT 10
#define BACK 11
#define INVERTEDBACK 12
#define TurnOp 13
#define Claw 14
 
void InitializeSide(char face[], int sidenumber) 										// char[10] -- 2 int
{
	for (int piece = 0; piece < 9; piece++)
	{
		myCube[sidenumber][piece] = face[piece];
	}
}

void SwapOnFaceOperation(int faceIdentifier, int spaceOne, int spaceTwo)				// 3 int -- 1 char
{
	char temp;
	temp = myCube[faceIdentifier][spaceTwo];
	myCube[faceIdentifier][spaceTwo] = myCube[faceIdentifier][spaceOne];
	myCube[faceIdentifier][spaceOne] = temp;
}

void RotateFaceRightOperation(int faceIdentifier) 										// 1 int 
{
	SwapOnFaceOperation(faceIdentifier, 1, 3);
	SwapOnFaceOperation(faceIdentifier, 3, 7);
	SwapOnFaceOperation(faceIdentifier, 7, 5);
	SwapOnFaceOperation(faceIdentifier, 0, 6);
	SwapOnFaceOperation(faceIdentifier, 6, 8);
	SwapOnFaceOperation(faceIdentifier, 8, 2);
}

void SwapBetweenFacesOperation(int FaceOne, int SpaceOne, int FaceTwo, int SpaceTwo) 	// 4 int -- 1 char 
{
	char temp;
	temp = myCube[FaceTwo][SpaceTwo];
	myCube[FaceTwo][SpaceTwo] = myCube[FaceOne][SpaceOne];
	myCube[FaceOne][SpaceOne] = temp;
}

void FaceSwapOperation(int faceOneIdentifier, int faceTwoIdentifier) 					// 3 int -- 1 char 
{
	char temp;

	for(int piece = 0; piece < 9; piece++)
	{
		temp = myCube[faceTwoIdentifier][piece];
		myCube[faceTwoIdentifier][piece] = myCube[faceOneIdentifier][piece];
		myCube[faceOneIdentifier][piece] = temp;
	}
}

void TurnCubeOperation() 																// 6 int -- 1 char
{
	/* face swap operations */
	/* swap front to left */
	FaceSwapOperation(LEFT_FACE, FRONT_FACE);

	/*swap left to back */
	for(int leftFaceSquare = 0, backFaceSquare = 8; leftFaceSquare < 9; leftFaceSquare++, backFaceSquare--)
	{
		SwapBetweenFacesOperation(LEFT_FACE, leftFaceSquare, BACK_FACE, backFaceSquare);
	}

	/*swap back to left */
	FaceSwapOperation(BACK_FACE, RIGHT_FACE);

	/* face rotate operations */
	/* top face operations */
	for(int i = 0; i < 3 ; i++)
		RotateFaceRightOperation(TOP_FACE);

	/* bot face operations */
	RotateFaceRightOperation(BOTTOM_FACE);
}

void RotateBottomOperation() 															// 6 int -- 1 char
{
	/* swap colors on bot */
	RotateFaceRightOperation(BOTTOM_FACE);

	/* rotate the 4 rows that get rotated */
	/* front 7,8,9 to left 7,8,9 */
	for(int faceSquare = 6; faceSquare < 9; faceSquare++)
	{
		SwapBetweenFacesOperation(FRONT_FACE, faceSquare, LEFT_FACE, faceSquare);
	}
	
	/* swap 7,8,9 left with 3,2,1 back */
	for(int leftFaceSquare = 6, backFaceSquare = 2; leftFaceSquare < 9; leftFaceSquare++, backFaceSquare--)
	{
		SwapBetweenFacesOperation(LEFT_FACE, leftFaceSquare, BACK_FACE, backFaceSquare);
	}

	/* swap 3,2,1 back with 3,2,1 right */
	for(int faceSquare = 2; faceSquare >= 0; faceSquare--)
	{
		SwapBetweenFacesOperation(BACK_FACE, faceSquare, RIGHT_FACE, faceSquare);
	}
}

void ClawPullOperation() 																// 3 int -- 1 char
{
	FaceSwapOperation(FRONT_FACE, BOTTOM_FACE);
	FaceSwapOperation(BOTTOM_FACE, BACK_FACE);
	FaceSwapOperation(BACK_FACE, TOP_FACE);

	/* right face operations */
	RotateFaceRightOperation(RIGHT_FACE);
	/* left face operations */
	for (int i = 0; i < 3; i++)
		RotateFaceRightOperation(LEFT_FACE);
}

// FInd complementing edge for heuristic.
void FindComplementingEdge(int face, int piece, int &complementFace, int &complementPiece) // 2 int 
{
	switch(face)
	{
		case TOP_FACE:
			if(piece == 1)
			{
				complementFace = BACK_FACE;
				complementPiece = 7;
			}
			else if (piece == 3)
			{
				complementFace = LEFT_FACE;
				complementPiece = 1;
			}
			else if (piece == 5)
			{
				complementFace = RIGHT_FACE;
				complementPiece = 7;
			}
			else if (piece == 7)
			{
				complementFace = FRONT_FACE;
				complementPiece = 1;
			}
		break;

		case RIGHT_FACE: 
			if(piece == 1)
			{
				complementFace = BOTTOM_FACE;
				complementPiece = 5;
			}
			else if (piece == 3)
			{
				complementFace = BACK_FACE;
				complementPiece = 5;
			}
			else if (piece == 5)
			{
				complementFace = FRONT_FACE;
				complementPiece = 5;
			}
			else if (piece == 7)
			{
				complementFace = TOP_FACE;
				complementPiece = 5;
			}
		break; 

		case FRONT_FACE: 
			if(piece == 1)
			{
				complementFace = TOP_FACE;
				complementPiece = 7;
			}
			else if (piece == 3)
			{
				complementFace = LEFT_FACE;
				complementPiece = 5;
			}
			else if (piece == 5)
			{
				complementFace = RIGHT_FACE;
				complementPiece = 5;
			}
			else if (piece == 7)
			{
				complementFace = BOTTOM_FACE;
				complementPiece = 1;
			}
		break; 

		case BACK_FACE:
			if(piece == 1)
			{
				complementFace = BOTTOM_FACE;
				complementPiece = 7;
			}
			else if (piece == 3)
			{
				complementFace = LEFT_FACE;
				complementPiece = 3;
			}
			else if (piece == 5)
			{
				complementFace = RIGHT_FACE;
				complementPiece = 3;
			}
			else if (piece == 7)
			{
				complementFace = TOP_FACE;
				complementPiece = 1;
			}
		break;

		case LEFT_FACE: 
			if(piece == 1)
			{
				complementFace = TOP_FACE;
				complementPiece = 3;
			}
			else if (piece == 3)
			{
				complementFace = BACK_FACE;
				complementPiece = 3;
			}
			else if (piece == 5)
			{
				complementFace = RIGHT_FACE;
				complementPiece = 3;
			}
			else if (piece == 7)
			{
				complementFace = BOTTOM_FACE;
				complementPiece = 3;
			}
		break; 

		case BOTTOM_FACE: 
			if(piece == 1)
			{
				complementFace = FRONT_FACE;
				complementPiece = 7;
			}
			else if (piece == 3)
			{
				complementFace = LEFT_FACE;
				complementPiece = 7;
			}
			else if (piece == 5)
			{
				complementFace = RIGHT_FACE;
				complementPiece = 1;
			}
			else if (piece == 7)
			{
				complementFace = BACK_FACE;
				complementPiece = 1;
			}

		break;
	}
}

void FindComplementingCorners(int face, int piece, int &complementFace, int &complementPiece, int &complementFace2, int &complementPiece2) // 2 int
{
	switch(face)
	{
		case TOP_FACE:
			if(piece == 0)
			{
				complementFace = LEFT_FACE;
				complementPiece = 0;
				complementFace2 = BACK_FACE;
				complementPiece2 = 6;
			}
			else if (piece == 2)
			{
				complementFace = BACK_FACE;
				complementPiece = 8;
				complementFace2 = RIGHT_FACE;
				complementPiece2 = 6;
			}
			else if (piece == 6)
			{
				complementFace = FRONT_FACE;
				complementPiece = 0;
				complementFace2 = LEFT_FACE;
				complementPiece2 = 2;
			}
			else if (piece == 8)
			{
				complementFace = RIGHT_FACE;
				complementPiece = 8;
				complementFace2 = FRONT_FACE;
				complementPiece2 = 2;
			}
		break;

		case RIGHT_FACE: 
			if(piece == 0)
			{
				complementFace = BOTTOM_FACE;
				complementPiece = 8;
				complementFace2 = BACK_FACE;
				complementPiece2 = 2;
			}
			else if (piece == 2)
			{
				complementFace = FRONT_FACE;
				complementPiece = 8;
				complementFace2 = BOTTOM_FACE;
				complementPiece2 = 2;
			}
			else if (piece == 6)
			{
				complementFace = TOP_FACE;
				complementPiece = 2;
				complementFace2 = BACK_FACE;
				complementPiece2 = 8;
			}
			else if (piece == 8)
			{
				complementFace = TOP_FACE;
				complementPiece = 8;
				complementFace2 = FRONT_FACE;
				complementPiece2 = 2;
			}
		break; 

		case FRONT_FACE: 
			if(piece == 0)
			{
				complementFace = TOP_FACE;
				complementPiece = 6;
				complementFace2 = LEFT_FACE;
				complementPiece2 = 2;
			}
			else if (piece == 2)
			{
				complementFace = TOP_FACE;
				complementPiece = 8;
				complementFace2 = RIGHT_FACE;
				complementPiece2 = 8;
			}
			else if (piece == 6)
			{
				complementFace = BOTTOM_FACE;
				complementPiece = 0;
				complementFace2 = LEFT_FACE;
				complementPiece2 = 8;
			}
			else if (piece == 8)
			{
				complementFace = BOTTOM_FACE;
				complementPiece = 2;
				complementFace2 = RIGHT_FACE;
				complementPiece2 = 2;
			}
		break;

		case BACK_FACE:
			if(piece == 0)
			{
				complementFace = BOTTOM_FACE;
				complementPiece = 6;
				complementFace2 = LEFT_FACE;
				complementPiece2 = 6;
			}
			else if (piece == 2)
			{
				complementFace = BOTTOM_FACE;
				complementPiece = 8;
				complementFace2 = RIGHT_FACE;
				complementPiece2 = 0;
			}
			else if (piece == 6)
			{
				complementFace = TOP_FACE;
				complementPiece = 0;
				complementFace2 = LEFT_FACE;
				complementPiece2 = 0;
			}
			else if (piece == 8)
			{
				complementFace = TOP_FACE;
				complementPiece = 2;
				complementFace2 = RIGHT_FACE;
				complementPiece2 = 6;
			}
		break;

		case LEFT_FACE: 
			if(piece == 0)
			{
				complementFace = TOP_FACE;
				complementPiece = 0;
				complementFace2 = BACK_FACE;
				complementPiece2 = 6;
			}
			else if (piece == 2)
			{
				complementFace = TOP_FACE;
				complementPiece = 6;
				complementFace2 = FRONT_FACE;
				complementPiece2 = 0;
			}
			else if (piece == 6)
			{
				complementFace = BOTTOM_FACE;
				complementPiece = 6;
				complementFace2 = BACK_FACE;
				complementPiece2 = 0;
			}
			else if (piece == 8)
			{
				complementFace = BOTTOM_FACE;
				complementPiece = 0;
				complementFace2 = FRONT_FACE;
				complementPiece2 = 6;
			}
		break;

		case BOTTOM_FACE: 
			if(piece == 0)
			{
				complementFace = FRONT_FACE;
				complementPiece = 6;
				complementFace2 = LEFT_FACE;
				complementPiece2 = 8;
			}
			else if (piece == 2)
			{
				complementFace = FRONT_FACE;
				complementPiece = 8;
				complementFace2 = RIGHT_FACE;
				complementPiece2 = 2;
			}
			else if (piece == 6)
			{
				complementFace = BACK_FACE;
				complementPiece = 0;
				complementFace2 = LEFT_FACE;
				complementPiece2 = 6;
			}
			else if (piece == 8)
			{
				complementFace = BACK_FACE;
				complementPiece = 2;
				complementFace2 = RIGHT_FACE;
				complementPiece2 = 0;
			}
		break;
	}
}

void RightOperation() 																		// 6 int -- 1 char
{
	TurnCubeOperation();
	ClawPullOperation();
	RotateBottomOperation();
}

void InvertedRightOperation()																// 7 int -- 1 char
{
	TurnCubeOperation();
	ClawPullOperation();
	for(int i = 0; i < 3; i++)
    {
        RotateBottomOperation();
    }
}

void LeftOperation()																		// 7 int -- 1 char
{
	for(int i = 0; i < 3; i++)
	{
		TurnCubeOperation();
	}
	ClawPullOperation();
	RotateBottomOperation();
}

void InvertedLeftOperation()																// 7 int -- 1 char
{
	for(int i = 0; i < 3; i++)
    {
        TurnCubeOperation();
    }
	ClawPullOperation();
	for(int i = 0; i < 3; i++)
    {
        RotateBottomOperation();
    }
}

void TopOperation()																			// 6 int -- 1 char
{
	for(int i = 0; i < 2; i++)
    {
        ClawPullOperation();
    }
	RotateBottomOperation();
}

void InvertedTopOperation()																	// 7 int -- 1 char
{
	for(int i = 0; i < 2; i++)
    {
        ClawPullOperation();
    }
	for(int i = 0; i < 3; i++)
    {
        RotateBottomOperation();
    }
}

void BottomOperation()																		// 6 int -- 1 char
{
	RotateBottomOperation();
}

void InvertedBottomOperation()																// 7 int -- 1 char 
{
	for(int i = 0; i < 3; i++)
    {
        RotateBottomOperation();
    }
}

void FrontOperation()																		// 6 int -- 1 char 
{
	for(int i = 0; i < 3; i++)
    {
        ClawPullOperation();
    }
	RotateBottomOperation();
}

void InvertedFrontOperation()																// 7 int -- 1 char 
{
	for(int i = 0; i < 3; i++)
    {
        ClawPullOperation();
    }
	for(int i = 0; i < 3; i++)
    {
        RotateBottomOperation();
    }
}

void BackOperation()																		// 6 int -- 1 char 
{
	ClawPullOperation();
	RotateBottomOperation();
}

void InvertedBackOperation()																// 7 int -- 1 char
{
	ClawPullOperation();
	for(int i = 0; i < 3; i++)
	{
		RotateBottomOperation();
	}

}

bool CmpArray(int a[], int b[])													// 1 int + 2 int[] hvad end størrelse der er sendt med, det er pass by value
{
	int length = 0;
	for(int i = 0; i < ArrayLen(a); i++)
	{
		if(a[i] != EMPTY_SPACE)
		{
			length++;
		}
	}
	
	if(length == ArrayLen(b))
	{
		for(int i = 0; i < length; i++)
		{
			if(a[i] != b[i])
			{
				return FALSE;
			}
		}
	} else 
	{
		return FALSE;
	}
	
	return TRUE;
}

int PlaceYellowOnTop(int &path[]) 																	// 7 int -- 2 char
{
	char colourTop = 'y';

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
			
			ArrayBuild(path, 13, 14, 14, 14);
			break;

		case 2: /* front */
			ClawPullOperation();
			
			ArrayBuild(path, 14);
			break;

		case 3: /* back */
			ClawPullOperation();
			ClawPullOperation();
			ClawPullOperation();
		
			ArrayBuild(path, 14, 14, 14);
			break;

		case 4: /* left */
			TurnCubeOperation();
			ClawPullOperation();
			
			ArrayBuild(path, 13, 14);
			break;

		case 5: /* bottom */
			ClawPullOperation();
			ClawPullOperation();
			
			ArrayBuild(path, 14, 14);
			break;
	}
}

void ChangeRepresentationFromMoveSet(int moveSet[])										// 1 int + int[] hvad end størrelse der er sendt med, det er pass by value
{
	for(int i = 0; i < ArrayLen(moveSet); i++)
	{
		switch(moveSet[i])
		{
			case RIGHT:
				RightOperation();
				break;
			case INVERTEDRIGHT:
				InvertedRightOperation();
				break;
			case LEFT:
				LeftOperation();
				break;
			case INVERTEDLEFT:
				InvertedLeftOperation();
				break;
			case TOP:
				TopOperation();
				break;
			case INVERTEDTOP:
				InvertedTopOperation();
				break;
			case BOTTOM:
				BottomOperation();
				break;
			case INVERTEDBOTTOM:
				InvertedBottomOperation();
				break;
			case FRONT:
				FrontOperation();
				break;
			case INVERTEDFRONT:
				InvertedFrontOperation();
				break;
			case BACK:
				BackOperation();
				break;
			case INVERTEDBACK:
				InvertedBackOperation();
				break;
			case TurnOp:
				TurnCubeOperation();
			case Claw:
				ClawPullOperation();
			default:
				break;
		}
	}
}


void ExecuteRobotMovesFromPath(int moveSet[])										// 1 int + int[] hvad end størrelse der er sendt med, det er pass by value
{
	for(int i = 0; i < ArrayLen(moveSet); i++)
	{
		switch(moveSet[i])
		{
			case RIGHT:
				RotateRightFace();
				break;
			case INVERTEDRIGHT:
				InvertedRightFaceRotate();
				break;
			case LEFT:
				RotateLeftFace();
				break;
			case INVERTEDLEFT:
				InvertedLeftFaceRotate();
				break;
			case TOP:
				RotateTopFace();
				break;
			case INVERTEDTOP:
				InvertedTopFaceRotate();
				break;
			case BOTTOM:
				RotateBottomFace();
				break;
			case INVERTEDBOTTOM:
				InvertedBottomFaceRotate();
				break;
			case FRONT:
				RotateFrontFace();
				break;
			case INVERTEDFRONT:
				InvertedFrontFaceRotate();
				break;
			case BACK:
				RotateBackFace();
				break;
			case INVERTEDBACK:
				InvertedBackFaceRotate();
				break;
			case TurnOp:
				TurnCubeRight();
				break;
			case Claw:
				FlipCube();
				break;
			default:
				break;
		}
	}
}







