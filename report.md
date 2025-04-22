# 41243241 彭毓升 41243233 林厚丞

作業一 sorting

## 解題說明

本次作業的目標是比較四種常見的排序演算法：Insertion Sort、Quick Sort、Merge Sort 和 Heap Sort，在不同輸入大小下的執行效能表現。每種排序法在平均情況與最壞情況下的效能，並繪製圖表進行分析。


## 實驗與測量方式

1.	使用 C++ 撰寫程式，並搭配 chrono 測量時間（單位為毫秒）。
2.	每種演算法對固定大小的資料進行排序，n 從 500 開始，逐漸增加至 5000。
3.	平均情況下，資料為隨機排列；最壞情況依照各演算法特性產生。
	-Insertion Sort 使用反向排序資料。
	-Quick Sort 設計成左右極不平衡的分割。
	-Merge Sort 使用特製資料使合併次數最大。
	-Heap Sort 則使用多組隨機資料，取最大值模擬最差情況。

## 程式實作


**Insertion Sort**

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

```cpp
#include "Merge.hpp"

template<class T>
void quick<T>::swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

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

template class Merge<int>;
```

**Heap Sort**

```cpp
#include "heap.hpp"

template<class T>
void quick<T>::swap(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

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
```

## 效能分析

排序演算法的效能可以從以下兩個角度來分析：時間複雜度與空間複雜度。

**時間複雜度比較**

| 演算法 | 最佳情況| 平均情況 | 最壞情況 |
|----------|--------------|----------|----------|
| Insertion Sort   | O(n)     | O(n²)        | O(n²)       |
| Quick Sort   | O(n log n)      | O(n log n)        | O(n²)         |
| Merge Sort   | O(n log n)     | O(n log n)        | O(n log n)        |
| Heap Sort  | O(n log n)     | O(n log n)       | O(n log n)     |


## 測試與驗證





### 測試案例

| 測試案例 | 輸入參數 $n$ | 預期輸出 | 實際輸出 |
|----------|--------------|----------|----------|
| 測試一   | 0      | 0        | 0        |
| 測試二   | 0      | 1        | 1        |
| 測試三   |0    | 6        | 6        |
| 測試四   | 0    | 15       | 15       |
| 測試五   | 0   | 0|  0|

### 圖表

![平均情況比較](https://github.com/allurelove17/Data-Structure/blob/main/Sorting/sorting_average_comparison.png)
![最壞情況比較](https://github.com/allurelove17/Data-Structure/blob/main/Sorting/sorting_worst_comparison.png)
![最差情況與平均情況比較](https://github.com/allurelove17/Data-Structure/blob/main/Sorting/sorting_comparison_combined.png) 



### 結論

這次實驗讓我們更清楚地理解不同排序演算法的效能差異。以下是幾個重點：
•小型資料：Insertion Sort 表現尚可。
•中大型資料：建議使用 Quick Sort，效能最佳。
•需要穩定與預測性：可選擇 Merge Sort。
•需要保守與穩定表現：Heap Sort 是不錯的選擇。
Quick Sort 是平均表現最優的演算法，但若擔心最壞情況，可以考慮 Heap Sort 或 Merge Sort。



## 申論及開發報告