#include "CubeOperations.h"

int whiteFace, whitePiece, complementFace, complementPiece;
bool isLocked = FALSE;

void LockCube()
{
    isLocked = TRUE;
    RotateMotorPID(OUT_B, 50, -140, 20, 40, 100);
    Wait(300);
}

void UnlockCube()
{
    isLocked = FALSE;
    OnFwd(OUT_B, 50);
    Wait(1000);
    Off(OUT_B);
    Wait(300);
}

void PlaceCube() {
    RotateMotorPID(OUT_B, 30, -140, 20, 40, 100);
    Wait(300);
    RotateMotorPID(OUT_B, 30, 140, 20, 40, 100);
}

void FlipCube() /* Tells the robot to flip the cube. */
{
    isLocked = TRUE;
    RotateMotorPID(OUT_B, 30, 60, 20, 40, 100);
    Wait(300);
    RotateMotorPID(OUT_B, 30, -60, 20, 40, 100);
    Wait(300);
    RotateMotorPID(OUT_B, 70, -90, 20, 40, 100);
    Wait(300);
    RotateMotorPID(OUT_B, 30, 130, 20, 40, 100);
    Wait(300);
    RotateMotorPID(OUT_B, 30, -40, 20, 40, 100);
    Wait(700);
}

void TurnCube(int x) /* Tells the robot to turn the cube. */
{ 
    RotateMotorPID(OUT_C, 15, x, 20, 40, 100);
    Wait(700);
}

void RotateCube(int x) /* Same as turn, higher power. */
{
    RotateMotorPID(OUT_C, 30, x, 20, 40, 100);
    Wait(700);
}

void SwapOnFace(int faceIdentifier, int spaceOne, int spaceTwo) /* swap space one with space two on a given face */
{
	char temp;
	temp = myCube[faceIdentifier][spaceTwo];
	myCube[faceIdentifier][spaceTwo] = myCube[faceIdentifier][spaceOne];
	myCube[faceIdentifier][spaceOne] = temp;
}

void RotateFaceRight(int faceIdentifier) /* rotate a face to the right (like when you rotate right side this is what happens to the colours on the right face) */
{
	SwapOnFace(faceIdentifier,1,3);
	SwapOnFace(faceIdentifier,3,7);
	SwapOnFace(faceIdentifier,7,5);
	SwapOnFace(faceIdentifier,0,6);
	SwapOnFace(faceIdentifier,6,8);
	SwapOnFace(faceIdentifier,8,2);
}

void SwapBetweenFaces(int FaceOne, int SpaceOne, int FaceTwo, int SpaceTwo) /* swap space one on face one with space two on face two */
{
	char temp;
	temp = myCube[FaceTwo][SpaceTwo];
	myCube[FaceTwo][SpaceTwo] = myCube[FaceOne][SpaceOne];
	myCube[FaceOne][SpaceOne] = temp;
}

void FaceSwap(int faceOneIdentifier, int faceTwoIdentifier) /* swap the pointer of two faces so they "swap places" */
{
	char temp;
	
	for(int i = 0; i < 9; i++)
	{
	    temp = myCube[faceTwoIdentifier][i];
    	myCube[faceTwoIdentifier][i] = myCube[faceOneIdentifier][i];
    	myCube[faceOneIdentifier][i] = temp;
 	}

}

void TurnCubeRight() /* turn cube without holding it, aka turning the cube entirely */
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
  {
		RotateFaceRight(0);
  }
	/* bot face operations */
	RotateFaceRight(5);


	if (isLocked)
	{
		UnlockCube();
	}

	TurnCube(-90);

}

void RotateBottomRight() /*holding the top and rotating the Bottom face */
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


	if (!isLocked)
	{
		LockCube();
	}

	RotateCube(-90);
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

	if (!isLocked)
	{
		LockCube();
	}

	FlipCube();
}

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
	RotateBottomRight();
	RotateBottomRight();
}

void TripleRotate()
{
	RotateBottomRight();
	RotateBottomRight();
	RotateBottomRight();
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