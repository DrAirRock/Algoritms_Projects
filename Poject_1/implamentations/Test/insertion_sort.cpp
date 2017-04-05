#include <iostream> 
#include "algo.h"


template <class T>
void quick_sort_inplace(const T a, int start, int stop){


	if( stop - start > 1){
	//	a_print(a,stop);	
		int pivot = start + rand() % (stop - start);			
		partition_inplace( a , start, stop, pivot);	
		quick_sort_inplace( a , start, pivot);
		quick_sort_inplace( a , pivot + 1, stop);
	}
	return; 

}



template<class T> 
void insertion_sort(const T a, int i, int j){ 
	//insert a[k] into a[i..k) 
	int k,x,p;	
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


int main (){
	
	int *p; 
	
	
	
	p = gen_intarray(SIZE,RANGE);		
	insertion_sort(p,0,SIZE);
	cout<<"insertion sort\n"; 
	//	a_print(p,SIZE);


	p = gen_intarray(SIZE,RANGE);		
	quick_sort_inplace(p,0,SIZE); 
	cout<<"quick in place\n"; 	
	
	
	
	return 0; 




	
}
 
