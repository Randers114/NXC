#include "Graph.h"


int main()
{
	
	// char top[10] = { 'o', 'o', 'o', 'y', 'o', 'g', 'o', 'o', 'b'}; 
	// char right[10] = { 'y', 'r', 'r', 'y', 'y', 'w', 'b', 'y', 'y'}; 
	// char front[10] = { 'b', 'b', 'r', 'o', 'b', 'b', 'b', 'b', 'g'}; 
	// char back[10] = { 'g', 'g', 'o', 'g', 'g', 'o', 'g', 'g', 'y'}; 
	// char left[10] = { 'w', 'b', 'w', 'w', 'w', 'w', 'w', 'w', 'w'}; 
	// char bottom[10] = { 'r', 'r', 'y', 'r', 'r', 'y', 'r', 'r', 'g'}; 
	
	char top[10] = { 'w', 'r', 'r', 'g', 'g', 'r', 'b', 'g', 'r'}; 
	char right[10] = { 'y', 'b', 'y', 'g', 'y', 'o', 'b', 'w', 'y'}; 
	char front[10] = { 'w', 'y', 'g', 'g', 'o', 'b', 'o', 'w', 'o'}; 
	char back[10] = { 'g', 'y', 'r', 'o', 'r', 'o', 'o', 'y', 'w'}; 
	char left[10] = { 'g', 'r', 'o', 'y', 'w', 'w', 'w', 'w', 'y'}; 
	char bottom[10] = { 'g', 'o', 'b', 'b', 'b', 'r', 'r', 'b', 'b'}; 
	
	// char top[10] = { 'b', 'r', 'y', 'g', 'w', 'g', 'w', 'r', 'w'};
	// char right[10] = { 'y', 'w', 'w', 'r', 'r', 'g', 'r', 'w', 'o'};
	// char front[10] = { 'b', 'b', 'b', 'b', 'g', 'o', 'r', 'o', 'o'};
	// char back[10] = { 'r', 'b', 'o', 'w', 'b', 'w', 'y', 'g', 'g'};
	// char left[10] = { 'o', 'y', 'r', 'o', 'o', 'o', 'g', 'r', 'y'};
	// char bottom[10] = { 'b', 'y', 'g', 'y', 'y', 'b', 'w', 'y', 'g'};
	
	
	
	// char top[10] = { 'y', 'g', 'w', 'r', 'w', 'g', 'b', 'g', 'o'}; 
	// char right[10] = { 'r', 'b', 'b', 'o', 'g', 'b', 'o', 'o', 'b'}; 
	// char front[10] = { 'o', 'y', 'w', 'o', 'o', 'r', 'g', 'r', 'w'}; 
	// char back[10] = { 'y', 'w', 'b', 'r', 'r', 'y', 'r', 'w', 'g'}; 
	// char left[10] = { 'g', 'g', 'y', 'w', 'b', 'w', 'o', 'b', 'r'}; 
	// char bottom[10] = { 'w', 'y', 'r', 'y', 'y', 'o', 'g', 'b', 'y'}; 


	InitializeSide(top, TOP_FACE);
	InitializeSide(right, RIGHT_FACE);
	InitializeSide(front, FRONT_FACE);
	InitializeSide(back, BACK_FACE);
	InitializeSide(left, LEFT_FACE);
	InitializeSide(bottom, BOTTOM_FACE);
	
	MainGraphConstruction();
	return 0;
}