#include <fstream>
#include <iostream>
#include <string>

#include "text_util.h"

int main()
{
	std::cout << "Choose the alignment/justification prefered" << std::endl;
	std::cout << "(R or r)for Right Align" << std::endl;
	std::cout << "(L orl) for left Align " << std::endl;
	std::cout << "(J or j) for justified " << std::endl;
	
	auto option = ' ';
	std::cin >> option;

	while (std::cin.fail() || option != 'R' && option != 'r' && option != 'J' && option != 'j' && option != 'L' && option != 'l')
	{
		std::cin.ignore(
			std::numeric_limits<std::streamsize>::max(),
			nwacc::k_newline);
		std::cout << "Invalid input, try again : ";
		std::cin >> option;
	}

	std::ofstream fout;

	fout.open("formatted_address.txt");

	if (option == 'R' || option == 'r')
	{
		std::ifstream fin;
		fin.open("address.txt");

		if (fin)
		{
			std::string input;
			while (getline(fin, input))
			{
				std::string word = nwacc::right_justify(input);
				fout << word;
			}
		}
		else
		{
			std::cout << "File failed to open" << std::endl;
		}

		fin.close();
	}

	else if (option == 'L' || option == 'l')
	{
		std::ifstream fin;
		fin.open("address.txt");

		if (fin)
		{
			std::string input;
			while (getline(fin, input))
			{
				std::string word = nwacc::left_justify(input);
				fout << word;
			}
		}
		else
		{
			std::cout << "File failed to open" << std::endl;
		}

		fin.close();
	}
	else
	{
		std::ifstream fin;
		fin.open("address.txt");

		if (fin)
		{
			std::string input;
			while (getline(fin, input))
			{
				std::string word = nwacc::justify(input);
				fout << word;
			}
		}
		else
		{
			std::cout << "File failed to open" << std::endl;
		}

		fin.close();

	}

	fout.close();

	return 0;
}

	
	

