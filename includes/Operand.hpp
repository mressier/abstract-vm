#ifndef OPERAND_HPP
# define OPERAND_HPP

#include "IOperand.hpp"

template <typename T>
class Operand : public IOperand
{
	public:
		Operand(eOperandType const & type, std::string const & value);
		Operand(Operand const & src);
		virtual ~Operand(void);

		/* getters */
		int					getPrecision(void) const;
		eOperandType		getType(void) const;

		std::string const & toString(void) const;

		/* operators */
		IOperand const * operator+(IOperand const & rhs) const;	// Sum
		IOperand const * operator-(IOperand const & rhs) const;	// Difference
		IOperand const * operator*(IOperand const & rhs) const;	// Product
		IOperand const * operator/(IOperand const & rhs) const;	// Quotient
		IOperand const * operator%(IOperand const & rhs) const;	// Modulo
		IOperand const & operator=(IOperand const & rhs);


		class InvalidValueException: public std::exception {
			public: virtual const char *what() const throw();
		};

		class OverflowException: public std::exception {
			public: virtual const char *what() const throw();
		};

		class DivisionByZeroException: public std::exception {
			public: virtual const char *what() const throw();
		};

	private:
		Operand();

		T					_value;
		eOperandType		_type;
		std::string			_str;

		double	getDoubleFromString(std::string const & value) const ;
		int		getIntegerFromString(std::string const & value) const ;

		IOperand const * makeOperation(char const operation, IOperand const & rhs) const ;
};

#endif
