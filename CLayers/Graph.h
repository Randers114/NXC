#include "heuristic.h"
#include "CFirstLayer.h"

int RootNodeMethod(char rootcube[6][10])
{
	for(int i = 1; i<=12;i++)
	{
		if(FirstLayer(i, rootcube) == 0)
		{
			return 0;
		}
	}
	printf("You're boned, no solution");
	return 1;
}