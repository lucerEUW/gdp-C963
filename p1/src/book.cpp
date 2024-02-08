#include<iostream>
#include"../include/book.h"
#include"../include/fileManagement.h"

Book::Book(const std::string &titel, const std::string &autor, std::string verlag, long isbn, double preis, int amount) : _titel(titel), _autor(autor), _verlag(std::move(verlag)), _isbn(isbn), _preis(preis), _amount(amount)
{
	try
	{
		std::string bookDirPath = "books/";
		std::string isbnString = std::to_string(isbn);
		_bookFile = bookDirPath + manage::toLower(titel) + manage::toLower(autor) + isbnString + ".txt";
	} catch (const std::exception &ex)
	{
		std::cerr << "Error in Book constructor: " << ex.what() << std::endl;
	}
}

void Book::Add()
{
	try
	{
		manage::UpdateCounter(1, _amount);
		std::ofstream book(_bookFile);
		if (!book.is_open())
		{
			throw std::runtime_error("Failed to open file for writing.");
		}
		book << _amount << std::endl << _titel << std::endl << _autor << std::endl << _verlag << std::endl << _isbn << std::endl << _preis
			 << std::endl;
		book.close();
	} catch (const std::exception &ex)
	{
		std::cerr << "Error in Add function: " << ex.what() << std::endl;
	}
}

void Book::Buy(const std::string &bookToBuy)
{
	try
	{
		char yn;
		std::string amountStr;
		if (std::stoi(manage::readAmount(bookToBuy)) > 0)
		{
			std::cout << "there are " << manage::readAmount(bookToBuy) << " copies left" << std::endl << std::setw(29)
					  << "do you want to buy this book?" << std::setw(29) << std::right << "[y/n][r:restock] " << std::endl
					  << "=========================================================" << std::endl;
			std::cin >> yn;

			switch (yn)
			{
				case 'y':
				{
					std::cout << "how many copies?: ";
					std::cin >> amountStr;
					int amount = std::stoi(amountStr);

					if (amount <= std::stoi(manage::readAmount(bookToBuy)))
					{
						std::cout << "total price: " << amount * std::stod(manage::getExactLine(bookToBuy, 6)) << std::endl;
						manage::UpdateCounter(0, amount);
						manage::UpdateAmount(bookToBuy, 0, amount);
					}
					else
					{
						std::cout << "not enough copies!" << std::endl;
					}
					break;
				}
				case 'n':
				{
					std::cout << "purchase canceled" << std::endl;
					break;
				}
				case 'r':
				{
					Book::Restock(bookToBuy);
					break;
				}
			}
		}
		else
		{
			std::cout << "no copies left!" << std::endl;
		}
	} catch (const std::exception &ex)
	{
		std::cerr << "Error in Buy function: " << ex.what() << std::endl;
	}
}

void Book::Restock(const std::string &bookToRestock)
{
	try
	{
		int amount;
		std::cout << "how many copies to add?: ";
		std::cin >> amount;
		manage::UpdateCounter(1, amount);
		manage::UpdateAmount(bookToRestock, 1, amount);
	} catch (const std::exception &ex)
	{
		std::cerr << "Error in Restock function: " << ex.what() << std::endl;
	}
}
