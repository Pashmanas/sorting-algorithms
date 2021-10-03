#pragma once

#include <vector>

/*
Пузырьковая сортировка.

			Наилучший	Средний		Наихудший

Время			O(n)	O(n^2)		O(n^2)

Память					O(1)
*/

template <typename T>
void BubbleSort2(T& array, size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = i + 1; j < size; j++) {
			if (array[j] < array[i]) {
				std::swap(array[j], array[i]);
			}
		}
	}
}

template <typename T>
void BubbleSort(T& array, size_t size) {
	for (size_t i = 0; i < size - 1; i++) {
		for (size_t j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				std::swap(array[j], array[j + 1]);
			}
		}
	}
}