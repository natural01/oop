#include "Rational.h"
#include <iostream>
#include <sstream>
#include <math.h>

const int defaultDenominator = 1;
const int defaultNumerator = 0;

CRational::CRational()
{
	m_numerator = defaultNumerator;
	m_denominator = defaultDenominator;
}

CRational::CRational(int value)
{
	m_numerator = value;
	m_denominator = defaultDenominator;
}

CRational::CRational(int numerator, int denominator)
{
	if (denominator < defaultDenominator)
	{
		if (denominator == defaultNumerator)
		{
			throw std::invalid_argument("Denominator is zero");
		}
		else
		{
			m_numerator = -numerator;
			m_denominator = -denominator;
		}
	}
	else
	{
		m_numerator = numerator;
		m_denominator = denominator;
		Reduction();
	}
}

void CRational::SetNumerator(int numerator)
{
	m_numerator = numerator;
}

void CRational::SetDenominator(int denominator)
{
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator is zero");
	}
	m_denominator = denominator;
}

int CRational::GetNumerator() const
{
	return m_numerator;
}

int CRational::GetDenominator() const
{
	return m_denominator;
}

double CRational::ToDouble() const
{
	return (double)m_numerator / (double)m_denominator;
}

CRational CRational::operator+() const
{
	return CRational(m_numerator, m_denominator);
}

CRational CRational::operator-() const
{
	int newNumerator = 0 - m_numerator;
	return CRational(newNumerator, m_denominator);
}

void CRational::Reduction()
{
	int denominator = m_denominator;
	int divider = abs(m_numerator);
	while (divider != denominator) {
		if (divider > denominator) {
			divider = divider - denominator;
		}
		else {
			denominator = denominator - divider;
		}
	}
	m_numerator /= divider;
	m_denominator /= divider;
}

CRational& CRational::operator+=(const CRational& rational)
{
	m_numerator = m_numerator * rational.GetDenominator() + rational.GetNumerator() * m_denominator;
	m_denominator *= rational.GetDenominator();
	Reduction();
	return *this;
}

CRational& CRational::operator-=(const CRational& rational)
{
	m_numerator = m_numerator * rational.GetDenominator() - rational.GetNumerator() * m_denominator;
	m_denominator *= rational.GetDenominator();
	Reduction();
	return *this;
}

CRational& CRational::operator*=(const CRational& rational)
{
	m_numerator *= rational.GetNumerator();
	m_denominator *= rational.GetDenominator();
	Reduction();
	return *this;
}

CRational& CRational::operator/=(const CRational& rational)
{
	if (rational.GetNumerator() == 0)
	{
		throw std::invalid_argument("Denominator is zero");
	}
	m_numerator *= rational.GetDenominator();
	m_denominator *= rational.GetNumerator();
	Reduction();
	return *this;
}

CRational operator+(const CRational& firstNum, const CRational& secondNum)
{
	int newNumerator = firstNum.GetNumerator() * secondNum.GetDenominator() + secondNum.GetNumerator() * firstNum.GetDenominator();
	int newDenominator = firstNum.GetDenominator() * secondNum.GetDenominator();
	return CRational(newNumerator, newDenominator);
}

CRational operator-(const CRational& firstNum, const CRational& secondNum)
{
	int newNumerator = firstNum.GetNumerator() * secondNum.GetDenominator() - secondNum.GetNumerator() * firstNum.GetDenominator();
	int newDenominator = firstNum.GetDenominator() * secondNum.GetDenominator();
	return CRational(newNumerator, newDenominator);
}

CRational operator*(const CRational& firstNum, const CRational& secondNum)
{
	int newNumerator = firstNum.GetNumerator() * secondNum.GetNumerator();
	int newDenominator = secondNum.GetDenominator() * firstNum.GetDenominator();
	return CRational(newNumerator, newDenominator);
}

CRational operator/(const CRational& firstNum, const CRational& secondNum)
{
	if (secondNum.GetNumerator() == 0)
	{
		throw std::invalid_argument("Denominator is zero");
	}
	int newNumerator = firstNum.GetNumerator() * secondNum.GetDenominator();
	int newDenominator = firstNum.GetDenominator() * secondNum.GetNumerator();
	return CRational(newNumerator, newDenominator);
}

bool operator==(const CRational& firstNum, const CRational& secondNum)
{
	return firstNum.GetNumerator() == secondNum.GetNumerator() && firstNum.GetDenominator() == secondNum.GetDenominator();
}

bool operator!=(const CRational& firstNum, const CRational& secondNum)
{
	return firstNum.GetNumerator() != secondNum.GetNumerator() || firstNum.GetDenominator() != secondNum.GetDenominator();
}

bool operator<(const CRational& firstNum, const CRational& secondNum)
{
	return firstNum.GetNumerator() * secondNum.GetDenominator() < firstNum.GetDenominator() * secondNum.GetNumerator();
}

bool operator<=(const CRational& firstNum, const CRational& secondNum)
{
	return firstNum.GetNumerator() * secondNum.GetDenominator() <= firstNum.GetDenominator() * secondNum.GetNumerator();
}

bool operator>(const CRational& firstNum, const CRational& secondNum)
{
	return firstNum.GetNumerator() * secondNum.GetDenominator() > firstNum.GetDenominator() * secondNum.GetNumerator();
}

bool operator>=(const CRational& firstNum, const CRational& secondNum)
{
	return firstNum.GetNumerator() * secondNum.GetDenominator() >= firstNum.GetDenominator() * secondNum.GetNumerator();
}

void operator<<(std::ostream& ostream, const CRational& rational)
{
	ostream << rational.GetNumerator() << "/" << rational.GetDenominator();
}

std::istream& operator>>(std::istream& istream, CRational& rational)
{
    char slesh;
	int numerator, denominator;
	istream >> numerator >> slesh >> denominator;
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator is zero");
	}
	rational.SetNumerator(numerator);
	rational.SetDenominator(denominator);
	rational.Reduction();
	return istream;
}