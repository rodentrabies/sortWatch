#ifndef ARRAY_H
#define ARRAY_H

#include <ctime>
#include <cstdlib>

class Array {
	public:
		enum Fill {
			random_filled = 1, nearly_sorted, 
			backwards, few_unique
		};

		Array(Fill, int);
		Array(const Array*);
		~Array() {delete [] array;};

		int* getArray() const {return array;};
		int getSize() const {return size;};

		bool sorted();
	private:
		int size;
		int* array;

		void random();
		void nearlySorted();
		void reversed();
		void fewUnique();
};

#endif
