#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
using namespace std;
//solutions 

template<class T> 
void partition(T a[], int pivot, int start, int stop){
	
	swap( a[pivot] , a[start]);
		//moves pivio to the start 
	T * temp = new T[stop - start];  //dynamicaly allocate array name 
	int k = 0; //next avalible postition in temp 
	for( int i = start + 1; i < stop; i++){ 

		if(a[i] <= pivot){
			temp[k] = a[i]; //taking everything less than the pivot and setting it to temp 	
			++k;
		}
	}
	temp[k] = a[start]; //start is the piviot 
	pivot = start + k; //final index in the array
	++k;

	for( int i = start + 1; i < stop; ++i){
		if (!(a[i] < a[start])){
			temp[k]  = a[i];
			++k;
		}
	}
	copy(temp, temp + k, a + start); 
	delete temp; 



}

template <class T>
void quick_sort( const T a[], int start, int stop){


	if( stop - start >= 2){
		int pivot = start + rand() % (stop - start);			
		partition( a , pivot, stop, stop);	
		quick_sort( a , start, pivot);
		quick_sort( a , pivot + 1, stop);
	}
	return; 

}



template <class T> 
void  a_print(const T array[], int size){ 
	
	for(int i = 0; i < size  ; i++){
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}


int main (){
	
	int a[7] = {60 , 12, 37, 42, 25, 38, 16};
	a_print(a,7);	
	quick_sort(a,0,7);
	a_print(a,7);
	return 0; 

}

