#ifndef RESULTS_H
#define RESULTS_H

#include <vector>
#include <array>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

class Results
{
public:
	Results() {};
	Results(bool random); // generate a random array or a hardcoded array
	Results(int first, int second, int third, int fourth, int fifth, int sixth);

	void test();
	int getNumber(int i);
	std::vector<int>* getNumbers();
	int getSize();

	bool notEmpty();
	bool correctSize();
	bool inRange();
	bool noDuplicates();

private:
	std::vector<int> m_numbers;
	int m_min, m_max;
};

#endif // !RESULTS_H
