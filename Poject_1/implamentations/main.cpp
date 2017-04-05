#include <iostream>
#include <cstdlib>
#include "algo.h"

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
;
		while( p >= i && x < a[p] ){ 
			a[p+1] = a[p];	
			--p;	
		}
	
		a[p+1] = x;
	}
}

template<class T> 
void selection_sort(const T a, int start , int stop){ 


	if((stop - start) >= 2){ 
	
	//	cout << "hll";	
//		int rank = stop; 

//		int k = my_max_element(a , start, stop, rank); 
		
		int k = my_max(a , start, stop ); 
		std::swap(a[k] , a[stop - 1]);

		selection_sort(a,start,stop-1);

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

	cout<<"insertion sort\n"; 
	p = gen_integerarray(SIZE,RANGE);		
	insertion_sort(p,0,SIZE);	
	cout<<"opertarions; "<< p[0].count() << "\n";	
	p[0].reset();
	q = gen_reverse_integer(p, SIZE); 	
	insertion_sort(q,0,SIZE);	
	cout<<"opertarions; "<< q[0].count() << "\n";
	q[0].reset();	
	r =  gen_integerinorder(SIZE); 
	insertion_sort(r,0,SIZE);	
	cout<<"opertarions; "<< r[0].count() << "\n";
	r[0].reset(); 	
	//	a_print_integer(p,SIZE);

	cout<<"quick first piviot\n"; 
	p = gen_integerarray(SIZE,RANGE);		
	quick_sort_start(p,0,SIZE);	
	cout<<"opertarions; "<< p[0].count() << "\n";
	p[0].reset();
	q = gen_reverse_integer(p, SIZE); 	
	quick_sort_start(q,0,SIZE);	
	cout<<"opertarions; "<< q[0].count() << "\n";
	q[0].reset();	
	r =  gen_integerinorder(SIZE); 
	quick_sort_start(r,0,SIZE);	
	cout<<"opertarions; "<< r[0].count() << "\n";
	r[0].reset();
	//	a_print_integer(p,SIZE);

	cout<<"quick\n";	
	p = gen_integerarray(SIZE,RANGE);		
	quick_sort(p,0,SIZE);	
	cout<<"opertarions; "<< p[0].count() << "\n";
	p[0].reset();	
	q = gen_reverse_integer(p, SIZE); 	
	quick_sort(q,0,SIZE);	
	cout<<"opertarions; "<< q[0].count() << "\n";
	q[0].reset();	
	r =  gen_integerinorder(SIZE); 
	quick_sort(r,0,SIZE);	
	cout<<"opertarions; "<< r[0].count() << "\n";
	r[0].reset();
	//	a_print_integer(p,SIZE);
	
	cout<<"quick sort inplace\n";	
	p = gen_integerarray(SIZE,RANGE);		
	quick_sort_inplace(p,0,SIZE);	
	cout<<"opertarions; "<< p[0].count() << "\n";
	p[0].reset();
	q = gen_reverse_integer(p, SIZE); 	
	quick_sort_inplace(q,0,SIZE);	
	cout<<"opertarions; "<< q[0].count() << "\n";
	q[0].reset();	
	r =  gen_integerinorder(SIZE); 
	quick_sort_inplace(r,0,SIZE);	
	cout<<"opertarions; "<< r[0].count() << "\n";
	r[0].reset();	

	cout<<"quick sort inplace\n";	
	p = gen_integerarray(SIZE,RANGE);		
	mergeSort(p,0,SIZE);	
	cout<<"opertarions; "<< p[0].count() << "\n";
	p[0].reset();
	q = gen_reverse_integer(p, SIZE); 	
	mergeSort(q,0,SIZE);	
	cout<<"opertarions; "<< q[0].count() << "\n";
	q[0].reset();	
	r =  gen_integerinorder(SIZE); 
	mergeSort(r,0,SIZE);	
	cout<<"opertarions; "<< r[0].count() << "\n";
	r[0].reset();	
//	a_print_integer(p,SIZE);

	cout<<"selection sort\n"; 
	p = gen_integerarray(SIZE,RANGE);		
	selection_sort(p,0,SIZE);	
	cout<<"opertarions; "<< p[0].count() << "\n";	
	p[0].reset();
	q = gen_reverse_integer(p, SIZE); 	
	selection_sort(q,0,SIZE);	
	cout<<"opertarions; "<< q[0].count() << "\n";
	q[0].reset();	
	r =  gen_integerinorder(SIZE); 
	selection_sort(r,0,SIZE);	
	cout<<"opertarions; "<< r[0].count() << "\n";
	r[0].reset(); 	
	a_print_integer(p,SIZE);
	//	a_print_integer(p,SIZE);

	
	
	
	return 0; 




	
}
 
