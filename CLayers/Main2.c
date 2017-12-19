#include "Heuristic.h"
#include <time.h>

char* FullPath;
unsigned int FullPathHead = 0;
int BESTHEURISTIC = 0;
clock_t before;

void PathReducer(){														//nothing
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
void GoBackTo(char thiscube[6][10]){									//1 cube 2 int
	ORMyCube(thiscube);
	PathReducer();
}
void AddPath(char toAdd[2]){											//char[2]
	if(toAdd[0] != 'I')
	{
		FullPath[FullPathHead] = toAdd[0];
		FullPathHead++;
	}
	else
	{
		FullPath[FullPathHead] = toAdd[0];
		FullPathHead++;
		FullPath[FullPathHead] = toAdd[1];
		FullPathHead++;
	}
	
}
void PrintCube(){														//2 int
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
int TwelvthLayer	(int move, const char parentcube[6][10]){			//12- 2 cube + 1689 int + 318 char
	char thiscube[6][10];
	memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move){
	case 1: 
	AddPath("R");
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
		GoBackTo(thiscube);
		return 1;
	}
	break;
	case 2: 
	AddPath("IR");
	InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
		GoBackTo(thiscube);
		return 1;
	}
	break;
	case 3: 
	AddPath("L");
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
		GoBackTo(thiscube);
		return 1;
	}
	break;
	case 4: 
	AddPath("IL");
	InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else
	{
		GoBackTo(thiscube);
		return 1;
	}
	break;
	case 5: 
	AddPath("T");
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
		GoBackTo(thiscube);
		return 1;
	}
	break;
	case 6: 
	AddPath("IT");
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
		GoBackTo(thiscube);
		return 1;
	}
	break;
	case 7: 
	AddPath("B");
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
		GoBackTo(thiscube);
		return 1;
	}
	break;
	case 8: 
	AddPath("IB");
	InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue(); 
		return 0;
	}
	else{
		GoBackTo(thiscube);
		return 1;
	}
	break;
	case 9: 
	AddPath("F");
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
		GoBackTo(thiscube);
		return 1;
	}
	break;
	case 10: 
	AddPath("IF");
	InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
		GoBackTo(thiscube);
		return 1;
	}
	break;
	case 11: 
	AddPath("V");
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue(); 
		return 0;
	}
	else{
		GoBackTo(thiscube);
		return 1;
	}
	break;
	case 12: 
	AddPath("IV");
	InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue(); 
		return 0;
	}
	else{
		GoBackTo(thiscube);
		return 1;
	}
	break;
	}
}
int EleventhLayer	(int move, const char parentcube[6][10]){			//11- 4 cube + 3390 int + 636 char
	char thiscube[6][10];
	memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move){
	case 1: 
	AddPath("R");
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TwelvthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 2: 
	AddPath("IR");
	InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TwelvthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 3: 
	AddPath("L");
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TwelvthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 4: 
	AddPath("IL");
	InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TwelvthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 5:
	AddPath("T");
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TwelvthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 6: 
	AddPath("IT");
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC){	
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TwelvthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 7: 
	AddPath("B");
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TwelvthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 8: 
	AddPath("IB");
	InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TwelvthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 9: 
	AddPath("F");
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TwelvthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 10: 
	AddPath("IF");
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TwelvthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 11: 
	AddPath("V"); 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TwelvthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 12: 
	AddPath("IV");
	InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TwelvthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	}
}
int TenthLayer		(int move, const char parentcube[6][10]){			//10- 6 cube + 5091 int + 954 char
	char thiscube[6][10];
	memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move){
	case 1: 
	AddPath("R");
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EleventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 2: 
	AddPath("IR");
	InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EleventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 3: 
	AddPath("L");
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EleventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 4: 
	AddPath("IL");
	InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EleventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 5:
	AddPath("T");
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EleventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 6: 
	AddPath("IT");
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC){	
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EleventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 7: 
	AddPath("B");
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EleventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 8: 
	AddPath("IB");
	InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EleventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 9: 
	AddPath("F");
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EleventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 10: 
	AddPath("IF");
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EleventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 11: 
	AddPath("V"); 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EleventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 12: 
	AddPath("IV");
	InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EleventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	}
}
int NinethLayer		(int move, const char parentcube[6][10]){			//9-  8 cube + 6792 int + 1272 char
	char thiscube[6][10];
	memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move){
	case 1: 
	AddPath("R");
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TenthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 2: 
	AddPath("IR");
	InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TenthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 3: 
	AddPath("L");
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TenthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 4: 
	AddPath("IL");
	InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TenthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 5:
	AddPath("T");
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TenthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 6: 
	AddPath("IT");
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC){	
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TenthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 7: 
	AddPath("B");
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TenthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 8: 
	AddPath("IB");
	InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TenthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 9: 
	AddPath("F");
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TenthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 10: 
	AddPath("IF");
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TenthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 11: 
	AddPath("V"); 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TenthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 12: 
	AddPath("IV");
	InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(TenthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	}
}
int EighthLayer		(int move, const char parentcube[6][10]){			//8- 10 cube + 8493  int + 1590 char
	char thiscube[6][10];
	memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move){
	case 1: 
	AddPath("R");
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(NinethLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 2: 
	AddPath("IR");
	InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(NinethLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 3: 
	AddPath("L");
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(NinethLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 4: 
	AddPath("IL");
	InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(NinethLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 5:
	AddPath("T");
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(NinethLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 6: 
	AddPath("IT");
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC){	
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(NinethLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 7: 
	AddPath("B");
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(NinethLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 8: 
	AddPath("IB");
	InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(NinethLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 9: 
	AddPath("F");
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(NinethLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 10: 
	AddPath("IF");
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(NinethLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 11: 
	AddPath("V"); 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(NinethLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 12: 
	AddPath("IV");
	InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(NinethLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	}
}
int SeventhLayer	(int move, const char parentcube[6][10]){			//7- 12 cube + 10194 int + 1908 char
	char thiscube[6][10];
	memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move){
	case 1: 
	AddPath("R");
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EighthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 2: 
	AddPath("IR");
	InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EighthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 3: 
	AddPath("L");
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EighthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 4: 
	AddPath("IL");
	InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EighthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 5:
	AddPath("T");
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EighthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 6: 
	AddPath("IT");
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC){	
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EighthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 7: 
	AddPath("B");
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EighthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 8: 
	AddPath("IB");
	InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EighthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 9: 
	AddPath("F");
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EighthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 10: 
	AddPath("IF");
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EighthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 11: 
	AddPath("V"); 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EighthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 12: 
	AddPath("IV");
	InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(EighthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	}
}
int SixthLayer		(int move, const char parentcube[6][10]){			//6- 14 cube + 11895 int + 2226 char
	char thiscube[6][10];
	memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move){
	case 1: 
	AddPath("R");
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SeventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 2: 
	AddPath("IR");
	InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SeventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 3: 
	AddPath("L");
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SeventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 4: 
	AddPath("IL");
	InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SeventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 5:
	AddPath("T");
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SeventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 6: 
	AddPath("IT");
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC){	
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SeventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 7: 
	AddPath("B");
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SeventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 8: 
	AddPath("IB");
	InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SeventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 9: 
	AddPath("F");
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SeventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 10: 
	AddPath("IF");
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SeventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 11: 
	AddPath("V"); 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SeventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 12: 
	AddPath("IV");
	InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SeventhLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	}
}
int FifthLayer		(int move, const char parentcube[6][10]){			//5- 16 cube + 13596 int + 2544 char
	char thiscube[6][10];
	memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move){
	case 1: 
	AddPath("R");
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SixthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 2: 
	AddPath("IR");
	InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SixthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 3: 
	AddPath("L");
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SixthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 4: 
	AddPath("IL");
	InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SixthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 5:
	AddPath("T");
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SixthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 6: 
	AddPath("IT");
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC){	
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SixthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 7: 
	AddPath("B");
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SixthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 8: 
	AddPath("IB");
	InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SixthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 9: 
	AddPath("F");
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SixthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 10: 
	AddPath("IF");
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SixthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 11: 
	AddPath("V"); 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SixthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 12: 
	AddPath("IV");
	InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(SixthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	}
}
int FourthLayer		(int move, const char parentcube[6][10]){			//4- 18 cube + 15297 int + 2862 char
	char thiscube[6][10];
	memcpy(thiscube,parentcube,60*sizeof(char));
	switch (move){
	case 1: 
	AddPath("R");
	RightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(FifthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 2: 
	AddPath("IR");
	InvertedRightOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(FifthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 3: 
	AddPath("L");
	LeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(FifthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 4: 
	AddPath("IL");
	InvertedLeftOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(FifthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 5:
	AddPath("T");
	TopOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(FifthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 6: 
	AddPath("IT");
	InvertedTopOperation();
	if(HeuristicValue() < BESTHEURISTIC){	
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(FifthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 7: 
	AddPath("B");
	BottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(FifthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 8: 
	AddPath("IB");
	InvertedBottomOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(FifthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 9: 
	AddPath("F");
	FrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(FifthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 10: 
	AddPath("IF");
	 InvertedFrontOperation();
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(FifthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 11: 
	AddPath("V"); 
	BackOperation();	
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(FifthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	case 12: 
	AddPath("IV");
	InvertedBackOperation(); 
	if(HeuristicValue() < BESTHEURISTIC){
		BESTHEURISTIC = HeuristicValue();
		return 0;
	}
	else{
			for(int i = 0; i<12;i++){
				if(FifthLayer(i,myCube) ==0)
					return 0;
			}
		}
	GoBackTo(thiscube);
	return 1;
	break;
	}
}
int RootNodeMethod	(const char rootcube[6][10]){						// 43 cube + 35674 int + 6678 char
	for(int i = 1; i<=12;i++)
	{
		if(EleventhLayer(i,rootcube) == 0) //check at depth 2
			return 0;
		if(NinethLayer(i,rootcube) == 0) // check at depth 4
			return 0;
		if(SeventhLayer(i,rootcube) == 0) // check at depth 6
			return 0;
		if(FourthLayer(i, rootcube) == 0) // check at depth 9
			return 0;
	}
	printf("You're boned, no solution");
	return 1;
}
int MoveCounter(){														//2 int
	int moves = 0;
	for(int i = 0; i<strlen(FullPath);i++)
	{
		if(FullPath[i] != 'I')
			moves++;
	}
	return moves;
}
void InitSides(){														//6 * char[10]
	char top[10] = { 'y', 'g', 'w', 'r', 'w', 'g', 'b', 'g', 'o'}; 
	char right[10] = { 'r', 'b', 'b', 'o', 'g', 'b', 'o', 'o', 'b'}; 
	char front[10] = { 'o', 'y', 'w', 'o', 'o', 'r', 'g', 'r', 'w'}; 
	char back[10] = { 'y', 'w', 'b', 'r', 'r', 'y', 'r', 'w', 'g'}; 
	char left[10] = { 'g', 'g', 'y', 'w', 'b', 'w', 'o', 'b', 'r'}; 
	char bottom[10] = { 'w', 'y', 'r', 'y', 'y', 'o', 'g', 'b', 'y'}; 
	
	InitializeSide(top, TOP_FACE);
	InitializeSide(right, RIGHT_FACE);
	InitializeSide(front, FRONT_FACE);
	InitializeSide(back, BACK_FACE);
	InitializeSide(left, LEFT_FACE);
	InitializeSide(bottom, BOTTOM_FACE);
}
void PrintPath(){														//1 int
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
void ExtendPath(){														//nothing
	FullPath = realloc(FullPath,(FullPathHead+18)*sizeof(char));
}
int main(){																//43 cube + 35675 int + 6744 char 80674 byte or 80.674KB maybe + lastlayer + yellowface
	InitSides();
	FullPath = malloc(36*sizeof(char));
	BESTHEURISTIC = HeuristicValue();

	before = clock();
	
	while(BESTHEURISTIC != 0)
	{
		if(RootNodeMethod(myCube) == 1)
			exit(0);
		if((FullPathHead % 18) < 18)
			ExtendPath();
	}
	
	clock_t difference = clock() - before;
	int msec = difference * 1000 / CLOCKS_PER_SEC;
	printf("|%d.%d| Seconds to find ---> path is |%d| long and is as follows: \n",msec/1000,msec%1000,MoveCounter());
	
	PrintPath();	
}