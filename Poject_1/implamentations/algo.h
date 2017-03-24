#ifndef ALGO_H
#define ALGO_H

#include <iostream>
#include <cstdlib>
#include "algo.h"

using std::cout;
using std::endl;
using std::to_string;


template <class T> 
void  a_print(const T array[], int size){ 
	
	for(int i = 0; i < size  ; i++){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}




// returns an array with 
int * gen_intarray(int size, int range){ 
	
	int * array = new int[size];

	for(int i = 0 ; i < size; i++){ 
		array[i] = rand() % range;

	} 

return array;
}


//this is broken 
//

char * gen_chrarray(int size, int range){ 
	
	char * array = new char[size];

	for(int i = 0 ; i < size; i++){ 
		array[i] = char(rand() % range);

	} 

return array;
}



#endif


