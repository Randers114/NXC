#include "CTwelvthLayer.h"

int EighthLayer(int move, char parentcube[6][10])
{
switch (move)
	{
	case 1:checks++; if(checks % 100000 == 0) printf("%d",checks);
	
	strcat(FullPath,   "R");
	FullPathHead++;
	ORMyCube(parentcube);
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); printf("%d\n",BESTHEURISTIC); 
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TwelvthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 2:checks++; if(checks % 100000 == 0) printf("%d",checks);
	strcat(FullPath,   "IR");
	FullPathHead++;
	ORMyCube(parentcube);
	FullPathHead++;RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); printf("%d\n",BESTHEURISTIC); 
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TwelvthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 3:checks++; if(checks % 100000 == 0) printf("%d",checks);
	strcat(FullPath,   "L");
	FullPathHead++;
	ORMyCube(parentcube);
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); printf("%d\n",BESTHEURISTIC); 
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TwelvthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 4:checks++; if(checks % 100000 == 0) printf("%d",checks);
	strcat(FullPath,   "IL");
	FullPathHead++;
	ORMyCube(parentcube);
	FullPathHead++;LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); printf("%d\n",BESTHEURISTIC); 
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TwelvthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 5:checks++; if(checks % 100000 == 0) printf("%d",checks);
	strcat(FullPath,   "T");
	FullPathHead++;
	ORMyCube(parentcube);
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); printf("%d\n",BESTHEURISTIC); 
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TwelvthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 6:checks++; if(checks % 100000 == 0) printf("%d",checks);
	strcat(FullPath,   "IT");
	FullPathHead++;
	ORMyCube(parentcube);
	FullPathHead++;TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); printf("%d\n",BESTHEURISTIC); 
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TwelvthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 7:checks++; if(checks % 100000 == 0) printf("%d",checks);
	strcat(FullPath,   "B");
	FullPathHead++;
	ORMyCube(parentcube);
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); printf("%d\n",BESTHEURISTIC); 
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TwelvthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 8:checks++; if(checks % 100000 == 0) printf("%d",checks);
	strcat(FullPath,   "IB");
	FullPathHead++;
	ORMyCube(parentcube);
	FullPathHead++;BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); printf("%d\n",BESTHEURISTIC); 
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TwelvthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 9:checks++; if(checks % 100000 == 0) printf("%d",checks);
	strcat(FullPath,   "F");
	FullPathHead++;
	ORMyCube(parentcube);
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); printf("%d\n",BESTHEURISTIC); 
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TwelvthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 10:checks++; if(checks % 100000 == 0) printf("%d",checks);
	strcat(FullPath,   "IF");
	FullPathHead++;
	ORMyCube(parentcube);
	FullPathHead++;FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); printf("%d\n",BESTHEURISTIC); 
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TwelvthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 11:checks++; if(checks % 100000 == 0) printf("%d",checks);
	strcat(FullPath,   "V"); 
	FullPathHead++;
	ORMyCube(parentcube);
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); printf("%d\n",BESTHEURISTIC); 
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TwelvthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 12:checks++; if(checks % 100000 == 0) printf("%d",checks);
	strcat(FullPath,   "IV"); 
	FullPathHead++;
	ORMyCube(parentcube);
	FullPathHead++;InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); printf("%d\n",BESTHEURISTIC); 
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TwelvthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	}
}
