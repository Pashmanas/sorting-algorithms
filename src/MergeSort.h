#pragma once

#include <vector>

/*
Сортировка слиянием.

			Всегда

Время		O(n*log n)

Память		O(n)
*/

template <typename T>
void Merge(std::vector<T>& output, size_t left, size_t middle, size_t right, std::vector<T>& temp) {
	size_t left_itr = left, right_itr = middle + 1;

	// склеиваем в порядке возрастания 2 подмассива и записываем в temp чтобы не потерять значения в output 
	for (size_t i = 0; i < (right - left + 1); i++) {
		// вставили все элементы левого массива, поэтому вставляем только правый
		if (left_itr > middle) {
			temp[i] = output[right_itr++];
			continue;
		}
		// вставили все элементы правого массива, поэтому вставляем только левый
		if (right_itr > right) {
			temp[i] = output[left_itr++];
			continue;
		}

		// Вставляем наибольший элемент
		if (output[left_itr] < output[right_itr]) {
			temp[i] = output[left_itr++];
		}
		else {
			temp[i] = output[right_itr++];
		}
	}

	// перезаписываем ту часть, которую мы склеивали, в output (в нужное место)
	for (size_t i = 0; i < (right - left + 1); i++) {
		output[left + i] = temp[i];
	}
}

template <typename T>
void Sort(std::vector<T>& array, size_t left, size_t right, std::vector<T>& temp) {
	if (right - left <= 0)
		return;

	size_t middle = (left + right) / 2;

	// делим подмассив на 2 части и сортируем их отдельно
	Sort(array, left, middle, temp);
	Sort(array, middle + 1, right, temp);

	// соединяем их и записываем в array
	Merge(array, left, middle, right, temp);
}

/*
Работает только с std::vector
*/
template <typename T>
void MergeSort(std::vector<T>& array, size_t size) {
	// временный массив для склейки частей (merge)
	// нужен, чтобы склеивать значения там, а не перезаписывать array
	std::vector<T> temp(size);

	Sort(array, 0, size - 1, temp);
}