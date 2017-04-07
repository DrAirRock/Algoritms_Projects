#include <iostream>
#include <cstdlib>
#include "algo.h"
#include <algorithm> 
#include <chrono>
#include <ctime> 

using std::cout;

//for stl algrithm 
struct comp{ 

	bool operator() (Integer a, Integer b) {return (a < b); }

}comp_obj;


template <class T>
void quick_sort_inplace(const T a, int start, int stop){
	


	if( stop - start > 1){
		int pivot = start + rand() % (stop - start);			
		partition_inplace( a , start, stop, pivot);	
		quick_sort_inplace( a , start, pivot);
		quick_sort_inplace( a , pivot + 1, stop);
	}
	

	return; 

}


template <class t>
void quick_sort(t a[], int start, int stop){
	
	if( stop - start > 1){
		
		int pivot = start + rand() % (stop - start);				
		partition( a , start, stop, pivot);	 
		quick_sort( a , start, pivot);
		quick_sort( a , pivot + 1, stop);
	
		
	}
	
	return; 
}

template <class T>
void quick_sort_start(T a[], int start, int stop){
	
	if( stop - start > 1){
		
		int pivot = start;				
		partition( a , start, stop, pivot);	 
		quick_sort( a , start, pivot);
		quick_sort( a , pivot + 1, stop);
	
		
	}
	

}
template<class T> 
void insertion_sort(const T a, int i, int j){ 
	//insert a[k] into a[i..k) 
	int k;
	Integer x;	
	int p;	
	k = i + 1;

	for (; k <= (j - 1); k++){
		x = a[k]; 
		p = k-1; 

		while( p >= i && x < a[p] ){ 
			a[p+1] = a[p];	
			--p;	
		}
	
		a[p+1] = x;
	}
}

/*
template<class T> 
void selection_sort(const T a, int start , int stop){ 

	if((stop - start) >= 2){ 
	
		int k = my_max(a , start, stop ); 
		
		std::swap(a[k] , a[stop - 1]);

		selection_sort(a,start,stop-1);

	}

} 
*/


