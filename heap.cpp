#include "heap.hpp"

/*template<class T>
void quick<T>::swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}*/

template<class T>
void heap<T>::print(int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << *(this->array + i) << ' ';
	}std::cout << '\n';
}

template<class T>
void heap<T>::maxheap(int root, int length) {
	int left = 2 * root, right = 2 * root + 1, max;
	T c;
	if (left <= length && *(this->array + left) > *(this->array + root))
		max = left;
	else
		max = root;
	if (right <= length && *(this->array + right) > *(this->array + max))
		max = right;
	if (max != root) {
		c = *(this->array + root);
		*(this->array + root) = *(this->array + max);
		*(this->array + max) = c;
		maxheap(max, length);
	}
}

template<class T>
void heap<T>::build(int size) {
	for (int i = size / 2; i >= 1; --i) {
		maxheap(i, size - 1);
	}
}

template<class T>
void heap<T>::heap_sort(int size) {
	T c;
	*(this->array) = 0;

	build(size);

	int len = size - 1;
	for (int i = size - 1; i >= 2; --i) {
		c = *(this->array + 1);
		*(this->array + 1) = *(this->array + i);
		*(this->array + i) = c;
		--len;
		maxheap(1, len);
	}
	for (int i = 0; i < size - 1; i++) {
		*(this->array + i) = *(this->array + i + 1);
	}
}

template class heap<int>;