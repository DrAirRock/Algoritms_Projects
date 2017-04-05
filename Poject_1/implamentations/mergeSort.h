#include <iostream>
#include <cstdlib>

// SEE IMPLEMENTATION
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

	


template <class T>
void mergeSort(T a[], int start, int stop){

	if (stop-start > 1){
		// Get the middle of the array
		int mid = (start + stop)/2;

		// Recursively sort both halves of a
		mergeSort(a, start, mid);
		mergeSort(a, mid, stop);
		merge(a, start, mid, stop);
	}
}
