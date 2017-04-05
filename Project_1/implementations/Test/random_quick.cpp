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
		partition( a , pivot, start , stop);	
	return 	quick_sort( a , start, pivot);
	return 	quick_sort( a , pivot + 1, stop);
	}
	return; 

}




int main (){


	int a[7] = {60 , 12, 37, 42, 25, 38, 16};
	a_print(a,7);	
	quick_sort(a,0,7);
	a_print(a,7);



	/*int *p ; 
	p = gen_intarray(SIZE,RANGE);
	quick_sort(p,0,SIZE);
	a_print(p,SIZE);
	return 0;  */


}

