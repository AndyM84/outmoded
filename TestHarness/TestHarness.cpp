#include <iostream>
#include <Outmoded.h>

//CellInfo Box[] = {
//	{ 'X', 1, 1 }, { 'X', 2, 1 }, { 'X', 3, 1 },
//	{ 'X', 1, 2 }, { 'X', 2, 2 }, { 'X', 3, 2 },
//	{ 'X', 1, 3 }, { 'X', 2, 3 }, { 'X', 3, 3 }
//};

int main()
{
	Outmoded::Point Box[] = {
		{ 1, 1 }, { 2, 1 }, { 3, 1 },
		{ 1, 2 }, { 2, 2 }, { 3, 2 },
		{ 1, 3 }, { 2, 3 }, { 3, 3 }
	};

	for (int i = 0; i < 9; ++i)
	{
		std::cout << Box[i].ToString() << std::endl;
	}

	std::cout << "Thanks for playing!" << std::endl;
	std::cin.get();

	return 0;
}
