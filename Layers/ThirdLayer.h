#include "/Layers/FourthLayer.h"

int ThirdLayer(int move, char parentcube[][])
{
	switch (move)
	{
	case 1:     TextOut(0,LCD_LINE2, "Im at L 3 ");
	FullPath[FullPathHead] =  "R";
	FullPathHead++;
	ORMyCube(parentcube);
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); NumOut(0,LCD_LINE6, BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FourthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 2:
	FullPath[FullPathHead] =  "IR";
	FullPathHead++;
	ORMyCube(parentcube);
	InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); NumOut(0,LCD_LINE6, BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FourthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 3:
	FullPath[FullPathHead] =  "L";
	FullPathHead++;
	ORMyCube(parentcube);
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); NumOut(0,LCD_LINE6, BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FourthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 4:
	FullPath[FullPathHead] =  "IL";
	FullPathHead++;
	ORMyCube(parentcube);
	InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); NumOut(0,LCD_LINE6, BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FourthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 5:
	FullPath[FullPathHead] =  "T";
	FullPathHead++;
	ORMyCube(parentcube);
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); NumOut(0,LCD_LINE6, BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FourthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 6:
	FullPath[FullPathHead] =  "IT";
	FullPathHead++;
	ORMyCube(parentcube);
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); NumOut(0,LCD_LINE6, BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FourthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 7:
	FullPath[FullPathHead] =  "B";
	FullPathHead++;
	ORMyCube(parentcube);
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); NumOut(0,LCD_LINE6, BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FourthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 8:
	FullPath[FullPathHead] =  "IB";
	FullPathHead++;
	ORMyCube(parentcube);
	InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); NumOut(0,LCD_LINE6, BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FourthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 9:
	FullPath[FullPathHead] =  "F";
	FullPathHead++;
	ORMyCube(parentcube);
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); NumOut(0,LCD_LINE6, BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FourthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 10:
	FullPath[FullPathHead] =  "IF";
	FullPathHead++;
	ORMyCube(parentcube);
	InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); NumOut(0,LCD_LINE6, BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FourthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 11:
	FullPath[FullPathHead] =  "V"; 
	FullPathHead++;
	ORMyCube(parentcube);
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); NumOut(0,LCD_LINE6, BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FourthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 12:
	FullPath[FullPathHead] =  "IV"; 
	FullPathHead++;
	ORMyCube(parentcube);
	InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue(); NumOut(0,LCD_LINE6, BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FourthLayer(i, myCube) == 0)
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
