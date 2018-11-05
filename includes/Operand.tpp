#include <string>
#include <sstream>
#include <iomanip>
#include <limits>
#include <math.h>
#include <regex>
#include "IOperand.hpp"
#include "Operand.hpp"

/*
** Constructeurs
*/

template <typename T>
Operand<T>::Operand(eOperandType const & type, std::string const & value)
	: _type(type)
{
	try
	{
		if (eOperandTypeIsInteger(type))
		{
			int number = this->getIntegerFromString(value);
			this->_value = static_cast<T>(number);
			if (this->_value != number)
				throw OverflowException();
		}
		else
		{
			double number = this->getDoubleFromString(value);
			this->_value = static_cast<T>(number);
		}
	}
	catch (std::invalid_argument)
	{
		throw InvalidValueException();
	}
	catch (std::out_of_range)
	{
		throw OverflowException();
	}

	if (isnan(this->_value))
		this->_str = "nan";
	else
		this->_str = value;
}

template <typename T>
Operand<T>::Operand(Operand const & src)
{
	this = src;
}

template <typename T>
Operand<T>::~Operand(void)
{
}

/*
** Public functions
*/

template <typename T>
int				Operand<T>::getPrecision(void) const
{
	return static_cast<int>(this->_type);
}

template <typename T>
eOperandType	Operand<T>::getType(void) const
{
	return this->_type;
}

/*
** Operator overload
*/

static std::string getValueToCleanString(double value, eOperandType type)
{
	std::stringstream		result;
	std::string				string;
	std::regex				trailing_zeros("(\\.[0-9][1-9]*)(0*)$");

	if (eOperandTypeIsInteger(type))
		result << std::fixed << std::setprecision(0) << value;
	else
		result << std::fixed << std::noshowpoint << std::setprecision(5) << value;

	string = result.str();
	string = std::regex_replace(string, trailing_zeros, "$1");
	return string;
}

template <typename T>
IOperand const * Operand<T>::makeOperation(char const operation, IOperand const & rhs) const
{
	eOperandType			newType;
	double					newValue;
	double					rhsValue;

	try
	{
		newType = higher(this->getType(), rhs.getType());
		rhsValue = this->getDoubleFromString(rhs.toString());

		switch (operation) {
			case '+':
				newValue = rhsValue + this->_value;
				break;
			case '-':
				newValue = rhsValue - this->_value;
				break;
			case '*':
				newValue = rhsValue * this->_value;
				break;
			case '/':
				if (this->_value == 0)
					throw DivisionByZeroException();
				newValue = rhsValue / this->_value;
				break;
			case '%':
				if (this->_value == 0)
					throw DivisionByZeroException();
				newValue = fmod(rhsValue, this->_value);
				break;
		}

		return OperandFactory::createOperand(newType, getValueToCleanString(newValue, newType));

	}
	catch (DivisionByZeroException & err) {
		throw DivisionByZeroException();
	}
	catch (std::exception & err) {
		throw OverflowException();
	}
}

template <typename T>
IOperand const * Operand<T>::operator+(IOperand const & rhs) const
{
	return makeOperation('+', rhs);
}

template <typename T>
IOperand const * Operand<T>::operator-(IOperand const & rhs) const
{
	return makeOperation('-', rhs);
}

template <typename T>
IOperand const * Operand<T>::operator*(IOperand const & rhs) const
{
	return makeOperation('*', rhs);
}

template <typename T>
IOperand const * Operand<T>::operator/(IOperand const & rhs) const
{
	return makeOperation('/', rhs);
}

template <typename T>
IOperand const * Operand<T>::operator%(IOperand const & rhs) const
{
	return makeOperation('%', rhs);
}

template <typename T>
IOperand const & Operand<T>::operator=(IOperand const & rhs)
{
	try
	{
		Operand<T> const & opRhs = dynamic_cast<Operand<T> const &>(rhs);
		this->_value = opRhs._value;
		this->_type = opRhs._type;
		this->_str = opRhs._str;
	}
	catch (std::exception & err)
	{
		std::cerr << "error : " << err.what() << std::endl;
	}
	return (*this);
}

template <typename T>
std::string const & Operand<T>::toString(void) const
{
	return (this->_str);
}

std::ostream & operator<<(std::ostream& o, IOperand const & rhs)
{
	o << std::noshowpoint << rhs.toString();
	return (o);
}

bool			operator==(IOperand const & lhs, IOperand const & rhs)
{
	if (lhs.getType() == rhs.getType())
	{
		double v1 = std::stod(lhs.toString());
		double v2 = std::stod(rhs.toString());
		return (v1 == v2 || (isnan(v1) && isnan(v2)));
	}
	return (false);
}

/*
** Private functions
*/

template <typename T>
int Operand<T>::getIntegerFromString(std::string const & value) const
{
	size_t next;
	int conv;

	conv = std::stoi(value, &next);
	if (next > value.length() || value[next] != '\0')
		throw InvalidValueException();
	return conv;
}

template <typename T>
double Operand<T>::getDoubleFromString(std::string const & value) const
{
	size_t next;
	double conv;

	conv = std::stod(value, &next);
	if (next > value.length() || value[next] != '\0')
		throw InvalidValueException();
	return conv;
}

/*
** Exceptions
*/
template <typename T>
const char *Operand<T>::InvalidValueException::what() const throw()
{
	return ("Value is not valid");
}

template <typename T>
const char *Operand<T>::OverflowException::what() const throw()
{
	return ("Value is not valid: overflow");
}

template <typename T>
const char *Operand<T>::DivisionByZeroException::what() const throw()
{
	return ("Trying to divide by zero");
}
