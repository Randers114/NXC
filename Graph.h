#include "Heuristic.h"
#include "/Layers/FirstLayer.h"

void RootNodeMethod(char rootcube[][])
{
	for(int i = 0; i<12;i++)
		FirstLayer(i, rootcube);
}





