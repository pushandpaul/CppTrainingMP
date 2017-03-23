#pragma once
#include <iostream>

class Number {
public:
	int toInteger() const;
	std::string toRomanNumeral() const;
	std::string toWordNumber() const;
	virtual bool parse() = 0;
};