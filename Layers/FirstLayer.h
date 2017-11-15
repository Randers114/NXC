#include "/Layers/SecondLayer.h"

int FirstLayer(int move, char parentcube[][])
{
	switch (move)
	{
	case 1:
	strcat(FullPath, "R");
	FullPathHead++;
	ORMyCube(parentcube);
	RightOperation();
	if(HeuristicValue()<BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	for(int i = 0; i<12;i++)
		if(SecondLayer(i, parentcube) == 0)
			return 0;
	FullPath[FullPathHead] = "\0";
	FullPathHead--;
	break;
	case 2:
	ORMyCube(parentcube);
	strcat(FullPath, "IR");
	FullPathHead++;
	ORMyCube(parentcube);
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();
		// reset from this node
	}
	FullPath[FullPathHead-1] = "\0";
	FullPath[FullPathHead] = "\0";
	FullPathHead--;
	FullPathHead--;
	//SaveCube();
	break;
	case 3:
	ORMyCube(parentcube);
	
	//SaveCube();
	break;
	case 4:
	ORMyCube(parentcube);
	
	//SaveCube();
	break;
	case 5:
	ORMyCube(parentcube);
	
	//SaveCube();
	break;
	case 6:
	ORMyCube(parentcube);
	
	//SaveCube();
	break;
	case 7:
	ORMyCube(parentcube);
	
	//SaveCube();
	break;
	case 8:
	ORMyCube(parentcube);
	
	//SaveCube();
	break;
	case 9:
	ORMyCube(parentcube);
	
	//SaveCube();
	break;
	case 10:
	ORMyCube(parentcube);
	
	//SaveCube();
	break;
	case 11:
	ORMyCube(parentcube);
	
	//SaveCube();
	break;
	case 12:
	ORMyCube(parentcube);
	
	//SaveCube();
	break;
	}
}