#ifndef ALGO_H
#define ALGO_H

#include <iostream>
#include <cstdlib>
#include "Integer.h" 
#include "algo.h"

#define SIZE   200000
#define RANGE  500


//I know ... for debugging
using std::cout;


template <class T> 
void  a_print(const T array[], int size){ 

	for(int i = 0; i < size  ; i++){
	
		cout << array[i] << " ";
	}
	cout << '\n';
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



// Partitioning algorithm for use with Quicksort
// NOTE: Partitions make use of a temporary array
template <class T>
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


// In place partitioning algorithm for use with Quicksort and my_max_element
// NOTE: Partitions in place, without the use of a temporary array
template<class T>
void partition_inplace(T a[], const int &start, const int &stop, int &pivot){

	// Create parameter indices
	int p = start;
	int q = start;

	// Must swap pivot with the last element
	int last = stop-1;
	std::swap( a[pivot], a[last] );

	// Get value of the pivot
	T pivotVal = a[last];

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


// A simple function to find the max element
// NOTE: Does not make use of partition_inplace
template<class T>
int my_max(T a[], int start , int stop){ 

	int temp = 0; 
	int i = 0;
	for (i = start; i < stop ; i++){ 
		//Less than is the only thing implamented 	
		if(!(a[i] < a[temp])){ 
				
			temp = i; 
		}
	}
	return temp;
}



// Finds the max element in the range, [start, stop)
// Very efficient, makes use of partition_inplace
// NOTE: Make sure the rank passed is stop-1
// NOTE: unstable :(
template<class T> 
int my_max_element(T a[], int start,  int stop, int rank){ 
	
	// If there is at least 2 elements
	while (stop - start > 1){ 

		// Set the pivot and run the partitioning algorithm
		int pivot = start + rand() % (stop - start);				
		partition_inplace(a , start, stop, pivot);  

		// If the rank is the pivot, we are done!
		if(rank == pivot)
			return a[pivot];

		// If the rank is less than the pivot, partition the left half
		// NOTE: Done by updating stop
		else if (rank < pivot)
			stop = pivot;
		
		// If the rank is greater than the pivot partition the right half
		// NOTE: Done by updating start
		else 
			start = pivot+1;
	}
	
	// If there is one position left, it must be the rank
	if (start == rank)
		return a[start];

	// The rank is not attainable, or a bug
	else
		return -1;
}

// Merges two portions together in increasing order
// For use with mergeSort
// NOTE: The two portions should be already sorted
template <class T>
void merge(T a[], int start, int mid, int stop){
	// First element in a
	int p = start;
	// Middle element in a
	int q = mid;

	// Create resulting array
	T *result = new T[stop-start];
	int k = 0; //next available position

	// Merging step
	// If a[p] < a[q] put a[p] first into result
	// If a[p] > a[q] put a[q] first into result
	while( p < mid && q < stop){
		if (a[p] < a[q]){
			result[k] = a[p];
			++p;
		}
		else{ //a[p] > a[q]
			result[k] = a[q];
			++q;
		}

		++k;
	}

	// Now we must copy the remaining values into result
	std::copy( a+p, a+mid, result+k);
	std::copy( a+q, a+stop, result+k);

	// Now copy result to a and delete result
	std::copy( result, result+(stop-start), a+start );
	delete[] result;
}




#endif


