#pragma once

#include <vector>

/*
Сортировка вставками.

			Наилучший	Средний		Наихудший

Время			O(n)	O(n^2)		O(n^2)

Память					O(1)
*/

template <typename T>
size_t FindInsertionIndex(T& array, size_t value_index) {
	auto value = array[value_index];

	for (size_t i = 0; i < value_index; i++) {
		if (value < array[i])
			return i;
	}

	return -1;
}

template <typename T>
void Insert(T& array, size_t value_index, size_t insertion_index) {
	auto value = array[value_index];

	for (size_t i = value_index; i > insertion_index; i--) {
		array[i] = array[i - 1];
	}

	array[insertion_index] = value;
}

template <typename T>
void InsertionSort(T& array, size_t size) {
	for (size_t i = 1; i < size; i++) {
		if (array[i] < array[i - 1]) {
			size_t insertion_index = FindInsertionIndex(array, i);
			Insert(array, i, insertion_index);
		}
	}
}