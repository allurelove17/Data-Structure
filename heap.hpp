#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template<class T>
class heap {
public:
	heap(int SIZE) {
		array = new T[SIZE];
	}
	void maxheap(int, int);
	void build(int);
	void heap_sort(int);
	void print(int);
	T* array;
private:

};

#endif
