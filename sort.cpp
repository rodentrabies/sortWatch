#include "sort_visualization.h"

void run() {
	int fill_A, fill_B, sort_A, sort_B;
	Array* A, * B;
	vector<string> fill;
	vector<string> sort;
	
	askUser(fill_A, sort_A, fill_B, sort_B, fill, sort);
	createArrays(fill_A, fill_B, A, B);

	SortingStep* SA = new SortingStep(A->getArray(), A->getSize(), static_cast<SortingStep::Sort>(sort_A));
	SortingStep* SB = new SortingStep(B->getArray(), B->getSize(), static_cast<SortingStep::Sort>(sort_B));

	while (!(A->sorted() && B->sorted())) {
		SA->makeStep();
		SB->makeStep();
		printInfo(fill_A, fill_B, sort_A, sort_B, fill, sort);
		printBars(A->getArray(), B->getArray(), A->getSize());
		usleep(300000);
	}

	delete A;
	delete B;
	delete SA;
	delete SB;
}


void createArrays(int& f_A, int& f_B, Array*& A, Array*& B) {
	int size = 15;
	A = new Array(static_cast<Array::Fill>(f_A), size);
	if (f_A == f_B)
		B = new Array(A);
	else
		B = new Array(static_cast<Array::Fill>(f_B), size);
}


void printBars(int* A, int* B, int size) {
	system("clear");
	header();
	int x_1 = 15, x_2 = 55, y_1 = 4, y_2 = 4;
	gotoxy(x_1, y_1);
	cout << "A";
	gotoxy(x_2, y_2);
	cout << "B";
	y_1++;
	y_2++;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < A[i]; j++) {
			gotoxy(x_1 + j, y_1 + i);
			cout << "\e[33;3m\u25AA\e[0m";
			cout.flush();
		}
		
		for (int k = 0; k < B[i]; k++) {
			gotoxy(x_2 + k, y_2 + i);
			cout << "\e[33;3m\u25AA\e[0m";
			cout.flush();
		}
	}

	cout << endl;
}

void askUser(int& f_A, int& s_A, int& f_B, int& s_B, vector<string>& fill, vector<string>& sort) {
	fill.push_back("fill"); // first string - meaning of objects
	fill.push_back("random");
	fill.push_back("nearly sorted");
	fill.push_back("reverse");
	fill.push_back("few unique items");

	sort.push_back("sort");
	sort.push_back("insertion");
	sort.push_back("selection");
	sort.push_back("bubble");
	sort.push_back("shell");

	choose(f_A, fill, 1);
	choose(f_B, fill, 2);
	choose(s_A, sort, 1);
	choose(s_B, sort, 2);
}


void choose(int& param, const vector<string>& names, int arr) {;
	const int MIN_Y = 8;
	const int MAX_Y = MIN_Y + names.size() - 2;
	int y = MIN_Y;

	while (true) {
		system("clear");
		header();
		gotoxy(25, 6);
		cout << "choose \e[4m" << names[0] << "\e[0m type for " 
		     << ((arr == 1) ? "\e[4mfirst\e[0m" : "\e[4msecond\e[0m") << " array:";
		int curr_y = MIN_Y - 1;
		for (int i = 1; i < names.size(); i++) {
			gotoxy(27, ++curr_y);
			if (y == curr_y)
				cout << "  \e[43;30m - " << names[i] << " \e[0m";
			else
				cout << "- " << names[i];
		}
		gotoxy(58, 6);
	
		char c = getch();
		switch (c) {
			case 'w':
				if (y > MIN_Y)
					y--;
				break;
			case 's':
				if (y < MAX_Y)
					y++;
				break;
			case '\n':
				param = y - MIN_Y + 1;
				return;
			default:
				break;
		}
	}
}

void repeat(int& answ) {
	int x = 32;
	int y = 23;
	bool go_on = true;
	while (true) {
		gotoxy(x, y);
		cout << ((go_on) ? "\e[43;30m continue \e[0m exit " : " continue \e[43;30m exit \e[0m");
		gotoxy(0, 24);
		char c = getch();
		switch (c) {
			case 'a':
				if (!go_on)
					go_on = true;
				break;
			case 'd':
				if (go_on)
					go_on = false;
				break;
			case '\n':
				answ = go_on;
				return;
			default:
				break;
		}
	}
}

void printInfo(int f_A, int f_B, int s_A, int s_B, const vector<string>& fill, const vector<string>& sort) {
	gotoxy(23, 21);
	cout << "A: " << fill[f_A] << ", " << sort[s_A] << " sort;";
	gotoxy(23, 22);
	cout << "B: " << fill[f_B] << ", " << sort[s_B] << " sort;";
}

void header() {
	gotoxy(30, 2);
	cout << "\e[45;37;1m SORT VISUALIZATION \e[0m";
}


void gotoxy(int x, int y) {
	cout << "\e[" << y << ";" << x << "f";
}

char getch() {
	char buf = 0;
	struct termios old = {0};
	fflush(stdout);
	if (tcgetattr(0, &old) < 0)
		perror("tcsetattr()");
	old.c_lflag&= ~ICANON;
	old.c_lflag&= ~ECHO;
	old.c_cc[VMIN] = 1;
	old.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSANOW, &old) < 0)
		perror("tcsetattr ICANON");
	if (read(0,&buf,1) < 0)
		perror("read()");
	old.c_lflag|=ICANON;
	old.c_lflag|=ECHO;
	if (tcsetattr(0, TCSADRAIN, &old) < 0)
		perror ("tcsetattr ~ICANON");
	return buf;
}
