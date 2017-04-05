#ifndef ALGO_H
#define ALGO_H

#include <iostream>
#include <cstdlib>
#include "Integer.h" 
#include "algo.h"

#define SIZE   10000
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

//FORE DEBUGGING
template <class T> 
void  a_print(const T array[],int start, int stop){ 

	for(int i = start; i < stop  ; i++){
	
		if(array[i] != NULL){
			
			std::cout << array[i] << " ";

	
		}	
	}
	std::cout << std::endl;
}


//for printing Integer arrays
template <class T> 
void a_print_integer(const T array[], int size){ 

	for(int i = 0; i < size  ; i++){

		if(array[i].value() != NULL){

			 std::cout << array[i].value()  << " ";
		}
	
	}
	std::cout << std::endl;
}


//Generation of INGETEER ARRAYSJ
Integer * gen_integerarray(int size, int range){ 
	
	//Integer * array = new Integer[size]; 
	Integer * array = new Integer[size]; 
	
	for(int i = 0 ; i < size; i++){ 
	
		array[i] = (rand() % range) + 1;

	} 


return array;
}


Integer *gen_reverse_integer(Integer *p, int size){ 

	Integer * array = new Integer[size]; 
	int x = 0;	
	for(int i = size-1; i >= 0; i--){ 
		
		array[x] = p[i];
		x++;
	
	} 	
return array; 
}

Integer *gen_integerinorder(int size){ 

	Integer * array = new Integer[size]; 

	for(int i = 1 ; i <= size; i++){ 
	
		array[i] = i;

	} 
return array; 
}




int * gen_intarray(int size, int range){ 
	
	int * array = new int[size];

	for(int i = 0 ; i < size; i++){ 
		
		array[i] = (rand() % range) + 1;

	} 

return array;
}


template<class T>
int max (T a, int start , int end ){ 

	for 

// Partitioning algorithm for use with Quicksort
// NOTE: Partitions make use of a temporary array
template<class T>
void partition(T a[], const int &start, const int &stop, int &pivot){
	// Move Pivot to end
	int last = stop-1;
	std::swap( a[pivot], a[last] );
	T pivotVal = a[last];

	// Allocate temporary array
	T *temp = new T[ stop - start ];
	int k = 0; //next available position

	// Partitioning step
	// NOTE: Position where pivot should be placed is tracked
	int pivotPos = 0;
	for (int i= start; i<last; ++i){
		temp[k] = a[i];
		if ( temp[k] < pivotVal){
			std::swap( temp[k], temp[pivotPos] );
			++pivotPos;
		}
		++k;
	}

	// Putting pivot in correct position and copying to a
	temp[k] = a[last];
	std::swap( temp[k], temp[pivotPos] );
	pivot = pivotPos + start; //Need to offset for actual array
	++k;

	std::copy(temp, temp + k, a + start);
	delete temp;
}


// In place partitioning algorithm for use with Quicksort
// NOTE: Partitions in place, without the use of a temporary array
template<class T>
void partition_inplace(T a[], const int &start, const int &stop, int &pivot){
	// Create parameter indices
	int p = start;
	int q = start;
//	cout<<"before swap";
	// Must swap pivot with the last element
	int last = stop-1;
	std::swap( a[pivot], a[last] );
//	cout<<"after swap";	
	// Get value of the pivot
	T pivotVal = a[last];
//	cout << "after piviot\n"; 
	// Partitioning step
	while (q < last){
		if (a[q] < pivotVal){
			std::swap( a[p], a[q] );
			++p;
		}
		++q;
	}

	// put pivot between partitions
	std::swap( a[p], a[last] );
	pivot = p;
}
	



#endif


