#include <stdio.h>
#include <math.h>
#include <string.h>

struct cube_t
{
 char sides[6][9];
 /* top
	right
	front
	back
	left
	buttom
*/
};

struct cube_t MyCube;
struct cube_t Testcube1;
int whiteFace, whitePiece, complementFace, complementPiece;

void InitializeSide(char a, char b, char c, char d, char e, char f, char g, char h, char i, int sidenumber)
{
	MyCube.sides[sidenumber][0] = a;
	MyCube.sides[sidenumber][1] = b;
	MyCube.sides[sidenumber][2] = c;
	MyCube.sides[sidenumber][3] = d;
	MyCube.sides[sidenumber][4] = e;
	MyCube.sides[sidenumber][5] = f;
	MyCube.sides[sidenumber][6] = g;
	MyCube.sides[sidenumber][7] = h;
	MyCube.sides[sidenumber][8] = i;
}

void InitializeCube()/* init with hardcoded colors */
{
	InitializeSide('g','g','o','r','b','g','w','y','y', 0); /* init top */
	InitializeSide('y','y','b','b','w','w','g','y','r', 1);	/* init right */
	InitializeSide('b','o','b','b','o','o','y','g','o', 2);	/* init front */
	InitializeSide('y','r','g','b','r','y','r','w','w', 3);	/* init back */
	InitializeSide('w','g','r','o','y','r','o','b','o', 4);	/* init left */
	InitializeSide('b','o','w','w','g','r','g','w','r', 5);	/* init buttom */
}

void InitializeCubeTest()
{
	InitializeSide('o','o','y','r','g','r','y','b','g', 0); /* init top */
	InitializeSide('r','w','b','y','o','w','o','b','o', 1);	/* init right */
	InitializeSide('g','y','w','g','w','o','w','w','w', 2);	/* init front */
	InitializeSide('b','g','b','g','y','g','y','b','b', 3);	/* init back */
	InitializeSide('g','y','r','w','r','r','w','o','g', 4);	/* init left */
	InitializeSide('r','r','r','y','b','b','o','o','y', 5);	/* init buttom */
}

void InitializeCubeTest2()
{
	InitializeSide('r','o','o','b','w','w','y','r','g', 0); /* init top */
	InitializeSide('w','w','o','y','g','g','w','b','r', 1);	/* init right */
	InitializeSide('o','g','y','o','o','o','y','o','g', 2);	/* init front */
	InitializeSide('y','g','r','y','r','r','b','w','b', 3);	/* init back */
	InitializeSide('w','r','g','b','b','y','r','g','o', 4);	/* init left */
	InitializeSide('b','b','w','w','y','r','b','y','g', 5);	/* init buttom */	
}

void SwapOnFace(int FaceIdentifier, int SpaceOne, int SpaceTwo) /* swap space one with space two on a given face */
{
	char temp;
	temp = MyCube.sides[FaceIdentifier][SpaceTwo];
	MyCube.sides[FaceIdentifier][SpaceTwo] = MyCube.sides[FaceIdentifier][SpaceOne];
	MyCube.sides[FaceIdentifier][SpaceOne] = temp;
}

void RotateFaceRight(int FaceIdentifier) /* rotate a face to the right (like when you rotate right side this is what happens to the colours on the right face) */
{
	SwapOnFace(FaceIdentifier,1,3);
	SwapOnFace(FaceIdentifier,3,7);
	SwapOnFace(FaceIdentifier,7,5);
	SwapOnFace(FaceIdentifier,0,6);
	SwapOnFace(FaceIdentifier,6,8);
	SwapOnFace(FaceIdentifier,8,2);
}

void SwapBetweenFaces(int FaceOne, int SpaceOne, int FaceTwo, int SpaceTwo) /* swap space one on face one with space two on face two */
{
	char temp;
	temp = MyCube.sides[FaceTwo][SpaceTwo];
	MyCube.sides[FaceTwo][SpaceTwo] = MyCube.sides[FaceOne][SpaceOne];
	MyCube.sides[FaceOne][SpaceOne] = temp;
}

