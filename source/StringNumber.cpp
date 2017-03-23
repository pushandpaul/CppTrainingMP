#include <iostream>
#include "Integer.hpp"
#include "RomanNumeral.hpp"
#include "StringNumber.hpp"
#include <vector>
#include <algorithm>

/**
* Constants
*/
const std::string count[10] = {"zero","one","two","three","four",
		"five","six","seven","eight","nine"};
const std::string tensException[10] = {"ten","eleven","twelve",
		"thirteen","fourteen","fifteen","sixteen","seventeen",
		"eighteen","nineteen"};
const std::string tens[10] = {"XX","XX","twenty", "thirty","forty",
		"fifty","sixty","seventy","eighty","ninety"};
const std::string hundredSpecifier = "hundred";
const std::string thousandSpecifier = "thousand";
const std::string whitespace = " ";

/**
* Private Function Prototypes
*/
std::vector<std::string> splitString(std::string stringNumber);
int getThousandsValue(std::vector<std::string> splitWords);
int getHundredsValue(std::vector<std::string> splitWords);
int getTensValue(std::vector<std::string> splitWords);
int getOnesValue(std::vector<std::string> splitWords);
int getExceptionValue(int value);
int getIndexOfWord(std::vector<std::string>& vector, 
						std::string search);
int getIndexOfWord(const std::string str[10], std::string search);
int isException(std::vector<std::string> splitWords);

int checkThousandSpecifier(std::string str);
int checkHundredSpecifier(std::string str);
int checkTensValue(std::string str, std::string& tensValue);
int checkExceptionSpecifier(std::string str, std::string& exception);
bool isPositionValid(std::vector<std::string> splitWords, 
						const std::string wordContainer[2]);
bool isValidWord(std::string word);

						
/**
* Constructors
*/
StringNumber::StringNumber()
{
	this->stringNumber = "zero";
}

StringNumber::StringNumber(std::string value)
{

	std::transform(value.begin(), value.end(), value.begin(), ::tolower);

	this->stringNumber = value;
	if (parse())
		this->stringNumber = value;
	else
		this->stringNumber = "INVALID";
}

StringNumber::StringNumber(int n)
{
	Integer integer = n;
	if (integer.parse())
		this->stringNumber = integer.toWordNumber();
	else
		this->stringNumber = "INVALID";
}

/**
* Operator Overloading
*/
void StringNumber::operator = (const StringNumber& s)
{
	this->stringNumber = s.stringNumber;
}
void StringNumber::operator = (const std::string& value)
{
	this->stringNumber = StringNumber(value).toWordNumber();
}

