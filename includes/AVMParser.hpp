#ifndef AVMParser_HPP
# define AVMParser_HPP

#include "AVM.hpp"
#include "AVMInstruction.hpp"

namespace	AVMParser
{
	AVMInstruction const *	tokensToInstruction(t_tokens const & lineTokens);

	/* exceptions */
	class EmptyLineException: public std::exception {
		public: virtual const char *what() const throw();
	};

	class InvalidFormatException: public std::exception {
		public: virtual const char *what() const throw();
	};

	class ExpressionException: public std::exception {
		public:
			ExpressionException(std::string const & instruction);
			std::string const & getInstruction() const;
		protected:
			std::string	const	_invalid_instruction;
	};

	class MissingExpressionException: public ExpressionException {
		public:
			MissingExpressionException(std::string const & instruction);
			virtual const char *what() const throw();
	};

	class TooMuchExpressionException: public ExpressionException {
		public:
			TooMuchExpressionException(std::string const & instruction);
			virtual const char *what() const throw();
	};

	class InvalidInstructionException: public ExpressionException {
		public:
			InvalidInstructionException(std::string const & instruction);
			virtual const char *what() const throw();
	};
}

#endif