void FaceSwap(int FaceOneIdentifier, int FaceTwoIdentifier) /* swap the pointer of two faces so they "swap places" */
{

	char temp[9];
	memcpy(temp, MyCube.sides[FaceTwoIdentifier], 9);
	memcpy(MyCube.sides[FaceTwoIdentifier], MyCube.sides[FaceOneIdentifier], 9);
	memcpy(MyCube.sides[FaceOneIdentifier], temp, 9);
}

void TurnCubeRight() /* turn cube without holding it, aka turning the cube entirly */
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
	for(int i = 0; i<3;i++)
		RotateFaceRight(0);
	
	/* bot face operations */
	RotateFaceRight(5);
}

void RotateButtomRight() /*holding the top and rotating the buttom face */
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

void ClawPull() /* representation changes when the claw pulls the cube front to top etc. */
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
	for(int i = 0; i<3;i++)
		{
			RotateButtomRight();
		}
}

void CompoundLeft()
{
	for(int i = 0; i<3;i++)
		{
			TurnCubeRight();
		}
	ClawPull();
	RotateButtomRight();
}

void CompoundInvertedLeft()
{
	for(int i = 0; i<3;i++)
		{
			TurnCubeRight();
		}
	ClawPull();
	for(int i = 0; i<3;i++)
		{
			RotateButtomRight();
		}
}

void CompoundTop ()
{
	for(int i = 0; i<2;i++)
		{
			ClawPull();
		}
	RotateButtomRight();
}

void CompoundInvertedTop()
{
	for(int i = 0; i<2;i++)
		{
			ClawPull();
		}
	for(int i = 0; i<3;i++)
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
	for(int i = 0; i<3;i++)
		{
			RotateButtomRight();
		}
}

void CompoundFront()
{
	for(int i = 0; i<3;i++)
		{
			ClawPull();
		}
	RotateButtomRight();
}

void CompoundInvertedFront()
{
	for(int i = 0; i<3;i++)
		{
			ClawPull();
		}
	for(int i = 0; i<3;i++)
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

void FillTestCube()
{
	for(int j = 0; j < 6; j++)
	{
		memcpy(Testcube1.sides[j], MyCube.sides[j], 9);
	}
}

void resetcube()
{
	for(int i = 0; i<6;i++)
	{
		memcpy(MyCube.sides[i], Testcube1.sides[i], 9);
	}
}




//____________________________________________________________

void DoubleClaw()
{
	ClawPull();
	ClawPull();
}

void TripleClaw()
{
	ClawPull();
	ClawPull();
	ClawPull();
}

void DoubleRotate()
{
	RotateButtomRight();
	RotateButtomRight();
}

void TripleRotate()
{
	RotateButtomRight();
	RotateButtomRight();
	RotateButtomRight();
}

void DoubleTurn()
{
	TurnCubeRight();
	TurnCubeRight();
}

void TripleTurn()
{
	TurnCubeRight();
	TurnCubeRight();
	TurnCubeRight();
}

void TurnToColour(char colourFront, char colourTop)
{
	/* Turn to the requested colour, given by the two characters of colourFront and colourTop. */
	int topFacePosition = 0;
	for (int i = 0; i < 6; i++)
	{
		if (MyCube.sides[i][4] == colourTop)
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
			TurnCubeRight();
			ClawPull();
			ClawPull();
			ClawPull();
			break;

		case 2: /* front */
			ClawPull();
			break;

		case 3: /* back */
			ClawPull();
			ClawPull();
			ClawPull();
			break;

		case 4: /* left */
			TurnCubeRight();
			ClawPull();
			break;

		case 5: /* bottom */
			ClawPull();
			ClawPull();
			break;
	}

	int frontFacePosition = 0;
	for (int j = 1; j < 5; j++)
	{
		if (MyCube.sides[j][4] == colourFront)
		{
			frontFacePosition = j;
			break;
		}
	}

	switch(frontFacePosition) /* Places the wanted front face correctly, now that we know that the top is correct. TurnCubeRight turns the cube counter-clockwise*/
	{
		case 1: /* right */
			TurnCubeRight();
			TurnCubeRight();
			TurnCubeRight();
			break;

		case 2: /* front */
			break;

		case 3: /* back */
			TurnCubeRight();
			TurnCubeRight();
			break;

		case 4: /* left */
			TurnCubeRight();
			break;

	}

}

void PrintCube()
{
	int i, j;
	for (j = 0; j < 6; j++)
	{
		for (i = 0; i < 9; i++)
		{
			printf("%c", MyCube.sides[j][i]);	
		}
		printf("\n");
	}
	printf("\n");
	
}

void FindComplementingEdge()
{
	switch(whiteFace) /* 0 = Top, 1 = Right, 2 = Front, 3 = Back, 4 = Left, 5 = Buttom. */
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
			if (MyCube.sides[face][piece] == 'x')
			{
				complementFace = face;
				complementPiece = piece;

			}
		}
	}     
}

