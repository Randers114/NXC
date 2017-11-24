#include "Graph.h"


int main()
{
	
	// char top[10] = { 'r', 'w', 'w', 'w', 'w', 'w', 'w', 'w', 'w'}; 
	// char right[10] = { 'y', 'o', 'y', 'g', 'g', 'g', 'g', 'g', 'g'}; 
	// char front[10] = { 'o', 'o', 'o', 'o', 'o', 'o', 'y', 'y', 'b'}; 
	// char back[10] = { 'o', 'g', 'g', 'r', 'r', 'r', 'b', 'r', 'r'}; 
	// char left[10] = { 'w', 'b', 'b', 'b', 'b', 'b', 'g', 'y', 'o'}; 
	// char bottom[10] = { 'b', 'b', 'r', 'r', 'y', 'y', 'y', 'y', 'r'}; 
		
	
	char top[10] = { 'b', 'o', 'r', 'g', 'b', 'r', 'o', 'o', 'r'}; 
	char right[10] = { 'g', 'b', 'w', 'w', 'r', 'r', 'w', 'b', 'b'}; 
	char front[10] = { 'w', 'b', 'y', 'b', 'w', 'g', 'o', 'g', 'r'}; 
	char back[10] = { 'r', 'o', 'y', 'r', 'y', 'o', 'o', 'g', 'g'}; 
	char left[10] = { 'w', 'y', 'g', 'w', 'o', 'w', 'y', 'y', 'b'}; 
	char bottom[10] = { 'y', 'w', 'b', 'r', 'g', 'y', 'g', 'y', 'o'}; 
	
	
	
	// char top[10] = { 'o', 'b', 'b', 'g', 'w', 'o', 'y', 'o', 'w'}; 
	// char right[10] = { 'w', 'y', 'o', 'o', 'r', 'g', 'r', 'y', 'g'}; 
	// char front[10] = { 'g', 'w', 'o', 'b', 'g', 'o', 'r', 'r', 'y'}; 
	// char back[10] = { 'g', 'r', 'o', 'b', 'b', 'b', 'b', 'y', 'y'}; 
	// char left[10] = { 'g', 'w', 'r', 'w', 'o', 'r', 'w', 'y', 'b'}; 
	// char bottom[10] = { 'w', 'w', 'g', 'r', 'y', 'g', 'r', 'g', 'b'}; 
	
	
	// char top[10] = { 'r', 'r', 'b', 'r', 'w', 'g', 'b', 'b', 'y'}; 
	// char right[10] = { 'g', 'y', 'g', 'g', 'o', 'o', 'r', 'w', 'g'}; 
	// char front[10] = { 'r', 'w', 'r', 'o', 'b', 'y', 'o', 'o', 'w'}; 
	// char back[10] = { 'w', 'b', 'y', 'o', 'g', 'y', 'w', 'g', 'y'}; 
	// char left[10] = { 'g', 'b', 'w', 'w', 'r', 'g', 'o', 'w', 'b'}; 
	// char bottom[10] = { 'y', 'b', 'o', 'r', 'y', 'r', 'b', 'y', 'o'}; 
	
	// char top[10] = { 'r', 'r', 'o', 'r', 'w', 'o', 'y', 'o', 'o'}; 
	// char right[10] = { 'g', 'b', 'b', 'y', 'b', 'w', 'b', 'y', 'w'}; 
	// char front[10] = { 'r', 'b', 'g', 'g', 'r', 'b', 'w', 'w', 'o'}; 
	// char back[10] = { 'y', 'y', 'y', 'r', 'o', 'b', 'w', 'w', 'y'}; 
	// char left[10] = { 'g', 'y', 'b', 'g', 'g', 'o', 'g', 'o', 'r'}; 
	// char bottom[10] = { 'b', 'g', 'w', 'w', 'y', 'r', 'r', 'g', 'o'}; 
	
	// Den vi sendte 
	// char top[10] = { 'w', 'r', 'r', 'g', 'g', 'r', 'b', 'g', 'r'}; 
	// char right[10] = { 'y', 'b', 'y', 'g', 'y', 'o', 'b', 'w', 'y'}; 
	// char front[10] = { 'w', 'y', 'g', 'g', 'o', 'b', 'o', 'w', 'o'}; 
	// char back[10] = { 'g', 'y', 'r', 'o', 'r', 'o', 'o', 'y', 'w'}; 
	// char left[10] = { 'g', 'r', 'o', 'y', 'w', 'w', 'w', 'w', 'y'}; 
	// char bottom[10] = { 'g', 'o', 'b', 'b', 'b', 'r', 'r', 'b', 'b'}; 
	
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