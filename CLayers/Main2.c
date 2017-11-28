#include "Heuristic.h"
#include <time.h>
#include <stdlib.h>

char* FullPath;
unsigned int FullPathHead = 0;
unsigned long long int checks = 0;
int BESTHEURISTIC = 0;
clock_t before;

void PrintCube(){
	printf("|1| |2| |3| |4| |5| |6| |7| |8| |9|\n");
		for(int k = 0; k<6;k++)
		{
			for(int j = 0;j<9;j++)
			{
				printf("|%c| ",myCube[k][j]);
			}
			printf("\n");
		}
		printf("\n");
}
void PathReducer(){
	
/*	checks++;
	if(checks == 2000000000 )
	{
		clock_t difference = clock() - before;
		int msec = difference * 1000 / CLOCKS_PER_SEC;
		printf("|%d.%d| Seconds to find\n",msec/1000,msec%1000);
	}
*/
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

int TwelvthLayer	(int move, const char parentcube[6][10]){
	char thiscube[6][10]; memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move)
	{
	case 1: 
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 2: 
	FullPath[FullPathHead] = ('I');
	FullPathHead++; 
	FullPath[FullPathHead] = ('R'); 
	FullPathHead++;
	InvertedRightOperation();
	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 3: 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 4: 
	FullPath[FullPathHead] = ('I');
	FullPathHead++;
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 5: 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 6: 
	FullPath[FullPathHead] = ('I');
	FullPathHead++;
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 7: 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 8: 
	FullPath[FullPathHead] = ('I');
	FullPathHead++;
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 9: 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 10: 
	FullPath[FullPathHead] = ('I');
	FullPathHead++;
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 11: 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 12: 
	FullPath[FullPathHead] = ('I');
	FullPathHead++;
	FullPath[FullPathHead] = ('V');
	FullPathHead++;
	InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	}
}
int EleventhLayer	(int move, const char parentcube[6][10]){
	char thiscube[6][10]; memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move)
	{
	case 1: 
	//TextOut(0,LCD_LINE3, "Im at L 11-1 ');
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 2: 
	//TextOut(0,LCD_LINE3, "Im at L 11-2 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 3: 
	//TextOut(0,LCD_LINE3, "Im at L 11-3 ');
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 4: 
	//TextOut(0,LCD_LINE3, "Im at L 11-4 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 5: 
	//TextOut(0,LCD_LINE3, "Im at L 11-5 ');
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 6: 
	//TextOut(0,LCD_LINE3, "Im at L 11-6 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 7: 
	//TextOut(0,LCD_LINE3, "Im at L 11-7 ');
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 8: 
	//TextOut(0,LCD_LINE3, "Im at L 11-8 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 9: 
	//TextOut(0,LCD_LINE3, "Im at L 11-9 ');
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 10: 
	//TextOut(0,LCD_LINE3, "Im at L 11-10 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 11: 
	//TextOut(0,LCD_LINE3, "Im at L 11-11 ');
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 12: 
	//TextOut(0,LCD_LINE3, "Im at L 11-12 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	}
}
int TenthLayer		(int move, const char parentcube[6][10]){
	char thiscube[6][10]; memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move)
	{
	case 1: 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 2: 
	//TextOut(0,LCD_LINE2, "Im at L 10-2 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 3: 
	//TextOut(0,LCD_LINE2, "Im at L 10-3 ');
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 4: 
	//TextOut(0,LCD_LINE2, "Im at L 10-4 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 5: 
	//TextOut(0,LCD_LINE2, "Im at L 10-5 ');
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 6: 
	//TextOut(0,LCD_LINE2, "Im at L 10-6 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 7: 
	//TextOut(0,LCD_LINE2, "Im at L 10-7 ');
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 8: 
	//TextOut(0,LCD_LINE2, "Im at L 10-8 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 9: 
	//TextOut(0,LCD_LINE2, "Im at L 10-9 ');
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 10: 
	//TextOut(0,LCD_LINE2, "Im at L 10-10 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 11: 
	//TextOut(0,LCD_LINE2, "Im at L 10-11 ');
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 12: 
	//TextOut(0,LCD_LINE2, "Im at L 10-12 ');
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	}
}
int NinethLayer		(int move, const char parentcube[6][10]){
	char thiscube[6][10]; memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move)
	{
	case 1: 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 2: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 3: 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 4: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 5: 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 6: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 7: 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 8: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 9: 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 10: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 11: 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 12: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	}
}
int EighthLayer		(int move, const char parentcube[6][10]){
	char thiscube[6][10]; memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move)
	{
	case 1: 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
		return 0;
	}
	else
	{
		for(int i = 1; i<=12;i++)
		{
			//for(int k = 0; k<9 ;k++)printf("%c", thiscube[0][k]);
			if(NinethLayer(i, myCube) == 0)
			{
				return 0;	
			}
		}
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 2: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 3: 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 4: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 5: 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 6: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 7: 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 8: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 9: 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 10: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 11: 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 12: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	}
}
int SeventhLayer	(int move, const char parentcube[6][10]){
	char thiscube[6][10]; memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move)
	{
	case 1: 
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 2:  
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 3: 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 4: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 5: 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 6: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 7: 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 8: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 9: 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 10: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 11: 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 12: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	}
}
int SixthLayer		(int move, const char parentcube[6][10]){
	char thiscube[6][10]; memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move)
	{
	case 1: 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 2: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 3: 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 4: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 5: 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 6: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 7: 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 8: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 9: 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 10: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 11: 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 12: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	}
}
int FifthLayer		(int move, const char parentcube[6][10]){
	char thiscube[6][10]; memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move)
	{
	case 1: 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 2: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 3: 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 4: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 5: 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 6: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 7: 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 8: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 9: 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 10: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 11: 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 12: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	}
}
int FourthLayer		(int move, const char parentcube[6][10]){
	char thiscube[6][10]; memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move)
	{
	case 1: 
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 2: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 3: 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 4: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 5: 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 6: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 7: 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 8: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 9: 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 10: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 11: 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 12: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	}
}
int ThirdLayer		(int move, const char parentcube[6][10]){
	char thiscube[6][10]; memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move)
	{
	case 1: 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 2: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 3: 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 4: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 5: 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 6: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 7: 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 8: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 9: 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 10: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 11: 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 12: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	}
}
int SecondLayer		(int move, const char parentcube[6][10]){
	char thiscube[6][10]; memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move)
	{
	case 1: 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 2: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 3: 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 4: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 5: 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 6: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 7: 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 8: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 9: 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 10: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 11: 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 12: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	}
}
int FirstLayer		(int move, const char parentcube[6][10]){
	char thiscube[6][10]; memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move)
	{
	case 1: 
	
	FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 2: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('R');
	FullPathHead++;
	 InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 3: 
	FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 4: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('L');
	FullPathHead++;
	 InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 5: 
	FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 6: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('T');
	FullPathHead++;
	 InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 7: 
	FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 8: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('B');
	FullPathHead++;
	 InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 9: 
	FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 10: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('F');
	FullPathHead++;
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 11: 
	FullPath[FullPathHead] = ('V'); 
	FullPathHead++;
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	case 12: 
	FullPath[FullPathHead] = ('I'); FullPathHead++; FullPath[FullPathHead] = ('V');
	FullPathHead++;
	 InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC)
	{
		BESTHEURISTIC = HeuristicValue();  printf("New H is: |%d|\n",BESTHEURISTIC);
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
		ORMyCube(thiscube); PathReducer();
		return 1;
	}
	break;
	}
}
int RootNodeMethod	(const char rootcube[6][10]){
	for(int i = 1; i<=12;i++)
	{
		if(EleventhLayer(i,rootcube) == 0)
			return 0;
		if(TenthLayer(i,rootcube) == 0)
			return 0;
		if(NinethLayer(i,rootcube) == 0)
			return 0;
		if(EighthLayer(i,rootcube) == 0)
			return 0;
		if(SeventhLayer(i,rootcube) == 0)
			return 0;
		if(SixthLayer(i,rootcube) == 0)
			return 0;
		if(FifthLayer(i,rootcube) == 0)
			return 0;
		if(FourthLayer(i, rootcube) == 0)
		{
			return 0;
		}
	}
	printf("You're boned, no solution");
	return 1;
}
int MoveCounter(){
	int moves = 0;
	for(int i = 0; i<strlen(FullPath);i++)
	{
		if(FullPath[i] != 'I')
			moves++;
	}
	return moves;
}
int main(){
	
	// char top[10] = { 'b', 'o', 'r', 'g', 'b', 'r', 'o', 'o', 'r'}; 
	// char right[10] = { 'g', 'b', 'w', 'w', 'r', 'r', 'w', 'b', 'b'}; 
	// char front[10] = { 'w', 'b', 'y', 'b', 'w', 'g', 'o', 'g', 'r'}; 
	// char back[10] = { 'r', 'o', 'y', 'r', 'y', 'o', 'o', 'g', 'g'}; 
	// char left[10] = { 'w', 'y', 'g', 'w', 'o', 'w', 'y', 'y', 'b'}; 
	// char bottom[10] = { 'y', 'w', 'b', 'r', 'g', 'y', 'g', 'y', 'o'}; 
	//works 116 - 3.120
	// 	works 56 46.667
	
	// char top[10] = { 'o', 'b', 'b', 'g', 'w', 'o', 'y', 'o', 'w'}; 
	// char right[10] = { 'w', 'y', 'o', 'o', 'r', 'g', 'r', 'y', 'g'}; 
	// char front[10] = { 'g', 'w', 'o', 'b', 'g', 'o', 'r', 'r', 'y'}; 
	// char back[10] = { 'g', 'r', 'o', 'b', 'b', 'b', 'b', 'y', 'y'}; 
	// char left[10] = { 'g', 'w', 'r', 'w', 'o', 'r', 'w', 'y', 'b'}; 
	// char bottom[10] = { 'w', 'w', 'g', 'r', 'y', 'g', 'r', 'g', 'b'}; 
	//works 113 - 23.765
	//doesnt work with optimisations
	
	// char top[10] = { 'r', 'r', 'b', 'r', 'w', 'g', 'b', 'b', 'y'}; 
	// char right[10] = { 'g', 'y', 'g', 'g', 'o', 'o', 'r', 'w', 'g'}; 
	// char front[10] = { 'r', 'w', 'r', 'o', 'b', 'y', 'o', 'o', 'w'}; 
	// char back[10] = { 'w', 'b', 'y', 'o', 'g', 'y', 'w', 'g', 'y'}; 
	// char left[10] = { 'g', 'b', 'w', 'w', 'r', 'g', 'o', 'w', 'b'}; 
	// char bottom[10] = { 'y', 'b', 'o', 'r', 'y', 'r', 'b', 'y', 'o'}; 
	//works 139 -2:50 ish
	//works 62 - 787.992
	
	// char top[10] = { 'r', 'r', 'o', 'r', 'w', 'o', 'y', 'o', 'o'}; 
	// char right[10] = { 'g', 'b', 'b', 'y', 'b', 'w', 'b', 'y', 'w'}; 
	// char front[10] = { 'r', 'b', 'g', 'g', 'r', 'b', 'w', 'w', 'o'}; 
	// char back[10] = { 'y', 'y', 'y', 'r', 'o', 'b', 'w', 'w', 'y'}; 
	// char left[10] = { 'g', 'y', 'b', 'g', 'g', 'o', 'g', 'o', 'r'}; 
	// char bottom[10] = { 'b', 'g', 'w', 'w', 'y', 'r', 'r', 'g', 'o'}; 
	//works 133 93.526 
	//works 69 153.278
	
	// char top[10] = { 'w', 'r', 'r', 'g', 'g', 'r', 'b', 'g', 'r'}; 
	// char right[10] = { 'y', 'b', 'y', 'g', 'y', 'o', 'b', 'w', 'y'}; 
	// char front[10] = { 'w', 'y', 'g', 'g', 'o', 'b', 'o', 'w', 'o'}; 
	// char back[10] = { 'g', 'y', 'r', 'o', 'r', 'o', 'o', 'y', 'w'}; 
	// char left[10] = { 'g', 'r', 'o', 'y', 'w', 'w', 'w', 'w', 'y'}; 
	// char bottom[10] = { 'g', 'o', 'b', 'b', 'b', 'r', 'r', 'b', 'b'}; 
	//works 133 90.858 
	//doesnt not work with optimisations
	
	// char top[10] = { 'b', 'r', 'y', 'g', 'w', 'g', 'w', 'r', 'w'};
	// char right[10] = { 'y', 'w', 'w', 'r', 'r', 'g', 'r', 'w', 'o'};
	// char front[10] = { 'b', 'b', 'b', 'b', 'g', 'o', 'r', 'o', 'o'};
	// char back[10] = { 'r', 'b', 'o', 'w', 'b', 'w', 'y', 'g', 'g'};
	// char left[10] = { 'o', 'y', 'r', 'o', 'o', 'o', 'g', 'r', 'y'};
	// char bottom[10] = { 'b', 'y', 'g', 'y', 'y', 'b', 'w', 'y', 'g'};
	//works 65 147.473
	
	char top[10] = { 'y', 'g', 'w', 'r', 'w', 'g', 'b', 'g', 'o'}; 
	char right[10] = { 'r', 'b', 'b', 'o', 'g', 'b', 'o', 'o', 'b'}; 
	char front[10] = { 'o', 'y', 'w', 'o', 'o', 'r', 'g', 'r', 'w'}; 
	char back[10] = { 'y', 'w', 'b', 'r', 'r', 'y', 'r', 'w', 'g'}; 
	char left[10] = { 'g', 'g', 'y', 'w', 'b', 'w', 'o', 'b', 'r'}; 
	char bottom[10] = { 'w', 'y', 'r', 'y', 'y', 'o', 'g', 'b', 'y'}; 
	//works 131 5.395
	//works 57 6.312
	
	// Den vi sendte  38 --- Case
	// char top[10] = { 'w', 'r', 'r', 'g', 'g', 'r', 'b', 'g', 'r'}; 
	// char right[10] = { 'y', 'b', 'y', 'g', 'y', 'o', 'b', 'w', 'y'}; 
	// char front[10] = { 'w', 'y', 'g', 'g', 'o', 'b', 'o', 'w', 'o'}; 
	// char back[10] = { 'g', 'y', 'r', 'o', 'r', 'o', 'o', 'y', 'w'}; 
	// char left[10] = { 'g', 'r', 'o', 'y', 'w', 'w', 'w', 'w', 'y'}; 
	// char bottom[10] = { 'g', 'o', 'b', 'b', 'b', 'r', 'r', 'b', 'b'};


	InitializeSide(top, TOP_FACE);
	InitializeSide(right, RIGHT_FACE);
	InitializeSide(front, FRONT_FACE);
	InitializeSide(back, BACK_FACE);
	InitializeSide(left, LEFT_FACE);
	InitializeSide(bottom, BOTTOM_FACE);

	FullPath = malloc(36*sizeof(char));
	BESTHEURISTIC = HeuristicValue();

	before = clock();
	while(BESTHEURISTIC != 0)
	{
		if(RootNodeMethod(myCube) == 1)
			exit(0);
		if(FullPathHead > 18)FullPath = realloc(FullPath,(FullPathHead+18)*sizeof(char));
	}
	clock_t difference = clock() - before;
	int msec = difference * 1000 / CLOCKS_PER_SEC;
	printf("|%d.%d| Seconds to find ---> path is |%d| long and is as follows: \n",msec/1000,msec%1000,MoveCounter());
	for(int i = 0; i < FullPathHead;i++)
	{
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
		{
			printf("%c%c ",FullPath[i], FullPath[i+1]);
			i++;
		}
			
	}	
}