#include "SortingStep.h"

void SortingStep::makeStep() {
	switch (sort_type) {
		case ins:
			insertion();
			break;
		case sel:
			selection();
			break;
		case bub:
			bubble();
			break;
		case sh:
			shell();
			break;
		case hp:
			heap();
			break;
		case q:
			quick();
			break;
		case q3:
			quick3();
			break;

		default:
			break;
	}
}

void SortingStep::insertion() {
	while (ins_i < size - 1) {
		for (int j = ins_i + 1; j > 0 && array[j - 1] > array[j]; j--) {
			int tmp = array[j];
			array[j] = array[j - 1];
			array[j - 1] = tmp;
		}
		ins_i++;
		return;
	}
}


void SortingStep::selection() {
	while (sel_i < size - 1) {
		sel_min_i = sel_i;
		for (int j = sel_i + 1; j < size; j++) {
			if (array[j] < array[sel_min_i])
				sel_min_i = j;
		}
		int tmp = array[sel_min_i];
		array[sel_min_i] = array[sel_i];
		array[sel_i] = tmp;
		sel_i++;
		return;
	}
}


void SortingStep::bubble() {
	while (!swap) {
		swap = true;
		for (int i = 1; i < size; i++) {
			if (array[i - 1] > array[i]) {
				int tmp = array[i - 1];
				array[i - 1] = array[i];
				array[i] = tmp;
				swap = false;
			}
		}
		return;
	}
}


void SortingStep::shell() {
	if (h == 0)
		h = ((h = (size / 2) % 2 == 1)) ? h : h - 1;
	else
		(h == 1) ? h = 1 : h /= 2;
	if (sh_i == 0)
		sh_i = h;
	while (sh_i < size) {
		for (int j = sh_i; j >= h && array[j - h] > array[j]; j -= h) {
			int tmp = array[j];
			array[j] = array[j - h];
			array[j - h] = tmp;
		}
		if (sh_i == size - 1)
			sh_i = 0;
		else
			sh_i++;
		return;
	}
}


void SortingStep::merge() {
// implement later
}
void SortingStep::heap() {}
void SortingStep::quick() {}
void SortingStep::quick3() {}

