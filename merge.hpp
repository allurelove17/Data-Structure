#ifndef MERGE_HPP
#define MERGE_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template<class T>
class Merge {
public:
	Merge(int SIZE) {
		array = new T[SIZE];
	}
	void merge_sort(int, int);
	void merge(int, int, int);
	void print(int);
	T* array;
private:

};

#endif
