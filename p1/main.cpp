#include<iostream>
#include"include/book.h"
#include"include/fileManagement.h"

int main()
{
	std::string titel, autor, verlag, searchTerm;
	long isbn;
	int amount;
	double preis;
	char choice;
	bool contRunning = true;

	while (contRunning)
	{
		std::string copies = "[" + manage::readCounter() + " copies]";
		std::cout << "=========================================================" << std::endl << std::setw(12) << std::left << "Bookmanager"
				  << std::setw(45) << std::right << copies << std::endl << "========================================================="
				  << std::endl << std::setw(25) << std::left << "s:search/restock/buy" << std::setw(14) << std::internal << "a:add new"
				  << std::setw(18) << std::right << "q:quit" << std::endl << "========================================================="
				  << std::endl;
		std::cin >> choice;

		switch (choice)
		{
			case 's':
				manage::Search();
				break;
			case 'a':
			{
				std::cout << "give data for book to add" << std::endl << "[titel autor verlag isbn preis anzahl]: ";
				std::cin >> titel >> autor >> verlag >> isbn >> preis >> amount;
				Book newBook(titel, autor, verlag, isbn, preis, amount);
				newBook.Add();
				break;
			}
			case 'q':
				std::cout << "quitting..." << std::endl;
				contRunning = false;
				break;
			default:
				std::cout << "invalid" << std::endl;
				break;
		}
	}
	return 0;
}
