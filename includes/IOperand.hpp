#ifndef IOPERAND_HPP
# define IOPERAND_HPP

#include "eOperandType.hpp"
#include <iostream>

class IOperand
{
	public :
		virtual		int getPrecision(void) const = 0;  // Precision of the type of the instance
		virtual		eOperandType getType(void) const = 0; // Type of the instance
		virtual		IOperand const * operator+(IOperand const & rhs) const = 0;	// Sum
		virtual		IOperand const * operator-(IOperand const & rhs) const = 0;	// Difference
		virtual		IOperand const * operator*(IOperand const & rhs) const = 0;	// Product
		virtual		IOperand const * operator/(IOperand const & rhs) const = 0;	// Quotient
		virtual		IOperand const * operator%(IOperand const & rhs) const = 0;	// Modulo
		virtual		IOperand const & operator=(IOperand const & rhs) = 0;		// Equal

		virtual		std::string const & toString(void) const = 0;	// String representation of the instance

		virtual		~IOperand(void) {}
};

std::ostream &		operator<<(std::ostream& o, IOperand const & rhs);
bool				operator==(IOperand const & lhs, IOperand const & rhs);

#endif
