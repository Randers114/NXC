char myCube[6][10];
#define TOP_FACE 0
#define RIGHT_FACE 1
#define FRONT_FACE 2
#define BACK_FACE 3
#define LEFT_FACE 4
#define BOTTOM_FACE 5
#define CENTER_PIECE 4
 
void InitializeSide(char face[], int sidenumber)
{
	for (int i = 0; i < 9; i++)
	{
		myCube[sidenumber][i] = face[i];
	}
}

void CubeCheck()
{
	int white = 0, blue = 0, red = 0, green = 0, orange = 0, yellow = 0;
  
  	for (int face = 0; face < 6; face++)
  	{
	
		for (int piece = 0; piece < 9; piece++)
		{
     		if (myCube[face][piece] == 'w')
	  		{
     	    	white++;
	 	    }
     	  	else if (myCube[face][piece] == 'o')
	 	  	{
      	    	orange++;
	  	 	}
      	 	else if (myCube[face][piece] == 'b')
	  	 	{
      	   		blue++;
	  	 	}
	  	 	else if (myCube[face][piece] == 'y')
	  	 	{
      	    	yellow++;
	  	 	}
	  	 	else if (myCube[face][piece] == 'g')
	  	 	{
      	    	green++;
	  	 	}
      	 	else if (myCube[face][piece] == 'r')
	  	 	{
      	    	red++;
	  	 	}
		}
  	}
	

	if (white != 9 || orange != 9 || blue != 9 || yellow != 9 || green != 9 || red != 9)
	{
    	PlaySound(SOUND_UP);
    	StopAllTasks();
  	}
}

void SwapOnFaceOperation(int faceIdentifier, int spaceOne, int spaceTwo) /* swap space one with space two on a given face */
{
	char temp;
	temp = myCube[faceIdentifier][spaceTwo];
	myCube[faceIdentifier][spaceTwo] = myCube[faceIdentifier][spaceOne];
	myCube[faceIdentifier][spaceOne] = temp;
}

void RotateFaceRightOperation(int faceIdentifier) /* rotate a face to the right (like when you rotate right side this is what happens to the colours on the right face) */
{
	SwapOnFaceOperation(faceIdentifier,1,3);
	SwapOnFaceOperation(faceIdentifier,3,7);
	SwapOnFaceOperation(faceIdentifier,7,5);
	SwapOnFaceOperation(faceIdentifier,0,6);
	SwapOnFaceOperation(faceIdentifier,6,8);
	SwapOnFaceOperation(faceIdentifier,8,2);
}

void SwapBetweenFacesOperation(int FaceOne, int SpaceOne, int FaceTwo, int SpaceTwo) /* swap space one on face one with space two on face two */
{
	char temp;
	
	temp = myCube[FaceTwo][SpaceTwo];
	myCube[FaceTwo][SpaceTwo] = myCube[FaceOne][SpaceOne];
	myCube[FaceOne][SpaceOne] = temp;
}

void FaceSwapOperation(int faceOneIdentifier, int faceTwoIdentifier) /* swap the pointer of two faces so they "swap places" */
{
	char temp;

	for(int i = 0; i < 9; i++)
	{
    	temp = myCube[faceTwoIdentifier][i];
    	myCube[faceTwoIdentifier][i] = myCube[faceOneIdentifier][i];
    	myCube[faceOneIdentifier][i] = temp;
  	}
	// memcpy(temp, myCube[faceTwoIdentifier], 9);
	//memcpy(myCube[faceTwoIdentifier], myCube[faceOneIdentifier], 9);
	//memcpy(myCube[faceOneIdentifier], temp, 9);
}

