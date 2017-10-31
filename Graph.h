#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cube.h"

#define SIZEOFCUBE 54

char graph[1][6][9];

void addNode(char cube[6][9])
{
	realloc(graph,sizeof(graph) + SIZEOFCUBE);
	
}

void CreateGraph()
{
	memcpy(graph[0],myCube,54);
	
}

void DoMove(int i)
{
	switch (i)
	{
	case 1:
	CompoundRight();
	break;
	case 2:
	CompoundInvertedRight();
	break;
	case 3:
	CompoundLeft();
	break;
	case 4:
	CompoundInvertedLeft();
	break;
	case 5:
	CompoundTop();
	break;
	case 6:
	CompoundInvertedTop();
	break;
	case 7:
	CompoundFront();
	break;
	case 8:
	CompoundInvertedFront();
	break;
	case 9:
	CompoundBack();
	break;
	case 10:
	CompoundInvertedBack();
	break;
	case 11:
	CompoundBottom();
	break;
	case 12:
	CompoundInvertedBottom();
	break;
	}
	
}