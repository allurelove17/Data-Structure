//#include "Merge.hpp"

/*template<class T>
void quick<T>::swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}*/
/*
template<class T>
void Merge<T>::print(int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << *(this->array + i) << ' ';
	}std::cout << '\n';
}

template<class T>
void Merge<T>::merge(int left, int mid, int right) {
	std::vector<T> leftsub(this->array + left, this->array + mid + 1),
		rightsub(this->array + mid + 1, this->array + right + 1);
	leftsub.push_back(INT_MAX);
	rightsub.push_back(INT_MAX);

	int left_ind = 0, right_ind = 0;

	for (int i = left; i <= right; ++i) {
		if (leftsub[left_ind] <= rightsub[right_ind]) {
			*(this->array + i) = leftsub[left_ind];
			left_ind++;
		}
		else {
			*(this->array + i) = rightsub[right_ind];
			right_ind++;
		}
	}
}

template<class T>
void Merge<T>::merge_sort(int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}

template class Merge<int>;*/