template<class T> 
void selection_sort(const T a, int start , int stop){ 

	while ((stop - start) >= 2){ 
	
		int k = my_max(a , start, stop ); 
		
		std::swap(a[k] , a[stop - 1]);
		
		stop--;
	//	selection_sort(a,start,stop-1);

	}

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


int main (){
	
	Integer *p; 
	Integer *q; 
	Integer *r; 
	
	//////////////// INSERTION SORT ////////////////
	
	cout << "ARRAYS ARE ON THE ORDER OF: " << SIZE << "\n";
	cout << "RANGE OF RANDOM NUBMERS IS:  " <<RANGE << "\n";
	cout << "\nInsertion Sort\n";
	cout << "//////////////////////////////\n";

	// Random array
	 p = gen_integerinorder(SIZE);		
	
	auto t_start = std::chrono::high_resolution_clock::now();
	insertion_sort(p,0,SIZE);	
	auto t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations: "<< p[0].count() << "\n\n";	
	p[0].reset();

	// Array in reverse order
	q = gen_reverse_integer(p, SIZE); 	

	t_start = std::chrono::high_resolution_clock::now();
	insertion_sort(q,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Reverse Order\n";
	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations: "<< q[0].count() << "\n\n";
	
	q[0].reset();	

	// Sorted Array
	r = gen_integerarray(SIZE,RANGE); 

	t_start = std::chrono::high_resolution_clock::now();
	insertion_sort(r,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Random\n";
	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations: "<< r[0].count() << '\n';
	r[0].reset(); 	
	//	a_print_integer(p,SIZE);	
	
	// Free up the memory
	delete[] p;
	delete[] q;
	delete[] r;

	cout << "//////////////////////////////\n";


	//////////////// QUICKSORT FIRST PIVOT ////////////////

	cout<<"\nQuicksort First Pivot\n"; 
	cout << "//////////////////////////////\n";

	// Random array
	  p = gen_integerinorder(SIZE);		

	t_start = std::chrono::high_resolution_clock::now();
	quick_sort_start(p,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations: "<< p[0].count() << "\n\n";
	p[0].reset();

	// Array in reverse order
	q = gen_reverse_integer(p, SIZE); 	

	t_start = std::chrono::high_resolution_clock::now();
	quick_sort_start(q,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations: "<< q[0].count() << "\n\n";
	q[0].reset();	

	// Sorted array
	r = gen_integerarray(SIZE,RANGE); 

	t_start = std::chrono::high_resolution_clock::now();
	quick_sort_start(r,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 


	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations: "<< r[0].count() << '\n';
	r[0].reset();
	//	a_print_integer(p,SIZE);
	
	// Free up the memory
	delete[] p;
	delete[] q;
	delete[] r;

	
	cout << "//////////////////////////////\n";


	//////////////// QUICKSORT  ////////////////

	cout<<"\nQuicksort\n";	
	cout << "//////////////////////////////\n";

	// Random
	  p = gen_integerinorder(SIZE);		

	t_start = std::chrono::high_resolution_clock::now();
	quick_sort(p,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations: "<< p[0].count() << "\n\n";

	p[0].reset();	

	// Reverse Order
	q = gen_reverse_integer(p, SIZE); 	

	t_start = std::chrono::high_resolution_clock::now();
	quick_sort(q,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Reverse Order\n";
	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations: "<< q[0].count() << "\n\n";

	q[0].reset();	

	// Sorted
	r = gen_integerarray(SIZE,RANGE); 

	t_start = std::chrono::high_resolution_clock::now();
	quick_sort(r,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 
	
	cout << "Sorted\n";
	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations "<< r[0].count() << '\n';

	r[0].reset();
	//	a_print_integer(p,SIZE);
	
	// Free up the memory
	delete[] p;
	delete[] q;
	delete[] r;

	
	cout << "//////////////////////////////\n";
	

	//////////////// QUICKSORT INPLACE ////////////////

	cout<<"\nQuicksort Inplace\n";	
	cout << "//////////////////////////////\n";

	// Random
	  p = gen_integerinorder(SIZE);		

	t_start = std::chrono::high_resolution_clock::now();
	quick_sort_inplace(p,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations: "<< p[0].count() << "\n\n";
	p[0].reset();

	// Reverse
	q = gen_reverse_integer(p, SIZE); 	
	
	t_start = std::chrono::high_resolution_clock::now();
	quick_sort_inplace(q,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Reverse Order\n";
	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations: "<< q[0].count() << "\n\n";
	q[0].reset();	

	// Sorted
	r = gen_integerarray(SIZE,RANGE); 

	t_start = std::chrono::high_resolution_clock::now();
	quick_sort_inplace(r,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations: "<< r[0].count() << '\n';
	r[0].reset();	
	
	// Free up the memory
	delete[] p;
	delete[] q;
	delete[] r;


	cout << "//////////////////////////////\n";

	//////////////// MERGESORT ////////////////

	cout<<"\nMergesort\n";	
	cout << "//////////////////////////////\n";

	// Random
	  p = gen_integerinorder(SIZE);		

	t_start = std::chrono::high_resolution_clock::now();
	mergeSort(p,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations "<< p[0].count() << "\n\n";
	p[0].reset();

	// Reverse
	q = gen_reverse_integer(p, SIZE); 	

	t_start = std::chrono::high_resolution_clock::now();
	mergeSort(q,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations "<< q[0].count() << "\n\n";
	q[0].reset();	

	// Sorted
	r = gen_integerarray(SIZE,RANGE); 

	t_start = std::chrono::high_resolution_clock::now();
	mergeSort(r,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations "<< r[0].count() << '\n';
	r[0].reset();	
//	a_print_integer(p,SIZE);
	
	// Free up the memory
	delete[] p;
	delete[] q;
	delete[] r;

	
	cout << "//////////////////////////////\n";


	//////////////// SELECTION SORT ////////////////

	cout<<"\nSelection Sort\n"; 
	cout << "//////////////////////////////\n";

	// Random
	  p = gen_integerinorder(SIZE);		

	t_start = std::chrono::high_resolution_clock::now();
	selection_sort(p,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations "<< p[0].count() << "\n\n";	
	p[0].reset();

	// Reverse
	q = gen_reverse_integer(p, SIZE); 	

	t_start = std::chrono::high_resolution_clock::now();
	selection_sort(q,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Reverse Order\n";
	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations "<< q[0].count() << "\n\n";
	q[0].reset();	

	// Sorted
	r = gen_integerarray(SIZE,RANGE); 

	t_start = std::chrono::high_resolution_clock::now();
	selection_sort(r,0,SIZE);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations "<< r[0].count() << "\n\n";
	r[0].reset(); 	
//	a_print_integer(p,SIZE);
	//	a_print_integer(p,SIZE);
	
	// Free up the memory
	delete[] p;
	delete[] q;
	delete[] r;

	

	cout<<"\nSTL sort algrithm\n"; 
	cout << "//////////////////////////////\n";

	// Random
	  p = gen_integerinorder(SIZE);		

	t_start = std::chrono::high_resolution_clock::now();
	std::sort(p, p+SIZE,comp_obj);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations "<< p[0].count() << "\n\n";	
	p[0].reset();

	// Reverse
	q = gen_reverse_integer(p, SIZE); 	

	t_start = std::chrono::high_resolution_clock::now();
	std::sort(q, q+SIZE,comp_obj);	
	t_end = std::chrono::high_resolution_clock::now(); 
//	a_print_integer(q,SIZE);
	cout << "Reverse Order\n";
	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations "<< q[0].count() << "\n\n";
	q[0].reset();	
	

	// Sorted
	r = gen_integerarray(SIZE,RANGE); 

	t_start = std::chrono::high_resolution_clock::now();
	std::sort(r, r+SIZE, comp_obj);	
	t_end = std::chrono::high_resolution_clock::now(); 

	cout << "Time taken: "<< std::chrono::duration<double, std::milli>(t_end - t_start).count() << "ms\n";
	cout<<"Operations "<< r[0].count() << "\n\n";
	r[0].reset(); 	
//	a_print_integer(p,SIZE);
	//	a_print_integer(p,SIZE);
	
	// Free up the memory
	delete[] p;
	delete[] q;
	delete[] r;

	return 0; 

}
 
