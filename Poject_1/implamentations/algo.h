#ifndef ALGO_H
#define ALGO_H

#include <iostream>
#include <cstdlib>
#include "algo.h"

#define SIZE  1000
#define RANGE  500


//I know ... for debugging
using std::cout;
using std::endl;
using std::to_string;


template <class T> 
void  a_print(const T array[], int size){ 

	for(int i = 0; i < size  ; i++){
	
		if(array[i] != NULL){
			
			std::cout << array[i] << " ";

	
		}
	}
	std::cout << std::endl;
}




// returns an array with 
int * gen_intarray(int size, int range){ 
	
	int * array = new int[size];

	for(int i = 0 ; i < size; i++){ 
		array[i] = (rand() % range) + 1;

	} 

return array;
}


//this is broken 
//

char * gen_chrarray(int size, int range){ 
	
	char * array = new char[size];

	for(int i = 0 ; i < size; i++){ 
		array[i] = char(rand() % range) + 1;

	} 

return array;
}

//partitioning algorithm TODO = fix it its broken  
template<class T>
void partition(T a[], int piviot, int start, int stop){ 
	
//	a_print(a,stop);
	T * tmp  = new T[stop - start]; 	
	int backset =( stop - start)  - 1;
	int offset = 0; 
	int i; 
	for (i = start   ; i < stop ; ++i){ 
		
		if( i != piviot){
			
			if(a[i] < a[piviot]){
				
				tmp[offset] = a[i];
				++offset;
			
			}
			else if(a[i] > a[piviot]){ 
			
				tmp[backset] = a[i];
				--backset;
			
			}
			else{ //equal in value to the piviot 
		
				tmp[offset] = a[i]; 
				++offset;	
		
			} 
		

		}
	}	
	tmp[offset] = a[piviot];
	std::copy(tmp, tmp + (stop - start) , a + start);		
	delete tmp;
}



//myswap function 

#endif


