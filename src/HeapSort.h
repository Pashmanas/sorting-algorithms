#pragma once

#include <vector>

/*
Сортировка кучей.

			Всегда

Время		O(n*log n)

Память		O(1)
*/

template <typename T>
void Heapify(T& array, size_t parent, size_t size) {
	size_t left_child = 2 * parent + 1;
	size_t right_child = 2 * parent + 2;
	size_t largest = parent;

	// проверяем, есть ли в потомках значения больше родителя
	if (left_child < size && array[left_child] > array[largest]) {
		largest = left_child;
	}
	if (right_child < size && array[right_child] > array[largest]) {
		largest = right_child;
	}

	// если в потомках есть значение больше - меняем их и перестраиваем нового потомка
	if (largest != parent) {
		std::swap(array[parent], array[largest]);

		Heapify(array, largest, size);
	}
}


template <typename T>
void HeapSort(T& array, size_t size) {
	// делаем из массива сортирующее дерево
	for (size_t i = size / 2; i > 0; i--) {
		Heapify(array, i - 1, size);
	}

	// перемещаем корень (максимальное значение) в конец массива и перестраиваем дерево
	for (size_t i = size; i > 0; i--) {
		std::swap(array[0], array[i - 1]);

		// уменьшаем размер чтобы не задеть отсортированные элементы
		Heapify(array, 0, i - 1);
	}
}