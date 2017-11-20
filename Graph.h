#include "Heuristic.h"
#include "/Layers/FirstLayer.h"

int RootNodeMethod(char rootcube[][])
{
	for(int i = 1; i<=12;i++)
	{
		NumOut(0,LCD_LINE5, i);
		if(FirstLayer(i, rootcube) == 0)
		{
			return 0;
		}
	}	
	return 1;
}