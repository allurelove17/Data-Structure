#include "insertion.hpp"

template<class T>
void insertion<T>::print(int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << *(this->array + i) << ' ';
	}std::cout << '\n';
}

template<class T>
void insertion<T>::insertion_sort(int size) {
	for (int i = 1; i < size; ++i) {
		int value = *(this->array + i), j;
		for (j = i - 1; j >= 0 && value < *(this->array + j); --j) {
			if (value < *(this->array + j))
				*(this->array + j + 1) = *(this->array + j);
		}
		*(this->array + j + 1) = value;
	}
}

template class insertion<int>;