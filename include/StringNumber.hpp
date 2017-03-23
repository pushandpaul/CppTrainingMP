#pragma once
#include <iostream>
#include "Number.hpp"
#include "Integer.hpp"
#include "RomanNumeral.hpp"

class Integer;
class RomanNumeral;
class StringNumber:public Number
{	
	
public:
	StringNumber();
	StringNumber(std::string value);
	StringNumber(int n);
	int toInteger() const;
	std::string toRomanNumeral() const;
	std::string toWordNumber() const;
	bool parse();
	~StringNumber();
	
	void operator = (const StringNumber& s);
	void operator = (const std::string& value);
	StringNumber operator + (const StringNumber& str);
	StringNumber operator + (const Integer& i);
	StringNumber operator + (const RomanNumeral& rN);
	StringNumber operator - (const StringNumber& str);
	StringNumber operator - (const Integer& i);
	StringNumber operator - (const RomanNumeral& rN);
	StringNumber operator * (const StringNumber& str);
	StringNumber operator * (const Integer& i);
	StringNumber operator * (const RomanNumeral& rN);
	StringNumber operator / (const StringNumber& str);
	StringNumber operator / (const Integer& i);
	StringNumber operator / (const RomanNumeral& rN);
	StringNumber operator % (const StringNumber& str);
	StringNumber operator % (const Integer& i);
	StringNumber operator % (const RomanNumeral& rN);
	bool operator < (const StringNumber& str);
	bool operator < (const Integer& i);
	bool operator < (const RomanNumeral& rN);
	bool operator > (const StringNumber& str);
	bool operator > (const Integer& i);
	bool operator > (const RomanNumeral& rN);
	bool operator <= (const StringNumber& str);
	bool operator <= (const Integer& i);
	bool operator <= (const RomanNumeral& rN);
	bool operator >= (const StringNumber& str);
	bool operator >= (const Integer& i);
	bool operator >= (const RomanNumeral& rN);
	bool operator == (const StringNumber& str);
	bool operator == (const Integer& i);
	bool operator == (const RomanNumeral& rN);
	bool operator != (const StringNumber& str);
	bool operator != (const Integer& i);
	bool operator != (const RomanNumeral& rN);
	StringNumber operator << (const StringNumber& str);
	StringNumber operator << (const Integer& i);
	StringNumber operator << (const RomanNumeral& rN);
	StringNumber operator >> (const StringNumber& str);
	StringNumber operator >> (const Integer& i);
	StringNumber operator >> (const RomanNumeral& rN);


private:
	std::string stringNumber;
};