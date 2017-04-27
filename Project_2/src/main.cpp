//Test Drivers


#include "Map.h"

#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

class Integer{
	private:
		int value_;
	
	public:
		Integer(){value_ = 0;}
		Integer(const int &x){value_ = x;}
		Integer(const Integer &x){value_ = x.value_;}

		bool operator<(const Integer &x){return value_ < x.value_;}
		void operator=(const Integer &x){value_ = x.value_;}
		void operator=(const int &x){value_ = x;}

		friend ostream& operator<<(ostream& os, const Integer &x);
};

ostream &operator<<(ostream &out, const Integer &x){
	out << x.value_;
	return out;
}


template <class K, class V>
void printItr(Map<K, V> &mp){

	auto endItr = mp.end();
	for (auto itr = mp.begin(); itr != endItr; ++itr){
		auto p = *itr;
		cout << p->first << ' ' << p->second << '\n';
	}
	cout << "Size: " << mp.size() << "\n\n";
}


int main(){
	Map<Integer, char> mp;

	Integer i7(7);

	mp[Integer(3)] = 'c';
	mp[Integer(5)] = 'e';
	mp[Integer(6)] = 'f';
	mp[Integer(2)] = 'b';
	mp[i7] = 'h';
	mp[Integer(4)] = 'd';
	mp[Integer(1)] = 'a';

	mp[i7] = 'g';

	//mp.printTree();
	Map<Integer, char> mp2(mp);	
	mp.clear();

	mp[24] = 'R';



	cout << "BEFORE:\n";
	printItr(mp);
	printItr(mp2);

	mp2.swap(mp);

	cout << "AFTER:\n";
	printItr(mp);
	printItr(mp2);
/*
	cout << mp2.erase(3) << '\n';

	printItr(mp2);

	auto itr = mp2.find(Integer(4));
	itr = mp2.erase(itr);

	auto p = *itr;
	cout << p->first << ' ' << p->second << "\n\n";

	printItr(mp2);

	itr = mp2.end();
	mp2.erase(itr);

	printItr(mp2);

	cout << mp2.empty() << '\n';

*/

	return 0;


}
