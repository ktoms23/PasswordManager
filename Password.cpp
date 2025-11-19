//
// Created by Kya Toms on 9/8/25.
//
#include "Password.h"
#include <cmath>
#include <cctype>
using namespace std;

Password::Password() : value(""), length(0){}

Password::Password(string val) : value(val), length(val.size()) {}

Strength Password::checkStrength() const
{
    double entropy = getEntropy();

    if (entropy < 28)
    {
      return Strength::WEAK;
    }
    else if (entropy < 60)
    {
      return Strength::MEDIUM;
    }
    else
    {
      return Strength::STRONG;
    }
}

double Password::getEntropy() const {
  bool hasLower = false;
  bool hasUpper = false;
  bool hasDigit = false;
  bool hasSymbol = false;

  for (char c : value)
  {
    if (islower(c))
    {
      hasLower = true;
    }
    if (isupper(c))
    {
      hasUpper = true;
    }
    if (isdigit(c))
    {
      hasDigit = true;
    }
    if (!isalnum(c))
    {
      hasSymbol = true;
    }
  }

  int charsetSize = 0;
  if (hasLower)
  {
    charsetSize += 26;
  }
  if (hasUpper)
  {
    charsetSize += 26;
  }
  if (hasDigit)
  {
    charsetSize += 10;
  }
  if (hasSymbol)
  {
    charsetSize += 32; //estimated for number of symbols/special characters on a keyboard
  }

  if (charsetSize == 0)
  {
    return 0.0;
  }

  //entropy formula: length * log2(charsetSize)
  return length * log2(charsetSize);
}

int Password::getLength() const
{
    return length;
}

string Password::getValue() const
{
    return value;
}

bool operator==(const Password& lhs, const Password& rhs)
{
    return lhs.value == rhs.value;
}

ostream& operator<<(ostream& os, const Password& pw)
{
  // print masked password as ****
  for (int i = 0; i < pw.length; i++)
  {
    os << '*';
  }
  return os;
}

ostream& operator<<(ostream& os, Strength s)
{
  switch (s)
  {
  case Strength::WEAK: os << "Weak"; break;
  case Strength::MEDIUM: os << "Medium"; break;
  case Strength::STRONG: os << "Strong"; break;
  }
  return os;
}


