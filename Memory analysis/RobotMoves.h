// #include "CubeOperations.h"

bool isLocked = FALSE;

void LockCube()
{
    isLocked = TRUE;
    RotateMotorPID(OUT_B, 50, -140, 20, 40, 100);
    Wait(MS_300);
}

void UnlockCube()
{
    isLocked = FALSE;
    OnFwd(OUT_B, 50);
    Wait(SEC_1);
    Off(OUT_B);
    Wait(MS_300);
}


void AlignCubeLayers()
{
	if (!isLocked){
		LockCube();
	} 

	isLocked = TRUE;
	RotateMotorPID(OUT_B, 50, 60, 20, 40, 100);
    Wait(MS_300);
    RotateMotorPID(OUT_B, 50, -60, 20, 40, 100);
    Wait(MS_300);
}

void FlipCube(int count) /* Tells the robot to flip the cube. */
{
	if (!isLocked){
		LockCube();
	} else 
	{
		AlignCubeLayers();
	}

    isLocked = TRUE;

    for (int i = 0; i < count; i++)
    {
	    RotateMotorPID(OUT_B, 80, -90, 20, 40, 100);
	    Wait(MS_300);
	    RotateMotorPID(OUT_B, 60, 130, 20, 40, 100);
	    Wait(MS_300);
	    RotateMotorPID(OUT_B, 60, -40, 20, 40, 100);
	    Wait(MS_300);
    }
}

void TurnCube(int degrees) /* Tells the robot to turn the cube. */
{ 
    RotateMotorPID(OUT_C, 15, degrees, 20, 40, 100);
    Wait(MS_300);
}

void RotateCube(int degrees) /* Same as turn, higher power. */
{
	RotateMotorPID(OUT_C, 30, degrees, 20, 40, 100);
	Wait(MS_300);
}

void TurnCubeRight() /* turn cube without holding it, aka turning the cube entirely */
{
	if (isLocked)
	{
		UnlockCube();
	}

	TurnCube(-90);
}

void RotateBottomRight() /*holding the top and rotating the Bottom face */
{
	if (!isLocked)
	{
		LockCube();
	}

	RotateCube(-90);
}

void ClawPull() /* representation changes when the claw pulls the cube front to top etc. */
{
	if (!isLocked)
	{
		LockCube();
	}

	FlipCube(1);
}

void DoubleClaw()
{
	FlipCube(2);
}

void TripleClaw()
{
	FlipCube(3);
}

void DoubleRotate()
{
	for(int i = 0; i < 2; i++)
	{
		RotateBottomRight();
	}
}

void TripleRotate()
{
	for(int i = 0; i < 3; i++)
	{
		RotateBottomRight();
	}
}

void DoubleTurn()
{
	for(int i = 0; i < 2; i++)
	{
		TurnCubeRight();
	}
}

void TripleTurn()
{
	for(int i = 0; i < 3; i++)
	{
		TurnCubeRight();
	}
}

// Rotates top face
void RotateTopFace()
{
	DoubleClaw();
	RotateBottomRight();
}

// Rotates right face
void RotateRightFace()
{
	TurnCubeRight();
	ClawPull();
	RotateBottomRight();
}

// Rotates front face
void RotateFrontFace()
{
	TripleClaw();
	RotateBottomRight();
}

// Rotates back face
void RotateBackFace()
{
	ClawPull();
	RotateBottomRight();
}

// Rotates left face
void RotateLeftFace()
{
	TripleTurn();
	ClawPull();
	RotateBottomRight();
}

void RotateBottomFace()
{
	RotateBottomRight();
}

void InvertedBottomFaceRotate()
{
	TripleRotate();
}

// Rotates top face opposite direction
void InvertedTopFaceRotate()
{
	DoubleClaw();
	TripleRotate();
}

// Rotates right face opposite direction
void InvertedRightFaceRotate()
{
	TurnCubeRight();
	ClawPull();
	TripleRotate();
}

// Rotates front face opposite direction
void InvertedFrontFaceRotate()
{
	TripleClaw();
	TripleRotate();
}

// Rotates back face opposite direction
void InvertedBackFaceRotate()
{
	ClawPull();
	TripleRotate();
}

// Rotates left face opposite direction
void InvertedLeftFaceRotate()
{
	TripleTurn();
	ClawPull();
	TripleRotate();
}
