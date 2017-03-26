#include <iostream>
#include <cstdlib>

#include "Integer.h"

using std::cout;

int main(){
	Integer x1 = Integer(5);
	Integer x2 = Integer();
	Integer x3 = Integer(x1);
	Integer x4 = Integer(7);

	cout << "x1 should be 5: " << x1.value() << '\n';
	cout << "x2 should be 0: " << x2.value() << '\n';
	cout << "x3 should be 5: " << x3.value() << '\n';
	cout << "x4 should be 7: " << x4.value() << '\n';
	cout << "count should be 1: " << x1.count() << "\n\n";

	cout << "x1 < x2 should be 0: " << (x1 < x2) << '\n';
	cout << "x1 < x4 should be 1: " << (x1 < x4) << '\n';
	x1 = x2;
	cout << "x1 should now be 0: " << x1.value() << '\n';
	cout << "x3 should still be 5: " << x3.value() << '\n';
	cout << "Count should be 4: " << x4.count() << "\n\n";

	return 0;
}
