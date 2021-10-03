#include <iostream>
#include <chrono>
#include <vector>
#include <random>
#include <functional>

#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"

using namespace std::chrono;


template<typename T>
bool IsArraySorted(const T& array, size_t size) {
	bool sorted = true;

	for (size_t i = 0; i < (size - 1); i++) {
		if (array[i] > array[i + 1]) {
			sorted = false;
			break;
		}
	}
	
	return sorted;
}

template<typename T>
void TestSortingAlgo(std::function<void(std::vector<T>&, size_t)> sorting_func, std::vector<T> array) {
	steady_clock::time_point start, end;
	milliseconds random_dur, sorted_dur, reverse_dur;

	// random
	start = steady_clock::now();
	sorting_func(array, array.size());
	end = steady_clock::now();
	random_dur = duration_cast<milliseconds>(end - start);
	if (!IsArraySorted(array, array.size()))
		throw std::exception("Array wasn't sorted.");

	// sorted
	start = steady_clock::now();
	sorting_func(array, array.size());
	end = steady_clock::now();
	sorted_dur = duration_cast<milliseconds>(end - start);
	if (!IsArraySorted(array, array.size()))
		throw std::exception("Array wasn't sorted.");

	// reverse
	std::reverse(array.begin(), array.end());
	start = steady_clock::now();
	sorting_func(array, array.size());
	end = steady_clock::now();
	reverse_dur = duration_cast<milliseconds>(end - start);
	if (!IsArraySorted(array, array.size()))
		throw std::exception("Array wasn't sorted.");

	std::cout << "Random: " << random_dur.count() << "ms | ";
	std::cout << "sorted: " << sorted_dur.count() << "ms | ";
	std::cout << "reverse sorted: " << reverse_dur.count() << "ms";
	std::cout << std::endl << std::endl;
}

int main() {
	std::random_device rd;
	std::mt19937 eng{ rd() };
	std::uniform_int_distribution<int> int_dist{ -10000, 10000 };
	std::uniform_real_distribution<double> double_dist{ -1.0, 1.0 };

	auto int_gen = [&int_dist, &eng]() -> int {
		return int_dist(eng);
	};

	auto double_gen = [&double_dist, &eng]() -> double {
		return double_dist(eng);
	};


	std::vector<int> int_vector(10000);
	std::vector<double> double_vector(10000);

	std::generate(int_vector.begin(), int_vector.end(), int_gen);
	std::generate(double_vector.begin(), double_vector.end(), double_gen);

	// int arrays test
	std::function<void(std::vector<int>&, size_t)> int_sorting_func;
	std::pair<const char*, std::function<void(std::vector<int>&, size_t)>> int_tests[] = {
		{"[Bubble sort]", BubbleSort<std::vector<int>>},
		{"[Selection sort]", SelectionSort<std::vector<int>>},
		{"[Insertion sort]", InsertionSort<std::vector<int>>},
		{"[Merge sort]", MergeSort<int>},
		{"[Heap sort]", HeapSort<std::vector<int>>},
		{"[Quick sort]", QuickSort<int>},
	};

	// double arrays test
	std::function<void(std::vector<double>&, size_t)> double_sorting_func;
	std::pair<const char*, std::function<void(std::vector<double>&, size_t)>> double_tests[] = {
		{"[Bubble sort]", BubbleSort<std::vector<double>>},
		{"[Selection sort]", SelectionSort<std::vector<double>>},
		{"[Insertion sort]", InsertionSort<std::vector<double>>},
		{"[Merge sort]", MergeSort<double>},
		{"[Heap sort]", HeapSort<std::vector<double>>},
		{"[Quick sort]", QuickSort<double>},
	};

	try {
		std::cout << "INT tests:" << std::endl << std::endl;
		for (auto& int_test : int_tests) {
			std::cout << int_test.first << std::endl;
			int_sorting_func = int_test.second;
			TestSortingAlgo(int_sorting_func, int_vector);
		}

		std::cout << "DOUBLE tests:" << std::endl << std::endl;
		for (auto& double_test : double_tests) {
			std::cout << double_test.first << std::endl;
			double_sorting_func = double_test.second;
			TestSortingAlgo(double_sorting_func, double_vector);
		}
	}
	catch (std::exception & exception) {
		std::cout << "Error! " << exception.what() << std::endl;
	}
	catch (...) {
		std::cout << "Unknown error." << std::endl;
	}

	return 0;
}