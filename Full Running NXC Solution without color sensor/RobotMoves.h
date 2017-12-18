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
	RotateMotorPID(OUT_B, 50, 60, 20, 40, 100);
    Wait(MS_300);
    RotateMotorPID(OUT_B, 50, -60, 20, 40, 100);
    Wait(MS_300);
}

void FlipCube(int count = 1) /* Tells the robot to flip the cube. */
{
	if (!isLocked){
		LockCube();
	}

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

void TurnCube(int degrees, int power = 15) /* Tells the robot to turn the cube. */
{ 
	// power was 15
    RotateMotorPID(OUT_C, power, degrees, 20, 40, 100);
    Wait(MS_300);
}

void RotateCube(int degrees, int power = 30) /* Same as turn, higher power. */
{
	// power was 30
	RotateMotorPID(OUT_C, power, degrees, 20, 40, 100);
	Wait(MS_300);
}

void TurnCubeRight(int count = 1) /* turn cube without holding it, aka turning the cube entirely */
{
	for(int i = 0; i < count; i ++)
	{
		if (isLocked)
		{
			UnlockCube();
		}

		TurnCube(-90, 40);
	}
	
}

void RotateBottomRight(int count = 1) /*holding the top and rotating the Bottom face */
{
	for(int i = 0; i < count; i ++)
	{
		if (!isLocked)
		{
			LockCube();
		}

		RotateCube(-90, 70);
	}
	
	AlignCubeLayers();
}

// Rotates top face
void RotateTopFace()
{
	FlipCube(2);
	RotateBottomRight();
}

// Rotates right face
void RotateRightFace()
{
	TurnCubeRight();
	FlipCube();
	RotateBottomRight();
}

// Rotates front face
void RotateFrontFace()
{
	FlipCube(3);
	RotateBottomRight();
}

// Rotates back face
void RotateBackFace()
{
	FlipCube();
	RotateBottomRight();
}

// Rotates left face
void RotateLeftFace()
{
	TurnCubeRight(3);
	FlipCube();
	RotateBottomRight();
}

void RotateBottomFace()
{
	RotateBottomRight();
}

void InvertedBottomFaceRotate()
{
	RotateBottomRight(3);
}

// Rotates top face opposite direction
void InvertedTopFaceRotate()
{
	FlipCube(2);
	RotateBottomRight(3);
}

// Rotates right face opposite direction
void InvertedRightFaceRotate()
{
	TurnCubeRight();
	FlipCube();
	RotateBottomRight(3);
}

// Rotates front face opposite direction
void InvertedFrontFaceRotate()
{
	FlipCube(3);
	RotateBottomRight(3);
}

// Rotates back face opposite direction
void InvertedBackFaceRotate()
{
	FlipCube();
	RotateBottomRight(3);
}

// Rotates left face opposite direction
void InvertedLeftFaceRotate()
{
	TurnCubeRight(3);
	FlipCube();
	RotateBottomRight(3);
}
