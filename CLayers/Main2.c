#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Heuristic.h"

char* FullPath;
unsigned int FullPathHead = 0;
unsigned long long int checks = 1;
int BESTHEURISTIC = 0;

void PathReducer()
{
	checks++; if(checks % 50000000 == 0)printf("%10llu checks ---> head: |%d| length: |%d| heuristic value |%d|\n",checks,FullPathHead,strlen(FullPath),BESTHEURISTIC);
	//printf("Latest element was: %c and head is at: %d and size of array is %d\n", FullPath[FullPathHead-1],FullPathHead, sizeof(FullPath));
	if(FullPath[FullPathHead-2] == 'I')
	{
		FullPath[FullPathHead-1] = '\0';
		FullPath[FullPathHead-2] = '\0';
		FullPathHead--;
		FullPathHead--;
	}
	else
	{
		FullPath[FullPathHead-1] = '\0';
		FullPathHead--;
	}
	
}

/*
	R = Right
	IR = Inverted Right
	L = Left
	IL = Inverted Left
	T = Top
	IT = Inverted Top
	B = Bot
	IB = Inverted Bot
	F = Front
	IF = Inverted Front
	V = Back (v for vaek)
	IV = Inverted Back ( V for vaek)
*/

int  TwelvthLayer(int move, char parentcube[6][10])
{
	switch (move)
	{
	case 1: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		PathReducer();
		return 1;
	}
	break;
	case 2: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I');
	FullPathHead++; 
	FullPath[FullPathHead] = ('R'); 
	FullPathHead++;
	InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		PathReducer();
		return 1;
	}
	break;
	case 3: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		PathReducer();
		return 1;
	}
	break;
	case 4: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I');
	FullPathHead++;
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		PathReducer();
		return 1;
	}
	break;
	case 5: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		PathReducer();
		return 1;
	}
	break;
	case 6: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I');
	FullPathHead++;
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		PathReducer();
		return 1;
	}
	break;
	case 7: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		PathReducer();
		return 1;
	}
	break;
	case 8: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I');
	FullPathHead++;
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		PathReducer();
		return 1;
	}
	break;
	case 9: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		PathReducer();
		return 1;
	}
	break;
	case 10: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I');
	FullPathHead++;
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		PathReducer();
		return 1;
	}
	break;
	case 11: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		PathReducer();
		return 1;
	}
	break;
	case 12: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I');
	FullPathHead++;
	FullPath[FullPathHead] = ('V');
	FullPathHead++;
	InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		PathReducer();
		return 1;
	}
	break;
	}
}

