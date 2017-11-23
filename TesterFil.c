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
	InitializeSide('w','b','y','y','b','r','b','g','o', 0); /* init top */
	InitializeSide('y','b','b','b','r','r','b','g','g', 1);	/* init right */
	InitializeSide('w','w','b','r','w','y','w','w','w', 2);	/* init front */
	InitializeSide('y','g','r','b','y','y','g','w','r', 3);	/* init back */
	InitializeSide('r','o','o','o','o','g','o','o','o', 4);	/* init left */
	InitializeSide('g','r','r','w','g','o','g','y','y', 5);	/* init buttom */
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

void main()/* main program starts here */
{
	InitializeCubeTest();
	FillTestCube();
	TestMethods();
	
	
}