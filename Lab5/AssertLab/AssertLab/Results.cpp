#include "Results.h"

Results::Results(bool random)
{
	if (random)
	{
		const int min = 1;
		const int max = 46;
		const int numberCount = 6;
		std::vector<int> remainingNumbers(max);

		// create array of 46 elements
		for (int i = 0; i < max; i++)
		{
			remainingNumbers[i] = i;
		}

		srand(time(NULL)); // rand to seed the vector

		for (int i = 0; i < numberCount; i++)
		{
			// from the created array of 46 numbers, pick a random number from within the range and insert in to our results vector
			int randInt = rand() % (max + 1 - min) + min;
			m_numbers.push_back(remainingNumbers[randInt]);
			remainingNumbers[randInt] = remainingNumbers[max - i - 1];
		}
	}

	else
	{
		m_numbers = {1, 5, 6, 12, 26, 42}; // hardcoded array
	}
}

Results::Results(int first, int second, int third, int fourth, int fifth, int sixth)
{
	m_numbers.push_back(first);
	m_numbers.push_back(second);
	m_numbers.push_back(third);
	m_numbers.push_back(fourth);
	m_numbers.push_back(fifth);
	m_numbers.push_back(sixth);
}

void Results::test()
{
	if (!notEmpty())
	{
		std::cout << "Vector array is empty." << std::endl;
	}
	if (!correctSize())
	{
		std::cout << "Vector array is incorrect size." << std::endl;
	}
	if (!inRange())
	{
		std::cout << "Vector array elements not in range." << std::endl;
	}
	if (!noDuplicates())
	{
		std::cout << "Vector array elements duplicated." << std::endl;
	}
}

int Results::getNumber(int i)
{
	return m_numbers[i];
}

std::vector<int>* Results::getNumbers()
{
	return &m_numbers;
}

int Results::getSize()
{
	return m_numbers.size();
}

bool Results::notEmpty()
{
	return getSize() != 0;
}

bool Results::correctSize()
{
	return getSize() == 6;
}

bool Results::inRange()
{
	bool result;
	for (auto& i : m_numbers)
	{
		if(i >= 1 && i <= 46) // ensure the vector value is between the range of 1 and 46
		{
			result = true;
		}
		else 
		{
			result = false;
			break;
		}
	}

	return result;
}

bool Results::noDuplicates()
{
	bool result;
	std::vector<int> temp = m_numbers;
	std::sort(temp.begin(), temp.end()); // sorting the array numerically
	auto last = std::unique(temp.begin(), temp.end()); // ensuring uniqueness
	temp.erase(last, temp.end());
	if (temp.size() == 6)
	{
		result = true;
	}
	else 
	{
		result = false;
	}
	return result;
}
