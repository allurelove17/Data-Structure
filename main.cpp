#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <chrono>
#include "insertion.hpp"
#include "quick.hpp"
#include "Merge.hpp"
#include "heap.hpp"
#include "permutation.hpp"

int main() {
	int n = 500;
	Permutation<int> generate_data(n);
	//generate_data.permutation(n);
	//std::vector<int> vec;
	
	insertion<int> arr_insertion(n);
	quick<int> arr_quick(n);
	Merge<int> arr_merge(n);
	heap<int> arr_heap(n);
	std::ifstream ifs("test.txt", std::ios::in);
	
	std::stringstream ss;
	ss << ifs.rdbuf();
	int x, ind = 0;
	while (true) {
		ss >> x;
		if (ss.fail()) break;
		arr_insertion.array[ind] = x;
		arr_merge.array[ind] = x;
		arr_heap.array[ind] = x;
		arr_quick.array[ind++] = x;
	}
	//arr_insertion.print(n);
	//arr_quick.print(n);
	auto start = std::chrono::steady_clock::now();
	clock_t tStart = clock();
	//arr_insertion.insertion_sort(n);
	//arr_merge.merge_sort(0, n - 1);
	arr_heap.heap_sort(n);
	auto end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration<double, std::milli>(end - start).count() << "ms\n";
	//std::cout << std::setprecision(1000) << "Time taken: " << (double)((clock() - tStart) / CLOCKS_PER_SEC) << '\n';
	arr_heap.print(n);

	tStart = clock();
	arr_quick.quick_sort(0, n - 1);
	end = std::chrono::steady_clock::now();
	std::cout << std::chrono::duration<double, std::milli>(end - start).count() << "ms\n";
	//arr_quick.print(n);
}