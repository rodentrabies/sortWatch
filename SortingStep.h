#ifndef SORTING_STEP_H
#define SORTING_STEP_H

class SortingStep {
	public:
		enum Sort {ins = 1, sel, bub, sh, mrg, hp, q, q3};
		SortingStep(int* A, int sz, Sort st)
			:array(A), size(sz), sort_type(st),
			 ins_i(), sel_i(), sel_min_i(), swap(), sh_i(), h() {}
		void makeStep();
	private:
		void insertion();
		void selection();
		void bubble();
		void shell();
		void merge();
		void heap();
		void quick();
		void quick3();
		
		// controll variables
		int ins_i; //insertion
		int sel_i; // selection
		int sel_min_i; // selection
		bool swap; // bubble
		int sh_i; // shell
		int h; // shell

		int* array;
		const int size;
		const Sort sort_type;
};

#endif

