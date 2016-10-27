// 10 FizzBuzz.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

long lgfnGetNum(std::string strPrompt) 
{
	long result = 0;
	while (true) {
		std::string strInput = "";
		//use getline to avoid errors with inputs
		std::cout << strPrompt;
		std::getline(std::cin, strInput);

		// this line defines a stringstream called 'mystream' and gives it the value of strinput
		std::stringstream myStream(strInput);
		//this line looks for result (i.e. a signed long) and stores it. If it can't, it returns false
		if (myStream >> result) {
			break;
		}
		std::cout << "That's not a number. Please enter a number.\n";
	}
	return result;
}

std::string strfnGetString(std::string strPrompt,long lgNumberToReplace)
{
	bool blTrigger = false;
	std::string strInput = "";
	std::cout << strPrompt;					//give prompt and capture input
	std::getline(std::cin, strInput);

	return strInput;

}

void vdWait()
{
	std::cin.clear(); // reset any error flags
	std::cin.ignore(32767, '\n'); // ignore any characters in the input buffer until we find an enter character
	std::cin.get(); // get one more char from the user
}




int main()
{

	//get number and string to fizz
	long			lgNumberToFizz;
	std::string		strStringToFizz;
	lgNumberToFizz = lgfnGetNum("Please enter your number to fizz:\n");
	strStringToFizz = strfnGetString("Please enter your text for 'fizz':\n", lgNumberToFizz);

	//get number and string to buzz
	long			lgNumberToBuzz;
	std::string		strStringToBuzz;
	lgNumberToBuzz = lgfnGetNum("Please enter your number to buzz:\n");
	strStringToBuzz = strfnGetString("Please enter your text for 'buzz':\n", lgNumberToBuzz);

	//get range to fizzbuzz
	long			lgNumberToStart;
	long			lgNumberToEnd;
	lgNumberToStart = lgfnGetNum("Where do you want to start?\n");
	lgNumberToEnd = lgfnGetNum("Where do you want to end?\n");

	do {
		std::cout << lgNumberToStart << " ";
		if (lgNumberToStart % lgNumberToFizz == 0 && lgNumberToStart % lgNumberToBuzz == 0){
			std::cout << strStringToFizz << strStringToBuzz << "\n";
		}
		else
		if(lgNumberToStart % lgNumberToFizz == 0) {
			std::cout << strStringToFizz << "\n";
		}
		else
		if (lgNumberToStart % lgNumberToBuzz == 0) {
			std::cout << strStringToBuzz << "\n";
		}
		else {
			std::cout << "\n";
		}
		lgNumberToStart++;
	} while (lgNumberToStart <= lgNumberToEnd);
	
	vdWait();

	return 0;
}

