
#include <iostream>
#include <map>
#include "Integer.hpp"
#include "RomanNumeral.hpp"
#include "StringNumber.hpp"

/**
* Constants
*/
std::map<int, std::string> romansReference = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
			 {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
const std::string count[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
const std::string tensException[10] = {"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
const std::string tens[10] = {"XX","XX","twenty", "thirty","forty","fifty","sixty","seventy","eighty","ninety"};
const std::string hundredSpecifier = "hundred";
const std::string thousandSpecifier = "thousand";
const std::string whitespace = " ";

/**
* Private Function Prototype
*/
std::string getThousandsDigitWord(int thousandsDigitValue);
std::string getHundredsDigitWord(int hundredsDigitValue);
bool isException(int tensDigitValue);
std::string getWordExceptions(int onesDigitValue);
std::string getTensDigitWord(int tensDigitValue);
std::string getOnesDigitWord(int onesDigitValue);
void removeExtraWhiteSpaces(std::string& wordNumber);


/**
* Constructors
*/
Integer::Integer()
{
	this->integer = 0;
}

Integer::Integer(int value)
{	
	this->integer = value;
	if (parse())
		this->integer = value;
	else
		this->integer = -1;
}
Integer::Integer(std::string str)
{
	StringNumber sN = str;
	if (sN.toWordNumber() != "INVALID")
		this->integer = sN.toInteger();
	else
		this->integer = -1;
}


/**
* Operator Overloading
*/
template <class T>
Integer add(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer + i2;
	return result;
}
template <class T>
Integer subtract(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer - i2;
	return result;
}
template <class T>
Integer multiply(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer * i2;
	return result;
}
template <class T>
Integer divide(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer / i2;
	return result;
}
template <class T>
Integer modulo(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer % i2;
	return result;
}
template <class T>
bool checkLT(T t, int i)
{
	Integer integer1 = i;
	Integer integer2 = t.toInteger();
	return integer1 < integer2;
}
template <class T>
bool checkGT(T t, int i)
{
	Integer integer1 = i;
	Integer integer2 = t.toInteger();
	return integer1 > integer2;
}
template <class T>
bool checkLE(T t, int i)
{
	Integer integer1 = i;
	Integer integer2 = t.toInteger();
	return integer1 <= integer2;
}
template <class T>
bool checkGE(T t, int i)
{
	Integer integer1 = i;
	Integer integer2 = t.toInteger();
	return integer1 >= integer2;
}
template <class T>
bool checkEQ(T t, int i)
{
	Integer integer1 = i;
	Integer integer2 = t.toInteger();
	return integer1 == integer2;
}
template <class T>
bool checkNE(T t, int i)
{
	Integer integer1 = i;
	Integer integer2 = t.toInteger();
	return integer1 != integer2;
}
template <class T>
Integer shiftR(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer >> i2;
	return result;
}
template <class T>
Integer shiftL(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer << i2;
	return result;
}

void Integer::operator = (const Integer& i)
{
	this->integer = i.integer;
}

Integer Integer::operator + (const Integer& i)
{
	Integer sum;
	if (this->integer == -1 || i.toInteger() == -1
		|| this->integer + i.toInteger() > 1000)
		sum = -1;
	else
		sum = this->integer + i.toInteger();
	return sum;
}

Integer Integer::operator + (const int& i)
{
	Integer sum;
	if (this->integer == -1 || i == -1
		|| this->integer + i > 1000)
		sum = -1;
	else
		sum = this->integer + i;
	return sum;
}

Integer Integer::operator + (const StringNumber& str)
{
	return add(str, this->toInteger());
}
Integer Integer::operator + (const RomanNumeral& rN)
{
	return add(rN, this->toInteger());
}

Integer Integer::operator - (const Integer& i)
{
	Integer diff;
	if (this->integer == -1 || i.toInteger() == -1
		|| this->integer - i.toInteger() < 0)
		diff = -1;
	else
		diff = this->integer - i.toInteger();
	return diff;
}

Integer Integer::operator - (const int& i)
{
	Integer sum;
	if (this->integer == -1 || i == -1
		|| this->integer - i > 1000)
		sum = -1;
	else
		sum = this->integer - i;
	return sum;
}

Integer Integer::operator - (const StringNumber& str)
{
	return subtract(str, this->toInteger());
}
Integer Integer::operator - (const RomanNumeral& rN)
{
	return subtract(rN, this->toInteger());
}

Integer Integer::operator * (const Integer& i)
{
	Integer product;
	if (this->integer == -1 || i.toInteger() == -1
		|| this->integer * i.toInteger() > 1000)
		product = -1;
	else
		product = this->integer * i.toInteger();
	return product;
}

Integer Integer::operator * (const int& i)
{
	Integer sum;
	if (this->integer == -1 || i == -1
		|| this->integer * i > 1000)
		sum = -1;
	else
		sum = this->integer * i;
	return sum;
}

Integer Integer::operator * (const StringNumber& str)
{
	return multiply(str, this->toInteger());
}
Integer Integer::operator * (const RomanNumeral& rN)
{
	return multiply(rN, this->toInteger());
}

Integer Integer::operator / (const Integer& i)
{
	Integer quotient;
	if (this->integer == -1 || i.toInteger() <= 0)
		quotient = -1;
	else
		quotient = this->integer / i.toInteger();
	return quotient;
}

Integer Integer::operator / (const int& i)
{
	Integer sum;
	if (this->integer == -1 || i == -1
		|| this->integer / i > 1000)
		sum = -1;
	else
		sum = this->integer / i;
	return sum;
}

Integer Integer::operator / (const StringNumber& str)
{
	return divide(str, this->toInteger());
}
Integer Integer::operator / (const RomanNumeral& rN)
{
	return divide(rN, this->toInteger());
}

Integer Integer::operator % (const Integer& i)
{
	Integer remainder;
	if (this->integer == -1 || i.toInteger() <= 0)
		remainder = -1;
	else
		remainder = this->integer % i.toInteger();
	return remainder;
}

Integer Integer::operator % (const int& i)
{
	Integer sum;
	if (this->integer == -1 || i == -1
		|| this->integer % i > 1000)
		sum = -1;
	else
		sum = this->integer % i;
	return sum;
}

Integer Integer::operator % (const StringNumber& str)
{
	return modulo(str, this->toInteger());
}
Integer Integer::operator % (const RomanNumeral& rN)
{
	return modulo(rN, this->toInteger());
}

bool Integer::operator < (const Integer& i)
{
	if (this->integer >= i.toInteger() || this->integer == -1 
			|| i.toInteger() == -1)
		return false;
	return true;
}
bool Integer::operator < (const StringNumber& str)
{
	return checkLT(str, this->toInteger());
}
bool Integer::operator < (const RomanNumeral& rN)
{
	return checkLT(rN, this->toInteger());
}

bool Integer::operator > (const Integer& i)
{
	if (this->integer <= i.toInteger() || this->integer == -1 
			|| i.toInteger() == -1)
		return false;
	return true;
}
bool Integer::operator > (const StringNumber& str)
{
	return checkGT(str, this->toInteger());
}
bool Integer::operator > (const RomanNumeral& rN)
{
	return checkGT(rN, this->toInteger());
}

bool Integer::operator <= (const Integer& i)
{
	if (this->integer > i.toInteger() || this->integer == -1 
			|| i.toInteger() == -1)
		return false;
	return true;
}
bool Integer::operator <= (const StringNumber& str)
{
	return checkLE(str, this->toInteger());
}
bool Integer::operator <= (const RomanNumeral& rN)
{
	return checkLE(rN, this->toInteger());
}

bool Integer::operator >= (const Integer& i)
{
	if (this->integer < i.toInteger() || this->integer == -1 
			|| i.toInteger() == -1)
		return false;
	return true;
}
bool Integer::operator >= (const StringNumber& str)
{
	return checkGE(str, this->toInteger());
}
bool Integer::operator >= (const RomanNumeral& rN)
{
	return checkGE(rN, this->toInteger());
}


bool Integer::operator == (const Integer& i)
{
	if (this->integer != i.toInteger() || this->integer == -1 
			|| i.toInteger() == -1)
		return false;
	return true;
}
bool Integer::operator == (const StringNumber& str)
{
	return checkEQ(str, this->toInteger());
}
bool Integer::operator == (const RomanNumeral& rN)
{
	return checkEQ(rN, this->toInteger());
}

bool Integer::operator != (const Integer& i)
{
	if (this->integer == i.toInteger() || this->integer == -1 
			|| i.toInteger() == -1)
		return false;
	return true;
}
bool Integer::operator != (const StringNumber& str)
{
	return checkNE(str, this->toInteger());
}
bool Integer::operator != (const RomanNumeral& rN)
{
	return checkNE(rN, this->toInteger());
}

Integer Integer::operator >> (const Integer& i)
{
	Integer result;
	if (this->integer == -1 || i.toInteger() == -1
		|| this->integer >> i.toInteger() > 1000)
		result = -1;
	else
		result = this->integer >> i.toInteger();
	return result;
}
Integer Integer::operator >> (const StringNumber& str)
{
	return shiftR(str, this->toInteger());
}
Integer Integer::operator >> (const RomanNumeral& rN)
{
	return shiftR(rN, this->toInteger());
}


Integer Integer::operator << (const Integer& i)
{
	Integer result;
	if (this->integer == -1 || i.toInteger() == -1
		|| this->integer << i.toInteger() > 1000)
		result = -1;
	else
		result = this->integer << i.toInteger();
	return result;
}
Integer Integer::operator << (const StringNumber& str)
{
	return shiftL(str, this->toInteger());
}
Integer Integer::operator << (const RomanNumeral& rN)
{
	return shiftL(rN, this->toInteger());
}


/**
* Destructor
*/
Integer::~Integer(){}

/**
* Integer Functions
*/
bool Integer::parse(){
	return this->integer >= 0 && this->integer <= 1000;
}

int Integer::toInteger() const
{
	return this->integer;
}

std::string Integer::toRomanNumeral() const
{
	if (integer == -1)
		return "INVALID";

	std::string str = "";
	int n = this->integer;
 	int index = 0;

 	while(n > 0){
 		if(n == 1000)
 			index = 1000;	
 		else if(n >= 900)
 			index = 900;
 		else if(n >= 500)
 			index = 500;
 		else if(n >= 400)
 			index = 400;
 		else if(n >= 100)
 			index = 100;
 		else if(n >= 90)
 			index = 90;
 		else if(n >= 50)
 			index = 50;
 		else if(n >= 40)
 			index = 40;
 		else if(n >= 10)
 			index = 10;
 		else if(n >= 9)
 			index = 9;
 		else if(n >= 5)
 			index = 5;
 		else if(n >= 4)
 			index = 4;
 		else if(n >= 1)
 			index = 1;

 		n -= index;
 		str += romansReference[index];
 	}
 	return str;
}

std::string Integer::toWordNumber() const
{
	if (integer == -1)
		return "INVALID";

	std::string wordNumber = "";
	int n = this->integer;
	if (n == 0)
		return count[n];
	
	int thousandsDigitValue = (n/1000) % 10;
	wordNumber += getThousandsDigitWord(thousandsDigitValue);
	
	int hundredsDigitValue = (n/100) % 10;
	wordNumber += getHundredsDigitWord(hundredsDigitValue);
	
	int tensDigitValue = (n/10) % 10;
	int onesDigitValue = n % 10;
	
	if (isException(tensDigitValue))
		wordNumber += getWordExceptions(onesDigitValue);
	else
	{
		wordNumber += getTensDigitWord(tensDigitValue);
		wordNumber += getOnesDigitWord(onesDigitValue);
	}
	
	removeExtraWhiteSpaces(wordNumber);
	
	return wordNumber;
}

/**
* Private Functions
*/
std::string getThousandsDigitWord(int thousandsDigitValue)
{
	std::string thousandsDigitInWord = "";
	if (thousandsDigitValue != 0)
	{
		thousandsDigitInWord += count[thousandsDigitValue] + whitespace;
		thousandsDigitInWord += thousandSpecifier + whitespace;
	}
	return thousandsDigitInWord;
}

std::string getHundredsDigitWord(int hundredsDigitValue)
{
	std::string hundredsDigitInWord = "";
	if (hundredsDigitValue != 0)
	{
		hundredsDigitInWord += count[hundredsDigitValue] + whitespace;
		hundredsDigitInWord += hundredSpecifier + whitespace;
	}
	return hundredsDigitInWord;
}

bool isException(int tensDigitValue)
{
	if (tensDigitValue == 1)
		return true;
	return false;
}

std::string getWordExceptions(int onesDigitValue)
{
	return tensException[onesDigitValue];
}

std::string getTensDigitWord(int tensDigitValue)
{
	std::string tensDigitInWord = "";
	if (tensDigitValue != 0)
	{
		tensDigitInWord += tens[tensDigitValue] + whitespace;
	}
	return tensDigitInWord;
}

std::string getOnesDigitWord(int onesDigitValue)
{
	std::string onesDigitInWord = "";
	if (onesDigitValue != 0)
	{
		onesDigitInWord += count[onesDigitValue];
	}
	return onesDigitInWord;
}

void removeExtraWhiteSpaces(std::string& wordNumber)
{
	if (wordNumber.at(wordNumber.length()-1) == ' ')
		wordNumber.erase(wordNumber.end()-1);

}