template <class T>
StringNumber add(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer + i2;
	StringNumber resultInWord = result.toWordNumber();
	return resultInWord;
}
template <class T>
StringNumber subtract(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer - i2;
	StringNumber resultInWord = result.toWordNumber();
	return resultInWord;
}
template <class T>
StringNumber multiply(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer * i2;
	StringNumber resultInWord = result.toWordNumber();
	return resultInWord;
}
template <class T>
StringNumber divide(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer / i2;
	StringNumber resultInWord = result.toWordNumber();
	return resultInWord;
}
template <class T>
StringNumber modulo(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer % i2;
	StringNumber resultInWord = result.toWordNumber();
	return resultInWord;
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
StringNumber shiftR(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer >> i2;
	StringNumber resultInWord = result.toWordNumber();
	return resultInWord;
}
template <class T>
StringNumber shiftL(T t, int i)
{
	Integer integer = i;
	Integer i2 = t.toInteger();
	Integer result = integer << i2;
	StringNumber resultInWord = result.toWordNumber();
	return resultInWord;
}


StringNumber StringNumber::operator + (const StringNumber& str)
{
	return add(str, this->toInteger());
}
StringNumber StringNumber::operator + (const Integer& i)
{
	return add(i, this->toInteger());
}
StringNumber StringNumber::operator + (const RomanNumeral& rN)
{
	return add(rN, this->toInteger());
}


StringNumber StringNumber::operator - (const StringNumber& str)
{
	return subtract(str, this->toInteger());
}

StringNumber StringNumber::operator - (const Integer& i)
{
	return subtract(i, this->toInteger());
}
StringNumber StringNumber::operator - (const RomanNumeral& rN)
{
	return subtract(rN, this->toInteger());
}


StringNumber StringNumber::operator * (const StringNumber& str)
{
	return multiply(str, this->toInteger());
}

StringNumber StringNumber::operator * (const Integer& i)
{
	return multiply(i, this->toInteger());
}
StringNumber StringNumber::operator * (const RomanNumeral& rN)
{
	return multiply(rN, this->toInteger());
}

StringNumber StringNumber::operator / (const StringNumber& str)
{
	return divide(str, this->toInteger());
}

StringNumber StringNumber::operator / (const Integer& i)
{
	return divide(i, this->toInteger());
}
StringNumber StringNumber::operator / (const RomanNumeral& rN)
{
	return divide(rN, this->toInteger());
}

StringNumber StringNumber::operator % (const StringNumber& str)
{
	return modulo(str, this->toInteger());
}

StringNumber StringNumber::operator % (const Integer& i)
{
	return modulo(i, this->toInteger());
}
StringNumber StringNumber::operator % (const RomanNumeral& rN)
{
	return modulo(rN, this->toInteger());
}



bool StringNumber::operator < (const StringNumber& str)
{
	return checkLT(str, this->toInteger());
}

bool StringNumber::operator < (const Integer& i)
{
	return checkLT(i, this->toInteger());
}
bool StringNumber::operator < (const RomanNumeral& rN)
{
	return checkLT(rN, this->toInteger());
}

bool StringNumber::operator > (const StringNumber& str)
{
	return checkGT(str, this->toInteger());
}

bool StringNumber::operator > (const Integer& i)
{
	return checkGT(i, this->toInteger());
}
bool StringNumber::operator > (const RomanNumeral& rN)
{
	return checkGT(rN, this->toInteger());
}

bool StringNumber::operator <= (const StringNumber& str)
{
	return checkLE(str, this->toInteger());
}

bool StringNumber::operator <= (const Integer& i)
{
	return checkLE(i, this->toInteger());
}
bool StringNumber::operator <= (const RomanNumeral& rN)
{
	return checkLE(rN, this->toInteger());
}

bool StringNumber::operator >= (const StringNumber& str)
{
	return checkGE(str, this->toInteger());
}

bool StringNumber::operator >= (const Integer& i)
{
	return checkGE(i, this->toInteger());
}
bool StringNumber::operator >= (const RomanNumeral& rN)
{
	return checkGE(rN, this->toInteger());
}
bool StringNumber::operator == (const StringNumber& str)
{
	return checkEQ(str, this->toInteger());
}

bool StringNumber::operator == (const Integer& i)
{
	return checkEQ(i, this->toInteger());
}
bool StringNumber::operator == (const RomanNumeral& rN)
{
	return checkEQ(rN, this->toInteger());
}

bool StringNumber::operator != (const StringNumber& str)
{
	return checkNE(str, this->toInteger());
}

bool StringNumber::operator != (const Integer& i)
{
	return checkNE(i, this->toInteger());
}
bool StringNumber::operator != (const RomanNumeral& rN)
{
	return checkNE(rN, this->toInteger());
}


StringNumber StringNumber::operator << (const StringNumber& str)
{
	return shiftL(str, this->toInteger());
}
StringNumber StringNumber::operator << (const Integer& i)
{
	return shiftL(i, this->toInteger());
}
StringNumber StringNumber::operator << (const RomanNumeral& rN)
{
	return shiftL(rN, this->toInteger());
}

StringNumber StringNumber::operator >> (const StringNumber& str)
{
	return shiftR(str, this->toInteger());
}
StringNumber StringNumber::operator >> (const Integer& i)
{
	return shiftR(i, this->toInteger());
}
StringNumber StringNumber::operator >> (const RomanNumeral& rN)
{
	return shiftR(rN, this->toInteger());
}


/**
* Destructor
*/
StringNumber::~StringNumber(){}

/**
* StringNumber Functions
*/
bool StringNumber::parse() {
	
	std::vector<std::string> splitWords = splitString(this->stringNumber);
	// Max Length
	if (splitWords.size() > 6)
		return false;

	int thousandSpecifierCount = 0;
	int hundredSpecifierCount = 0;
	int tensValueCount = 0;
	int exceptionsCount = 0;
	
	std::string wordContainer[2] = {"XXX","XXX"};
	
	for (std::string element: splitWords)
	{
		if (!isValidWord(element))
			return false;
		
		thousandSpecifierCount += checkThousandSpecifier(element);
		hundredSpecifierCount += checkHundredSpecifier(element);
		tensValueCount += checkTensValue(element, wordContainer[0]);
		exceptionsCount += checkExceptionSpecifier(element, wordContainer[1]);
		
		if (thousandSpecifierCount > 1 || hundredSpecifierCount > 1 ||
			tensValueCount > 1 || exceptionsCount > 1)
			return false;
	}
	if (!isPositionValid(splitWords, wordContainer))
		return false;
	
	return true;
}

int StringNumber::toInteger() const
{
	int integer = 0;
	
	std::string stringNumber = this->stringNumber;
	std::vector<std::string> splitWords = splitString(stringNumber);
	
	if (stringNumber == "INVALID")
		return -1;
	
	integer += getThousandsValue(splitWords);
	integer += getHundredsValue(splitWords);
	
	int indexInExceptionsList = isException(splitWords);	
	if (indexInExceptionsList != -1)
		integer += getExceptionValue(indexInExceptionsList);
	else
	{
		integer += getTensValue(splitWords);
		integer += getOnesValue(splitWords);
	}
	return integer;
}

std::string StringNumber::toWordNumber() const
{
	return this->stringNumber;
}


std::string StringNumber::toRomanNumeral() const
{
	Integer i = this->toInteger();
	return i.toRomanNumeral();	
}

/**
* Private Functions
*/
std::vector<std::string> splitString(std::string stringNumber)
{
	std::vector<std::string> splitWords;
	std::string temp = "";
	for (int i = 0; i < stringNumber.length(); i++)
	{
		if (stringNumber[i] == ' ')
		{
			splitWords.push_back(temp);
			temp = "";
		}
		else if (i == stringNumber.length() - 1)
		{
			temp += stringNumber[i];
			splitWords.push_back(temp);
		}
		else
		{
			temp += stringNumber[i];
		}
	}
	return splitWords;
}

int getThousandsValue(std::vector<std::string> splitWords)
{
	int value = 0;
	int indexOfSpecifier = getIndexOfWord(splitWords,thousandSpecifier);
	if (indexOfSpecifier != -1)
		value += 1000*getIndexOfWord(count, splitWords[indexOfSpecifier-1]);
	return value;
}

int getHundredsValue(std::vector<std::string> splitWords)
{
	int value = 0;
	int indexOfSpecifier = getIndexOfWord(splitWords,hundredSpecifier);
	if (indexOfSpecifier != -1)
		value += 100*getIndexOfWord(count, splitWords[indexOfSpecifier-1]);
	return value;
}

int getTensValue(std::vector<std::string> splitWords)
{
	int value = 0;
	int length = splitWords.size()-1;

	// If Tens value(word) is the last word
	int indexOfTensValue = getIndexOfWord(tens, splitWords[length]);
	if (indexOfTensValue != -1)
		return 10*indexOfTensValue;
		
	if (length >= 1)
	{
		// If Tens value(word) is the second to the last word
		indexOfTensValue = getIndexOfWord(tens, splitWords[length-1]);
		if (indexOfTensValue != -1)
			return 10*indexOfTensValue;
	}

	return 0;
}

int getOnesValue(std::vector<std::string> splitWords)
{
	int value = 0;
	int length = splitWords.size()-1;
	
	int indexOfTensValue = getIndexOfWord(count, splitWords[length]);
	if (indexOfTensValue != -1)
		return indexOfTensValue;
	
	return 0;
}

int getExceptionValue(int value)
{
	return 10 + value;
}

int isException(std::vector<std::string> splitWords)
{
	int indexInExceptionsList = 0;
	for (auto element: splitWords)
	{
		indexInExceptionsList = getIndexOfWord(tensException, element);
		if (indexInExceptionsList != -1)
			return indexInExceptionsList;
	}
	return -1;
}

int getIndexOfWord(std::vector<std::string>& vector, 
						std::string search)
{
	auto it = find(vector.begin(), vector.end(), search);
	if (it == vector.end())
		return -1;
	else
		return it - vector.begin();
}

int getIndexOfWord(const std::string str[10], std::string search)
{
	for (int i = 0; i < 10; i++)
	{
		if (str[i] == search)
		{
			return i;
		}
	}
	return -1;
}


int checkThousandSpecifier(std::string str)
{
	if(str == thousandSpecifier)
		return 1;
	return 0;
}

int checkHundredSpecifier(std::string str)
{
	if(str == hundredSpecifier)
		return 1;
	return 0;
}

int checkTensValue(std::string str, std::string& tensValue)
{
	int indexOfTensValue = getIndexOfWord(tens, str);
	if(indexOfTensValue != -1)
	{
		tensValue = str;
		return 1;
	}
	return 0;
}

int checkExceptionSpecifier(std::string str, std::string& exception)
{
	int indexOfException = getIndexOfWord(tensException, str);
	if(indexOfException != -1)
	{
		exception = str;
		return 1;
	}
	return 0;
}

bool isPositionValid(std::vector<std::string> splitWords, 
				const std::string wordContainer[2])
{
	int indexOfThousandsSpecifier = getIndexOfWord(splitWords,
								thousandSpecifier);
	int indexOfHundredSpecifier = getIndexOfWord(splitWords,
								hundredSpecifier);
	int indexOfTensValue = getIndexOfWord(splitWords,
								wordContainer[0]);
	int indexOfException = getIndexOfWord(splitWords,
								wordContainer[1]);
	int lengthOfSplitWord = splitWords.size() - 1;
	int indexOfZero = getIndexOfWord(splitWords, count[0]);

	// validity of zero word
	if (indexOfZero != -1 && splitWords.size() != 1)
		return false;

	// Conditions not applicable for two or more words
	if (lengthOfSplitWord < 1)
		return true;
	
	if (indexOfThousandsSpecifier != -1)
	{
		if (indexOfThousandsSpecifier != 1)
			return false;
	}
	
	if (indexOfHundredSpecifier != -1)
	{
		if (indexOfHundredSpecifier != 1 && indexOfHundredSpecifier != 3)
			return false;
	}

	if (indexOfHundredSpecifier != -1 && indexOfThousandsSpecifier != -1)
	{
		if ((indexOfHundredSpecifier > indexOfThousandsSpecifier))
			return false;
	}
	
	if (indexOfTensValue != -1)
	{
		if (indexOfTensValue != lengthOfSplitWord && 
			indexOfTensValue != lengthOfSplitWord -1)
			return false;
		if (indexOfException != -1)
			return false;
	}
	if (indexOfException != -1)
	{
		if (indexOfException != lengthOfSplitWord)
			return false;
	}
	
	return true;
}

bool isValidWord(std::string word)
{
	bool isValid = false;
	
	int indexInCountList = getIndexOfWord(count, word);
	int indexInTensList = getIndexOfWord(tens, word);
	int indexInExceptionsList = getIndexOfWord(tensException, word);
	
	if (indexInCountList != -1)
		return true;
	if (indexInTensList != -1)
		return true;
	if (indexInExceptionsList != -1)
		return true;
	if (word == thousandSpecifier)
		return true;
	if (word == hundredSpecifier)
		return true;
	return false;
}