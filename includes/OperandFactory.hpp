#ifndef OPERAND_FACTORY_HPP
# define OPERAND_FACTORY_HPP

class OperandFactory {
	public:
		static IOperand const * createOperand(eOperandType type, std::string const & value);

	class InvalidOperandException: public std::exception {
		public: virtual const char *what() const throw();
	};

	private:
		static IOperand const * createInt8(std::string const & value);
		static IOperand const * createInt16(std::string const & value);
		static IOperand const * createInt32(std::string const & value);
		static IOperand const * createFloat(std::string const & value);
		static IOperand const * createDouble(std::string const & value);
};

#endif