void WhiteCrossMoveset()
{
	switch(complementFace)
	{
		/* TurnCubeRight();  ClawPull(); RotateButtomRight();*/
		/* Top face */
		case 0:							
			if(complementPiece == 1)
			{
				ClawPull();
				RotateButtomRight();
				TripleTurn();
				ClawPull();
				TripleRotate();
				TripleTurn();
				ClawPull();
				RotateButtomRight();
				TurnCubeRight();
				ClawPull();
				DoubleRotate();
				TurnCubeRight();
				ClawPull();
				RotateButtomRight();
				TurnCubeRight();
				ClawPull();
			}
			else if(complementPiece == 3)
			{
				TripleTurn();
				ClawPull();
				RotateButtomRight();
				TurnCubeRight();
				ClawPull();
				RotateButtomRight();
				TurnCubeRight();
				DoubleClaw();
				RotateButtomRight();
				TripleClaw();

			}
			else if(complementPiece == 5)
			{
				TurnCubeRight();
				ClawPull();
				TripleRotate();
				TurnCubeRight();
				ClawPull();
				TripleRotate();
				TurnCubeRight();
				ClawPull();
			}
			else if(complementPiece == 7)
			{
				DoubleClaw();
				TripleRotate();
				TurnCubeRight();
				ClawPull();
				TripleRotate();
				TripleClaw();
				RotateButtomRight();
				TripleTurn();
				ClawPull();
				TripleRotate();
				ClawPull();
			}
		break;

		/* Right face */
		case 1:							
			if(complementPiece == 1)
			{
				TripleRotate();
				TripleClaw();
				DoubleRotate();
				ClawPull();
			}
			else if(complementPiece == 3)
			{
				TurnCubeRight();
				ClawPull();
				RotateButtomRight();
				TripleClaw();
				TripleRotate();
				ClawPull();
				TripleRotate();
				TurnCubeRight();
				ClawPull();
				DoubleRotate();
				TripleTurn();
				ClawPull();
			}
			else if(complementPiece == 5)
			{
				TurnCubeRight();
				ClawPull();
				TripleRotate();
				TripleClaw();
				TripleRotate();
				ClawPull();
				RotateButtomRight();
				TurnCubeRight();
				ClawPull();
				DoubleRotate();
				TurnCubeRight();
				ClawPull();
			}
			else if(complementPiece == 7)
			{
				TurnCubeRight();
				ClawPull();
				DoubleRotate();
				ClawPull();
				TripleRotate();
				TurnCubeRight();
				ClawPull();
				DoubleRotate();
				TripleClaw();
			}

		break;

		/* front face */
		case 2:							
			if(complementPiece == 3)
			{
				TripleClaw();
				RotateButtomRight();
				ClawPull();
			}
			else if(complementPiece == 5)
			{
				TripleClaw();
				TripleRotate();
				ClawPull();
			}
			else if(complementPiece == 7)
			{
				TripleClaw();
				DoubleTurn();
				ClawPull();
			}

		break;

		/* back face */
		case 3:
			if(complementPiece == 1)
			{
				DoubleRotate();
				TripleClaw();
				DoubleRotate();
				ClawPull();
			}
			else if(complementPiece == 3)
			{
				ClawPull();
				RotateButtomRight();
				TripleClaw();
				DoubleRotate();
				ClawPull();
				TripleRotate();
				DoubleClaw();
				DoubleRotate();
				ClawPull();			
			}
			else if(complementPiece == 5)
			{
				ClawPull();
				TripleRotate();
				TripleClaw();
				DoubleRotate();
				ClawPull();
				RotateButtomRight();
				DoubleClaw();
				DoubleRotate();
				ClawPull();	
			}
			else if(complementPiece == 7)
			{
				ClawPull();
				DoubleRotate();
				TripleClaw();
				DoubleRotate();
				TripleClaw();
				DoubleRotate();
				ClawPull();				
			}

		break;

		/* Left face */
		case 4:
			if(complementPiece == 1)
			{
				TripleTurn();
				ClawPull();
				DoubleRotate();
				TripleClaw();
				RotateButtomRight();
				TripleTurn();
				ClawPull();
				DoubleRotate();
				TripleClaw();
			}
			else if(complementPiece == 3)
			{
				TripleTurn();
				ClawPull();
				TripleRotate();
				TripleClaw();
				RotateButtomRight();
				ClawPull();
				RotateButtomRight();
				TripleTurn();
				ClawPull();
				DoubleRotate();
				TripleTurn();
				ClawPull();
			}
			else if(complementPiece == 5)
			{
				TripleTurn();
				ClawPull();
				RotateButtomRight();
				DoubleTurn();
				ClawPull();
				RotateButtomRight();
				DoubleTurn();
				ClawPull();
				TripleRotate();
				TripleTurn();
				ClawPull();
				DoubleRotate();
				TripleTurn();
				ClawPull();
			}
			else if(complementPiece == 7)
			{
				RotateButtomRight();
				TripleClaw();
				DoubleRotate();
				ClawPull();	
			}

		break;

		/* Bottom face */
		case 5:
			if(complementPiece == 1)
			{
				RotateButtomRight();
				TripleTurn();
				ClawPull();
				TripleRotate();
				TurnCubeRight();
				ClawPull();
				RotateButtomRight();
				DoubleTurn();
				ClawPull();
				RotateButtomRight();
				TurnCubeRight();
				ClawPull();	
			}
			else if(complementPiece == 3)
			{
				TripleTurn();
				ClawPull();
				TripleRotate();
				TripleTurn();
				ClawPull();
				RotateButtomRight();
				DoubleTurn();
				ClawPull();
				RotateButtomRight();
				TurnCubeRight();
				ClawPull();				
			}
			else if(complementPiece == 5)
			{
				TurnCubeRight();
				ClawPull();
				RotateButtomRight();
				TurnCubeRight();
				ClawPull();
				TripleRotate();
				DoubleTurn();
				ClawPull();
				TripleRotate();
				TripleTurn();
				ClawPull();
			}
			else if(complementPiece == 7)
			{
				RotateButtomRight();
				TripleTurn();
				ClawPull();	
				TripleRotate();
				TripleTurn();
				ClawPull();	
				RotateButtomRight();
				DoubleTurn();
				ClawPull();	
				RotateButtomRight();
				TurnCubeRight();
			}

		break;
	}
}

