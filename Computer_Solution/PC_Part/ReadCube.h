#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CheckCase.h"
#include <windows.h>


void ReadFileFromNXT(char *filePath)
{
	char *copyFilePath;
	
	copyFilePath = realloc(copyFilePath, sizeof(char) * 17 + strlen(filePath));
	
	strcpy(copyFilePath, filePath);
	
	strcat(copyFilePath, "/initialCube.txt");
	
	FILE *rp = fopen(copyFilePath, "r"); 
	
	for(int i = 0 ; i < 6; i++)
   	{
        fscanf(rp,"%c %c %c %c %c %c %c %c %c ", &myCube[i][0], &myCube[i][1], &myCube[i][2], &myCube[i][3], &myCube[i][4], 
												 &myCube[i][5], &myCube[i][6], &myCube[i][7], &myCube[i][8]);
    }
	
	fclose(rp);

}

void WriteFileToNXT(int path[], int length, char *filePath)
{
	char *copyFilePath;
	
	copyFilePath = realloc(copyFilePath, sizeof(char) * 15 + strlen(filePath));
	
	strcpy(copyFilePath, filePath);
	
	strcat(copyFilePath, "/cube_path.txt");
	
	FILE *wp = fopen(copyFilePath, "w"); 
	
	for(int i = 0 ; i < 6; i++)
   	{
        fprintf(wp,"%c %c %c %c %c %c %c %c %c \n", myCube[i][0], myCube[i][1], myCube[i][2], myCube[i][3], myCube[i][4], 
													myCube[i][5], myCube[i][6], myCube[i][7], myCube[i][8]);
    }
	
    for (int i = 0; i < length; i++)
    {
		if(path[i] != 0)
		{
			fprintf(wp,"%i ", path[i]);
		}
    }
	
	fprintf(wp, "%s", "$");
	
	fclose(wp);
}