#include <iostream> 
#include "algo.h"

using std::cout; 


int main(){ 
/*
	int * p; 
	int size = 100000, range = 5;
	p = gen_intarray(size , range); 
	a_print(p,size);
*/

	int a[10];
	a[0] = 17;
	a[1] = 72;
	a[2] = 13;
	a[3] = 0;
	a[4] = 52;
	a[5] = 100;
	a[6] = 2;
	a[7] = 1;
	a[8] = 63;
	a[9] = 50;

	int pivot = 4;

	cout << "Before partition:\n";
	for(int i=0; i<10; i++)
		cout << a[i] << '\n';
	
	cout << "\nPivot: " << a[pivot] << "\n\n";

	partition(a, 0, 10, pivot);

	cout << "After partition:\n";
	for(int i=0; i<10; i++)
		cout << a[i] << '\n';


	return 0; 
}
