#include "CubeOperations.h"

#define SIZEOFCUBE 54
char graph[100][6][9];
char FullPath[100];
int graphLast = 0;

void SaveCube()
{
	for(int i = 0;i<6;i++)
		for(int j = 0;j<9;j++)
		{
			graph[graphLast][i][j] = myCube[i][j];
			graphLast++;
		}
}

void CreateChild(int move, char parentcube[6][9])
{
	switch move:
	case 1:
	ORMyCube(parentcube);
	RightOperation();
	SaveCube();
	break;
	case 2:
	ORMyCube(parentcube);
	InvertedRightOperation();
	SaveCube();
	//check heuristic
	//potential save of path and repeat entire algo from this node
	break;
	case 3:
	ORMyCube(parentcube);
	
	SaveCube();
	break;
	case 4:
	ORMyCube(parentcube);
	
	SaveCube();
	break;
	case 5:
	ORMyCube(parentcube);
	
	SaveCube();
	break;
	case 6:
	ORMyCube(parentcube);
	
	SaveCube();
	break;
	case 7:
	ORMyCube(parentcube);
	
	SaveCube();
	break;
	case 8:
	ORMyCube(parentcube);
	
	SaveCube();
	break;
	case 9:
	ORMyCube(parentcube);
	
	SaveCube();
	break;
	case 10:
	ORMyCube(parentcube);
	
	SaveCube();
	break;
	case 11:
	ORMyCube(parentcube);
	
	SaveCube();
	break;
	case 12:
	ORMyCube(parentcube);
	
	SaveCube();
	break;
}


void RootNodeMethod() 
{
	for(int i = 0; i<12;i++)
		CreateChild(i, thiscube);
	for(int j = 0; j<12;j++)
		FirstLayer(j);
}

void FirstLayer(int i)
{
	for(i<12)
	{
		CreateChild(i);
		i++;
	}
	for(int j = 0; j<12;j++)
		SecondLayer(j);	
}

void SecondLayer(int i)
{
	for(i<12)
	{
		CreateChild(i);
		i++;
	}
	for(int j = 0; j<12;j++)
		ThirdLayer(j);
}

void ThirdLayer(int i)
{
	for(i<12)
	{
		CreateChild(i);
		i++;
	}
	
}