void TurnCubeOperation() /* turn cube without holding it, aka turning the cube entirly */
{
	/* face swap operations */
	/* swap front to left */
	FaceSwapOperation(4,2);

	/*swap left to back */
	SwapBetweenFacesOperation(4,0,3,8);
	SwapBetweenFacesOperation(4,1,3,7);
	SwapBetweenFacesOperation(4,2,3,6);
	SwapBetweenFacesOperation(4,3,3,5);
	SwapBetweenFacesOperation(4,4,3,4);
	SwapBetweenFacesOperation(4,5,3,3);
	SwapBetweenFacesOperation(4,6,3,2);
	SwapBetweenFacesOperation(4,7,3,1);
	SwapBetweenFacesOperation(4,8,3,0);

	/*swap back to left */
	FaceSwapOperation(3,1);

	/* face rotate operations */
	/* top face operations */
	for(int i = 0; i<3 ; i++)
		RotateFaceRightOperation(0);

	/* bot face operations */
	RotateFaceRightOperation(5);
}

void RotateBottomOperation() /*holding the top and rotating the buttom face */
{
	/* swap colors on bot */
	RotateFaceRightOperation(5);

	/* rotate the 4 rows that get rotated */
	/* front 7,8,9 to left 7,8,9 */
	SwapBetweenFacesOperation(2,6,4,6);
	SwapBetweenFacesOperation(2,7,4,7);
	SwapBetweenFacesOperation(2,8,4,8);
	/* swap 7,8,9 left with 3,2,1 back */
	SwapBetweenFacesOperation(4,6,3,2);
	SwapBetweenFacesOperation(4,7,3,1);
	SwapBetweenFacesOperation(4,8,3,0);
	/* swap 3,2,1 back with 3,2,1 right */
	SwapBetweenFacesOperation(3,2,1,2);
	SwapBetweenFacesOperation(3,1,1,1);
	SwapBetweenFacesOperation(3,0,1,0);

}

void ClawPullOperation() /* representation changes when the claw pulls the cube front to top etc. */
{
	FaceSwapOperation(2,5);
	FaceSwapOperation(5,3);
	FaceSwapOperation(3,0);

	/* right face operations */
	RotateFaceRightOperation(1);
	/* left face operations */
	for (int i = 0; i<3; i++)
		RotateFaceRightOperation(4);
}

// FInd complementing edge for heuristic.
void FindComplementingEdge(int face, int piece, int *complementFace, int *complementPiece)
{
	switch(face)
	{
		case TOP_FACE:
			if(piece == 1)
			{
				*complementFace = BACK_FACE;
				*complementPiece = 7;
			}
			else if (piece == 3)
			{
				*complementFace = LEFT_FACE;
				*complementPiece = 1;
			}
			else if (piece == 5)
			{
				*complementFace = RIGHT_FACE;
				*complementPiece = 7;
			}
			else if (piece == 7)
			{
				*complementFace = FRONT_FACE;
				*complementPiece = 1;
			}
		break;

		case RIGHT_FACE: 
			if(piece == 1)
			{
				*complementFace = BOTTOM_FACE;
				*complementPiece = 5;
			}
			else if (piece == 3)
			{
				*complementFace = BACK_FACE;
				*complementPiece = 5;
			}
			else if (piece == 5)
			{
				*complementFace = FRONT_FACE;
				*complementPiece = 5;
			}
			else if (piece == 7)
			{
				*complementFace = TOP_FACE;
				*complementPiece = 5;
			}
		break; 

		case FRONT_FACE: 
			if(piece == 1)
			{
				*complementFace = TOP_FACE;
				*complementPiece = 7;
			}
			else if (piece == 3)
			{
				*complementFace = LEFT_FACE;
				*complementPiece = 5;
			}
			else if (piece == 5)
			{
				*complementFace = RIGHT_FACE;
				*complementPiece = 5;
			}
			else if (piece == 7)
			{
				*complementFace = BOTTOM_FACE;
				*complementPiece = 1;
			}
		break; 

		case BACK_FACE:
			if(piece == 1)
			{
				*complementFace = BOTTOM_FACE;
				*complementPiece = 7;
			}
			else if (piece == 3)
			{
				*complementFace = LEFT_FACE;
				*complementPiece = 3;
			}
			else if (piece == 5)
			{
				*complementFace = RIGHT_FACE;
				*complementPiece = 3;
			}
			else if (piece == 7)
			{
				*complementFace = TOP_FACE;
				*complementPiece = 1;
			}
		break;

		case LEFT_FACE: 
			if(piece == 1)
			{
				*complementFace = TOP_FACE;
				*complementPiece = 3;
			}
			else if (piece == 3)
			{
				*complementFace = BACK_FACE;
				*complementPiece = 3;
			}
			else if (piece == 5)
			{
				*complementFace = RIGHT_FACE;
				*complementPiece = 3;
			}
			else if (piece == 7)
			{
				*complementFace = BOTTOM_FACE;
				*complementPiece = 3;
			}
		break; 

		case BOTTOM_FACE: 
			if(piece == 1)
			{
				*complementFace = FRONT_FACE;
				*complementPiece = 7;
			}
			else if (piece == 3)
			{
				*complementFace = LEFT_FACE;
				*complementPiece = 7;
			}
			else if (piece == 5)
			{
				*complementFace = RIGHT_FACE;
				*complementPiece = 1;
			}
			else if (piece == 7)
			{
				*complementFace = FRONT_FACE;
				*complementPiece = 7;
			}

		break;
	}
}

