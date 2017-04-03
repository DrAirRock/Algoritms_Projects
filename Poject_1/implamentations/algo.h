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


template <class T> 
void  a_print(const T array[],int start, int stop){ 

	for(int i = start; i < stop  ; i++){
	
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



template<class T>
void partition(T a[], int start, int stop, int pivot){
	// Create parameter indices
	int p = 0;
	int q = 0;

	// Must swap pivot with the last element
	int last = stop-1;
	std::swap( a[pivot], a[last] );
	
	// Get value of the pivot
	int pivotVal = a[last];

	// Partitioning
	while (q < last){
		if (a[q] <= pivotVal){
			std::swap( a[p], a[q] );
			++p;
		}
		++q;
	}

	// Put pivot between partitions
	std::swap( a[p], a[last] );
	pivot = p;
}
	



/*
//partitioning algorithm TODO = fix it its broken  
template<class T>
void partition(T a[], int piviot, int start, int stop){ 
	
	cout <<"\nPIVOT: " <<  a[piviot] << "\n";
//kj:w
	cout<<"PASSED IN:   ";	
	a_print(a,start,stop);
	T * tmp  = new T[stop - start]; 	
	int backset =( stop - start)  - 1;
	int offset = 0; 
	int i; 
	for (i = start  ; i <stop ; ++i){ 
		
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
	cout << "TEMP:        "	;
	a_print(tmp, stop-start);
	cout <<"BEFORE COPY: ";		
	a_print(a, start, stop);
	std::copy(tmp, tmp + (stop - start) , a + start);		
	cout << "AFTER COPY:  ";	
	a_print(a,start,stop);
	delete tmp;
}
*/


//myswap function 

#endif


