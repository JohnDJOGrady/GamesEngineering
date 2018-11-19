#include "Results.h"

int main()
{
	// getting user input
	Results numbers;
	int first, second, third, fourth, fifth, sixth;
	std::cout << "Please enter digits:" << std::endl;
	std::cin >> first >> second >> third >> fourth >> fifth >> sixth;

	numbers = Results(first, second, third, fourth, fifth, sixth);
	numbers.test(); // ensure user input is correct

	system("PAUSE");
	return 0;
}