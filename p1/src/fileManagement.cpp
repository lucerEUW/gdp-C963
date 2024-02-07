#include<iostream>
#include"../include/fileManagement.h"

namespace manage
{
	std::string getExactLine(const std::string &filename, int lineNumber)
	{
		try
		{
			std::ifstream file("books/" + filename);
			if (!file.is_open())
			{
				throw std::runtime_error("Failed to open file: " + filename);
			}
			std::string outputLine;
			for (int i = 0; i < lineNumber - 1; i++)
			{
				if (!std::getline(file, outputLine))
				{
					return "";
				}
			}
			std::getline(file, outputLine);
			file.close();
			return outputLine;
		} catch (const std::exception &ex)
		{
			std::cerr << "Error in getExactLine function: " << ex.what() << std::endl;
			return "";
		}
	}

	void displayDetails(const std::string &filename)
	{
		try
		{
			std::cout << std::setw(19) << std::left << "further details   :" << std::endl << std::setw(19) << std::left
					  << "title             :" << std::setw(38) << std::right << getExactLine(filename, 2) << std::endl << std::setw(19)
					  << std::left << "author            :" << std::setw(38) << std::right << getExactLine(filename, 3) << std::endl
					  << std::setw(19) << std::left << "published by      :" << std::setw(38) << std::right << getExactLine(filename, 4)
					  << std::endl << std::setw(19) << std::left << "_isbn              :" << std::setw(38) << std::right
					  << getExactLine(filename, 5) << std::endl << std::setw(19) << std::left << "price [in euros]  :" << std::setw(38)
					  << std::right << getExactLine(filename, 6) << std::endl << "========================================================="
					  << std::endl;
		} catch (const std::exception &ex)
		{
			std::cerr << "Error in displayDetails function: " << ex.what() << std::endl;
		}
	}

	std::string readAmount(const std::string &targetFile)
	{
		try
		{
			std::ifstream amountIn("books/" + targetFile);
			if (!amountIn.is_open())
			{
				throw std::runtime_error("Failed to open file for reading: " + targetFile);
			}
			std::string amount;
			std::getline(amountIn, amount);
			amountIn.close();
			return amount;
		} catch (const std::exception &ex)
		{
			std::cerr << "Error in readAmount function: " << ex.what() << std::endl;
			return "";
		}
	}

	void UpdateAmount(const std::string &targetFile, int action, int amount)
	{
		try
		{
			int bAmountI = std::stoi(readAmount(targetFile));
			switch (action) {
				case 0:
					bAmountI -= amount;
					break;
				case 1:
					bAmountI += amount;
					break;
			}

			std::string newString = std::to_string(bAmountI);
			std::fstream file("books/" + targetFile, std::ios::in | std::ios::out);
			if (!file.is_open())
			{
				throw std::runtime_error("Failed to open file for updating: " + targetFile);
			}
			std::vector<std::string> lines;
			std::string line;
			while (std::getline(file, line))
			{
				lines.push_back(line);
			}
			file.clear();
			if (!lines.empty())
			{
				size_t oldLineLength = lines[0].size();
				size_t newLineLength = newString.size();
				file.seekp(0);
				if (newLineLength <= oldLineLength)
				{
					file << newString;
					file << std::string(oldLineLength - newLineLength, ' ');
				}
				else
				{
					file << newString;
					for (size_t i = 1; i < lines.size(); ++i)
					{
						file << '\n' << lines[i];
					}
				}
			}
			else
			{
				std::cerr << "Error: Empty file." << std::endl;
			}
			file.close();
		} catch (const std::exception &ex)
		{
			std::cerr << "Error in UpdateAmount function: " << ex.what() << std::endl;
		}
	}

	std::string readCounter()
	{
		try
		{
			std::string count;
			std::ifstream booksIn("counter.txt");
			if (!booksIn.is_open())
			{
				throw std::runtime_error("Failed to open counter file for reading.");
			}
			std::getline(booksIn, count);
			booksIn.close();
			return count;
		} catch (const std::exception &ex)
		{
			std::cerr << "Error in readCounter function: " << ex.what() << std::endl;
			return "";
		}
	}

	void UpdateCounter(int action, int amount)
	{
		try
		{
			int firstLineI = std::stoi(readCounter());
			switch (action)
			{
				case 0:
					firstLineI = firstLineI - amount;
					break;
				case 1:
					firstLineI = firstLineI + amount;
					break;
			}
			std::ofstream booksOut("counter.txt");
			if (!booksOut.is_open())
			{
				throw std::runtime_error("Failed to open counter file for writing.");
			}
			booksOut << firstLineI;
			booksOut.close();
		} catch (const std::exception &ex)
		{
			std::cerr << "Error in UpdateCounter function: " << ex.what() << std::endl;
		}
	}

	std::string toLower(std::string searchTerm)
	{
		try
		{
			std::transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), [](unsigned char c)
			{
				return std::tolower(c);
			});
			return searchTerm;
		} catch (const std::exception &ex)
		{
			std::cerr << "Error in toLower function: " << ex.what() << std::endl;
			return searchTerm;
		}
	}

	std::string getSearchTerm()
	{
		try
		{
			std::string searchTerm;
			std::cout << "search for book: ";
			std::cin >> searchTerm;
			std::cout << "=========================================================" << std::endl;
			return searchTerm;
		} catch (const std::exception &ex)
		{
			std::cerr << "Error in getSearchTerm function: " << ex.what() << std::endl;
			return "";
		}
	}

	void Search()
	{
		try
		{
			std::string searchTerm, filename, foundFileName;
			searchTerm = toLower(getSearchTerm());
			int booksFound = 0;
			for (const auto &entry: std::filesystem::directory_iterator("books/"))
			{
				filename = entry.path().filename().string();
				if (filename.find(searchTerm) != std::string::npos)
				{
					foundFileName = filename;
					std::cout << std::setw(19) << std::left << getExactLine(filename, 2) << std::setw(19) << std::left
							  << getExactLine(filename, 3) << std::setw(19) << std::right << getExactLine(filename, 5) << std::endl;
					booksFound++;
				}
			}
			std::cout << "=========================================================" << std::endl;
			if (booksFound == 1)
			{
				displayDetails(foundFileName);
				Book::Buy(foundFileName);
			}
			else
			{
				std::cout << booksFound << " different results found. please specify further!" << std::endl;
				Search();
			}
		} catch (const std::exception &ex)
		{
			std::cerr << "Error in Search function: " << ex.what() << std::endl;
		}
	}
}
