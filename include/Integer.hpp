#pragma once
#include <iostream>
#include "Number.hpp"

class StringNumber;
class RomanNumeral;


class Integer:public Number
{
public:
	Integer();
	Integer(int value);
	Integer(std::string str);
	int toInteger() const;
	std::string toRomanNumeral() const;
	std::string toWordNumber() const;
	bool parse();
	~Integer();
	
	void operator = (const Integer& i);
	Integer operator + (const Integer& i);
	Integer operator + (const int& i);
	Integer operator + (const RomanNumeral& rN);
	Integer operator + (const StringNumber& str);
	Integer operator - (const Integer& i);
	Integer operator - (const int& i);
	Integer operator - (const RomanNumeral& rN);
	Integer operator - (const StringNumber& str);
	Integer operator * (const Integer& i);
	Integer operator * (const int& i);
	Integer operator * (const RomanNumeral& rN);
	Integer operator * (const StringNumber& str);
	Integer operator / (const Integer& i)	;
	Integer operator / (const int& i);
	Integer operator / (const RomanNumeral& rN);
	Integer operator / (const StringNumber& str);
	Integer operator % (const Integer& i);
	Integer operator % (const int& i);
	Integer operator % (const RomanNumeral& rN);
	Integer operator % (const StringNumber& str);
	bool operator < (const Integer& i);
	bool operator < (const RomanNumeral& rN);
	bool operator < (const StringNumber& str);
	bool operator > (const Integer& i);
	bool operator > (const RomanNumeral& rN);
	bool operator > (const StringNumber& str);
	bool operator <= (const Integer& i);
	bool operator <= (const RomanNumeral& rN);
	bool operator <= (const StringNumber& str);
	bool operator >= (const Integer& i);
	bool operator >= (const RomanNumeral& rN);
	bool operator >= (const StringNumber& str);
	bool operator == (const Integer& i);
	bool operator == (const RomanNumeral& rN);
	bool operator == (const StringNumber& str);
	bool operator != (const Integer& i);
	bool operator != (const RomanNumeral& rN);
	bool operator != (const StringNumber& str);
	Integer operator >> (const Integer& i);
	Integer operator >> (const RomanNumeral& rN);
	Integer operator >> (const StringNumber& str);
	Integer operator << (const Integer& i);
	Integer operator << (const RomanNumeral& rN);
	Integer operator << (const StringNumber& str);

	//Integer operator Integer (const int& i)
	
//private:
	int integer;
	std::string stringNumber;
	std::string romanNumber;
};