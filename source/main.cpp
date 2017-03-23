#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <RomanNumeral.hpp>
#include <Integer.hpp>

int main()
{
	RomanNumeral roman;
	StringNumber strNum;
	strNum = "one hundred one";
	
	roman = "III";
	std::cout << roman.toInteger() << std::endl;
	roman = "I I I";
	std::cout << roman.toInteger() << std::endl;
	roman = "MCXIXX";
	std::cout << roman.toInteger() << std::endl;
	roman = "MMMMM";
	std::cout << roman.toInteger() << std::endl;
	roman = "cdxxix";
	std::cout << roman.toInteger() << std::endl;
	roman = 99;
	std::cout << roman.toRomanNumeral() << std::endl;
	std::cout << strNum.toWordNumber() << std::endl;
}