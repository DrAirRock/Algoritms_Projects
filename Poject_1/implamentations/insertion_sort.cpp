#include <iostream> 
#include "algo.h"


template<class T> 
void insertion_sort(const T a, int i, int j){ 
	//insert a[k] into a[i..k) 
	int k,x,p;	
	k = i + 1;

	for ( k ; k <= (j - 1); k++){
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
	a_print(p,SIZE);
	return 0; 

}
 
