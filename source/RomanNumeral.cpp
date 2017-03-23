#include <RomanNumeral.hpp>

std::map<char, int> _romans = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
const std::string invalid = "INVALID";

RomanNumeral::RomanNumeral()
{
    roman = "";
}

RomanNumeral::RomanNumeral(int i)
{
    Integer integer = i;

    if(integer.parse()){
        roman = integer.toRomanNumeral();
    }
    else
        roman = invalid;
}

RomanNumeral::RomanNumeral(std::string str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    roman = str;

    if(!parse())
        roman = invalid;
}

RomanNumeral::~RomanNumeral(){}

//overload templates

void RomanNumeral::operator = (const int& i)
{
    Integer _i = i;
    this->roman = _i.toRomanNumeral();
}

void RomanNumeral::operator = (const Integer& i)
{
    this->roman = i.toRomanNumeral();
}

void RomanNumeral::operator = (const std::string& str)
{
    RomanNumeral roman(str);
    this->roman = roman.toRomanNumeral();
}

template <class T>
RomanNumeral add(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    Integer result = i1 + i2;
    RomanNumeral resultInRoman = result.toRomanNumeral();
    return resultInRoman;
}

template <class T>
RomanNumeral subtract(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    Integer result = i1 - i2;
    RomanNumeral resultInRoman = result.toRomanNumeral();
    return resultInRoman;
}

template <class T>
RomanNumeral multiply(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    Integer result = i1 * i2;
    RomanNumeral resultInRoman = result.toRomanNumeral();
    return resultInRoman;
}

template <class T>
RomanNumeral divide(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    Integer result = i1 / i2;
    RomanNumeral resultInRoman = result.toRomanNumeral();
    return resultInRoman;
}

template <class T>
RomanNumeral modulo(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    Integer result = i1 % i2;
    RomanNumeral resultInRoman = result.toRomanNumeral();
    return resultInRoman;
}

template <class T>
RomanNumeral shiftR(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    Integer result = i1 >> i2;
    RomanNumeral resultInRoman = result.toRomanNumeral();
    return resultInRoman;
}
template <class T>
RomanNumeral shiftL(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    Integer result = i1 << i2;
    RomanNumeral resultInRoman = result.toRomanNumeral();
    return resultInRoman;
}

template <class T>
bool checkLT(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    return i1 < i2;
}

template <class T>
bool checkGT(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    return i1 > i2;
}

template <class T>
bool checkLE(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    return i1 <= i2;
}

template <class T>
bool checkGE(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    return i1 >= i2;
}

template <class T>
bool checkEQ(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    return i1 == i2;
}

template <class T>
bool checkNE(int romanInInt, T t)
{
    Integer i1 = romanInInt;
    Integer i2 = t.toInteger();
    return i1 != i2;
}

//addition overload
RomanNumeral RomanNumeral::operator + (const StringNumber& strNum)
{
    return add(this->toInteger(), strNum);
}

RomanNumeral RomanNumeral::operator + (const RomanNumeral& _roman)
{
    return add(this->toInteger(), _roman);
}

RomanNumeral RomanNumeral::operator + (const Integer& i)
{
    return add(this->toInteger(), i);
}

RomanNumeral RomanNumeral::operator + (const int& i)
{
    Integer integer = this->toInteger() + i;
    RomanNumeral roman(integer.toRomanNumeral());
    return roman;
}

RomanNumeral RomanNumeral::operator - (const StringNumber& strNum)
{
    return subtract(this->toInteger(), strNum);
}

RomanNumeral RomanNumeral::operator - (const RomanNumeral& _roman)
{
    return subtract(this->toInteger(), _roman);
}

RomanNumeral RomanNumeral::operator - (const Integer& i)
{
    return subtract(this->toInteger(), i);
}

RomanNumeral RomanNumeral::operator - (const int& i)
{
    Integer integer = this->toInteger() - i;
    RomanNumeral roman(integer.toRomanNumeral());
    return roman;
}

//multiplication overload
RomanNumeral RomanNumeral::operator * (const StringNumber& strNum)
{
    return multiply(this->toInteger(), strNum);
}

RomanNumeral RomanNumeral::operator * (const RomanNumeral& _roman)
{
    return multiply(this->toInteger(), _roman);
}

RomanNumeral RomanNumeral::operator * (const Integer& i)
{
    return multiply(this->toInteger(), i);
}