int  EleventhLayer(int move, char parentcube[6][10])
{
	switch (move)
	{
	case 1: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE3, "Im at L 11-1 ');
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 2: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE3, "Im at L 11-2 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 3: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE3, "Im at L 11-3 ');
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 4: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE3, "Im at L 11-4 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 5: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE3, "Im at L 11-5 ');
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 6: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE3, "Im at L 11-6 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 7: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE3, "Im at L 11-7 ');
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 8: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE3, "Im at L 11-8 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 9: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE3, "Im at L 11-9 ');
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 10: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE3, "Im at L 11-10 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 11: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE3, "Im at L 11-11 ');
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 12: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE3, "Im at L 11-12 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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

int TenthLayer(int move, char parentcube[6][10])
{
	switch (move)
	{
	case 1: ORMyCube(parentcube); 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EleventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 2: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE2, "Im at L 10-2 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EleventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 3: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE2, "Im at L 10-3 ');
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EleventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 4: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE2, "Im at L 10-4 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EleventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 5: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE2, "Im at L 10-5 ');
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EleventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 6: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE2, "Im at L 10-6 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EleventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 7: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE2, "Im at L 10-7 ');
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EleventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 8: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE2, "Im at L 10-8 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EleventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 9: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE2, "Im at L 10-9 ');
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EleventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 10: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE2, "Im at L 10-10 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EleventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 11: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE2, "Im at L 10-11 ');
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EleventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 12: ORMyCube(parentcube); 
	//TextOut(0,LCD_LINE2, "Im at L 10-12 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EleventhLayer(i, myCube) == 0)
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

int NinethLayer(int move, char parentcube[6][10])
{
	switch (move)
	{
	case 1: ORMyCube(parentcube); 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TenthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 2: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TenthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 3: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TenthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 4: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TenthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 5: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TenthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 6: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TenthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 7: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TenthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 8: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TenthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 9: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TenthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 10: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TenthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 11: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TenthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 12: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(TenthLayer(i, myCube) == 0)
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

int  EighthLayer(int move, char parentcube[6][10])
{
switch (move)
	{
	case 1: ORMyCube(parentcube); 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(NinethLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 2: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(NinethLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 3: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(NinethLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 4: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(NinethLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 5: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(NinethLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 6: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(NinethLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 7: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(NinethLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 8: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(NinethLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 9: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(NinethLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 10: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(NinethLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 11: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(NinethLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 12: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(NinethLayer(i, myCube) == 0)
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

int SeventhLayer(int move, char parentcube[6][10])
{
	switch (move)
	{
	case 1: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EighthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 2: ORMyCube(parentcube);  
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EighthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 3: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EighthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 4: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EighthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 5: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EighthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 6: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EighthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 7: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EighthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 8: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EighthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 9: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EighthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 10: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EighthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 11: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EighthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 12: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(EighthLayer(i, myCube) == 0)
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

int SixthLayer(int move, char parentcube[6][10])
{
	switch (move)
	{
	case 1: ORMyCube(parentcube); 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SeventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 2: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SeventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 3: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SeventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 4: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SeventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 5: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SeventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 6: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SeventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 7: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SeventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 8: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SeventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 9: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SeventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 10: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SeventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 11: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SeventhLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 12: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SeventhLayer(i, myCube) == 0)
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

int FifthLayer(int move, char parentcube[6][10])
{
	switch (move)
	{
	case 1: ORMyCube(parentcube); 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SixthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 2: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SixthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 3: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SixthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 4: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SixthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 5: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SixthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 6: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SixthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 7: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SixthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 8: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SixthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 9: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SixthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 10: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SixthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 11: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SixthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 12: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SixthLayer(i, myCube) == 0)
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

int FourthLayer(int move, char parentcube[6][10])
{
	switch (move)
	{
	case 1: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		if(checks % 10000000 == 0)
			printf("%d\n",checks);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FifthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 2: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FifthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 3: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FifthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 4: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FifthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 5: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FifthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 6: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FifthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 7: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FifthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 8: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FifthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 9: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FifthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 10: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FifthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 11: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FifthLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 12: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(FifthLayer(i, myCube) == 0)
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

int ThirdLayer(int move, char parentcube[6][10])
{
	switch (move)
	{
	case 1: ORMyCube(parentcube); 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 2: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 3: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 4: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 5: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 6: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 7: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 8: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 9: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 10: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 11: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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
	case 12: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
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

int  SecondLayer(int move, char parentcube[6][10])
{
	switch (move)
	{
	case 1: ORMyCube(parentcube); 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(ThirdLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 2: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(ThirdLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 3: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(ThirdLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 4: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(ThirdLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 5: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(ThirdLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 6: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(ThirdLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 7: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(ThirdLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 8: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(ThirdLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 9: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(ThirdLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 10: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(ThirdLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 11: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(ThirdLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 12: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(ThirdLayer(i, myCube) == 0)
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

int FirstLayer(int move, char parentcube[6][10])
{
	switch (move)
	{
	case 1: ORMyCube(parentcube); 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SecondLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 2: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SecondLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 3: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SecondLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 4: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SecondLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 5: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SecondLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 6: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SecondLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 7: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SecondLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 8: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SecondLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 9: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SecondLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 10: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SecondLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 11: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SecondLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		PathReducer();
		return 1;
	}
	break;
	case 12: ORMyCube(parentcube); 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("%d ",BESTHEURISTIC); printf("%c\n",FullPath[FullPathHead-1]);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			if(SecondLayer(i, myCube) == 0)
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

int  RootNodeMethod(char rootcube[6][10])
{
	for(int i = 1; i<=12;i++)
	{
		if(FourthLayer(i, rootcube) == 0)
		{
			return 0;
		}
	}
	printf("You're boned, no solution");
	return 1;
}
int main()
{
	
	
char top[10] = 		{ 'w', 'r', 'r', 'g', 'g', 'r', 'b', 'g', 'r'}; 
char right[10] = 	{ 'y', 'b', 'y', 'g', 'y', 'o', 'b', 'w', 'y'}; 
char front[10] = 	{ 'w', 'y', 'g', 'g', 'o', 'b', 'o', 'w', 'o'}; 
char back[10] =		{ 'g', 'y', 'r', 'o', 'r', 'o', 'o', 'y', 'w'}; 
char left[10] = 	{ 'g', 'r', 'o', 'y', 'w', 'w', 'w', 'w', 'y'}; 
char bottom[10] = 	{ 'g', 'o', 'b', 'b', 'b', 'r', 'r', 'b', 'b'};

InitializeSide(top, TOP_FACE);
InitializeSide(right, RIGHT_FACE);
InitializeSide(front, FRONT_FACE);
InitializeSide(back, BACK_FACE);
InitializeSide(left, LEFT_FACE);
InitializeSide(bottom, BOTTOM_FACE);

FullPath = realloc(FullPath, 50*sizeof(char));
BESTHEURISTIC = HeuristicValue();

while(BESTHEURISTIC != 0)
{
    RootNodeMethod(myCube);
	FullPath = realloc(FullPath,(FullPathHead+25)*sizeof(char));
}
for(int i = 0; i < FullPathHead;i++)
{
	printf("Path is : ");
	if(FullPath[i] == 'R'
	|| FullPath[i] == 'L'
	|| FullPath[i] == 'T'
	|| FullPath[i] == 'B' 
	|| FullPath[i] == 'F' 
	|| FullPath[i] == 'V' )
		printf("%c ",FullPath[i]);
	if( FullPath[i] == 'I'
	&&( FullPath[i+1] == 'R'
	|| FullPath[i+1] == 'L'
	|| FullPath[i+1] == 'T'
	|| FullPath[i+1] == 'B'
	|| FullPath[i+1] == 'F'
	|| FullPath[i+1] == 'V'))
        printf("%c%c ",FullPath[i], FullPath[i++]);
}	
}