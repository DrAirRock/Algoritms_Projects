#ifndef _Integer_h_
#define _Integer_h_

#include <iostream>

// Global variable used for counting
// the number of comparisons or copying performed
unsigned int Integer_count = 0;

class Integer{
	private:
		// Actual number value of the object
		int value_;
	
	public:
		// Constructors

		Integer() : value_(0) {}
		Integer(int x) : value_(x) {}
			// NOTE: below adds 1 to Integer_count
		Integer(const Integer &x);

		// Methods and Comparators

		// Returns the value associated with this object
		int value() const { return value_;}

		// Returns the count which is just the global Integer_count
		int count() const { return Integer_count;}
		
		// Resets the count to 0
		void reset() { Integer_count = 0; }


		// Comparison operator <
		// Returns true if value of Integer on the left
		// is less than the value of the Integer on the
		// right
		// NOTE: Adds 1 to Integer_count
		bool operator<(const Integer &x);

		// Assignment operator =
		// Sets value of Integer on the left to
		// be equal to value on the right
		// NOTE: Adds 1 to Integer_count
		void operator=(const Integer &x);
};


// Implementation of copy constructor
inline Integer::Integer(const Integer &x){

	value_ = x.value();
	++Integer_count;

}


//Implementation of operator <
inline bool Integer::operator<(const Integer &x){
	
	++Integer_count;
	return (value_ < x.value());

}


//Implementation of operator =
inline void Integer::operator=(const Integer &x){

	++Integer_count;
	value_ = x.value();

}


#endif