RomanNumeral RomanNumeral::operator * (const int& i)
{
    Integer integer = this->toInteger() * i;
    RomanNumeral roman(integer.toRomanNumeral());
    return roman;
}

//division overload
RomanNumeral RomanNumeral::operator / (const StringNumber& strNum)
{
    return divide(this->toInteger(), strNum);
}

RomanNumeral RomanNumeral::operator / (const RomanNumeral& _roman)
{
    return divide(this->toInteger(), _roman);
}

RomanNumeral RomanNumeral::operator / (const Integer& i)
{
    return divide(this->toInteger(), i);
}

RomanNumeral RomanNumeral::operator / (const int& i)
{
    Integer integer = this->toInteger() / i;
    RomanNumeral roman(integer.toRomanNumeral());
    return roman;
}

//modulo overload
RomanNumeral RomanNumeral::operator % (const StringNumber& strNum)
{
    return modulo(this->toInteger(), strNum);
}

RomanNumeral RomanNumeral::operator % (const RomanNumeral& _roman)
{
    return modulo(this->toInteger(), _roman);
}

RomanNumeral RomanNumeral::operator % (const Integer& i)
{
    return modulo(this->toInteger(), i);
}

RomanNumeral RomanNumeral::operator % (const int& i)
{
    Integer integer = this->toInteger() % i;
    RomanNumeral roman(integer.toRomanNumeral());
    return roman;
}

//Bin right shift overload
RomanNumeral RomanNumeral::operator >> (const StringNumber& strNum)
{
    return shiftR(this->toInteger(), strNum);
}

RomanNumeral RomanNumeral::operator >> (const RomanNumeral& _roman)
{
    return shiftR(this->toInteger(), _roman);
}

RomanNumeral RomanNumeral::operator >> (const Integer& i)
{
    return shiftR(this->toInteger(), i);
}

RomanNumeral RomanNumeral::operator >> (const int& i)
{
    Integer integer = this->toInteger() >>  i;
    RomanNumeral roman(integer.toRomanNumeral());
    return roman;
}

//Bin left shift overload
RomanNumeral RomanNumeral::operator << (const StringNumber& strNum)
{
    return shiftL(this->toInteger(), strNum);
}

RomanNumeral RomanNumeral::operator << (const RomanNumeral& _roman)
{
    return shiftL(this->toInteger(), _roman);
}

RomanNumeral RomanNumeral::operator << (const Integer& i)
{
    return shiftL(this->toInteger(), i);
}

RomanNumeral RomanNumeral::operator << (const int& i)
{
    Integer integer = this->toInteger() <<  i;
    RomanNumeral roman(integer.toRomanNumeral());
    return roman;
}

//logic overloads
bool RomanNumeral::operator < (const StringNumber& strNum)
{
    return checkLT(this->toInteger(), strNum);
}

bool RomanNumeral::operator < (const RomanNumeral& _roman)
{
    return checkLT(this->toInteger(), _roman);
}

bool RomanNumeral::operator < (const Integer& i)
{
    return checkLT(this->toInteger(), i);
}

bool RomanNumeral::operator < (const int& i)
{
    return this->toInteger() < i;
}

bool RomanNumeral::operator > (const StringNumber& strNum)
{
    return checkGT(this->toInteger(), strNum);
}

bool RomanNumeral::operator > (const RomanNumeral& _roman)
{
    return checkGT(this->toInteger(), _roman);
}

bool RomanNumeral::operator > (const Integer& i)
{
    return checkGT(this->toInteger(), i);
}

bool RomanNumeral::operator > (const int& i)
{
    return this->toInteger() > i;
}

bool RomanNumeral::operator <= (const StringNumber& strNum)
{
    return checkLE(this->toInteger(), strNum);
}

bool RomanNumeral::operator <= (const RomanNumeral& _roman)
{
    return checkLE(this->toInteger(), _roman);
}

bool RomanNumeral::operator <= (const Integer& i)
{
    return checkLE(this->toInteger(), i);
}

bool RomanNumeral::operator <= (const int& i)
{
    return this->toInteger() <= i;
}

bool RomanNumeral::operator >= (const StringNumber& strNum)
{
    return checkGE(this->toInteger(), strNum);
}

bool RomanNumeral::operator >= (const RomanNumeral& _roman)
{
    return checkGE(this->toInteger(), _roman);
}

bool RomanNumeral::operator >= (const Integer& i)
{
    return checkGE(this->toInteger(), i);
}

bool RomanNumeral::operator >= (const int& i)
{
    return this->toInteger() >= i;
}

