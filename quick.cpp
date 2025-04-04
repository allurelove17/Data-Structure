#include "quick.hpp"

/*template<class T>
void quick<T>::swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}*/

template<class T>
void quick<T>::print(int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << *(this->array + i) << ' ';
	}std::cout << '\n';
}

template<class T>
int quick<T>::pivot(int left, int right) {
	int p = *(this->array + right), i = left - 1, j = left;
	T c;
	while (j < right) {
		if (*(this->array + j) < p) {
			++i;
			//swap((this->array + i), (this->array + j));
			c = *(this->array + i);
			*(this->array + i) = *(this->array + j);
			*(this->array + j) = c;
			
		}
		++j;
	}
	++i;
	//swap((this->array + i), (this->array + right));
	c = *(this->array + i);
	*(this->array + i) = *(this->array + right);
	*(this->array + right) = c;
	return i;
}

template<class T>
void quick<T>::quick_sort(int left, int right) {
	if (left < right) {
		int p = pivot(left, right);
		quick_sort(left, p - 1);
		quick_sort(p + 1, right);
	}
}

template class quick<int>;