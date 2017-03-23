#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <Integer.hpp>
#include <StringNumber.hpp>

class Integer;
class StringNumber;
class RomanNumeral:public Number
{
public:
	RomanNumeral();
	RomanNumeral(int i);
	RomanNumeral(std::string str);
	~RomanNumeral();

	void operator = (const int& i);
	void operator = (const Integer& i);
	void operator = (const std::string& str);

	RomanNumeral operator + (const StringNumber& strNum);
	RomanNumeral operator + (const RomanNumeral& _roman);
	RomanNumeral operator + (const Integer& i);
	RomanNumeral operator + (const int& i);

	RomanNumeral operator - (const StringNumber& strNum);
	RomanNumeral operator - (const RomanNumeral& _roman);
	RomanNumeral operator - (const Integer& i);
	RomanNumeral operator - (const int& i);

	RomanNumeral operator * (const StringNumber& strNum);
	RomanNumeral operator * (const RomanNumeral& _roman);
	RomanNumeral operator * (const Integer& i);
	RomanNumeral operator * (const int& i);

	RomanNumeral operator / (const StringNumber& strNum);
	RomanNumeral operator / (const RomanNumeral& _roman);
	RomanNumeral operator / (const Integer& i);
	RomanNumeral operator / (const int& i);

	RomanNumeral operator % (const StringNumber& strNum);
	RomanNumeral operator % (const RomanNumeral& _roman);
	RomanNumeral operator % (const Integer& i);
	RomanNumeral operator % (const int& i);

	RomanNumeral operator >> (const StringNumber& strNum);
	RomanNumeral operator >> (const RomanNumeral& _roman);
	RomanNumeral operator >> (const Integer& i);
	RomanNumeral operator >> (const int& i);

	RomanNumeral operator << (const StringNumber& strNum);
	RomanNumeral operator << (const RomanNumeral& _roman);
	RomanNumeral operator << (const Integer& i);
	RomanNumeral operator << (const int& i);

	bool operator < (const StringNumber& strNum);
	bool operator < (const RomanNumeral& _roman);
	bool operator < (const Integer& i);
	bool operator < (const int& i);

	bool operator > (const StringNumber& strNum);
	bool operator > (const RomanNumeral& _roman);
	bool operator > (const Integer& i);
	bool operator > (const int& i);

	bool operator <= (const StringNumber& strNum);
	bool operator <= (const RomanNumeral& _roman);
	bool operator <= (const Integer& i);
	bool operator <= (const int& i);
	
	bool operator >= (const StringNumber& strNum);
	bool operator >= (const RomanNumeral& _roman);
	bool operator >= (const Integer& i);
	bool operator >= (const int& i);

	bool operator == (const StringNumber& strNum);
	bool operator == (const RomanNumeral& _roman);
	bool operator == (const Integer& i);
	bool operator == (const int& i);

	bool operator != (const StringNumber& strNum);
	bool operator != (const RomanNumeral& _roman);
	bool operator != (const Integer& i);
	bool operator != (const int& i);

	std::string toRomanNumeral() const;
	int toInteger() const;
	bool parse();
    
private:
	std::string roman;
	void markDonePlace(std::vector<bool>& donePlace, int start);
	bool checkIfValidDigit(std::string& str);
	bool checkIfValidChars(std::string& str);
};