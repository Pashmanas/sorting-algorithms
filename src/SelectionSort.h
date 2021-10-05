#pragma once

#include <vector>

/*
Сортировка выбором.

			Наилучший	Средний		Наихудший

Время		O(n^2)		O(n^2)		O(n^2)

Память					O(1)
*/

template <typename T>
void SelectionSort(T& array, size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		size_t min_index = i;
		for (size_t j = i + 1; j < size; j++) {
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i) {
			std::swap(array[min_index], array[i]);
		}
	}
}