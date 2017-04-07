#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include "algo.h"


using std::cout;



template <class T>
void quick_sort(const T a, int start, int stop){


	if( stop - start > 1){
	//	a_print(a,stop);	
		int pivot = start + rand() % (stop - start);			
		partition_inplace( a , start, stop, pivot);	
		quick_sort( a , start, pivot);
		quick_sort( a , pivot + 1, stop);
	}
	return; 

}




int main (){


	int a[10] = {12 , 13, 14, 15, 16, 72, 73, 80, 100, 210};

	a_print(a,10);	

	quick_sort(a,0,10);
	
	a_print(a,10);





}

