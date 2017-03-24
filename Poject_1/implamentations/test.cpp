#include <iostream> 
#include "algo.h"

using std::cout; 


int main(){ 

	int * p; 
	int size = 100000, range = 5;
	p = gen_intarray(size , range); 
	a_print(p,size);

	return 0; 
}
