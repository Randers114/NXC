char myCube[6][10];
char testCube[6][10];


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
	SwapOnFace(faceIdentifier,1,3);
	SwapOnFace(faceIdentifier,3,7);
	SwapOnFace(faceIdentifier,7,5);
	SwapOnFace(faceIdentifier,0,6);
	SwapOnFace(faceIdentifier,6,8);
	SwapOnFace(faceIdentifier,8,2);
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

void TurnCubeRightOperation() /* turn cube without holding it, aka turning the cube entirly */
{
	/* face swap operations */
	/* swap front to left */
	FaceSwap(4,2);

	/*swap left to back */
	SwapBetweenFaces(4,0,3,8);
	SwapBetweenFaces(4,1,3,7);
	SwapBetweenFaces(4,2,3,6);
	SwapBetweenFaces(4,3,3,5);
	SwapBetweenFaces(4,4,3,4);
	SwapBetweenFaces(4,5,3,3);
	SwapBetweenFaces(4,6,3,2);
	SwapBetweenFaces(4,7,3,1);
	SwapBetweenFaces(4,8,3,0);

	/*swap back to left */
	FaceSwap(3,1);

	/* face rotate operations */
	/* top face operations */
	for(int i = 0; i<3 ; i++)
		RotateFaceRight(0);

	/* bot face operations */
	RotateFaceRight(5);
}

void RotateBottomRightOperation() /*holding the top and rotating the buttom face */
{
	/* swap colors on bot */
	RotateFaceRight(5);

	/* rotate the 4 rows that get rotated */
	/* front 7,8,9 to left 7,8,9 */
	SwapBetweenFaces(2,6,4,6);
	SwapBetweenFaces(2,7,4,7);
	SwapBetweenFaces(2,8,4,8);
	/* swap 7,8,9 left with 3,2,1 back */
	SwapBetweenFaces(4,6,3,2);
	SwapBetweenFaces(4,7,3,1);
	SwapBetweenFaces(4,8,3,0);
	/* swap 3,2,1 back with 3,2,1 right */
	SwapBetweenFaces(3,2,1,2);
	SwapBetweenFaces(3,1,1,1);
	SwapBetweenFaces(3,0,1,0);

}

void ClawPullOperation() /* representation changes when the claw pulls the cube front to top etc. */
{
	FaceSwap(2,5);
	FaceSwap(5,3);
	FaceSwap(3,0);

	/* right face operations */
	RotateFaceRight(1);
	/* left face operations */
	for (int i = 0; i<3; i++)
		RotateFaceRight(4);
}

// FInd complementing edge for heuristic.
void FindComplementingEdge()
{
	switch(whiteFace) /* 0 = Top, 1 = Right, 2 = Front, 3 = Back, 4 = Left, 5 = Bottom. */
	{
		case 0:
			if(whitePiece == 1)
			{
				complementFace = 3;
				complementPiece = 7;
			}
			else if (whitePiece == 3)
			{
				complementFace = 4;
				complementPiece = 1;
			}
			else if (whitePiece == 5)
			{
				complementFace = 1;
				complementPiece = 7;
			}
			else if (whitePiece == 7)
			{
				complementFace = 2;
				complementPiece = 1;
			}
		break;

		case 1: 
			if(whitePiece == 1)
			{
				complementFace = 5;
				complementPiece = 5;
			}
			else if (whitePiece == 3)
			{
				complementFace = 3;
				complementPiece = 5;
			}
			else if (whitePiece == 5)
			{
				complementFace = 2;
				complementPiece = 5;
			}
			else if (whitePiece == 7)
			{
				complementFace = 0;
				complementPiece = 5;
			}
		break; 

		case 2: 
			if(whitePiece == 1)
			{
				complementFace = 0;
				complementPiece = 7;
			}
			else if (whitePiece == 3)
			{
				complementFace = 4;
				complementPiece = 5;
			}
			else if (whitePiece == 5)
			{
				complementFace = 1;
				complementPiece = 5;
			}
			else if (whitePiece == 7)
			{
				complementFace = 5;
				complementPiece = 1;
			}
		break; 

		case 3:
			if(whitePiece == 1)
			{
				complementFace = 5;
				complementPiece = 7;
			}
			else if (whitePiece == 3)
			{
				complementFace = 4;
				complementPiece = 3;
			}
			else if (whitePiece == 5)
			{
				complementFace = 1;
				complementPiece = 3;
			}
			else if (whitePiece == 7)
			{
				complementFace = 0;
				complementPiece = 1;
			}
		break;

		case 4: 
			if(whitePiece == 1)
			{
				complementFace = 0;
				complementPiece = 3;
			}
			else if (whitePiece == 3)
			{
				complementFace = 3;
				complementPiece = 3;
			}
			else if (whitePiece == 5)
			{
				complementFace = 1;
				complementPiece = 3;
			}
			else if (whitePiece == 7)
			{
				complementFace = 5;
				complementPiece = 3;
			}
		break; 

		case 5: 
			if(whitePiece == 1)
			{
				complementFace = 2;
				complementPiece = 7;
			}
			else if (whitePiece == 3)
			{
				complementFace = 4;
				complementPiece = 7;
			}
			else if (whitePiece == 5)
			{
				complementFace = 1;
				complementPiece = 1;
			}
			else if (whitePiece == 7)
			{
				complementFace = 2;
				complementPiece = 7;
			}

		break;
	}
}

void FindXPosition()
{
	for (int face = 0; face < 6; face++)
	{
		for (int piece = 1; piece < 8; piece += 2)
		{
			if (myCube[face][piece] == 'x')
			{
				complementFace = face;
				complementPiece = piece;
			}
		}
	}     
}

/*
Compound functions are moves to be executed by hand like inverted right or top or inverted bottom
but reflect this in the representation since this is multiple moves, or a compound of other functions ;-)
*/

void CompoundRight()
{
	TurnCubeRight();
	ClawPull();
	RotateButtomRight();
}

void CompoundInvertedRight()
{
	TurnCubeRight();
	ClawPull();
	for(int i = 0; i < 3; i++)
		{
			RotateButtomRight();
		}
}

void CompoundLeft()
{
	for(int i = 0; i < 3; i++)
		{
			TurnCubeRight();
		}
	ClawPull();
	RotateButtomRight();
}

void CompoundInvertedLeft()
{
	for(int i = 0; i < 3; i++)
		{
			TurnCubeRight();
		}
	ClawPull();
	for(int i = 0; i < 3; i++)
		{
			RotateButtomRight();
		}
}

void CompoundTop ()
{
	for(int i = 0; i < 2; i++)
		{
			ClawPull();
		}
	RotateButtomRight();
}

void CompoundInvertedTop()
{
	for(int i = 0; i < 2; i++)
		{
			ClawPull();
		}
	for(int i = 0; i < 3; i++)
		{
			RotateButtomRight();
		}
}

void CompoundBottom()
{
	RotateButtomRight();
}

void CompoundInvertedBottom()
{
	for(int i = 0; i < 3; i++)
		{
			RotateButtomRight();
		}
}

void CompoundFront()
{
	for(int i = 0; i < 3; i++)
		{
			ClawPull();
		}
	RotateButtomRight();
}

void CompoundInvertedFront()
{
	for(int i = 0; i < 3; i++)
		{
			ClawPull();
		}
	for(int i = 0; i < 3; i++)
		{
			RotateButtomRight();
		}
}

void CompoundBack()
{
	ClawPull();
	RotateButtomRight();
}

void CompoundInvertedBack()
{
	ClawPull();
	for(int i = 0; i < 3; i++)
	{
		RotateButtomRight();
	}
}
