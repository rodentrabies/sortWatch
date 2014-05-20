#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <vector>
#include <string>

#include "Array.h"
#include "SortingStep.h"

using namespace std;

char getch();
void gotoxy(int, int);
void askUser(int&, int&, int&, int&, vector<string>&, vector<string>&);
void createArrays(int&, int&, Array*&, Array*&);
void choose(int&, const vector<string>&, int);
void header();
void printBars(int*, int*, int);
void run();
void repeat(int&);
void printInfo(int, int, int, int, const vector<string>&, const vector<string>&);