int DoWhiteCrossPiece() /* If this returns 0, then the piece was already placed correctly. If it returns 1 then moves were made. */
{
	FindComplementingEdge();

	if ((MyCube.sides[whiteFace][whitePiece] == MyCube.sides[whiteFace][4]) && (MyCube.sides[complementFace][complementPiece] == MyCube.sides[complementFace][4]))
	{
		printf("Piece %i, %i is already placed correctly.\n", whiteFace, whitePiece);
		printf("Complementing piece is %i, %i. \n\n", complementFace, complementPiece);

		return 0;
	}

	else
	{
		char complementingColour = MyCube.sides[complementFace][complementPiece];

		PrintCube();
		MyCube.sides[complementFace][complementPiece] = 'x';
		TurnToColour(complementingColour, 'w'); /* Orients the cube so that complementingColour is front and the top face is white. */

		printf("Cube is now oriented correctly, with colour %c as front.\n", complementingColour);
		PrintCube();
		FindXPosition();
		// printf("Piece %i, %i is being placed correctly.\n", whiteFace, whitePiece);
		printf("Complementing piece is %i, %i, with colour %c. \n\n", complementFace, complementPiece, complementingColour);


		WhiteCrossMoveset();
		/* GØR DE MOVES SOM VI SKAL GØRE, NU NÅR RUBIKS ER PLACERET KORREKT */
		FindXPosition();
		MyCube.sides[complementFace][complementPiece] = complementingColour;
		PrintCube();
		printf("______________________________________________________\n");

		return 1;

	}
}




