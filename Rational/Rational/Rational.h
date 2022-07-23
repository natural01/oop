#pragma once
#include <iostream>

class CRational
{
public:
	CRational();
	CRational(int value);
	CRational(int numerator, int denominator);

	CRational operator+() const;
	CRational operator-() const;

	CRational& operator+=(const CRational& rational);
	CRational& operator-=(const CRational& rational);
	CRational& operator*=(const CRational& rational);
	CRational& operator/=(const CRational& rational);

	int GetNumerator()const;
	int GetDenominator()const;
	double ToDouble()const;

private:
	int m_numerator;
	int m_denominator;
	void Reduction();
};

CRational operator+(const CRational& firstNum, const CRational& secondNum);
CRational operator-(const CRational& firstNum, const CRational& secondNum);
CRational operator*(const CRational& firstNum, const CRational& secondNum);
CRational operator/(const CRational& firstNum, const CRational& secondNum);
bool operator==(const CRational& firstNum, const CRational& secondNum);
bool operator!=(const CRational& firstNum, const CRational& secondNum);
bool operator>(const CRational& firstNum, const CRational& secondNum);
bool operator<(const CRational& firstNum, const CRational& secondNum);
bool operator<=(const CRational& firstNum, const CRational& secondNum);
bool operator>=(const CRational& firstNum, const CRational& secondNum);
void operator<<(std::ostream& ostream, const CRational& secondNum);
void operator>>(std::istream& istream, const CRational& secondNum);