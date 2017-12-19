#include "Graph.h"

int main(int argc, char *argv[])
{	
	ReadFileFromNXT(argv[1]);
	
	MainGraphConstruction();
	
	WriteFileToNXT(Path, (HIGHEST_HEURISTIC_VALUE * GRAPH_SIZE + WORST_NUMBER_OF_CASES * NUMBER_OF_MOVES_IN_CASE), argv[1]);
	
	return 0;
}