void DeterministicWhiteCross()
{
	for (int face = 0; face < 6; face++)
	{
		printf("face = %d\n",face);	
		for (int piece = 1; piece < 8; piece += 2)
		{
			if (MyCube.sides[face][piece] == 'w')
			{
				whiteFace = face;
				whitePiece = piece;

				int evaluateCorrect = DoWhiteCrossPiece(); /* If DoWhiteCrossPiece() returns 0, then continue. If DoWhiteCrossPiece() returns 1, then call DeterministicWhiteCross. */
				
				if (evaluateCorrect == 1)
				{
					DeterministicWhiteCross();
					break;
				}
			}
		}
	}     
}



void TestMethods()
{
	RotateButtomRight();
	if(	strncmp(MyCube.sides[5],"oyrobrybr",9) == 0 /* COORECT */
		&& strncmp(MyCube.sides[1], "wwwyowobo",9) == 0 /* CORRECT */
		&& strncmp(MyCube.sides[2], "gywgwowog",9) == 0 /*CORRECT */
		&& strncmp(MyCube.sides[3], "rwbgygybb",9) == 0) /* CORRECT*/
		{
			printf("Test 1 succes!\n");
		}
		
	else
	{
		printf("Test 1 failed!\n");
			for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[5][i]);
		printf("\n");
				for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[1][i]);
		printf("\n");
				for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[2][i]);
		printf("\n");
		for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[3][i]);
		printf("\n");
	}
		
	resetcube();
	
	ClawPull();
	if(	strncmp(MyCube.sides[0],"gywgwowww",9) == 0 /* CORRECT */
		&& strncmp(MyCube.sides[1], "oyrbowowb",9) == 0 /* CORRECT */
		&& strncmp(MyCube.sides[2], "rrrybbooy",9) == 0 /* CORRECT */
		&& strncmp(MyCube.sides[3], "ooyrgrybg",9) == 0 /* CORRECT */
		&& strncmp(MyCube.sides[4], "rrgyrogww",9) == 0 /* CORRECT */
		&& strncmp(MyCube.sides[5], "bgbgygybb",9) == 0) /* CORRECT */
		{
			printf("Test 2 succes!\n");
		}
	else
	{
		printf("Test 2 failed!\n");
				printf("Test 1 failed!\n");
			for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[0][i]);
		printf("\n");
				for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[1][i]);
		printf("\n");
				for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[2][i]);
		printf("\n");
		for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[3][i]);
		printf("\n");
				for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[4][i]);
		printf("\n");
				for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[5][i]);
		printf("\n");
	}
		
	resetcube();
	
	TurnCubeRight();
	if(	strncmp(MyCube.sides[0],"yrgogbory",9) == 0 /* COORECT */
		&& strncmp(MyCube.sides[1], "wwwowgwyg",9) == 0 /* COORECT */
		&& strncmp(MyCube.sides[2], "gyrwrrwog",9) == 0 /* CORRECT */
		&& strncmp(MyCube.sides[3], "rwbyowobo",9) == 0 /* CORRECT */
		&& strncmp(MyCube.sides[4], "bbygygbgb",9) == 0 /* CORRECT */
		&& strncmp(MyCube.sides[5], "oyrobrybr",9) == 0) /* COORECT */
		printf("Test 3 succes!\n");
	else
	{
		printf("Test 3 failed!\n");
			for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[0][i]);
		printf("\n");
				for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[1][i]);
		printf("\n");
				for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[2][i]);
		printf("\n");
		for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[3][i]);
		printf("\n");
				for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[4][i]);
		printf("\n");
				for (int i = 0; i < 9; i++)
			printf("%c", MyCube.sides[5][i]);
		printf("\n");
	}
	
	resetcube();
}

int main(void)/* main program starts here */
{
	InitializeCubeTest();
	//FillTestCube();
	DeterministicWhiteCross();
	//TestMethods();
	
	return 0;	
	
}