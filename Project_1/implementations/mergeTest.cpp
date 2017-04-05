#include <iostream>
#include "mergeSort.h"

using std::cout;

int main(){
	int a[2];

	a[0] = 12;
	a[1] = 6;

	for (int i=0; i<2; ++i)
		cout << a[i] << ' ';
	cout << "\n\n";

	mergeSort(a, 0, 2);

	for (int i=0; i<2; ++i)
		cout << a[i] << ' ';
	cout << '\n';
}	

