#ifndef INSERTION_HPP
#define INSERTION_HPP

#include <iostream>
#include <algorithm>

template<class T>
class insertion{
public:
	insertion(int SIZE) {
		array = new T[SIZE];
	}
	void insertion_sort(int);
	void print(int);
	T* array;
private:
	
};

#endif
