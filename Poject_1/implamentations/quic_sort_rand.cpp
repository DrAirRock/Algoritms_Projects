#include <iostream>
#include <cstdlib>
#include "algo.h"
//#include <algorithm>
#include <utility>
using namespace std;
//solutions 

template<class T> 
void Swap_t(T a, T s , T  p){ 
	T temp[1];
	temp[0] = a[s]; 
	a[s] = a[p]; 
	a[p] = temp[0];

}

/*
template<class T> 
void partition(T a, int p, int start , int stop){ 
	
	a_print(a,stop);
	//you only care to move theings to the left of the piviot 
	cout<<"partion"; 
	int j = p + 1;	
	for(int i = p+1; i < stop; i++){ 
		if( a[i] < a[p]){
			j++;
			Swap_t(a,i,j);
			cout<<"\nHELLO\n";	
		}	
	
	}
}
*/


template <class T>
void quick_sort(T a[], int start, int stop){

	cout<<"in quicksort";
	
	if( stop - start >= 1){
		int pivot = start + rand() % (stop - start);			
		cout<<"\npivot:" << pivot << endl;	
	
	 	a_print(a,stop);
		partition( a , pivot, stop, stop);	 
		quick_sort( a , start, pivot);
		quick_sort( a , pivot + 1, stop);
	
		
	}
	
	cout<<"END\n";
	//return; 

}





int main (){
	
	int a[7] = {60 , 12, 37, 42, 25, 38, 16};
	a_print(a,7);	
	quick_sort(a,0,7);
	cout<< "hello";	
	a_print(a,7);

	return 0;
}

