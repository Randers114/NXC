#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Graph.h"


int main()
{
	
	
char top[10] = { 'b', 'r', 'y', 'g', 'w', 'g', 'w', 'r', 'w'};
char right[10] = { 'y', 'w', 'w', 'r', 'r', 'g', 'r', 'w', 'o'};
char front[10] = { 'b', 'b', 'b', 'b', 'g', 'o', 'r', 'o', 'o'};
char back[10] = { 'r', 'b', 'o', 'w', 'b', 'w', 'y', 'g', 'g'};
char left[10] = { 'o', 'y', 'r', 'o', 'o', 'o', 'g', 'r', 'y'};
char bottom[10] = { 'b', 'y', 'g', 'y', 'y', 'b', 'w', 'y', 'g'};

InitializeSide(top, TOP_FACE);
InitializeSide(right, RIGHT_FACE);
InitializeSide(front, FRONT_FACE);
InitializeSide(back, BACK_FACE);
InitializeSide(left, LEFT_FACE);
InitializeSide(bottom, BOTTOM_FACE);

BESTHEURISTIC = HeuristicValue();

while(BESTHEURISTIC != 0)
{
    RootNodeMethod(myCube);
}
for(int i = 0; i < FullPathHead;i++)
{
	if(FullPath[i] == 'R'
	|| FullPath[i] == 'L'
	|| FullPath[i] == 'T'
	|| FullPath[i] == 'B' 
	|| FullPath[i] == 'F' 
	|| FullPath[i] == 'V' )
		printf("%c",FullPath[i]);
	if( FullPath[i] == 'I'
	&&( FullPath[i+1] == 'R'
	|| FullPath[i+1] == 'L'
	|| FullPath[i+1] == 'T'
	|| FullPath[i+1] == 'B'
	|| FullPath[i+1] == 'F'
	|| FullPath[i+1] == 'V'))
        printf("%c%c",FullPath[i], FullPath[i+1]);
}	
}