#include "Array.h"

Array::Array(Fill fill, int s = 15) {
	size = s;
	array = new int [size];
	srand(time(NULL));
	for (int i = 0; i < size; i++)
		array[i] = 0;
	switch (fill) {
		case random_filled:
			random();
			break;
		case nearly_sorted:
			nearlySorted();
			break;
		case backwards:
			reversed();
			break;
		case few_unique:
			fewUnique();
			break;
	}
}

Array::Array(const Array* A) {
	size = A->getSize();
	array = new int [size];
	for (int i = 0; i < size; i++) 
		array[i] = (A->getArray())[i];
}

void Array::random() {
	int k = 1, a;
	while (k <= size) {
		if (array[a = rand() % size] == 0) {
			array[a] = k;
			k++;
		}
	}
}

void Array::nearlySorted() {
	for (int i = 0; i < size; i++)
		array[i] = i + 1;
	for (int i = 0; i < size - 1; i++)
		if (rand() % 2) {
			int tmp = array[i + 1];
			array[i + 1] = array[i];
			array[i] = tmp;
		}
}

void Array::reversed() {
	for (int i = 0; i < size; i++)
		array[i] = size - i;
}

void Array::fewUnique() {
	int items = 4;
	for (int i = 0; i < size; i++)
		array[i] = (size / items) * (rand() % items + 1);
}

bool Array::sorted() {
	for (int i = 0; i < size - 1; i++) 
		if (array[i] > array[i + 1])
			return false;
	return true;
}
