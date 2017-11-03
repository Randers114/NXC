// #include "CubeOperations.h"

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


void AlignCubeLayers()
{
	if (!isLocked){
		LockCube();
	} 

	isLocked = TRUE;
	RotateMotorPID(OUT_B, 30, 60, 20, 40, 100);
    Wait(300);
    RotateMotorPID(OUT_B, 30, -60, 20, 40, 100);
    Wait(300);
}

void FlipCube(int count) /* Tells the robot to flip the cube. */
{
	if (!isLocked){
		LockCube();
	}

    isLocked = TRUE;
    AlignCubeLayers();

    for (int i = 0; i < count; i++)
    {
	    RotateMotorPID(OUT_B, 70, -90, 20, 40, 100);
	    Wait(300);
	    RotateMotorPID(OUT_B, 30, 130, 20, 40, 100);
	    Wait(300);
	    RotateMotorPID(OUT_B, 30, -40, 20, 40, 100);
	    Wait(300);
    }
}

void TurnCube(int degrees) /* Tells the robot to turn the cube. */
{ 
    RotateMotorPID(OUT_C, 15, degrees, 20, 40, 100);
    Wait(300);
}

void RotateCube(int degrees) /* Same as turn, higher power. */
{
	RotateMotorPID(OUT_C, 30, degrees, 20, 40, 100);
	Wait(300);
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
