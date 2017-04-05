#include <iostream>
#include "algo.h"

using std::cout;

int main(){
	int a[10];
	
	a[0] = 20;
	a[1] = 3;
	a[2] = 100;
	a[3] = 6;
	a[4] = 2000;
	a[5] = 8;
	a[6] = 70;
	a[7] = 7;
	a[8] = 6000;
	a[9] = 54;

	int max = my_max_element(a, 0, 10, 9);

	cout << "ARRAY: ";
	for (int i=0; i<10; ++i)
		cout << a[i] << ' ';
	
	cout << "\nMAX: " << max << '\n';
}
