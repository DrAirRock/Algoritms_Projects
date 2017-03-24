#include <iostream> 
//#include <algrithm> 
#include "algo.h"

//using namespace std; 


template<class T> 
void insertion_sort(const T a, int i, int j){ 
	//insert a[k] into a[i..k) 
	std::cout << i;
	std::cout << j;
	int k,x,p;	
	k = i + 1;

	for ( k ; k <= (j - 1); k++){
		x = a[k]; 
		p = k-1; 
		while( p >= i && x < a[p] ){ 
			a[p+1] = a[p];	
			a_print(a,j);
			--p;	
		}
		a[p+1] = x;
		a_print(a,j);
	}
}

/*template <class T> 
void  a_print(const T array[], int size){ 
	
	for(int i = 0; i < size  ; i++){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}
*/

int main (){
	
	int a[7] = {60 , 12, 37, 42, 25, 38, 16};
	a_print(a,7);	
	insertion_sort(a,0,7);
	a_print(a,7);
	return 0; 

}
 
