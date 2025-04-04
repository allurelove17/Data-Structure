#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

template<class T>
class Permutation {
public:
	void permutation(int);
	Permutation(int n) {
		srand(time(NULL));
		std::ofstream ofs;
		ofs.open("test.txt");
		if (!ofs.is_open()) {
			std::cout << "Failed to open file!\n";
		}
		for (int i = 0; i < n; ++i) {
			int x = rand() % INT_MAX;
			ofs << x << ' ';
		}
		ofs.close();
	}
};