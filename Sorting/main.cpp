#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <chrono>
#include "insertion.hpp"
#include "quick.hpp"
#include "Merge.hpp"
#include "heap.hpp"
#include "permutation.hpp"

int main() {
	std::ofstream WorstCaseResults("sorting_worstcase.csv");
	std::vector<int> sizes = { 500, 1000, 2000, 3000, 4000, 5000 };
	//std::vector<int> sizes = { 5000 };
	// WORST CASE
	for (auto size : sizes) {
		Worst_Permutation<int> generate_data(size);
		//generate_data.permutation(n);
		//std::vector<int> vec;

		insertion<int> arr_insertion(size);
		quick<int> arr_quick(size);
		Merge<int> arr_merge(size);
		heap<int> arr_heap(size);
		//std::ifstream ifs("test.txt", std::ios::in);
		std::ifstream worstinserifs("worstinser.txt", std::ios::in);
		std::ifstream worstmergeifs("worstmerge.txt", std::ios::in);

		for (int i = 0; i < size; ++i) {
			arr_insertion.array[i] = size - i;
		}

		std::stringstream ss_inser, ss_merge;
		ss_inser << worstinserifs.rdbuf();
		ss_merge << worstmergeifs.rdbuf();
		worstinserifs.close();
		worstmergeifs.close();
		int x, ind = 0;

		while (true) {
			ss_merge >> x;
			if (ss_merge.fail())break;
			arr_merge.array[ind++] = x;
		}

		ind = 0;
		while (true) {
			ss_inser >> x;
			if (ss_inser.fail()) break;
			//arr_insertion.array[ind] = x;
			//arr_merge.array[ind] = x;
			arr_heap.array[ind] = x;
			arr_quick.array[ind++] = x;
		}
		double insertion_time = arr_insertion.insertion_sort(size);
		//arr_insertion.print(size);
		double quick_time = arr_quick.quicktime(0, size - 1);
		//arr_quick.print(size);
		double merge_time = arr_merge.mergetime(0, size - 1);
		//arr_merge.print(size);
		double heap_time = arr_heap.heap_sort(size);
		//arr_heap.print(size);
		WorstCaseResults << size << ","
			<< insertion_time << ","
			<< quick_time << ","
			<< merge_time << ","
			<< heap_time << '\n';
	}
}