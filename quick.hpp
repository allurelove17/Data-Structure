#ifndef QUICK_HPP
#define QUICK_HPP

#include <iostream>
#include <algorithm>

template<class T>
class quick {
public:
	quick(int SIZE) {
		array = new T[SIZE];
	}
	void quick_sort(int, int);
	void print(int);
	int pivot(int, int);
	//void swap(T&, T&);
	T* array;
private:

};

#endif
