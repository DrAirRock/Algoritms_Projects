//Test Drivers


#include "Map.h"

#include <iostream>

using std::cout;
using std::endl;


int main(){
	Map<int, char> mp;

	mp.insert(15, 'o');
	mp.insert(20, 't');
	mp.insert(1, 'a');
	mp.insert(2, 'b');
	mp.insert(22, 'v');
	mp.insert(7, 'g');
	mp.insert(14, 'n');
	mp.insert(25, 'y');
	mp.insert(4, 'd');
	mp.insert(26, 'z');
	mp.insert(5, 'e');
	mp.insert(10, 'j');
	mp.insert(23, 'w');
	mp.insert(8, 'h');
	mp.insert(6, 'f');
	mp.insert(11, 'k');
	mp.insert(12, 'l');
	mp.insert(21, 'u');
	mp.insert(16, 'p');
	mp.insert(17, 'q');
	mp.insert(9, 'i');
	mp.insert(13, 'm');
	mp.insert(18, 'r');
	mp.insert(19, 's');
	mp.insert(3, 'c');
	mp.insert(24, 'x');
/*
	mp.erase(24);
	mp.erase(15);
	mp.erase(22);
	mp.erase(9);
	mp.erase(16);
	mp.erase(3);
*/
    //mp.printTree();
    //mp.clear();
/*
	mp.insert(15, 'o');
	mp.erase(20);
	mp.insert(9, 'i');


    mp.clear();
    cout<<"is tree empty: "<< mp.empty() << "\n";
	//mp.printTree();
	mp.insert(19, 's');
	mp.insert(3, 'c');
	mp.insert(24, 'x');
    cout<<"is tree empty: "<< mp.empty() << "\n";
*/
    //mp.printTree();

	Iterator<int, char> itr = mp.begin();
	Iterator<int, char> endItr = mp.end();

	while (1){
		if (itr == endItr)
			break;

		auto p = *itr;
		cout << p->first << ' ' << p->second << '\n';
		++itr;
	}


	return 0;


}

