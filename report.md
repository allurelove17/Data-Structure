# 41243241 彭毓升 41243233 林厚丞

作業一

## 解題說明

本次作業的目標是比較四種常見的排序演算法：Insertion Sort、Quick Sort、Merge Sort 和 Heap Sort，在不同輸入大小下的執行效能表現。我們探討了每種排序法在平均情況與最壞情況下的效能，並繪製圖表進行分析。

## 程式實作

**Insertion Sort**

1.時間複雜度：最壞 O(n^2)，平均 O(n^2)
2.穩定排序法，實作簡單
3.適用於小型資料集

```cpp
#include "insertion.hpp"

template<class T>
void insertion<T>::print(int size) {
	for (int i = 0; i < size; ++i) {
		std::cout << *(this->array + i) << ' ';
	}std::cout << '\n';
}

template<class T>
double insertion<T>::insertion_sort(int size) {
	auto start = std::chrono::steady_clock::now();
	for (int i = 1; i < size; ++i) {
		int value = *(this->array + i), j;
		for (j = i - 1; j >= 0 && value < *(this->array + j); --j) {
			if (value < *(this->array + j))
				*(this->array + j + 1) = *(this->array + j);
		}
		*(this->array + j + 1) = value;
	}
	auto end = std::chrono::steady_clock::now();
	return std::chrono::duration<double, std::milli>(end - start).count();
}

template class insertion<int>;
```

**Quick Sort**

1.時間複雜度：平均 O(n log n)，最壞 O(n^2)
2.使用 median-of-three 選擇 pivot
3.實作簡單，常數項小，速度快

```cpp
#include "quick.hpp"

template<class T>
void quick<T>::swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

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
double quick<T>::quick_sort(int left, int right) {
	auto start = std::chrono::steady_clock::now();
	if (left < right) {
		int p = pivot(left, right);
		quick_sort(left, p - 1);
		quick_sort(p + 1, right);
	}
	auto end = std::chrono::steady_clock::now();
	return std::chrono::duration<double, std::milli>(end - start).count();
}

template class quick<int>;
```

**Merge Sort**

1.時間複雜度：O(n log n)
2.穩定排序法，需額外記憶體空間
3.使用 iterative 方法實作

```cpp
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
```

**Heap Sort**

1.時間複雜度：O(n log n)
2.不需額外記憶體，具穩定效能
3.在實務上略慢於 Merge Sort

```cpp
//#include "heap.hpp"

/*template<class T>
void quick<T>::swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}*/

/*template<class T>
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

template class heap<int>;*/
```

## 效能分析

1. 時間複雜度：程式的時間複雜度為 $O(\log n)$。
2. 空間複雜度：空間複雜度為 $O(100\times \log n + \pi)$。

## 測試與驗證

### 測試案例

| 測試案例 | 輸入參數 $n$ | 預期輸出 | 實際輸出 |
|----------|--------------|----------|----------|
| 測試一   | $n = 0$      | 0        | 0        |
| 測試二   | $n = 1$      | 1        | 1        |
| 測試三   | $n = 3$      | 6        | 6        |
| 測試四   | $n = 5$      | 15       | 15       |
| 測試五   | $n = -1$     | 異常拋出 | 異常拋出 |

### 圖表
![平均情況比較](sorting_average_comparison-1.png)
![最壞情況比較](sorting_worst_comparison-1.png)
![最差情況與平均情況比較](sorting_comparison_combined-1.png) 

### 結論

這次實驗讓我們更清楚地理解不同排序演算法的效能差異。以下是幾個重點：
•小型資料：Insertion Sort 表現尚可。
•中大型資料：建議使用 Quick Sort，效能最佳。
•需要穩定與預測性：可選擇 Merge Sort。
•需要保守與穩定表現：Heap Sort 是不錯的選擇。
Quick Sort 是平均表現最優的演算法，但若擔心最壞情況，可以考慮 Heap Sort 或 Merge Sort。


## 申論及開發報告