bool RomanNumeral::operator == (const StringNumber& strNum)
{
    return checkEQ(this->toInteger(), strNum);
}

bool RomanNumeral::operator == (const RomanNumeral& _roman)
{
    return checkEQ(this->toInteger(), _roman);
}

bool RomanNumeral::operator == (const Integer& i)
{
    return checkEQ(this->toInteger(), i);
}

bool RomanNumeral::operator == (const int& i)
{
    return this->toInteger() == i;
}

bool RomanNumeral::operator != (const StringNumber& strNum)
{
    return checkNE(this->toInteger(), strNum);
}

bool RomanNumeral::operator != (const RomanNumeral& _roman)
{
    return checkNE(this->toInteger(), _roman);
}

bool RomanNumeral::operator != (const Integer& i)
{
    return checkNE(this->toInteger(), i);
}

bool RomanNumeral::operator != (const int& i)
{
    return this->toInteger() != i;
}

std::string RomanNumeral::toRomanNumeral() const
{
    return this->roman;
}

int RomanNumeral::toInteger() const
{ 
    int n = 0;
    int toAdd = 0;
    std::string str = this->roman;

    if(str == invalid)
        return -1;

    for(int i = 0; i < str.length(); i ++)
    {
        if(i < str.length()-1)
        {
            if(_romans[str[i]] < _romans[str[i+1]])
            {
                toAdd = _romans[str[i + 1]] - _romans[str[i]];
                i++;
            }
            else
                toAdd = _romans[str[i]];
        }
        else
            toAdd = _romans[str[i]];
        n += toAdd;
    }

    if(n < 0 || n > 1000)
        return -1;

    return n;
}

bool RomanNumeral::parse()
{
    std::vector<bool> donePlace = {false, false, false, false};
    std::map<char,int> places = {{'I',0}, {'V',0}, {'X',1}, {'L',1}, {'C',2}, {'D',2}, {'M',3}};
    
    std::string str = this->roman;
    int curr_place = places[str[0]];
    bool checkDigit = false;
    std::string digit = "";
    std::string reserved = "";
    
    digit += str[0]; 
    
    if(!checkIfValidChars(str))
        return false;

    if(curr_place <= 3)
        markDonePlace(donePlace, curr_place + 1);

    for(int i = 1; i < str.size();i++)
    {

        if(curr_place == places[str[i]] && !donePlace[curr_place])
        {
            digit += str[i];
        }
        else if(curr_place > places[str[i]])
        {
            checkDigit = true;
            reserved += str[i];
            markDonePlace(donePlace, curr_place);
            curr_place = places[str[i]];
        }
        else if(curr_place < places[str[i]])
        {
            if((str[i-1] == 'I' && str[i] == 'X') || (str[i-1] == 'X' && str[i] == 'C') || (str[i-1] == 'C' && str[i] == 'M'))
            {
                if(!donePlace[curr_place])
                {
                    digit += str[i];
                    checkDigit = true;
                    markDonePlace(donePlace, curr_place);
                }
                else
                {
                    //std::cout << "Digit done" << std::endl;
                    return false;
                }
            }
            else
            {
                //std::cout << "Wrong precedence" << std::endl;
                return false;
            }
        }
        else
        {
            //std::cout << "XXXXX" << std::endl;
            return false;
        }

        if(checkDigit || i == str.size() - 1)
        {
            if(!checkIfValidDigit(digit))
            {
                //std::cout << "Digit not valid: " << digit << std::endl;
                return false;
            }
            checkDigit = false;
            digit = "";
            digit += reserved;
            reserved = "";
        }
    }
    return true;
}

void RomanNumeral::markDonePlace(std::vector<bool>& donePlace, int start)
{
    for(int i = start; i < donePlace.size(); i++)
    {
        donePlace[i] = true;
    }
}   

bool RomanNumeral::checkIfValidDigit(std::string& str)
{
    std::vector<std::string> validDigits = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
                                            "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
                                            "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
                                            "M", ""};
    if(std::find(validDigits.begin(), validDigits.end(), str) == validDigits.end())
    {
        return false;
    }   
    else
    {
        return true;
    }
}

bool RomanNumeral::checkIfValidChars(std::string& str)
{
    //std::cout << str;
    for(char ch:str)
    {
        if(ch != 'I' && ch != 'V' && ch != 'X' && ch != 'L' && ch != 'C' && ch != 'D' && ch != 'M')
            return false;
    }
    return true;
}
    
