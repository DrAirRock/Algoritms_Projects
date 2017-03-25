#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include "algo.h"
//fix this 
using namespace std;



template <class T>
void quick_sort(const T a, int start, int stop){


	if( stop - start >= 2){
		int pivot = start + rand() % (stop - start);			
		partition( a , pivot, stop, stop);	
		quick_sort( a , start, pivot);
		quick_sort( a , pivot + 1, stop);
	}
	return; 

}




int main (){
	
	int a[7] = {60 , 12, 37, 42, 25, 38, 16};
	a_print(a,7);	
	quick_sort(a,1,7);
	a_print(a,7);
	return 0; 

}

