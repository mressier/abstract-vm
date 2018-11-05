#include "AbstractVM.hpp"
#include "Operand.tpp"
#include <iostream>

IOperand const * OperandFactory::createInt8( std::string const & value )
{
	return new Operand<char>(opInt8, value);
}

IOperand const * OperandFactory::createInt16(std::string const & value)
{
	return new Operand<short>(opInt16, value);
}

IOperand const * OperandFactory::createInt32(std::string const & value)
{
	return new Operand<int>(opInt32, value);
}

IOperand const * OperandFactory::createFloat(std::string const & value)
{
	return new Operand<float>(opFloat, value);
}

IOperand const * OperandFactory::createDouble(std::string const & value)
{
	return new Operand<double>(opDouble, value);
}

/*
** Public functions
*/
typedef IOperand const * (*funcCreate)(std::string const &);

IOperand const * OperandFactory::createOperand(eOperandType type, std::string const & value)
{
	funcCreate funcs[opMax];

	funcs[opInt8] = &OperandFactory::createInt8;
	funcs[opInt16] = &OperandFactory::createInt16;
	funcs[opInt32] = &OperandFactory::createInt32;
	funcs[opFloat] = &OperandFactory::createFloat;
	funcs[opDouble] = &OperandFactory::createDouble;

	if (type < opMin || type >= opMax)
		throw InvalidOperandException();
	return ((*funcs[type])(value));
}

/*
** Exceptions
*/
const char * OperandFactory::InvalidOperandException::what() const throw()
{
	return ("Operand is not valid");
}
