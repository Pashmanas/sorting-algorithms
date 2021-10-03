#pragma once

#include <vector>

/*
Быстрая сортировка.

			Наилучший	Средний		Наихудший

Время		O(n*log n)	O(n*log n)	O(n^2)

Память					O(1)
*/

template <typename T>
void Sort(std::vector<T>& array, size_t left, size_t right) {
	if (right <= left)
		return;

	// выбираем опорный элемент (центральный)
	size_t pivot_idx = (right + left) / 2;
	T pivot_value = array[pivot_idx];

	// проходим массив с обоих концов и перемещаем элементы меньше опорного влево
	// а больше опорного вправо
	size_t left_idx = left, right_idx = right;
	while (left_idx <= right_idx) {
		if (array[left_idx] < pivot_value) {
			left_idx++;
			continue;
		}
		if (array[right_idx] > pivot_value) {
			right_idx--;
			continue;
		}

		// меняем пару подходящих элементов
		if (left_idx <= right_idx) {
			std::swap(array[left_idx], array[right_idx]);
			left_idx++;

			// пусть пока будет так
			if (right_idx != 0)
				right_idx--;
		}
	}

	Sort(array, left, right_idx);
	Sort(array, left_idx, right);
}

/*
Работает только с std::vector
*/
template <typename T>
void QuickSort(std::vector<T>& array, size_t size) {
	Sort(array, 0, size - 1);
}