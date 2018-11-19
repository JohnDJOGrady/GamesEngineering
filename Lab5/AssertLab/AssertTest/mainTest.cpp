#include <assert.h>
#include "../AssertLab/Results.h"

int main()
{
	Results numbers = Results(false); // generate a random array of numbers based on bool

	assert(numbers.notEmpty() == true);
	std::cout << "Array not empty." << std::endl;
	assert(numbers.correctSize() == true);
	std::cout << "Array correct Size." << std::endl;
	assert(numbers.inRange() == true);
	std::cout << "Array elemnts in range." << std::endl;
	assert(numbers.noDuplicates() == true);
	std::cout << "Array elements are unique." << std::endl;

	std::cin.get();
}