void FindComplementingCorners(int face, int piece, int *complementFace, int *complementPiece, int *complementFace2, int *complementPiece2)
{
	switch(face)
	{
		case TOP_FACE:
			if(piece == 0)
			{
				*complementFace = LEFT_FACE;
				*complementPiece = 0;
				*complementFace2 = BACK_FACE;
				*complementPiece2 = 6;
			}
			else if (piece == 2)
			{
				*complementFace = BACK_FACE;
				*complementPiece = 8;
				*complementFace2 = RIGHT_FACE;
				*complementPiece2 = 6;
			}
			else if (piece == 6)
			{
				*complementFace = FRONT_FACE;
				*complementPiece = 0;
				*complementFace2 = LEFT_FACE;
				*complementPiece2 = 6;
			}
			else if (piece == 8)
			{
				*complementFace = RIGHT_FACE;
				*complementPiece = 8;
				*complementFace2 = FRONT_FACE;
				*complementPiece2 = 2;
			}
		break;

		case RIGHT_FACE: 
			if(piece == 0)
			{
				*complementFace = BOTTOM_FACE;
				*complementPiece = 8;
				*complementFace2 = BACK_FACE;
				*complementPiece2 = 2;
			}
			else if (piece == 2)
			{
				*complementFace = FRONT_FACE;
				*complementPiece = 8;
				*complementFace2 = BOTTOM_FACE;
				*complementPiece2 = 2;
			}
			else if (piece == 6)
			{
				*complementFace = TOP_FACE;
				*complementPiece = 2;
				*complementFace2 = BACK_FACE;
				*complementPiece2 = 8;
			}
			else if (piece == 8)
			{
				*complementFace = TOP_FACE;
				*complementPiece = 8;
				*complementFace2 = FRONT_FACE;
				*complementPiece2 = 2;
			}
		break; 

		case FRONT_FACE: 
			if(piece == 0)
			{
				*complementFace = TOP_FACE;
				*complementPiece = 6;
				*complementFace2 = LEFT_FACE;
				*complementPiece2 = 6;
			}
			else if (piece == 2)
			{
				*complementFace = TOP_FACE;
				*complementPiece = 8;
				*complementFace2 = RIGHT_FACE;
				*complementPiece2 = 8;
			}
			else if (piece == 6)
			{
				*complementFace = BOTTOM_FACE;
				*complementPiece = 0;
				*complementFace2 = LEFT_FACE;
				*complementPiece2 = 8;
			}
			else if (piece == 8)
			{
				*complementFace = BOTTOM_FACE;
				*complementPiece = 2;
				*complementFace2 = RIGHT_FACE;
				*complementPiece2 = 2;
			}
		break;

		case BACK_FACE:
			if(piece == 0)
			{
				*complementFace = BOTTOM_FACE;
				*complementPiece = 6;
				*complementFace2 = LEFT_FACE;
				*complementPiece2 = 6;
			}
			else if (piece == 2)
			{
				*complementFace = BOTTOM_FACE;
				*complementPiece = 8;
				*complementFace2 = RIGHT_FACE;
				*complementPiece2 = 0;
			}
			else if (piece == 6)
			{
				*complementFace = TOP_FACE;
				*complementPiece = 0;
				*complementFace2 = LEFT_FACE;
				*complementPiece2 = 0;
			}
			else if (piece == 8)
			{
				*complementFace = TOP_FACE;
				*complementPiece = 2;
				*complementFace2 = RIGHT_FACE;
				*complementPiece2 = 6;
			}
		break;

		case LEFT_FACE: 
			if(piece == 0)
			{
				*complementFace = TOP_FACE;
				*complementPiece = 0;
				*complementFace2 = BACK_FACE;
				*complementPiece2 = 6;
			}
			else if (piece == 2)
			{
				*complementFace = TOP_FACE;
				*complementPiece = 6;
				*complementFace2 = FRONT_FACE;
				*complementPiece2 = 0;
			}
			else if (piece == 6)
			{
				*complementFace = BOTTOM_FACE;
				*complementPiece = 6;
				*complementFace2 = BACK_FACE;
				*complementPiece2 = 0;
			}
			else if (piece == 8)
			{
				*complementFace = BOTTOM_FACE;
				*complementPiece = 0;
				*complementFace2 = FRONT_FACE;
				*complementPiece2 = 6;
			}
		break;

		case BOTTOM_FACE: 
			if(piece == 0)
			{
				*complementFace = FRONT_FACE;
				*complementPiece = 6;
				*complementFace2 = LEFT_FACE;
				*complementPiece2 = 8;
			}
			else if (piece == 2)
			{
				*complementFace = FRONT_FACE;
				*complementPiece = 8;
				*complementFace2 = RIGHT_FACE;
				*complementPiece2 = 2;
			}
			else if (piece == 6)
			{
				*complementFace = BACK_FACE;
				*complementPiece = 0;
				*complementFace2 = LEFT_FACE;
				*complementPiece2 = 6;
			}
			else if (piece == 8)
			{
				*complementFace = BACK_FACE;
				*complementPiece = 2;
				*complementFace2 = RIGHT_FACE;
				*complementPiece2 = 0;
			}
		break;
	}
}

/*
Compound functions are moves to be executed by hand like inverted right or top or inverted bottom
but reflect this in the representation since this is multiple moves, or a compound of other functions ;-)
*/

void RightOperation()
{
	TurnCubeOperation();
	ClawPullOperation();
	RotateBottomOperation();
}

void InvertedRightOperation()
{
	TurnCubeOperation();
	ClawPullOperation();
	for(int i = 0; i < 3; i++)
    {
        RotateBottomOperation();
    }
}

void LeftOperation()
{
	for(int i = 0; i < 3; i++)
	{
		TurnCubeOperation();
	}
	ClawPullOperation();
	RotateBottomOperation();
}

void InvertedLeftOperation()
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

void TopOperation()
{
	for(int i = 0; i < 2; i++)
    {
        ClawPullOperation();
    }
	RotateBottomOperation();
}

void InvertedTopOperation()
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

void BottomOperation()
{
	RotateBottomOperation();
}

void InvertedBottomOperation()
{
	for(int i = 0; i < 3; i++)
    {
        RotateBottomOperation();
    }
}

void FrontOperation()
{
	for(int i = 0; i < 3; i++)
    {
        ClawPullOperation();
    }
	RotateBottomOperation();
}

void InvertedFrontOperation()
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

void BackOperation()
{
	ClawPullOperation();
	RotateBottomOperation();
}

void InvertedBackOperation()
{
	ClawPullOperation();
	for(int i = 0; i < 3; i++)
	{
		RotateBottomOperation();
	}
}
