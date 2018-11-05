#include "AVMParser.hpp"
#include "OperandFactory.hpp"
#include <regex>

/*
** Tools
*/
static IOperand const *		_stringToOperand(std::string const & token)
{
	std::smatch			reg_match;
	std::regex			regex_to_search;
	eOperandType		operandType;
	std::string			operandValue;

	// valid global format
	regex_to_search = std::regex(REG_VALUE);
	if (!std::regex_match(token, reg_match, regex_to_search, std::regex_constants::match_not_null) || reg_match.size() < 1)
		throw AVMParser::InvalidFormatException();

	regex_to_search = std::regex(REG_OPERANDS);
	if (!std::regex_search(token, reg_match, regex_to_search, std::regex_constants::match_not_null) || reg_match.size() < 1)
		throw AVMParser::InvalidFormatException();
	operandType = eOperandTypeFromString(reg_match[0]);

	regex_to_search = eOperandTypeIsInteger(operandType) ? std::regex(REG_CATCH_INT_NUMBER) : std::regex(REG_CATCH_FLOAT_NUMBER);
	if (!std::regex_search(token, reg_match, regex_to_search, std::regex_constants::match_not_null) || reg_match.size() < 2)
		throw AVMParser::InvalidFormatException();
	operandValue = reg_match[1];

	return OperandFactory::createOperand(operandType, operandValue);
}

static IOperand const *		_stringNumberToOperand(std::string const & token)
{
	std::smatch			reg_match;
	std::regex			regex_to_search;
	eOperandType		operandType;
	std::string			operandValue;

	regex_to_search = std::regex(REG_NUMBER);
	if (!std::regex_match(token, reg_match, regex_to_search, std::regex_constants::match_not_null) || reg_match.size() < 1)
		throw AVMParser::InvalidFormatException();
	operandValue = reg_match[0];
	operandType = opInt16;

	return OperandFactory::createOperand(operandType, operandValue);
}

static eInstruction			_stringToInstruction(std::string const & token)
{
	return eInstructionFromString(token);
}

/*
** AVMParser
*/
namespace AVMParser
{
	AVMInstruction const *		tokensToInstruction(t_tokens const & lineTokens)
	{
		eInstruction		instruction;
		IOperand const *	operand;
		unsigned int		pos;

		pos = 0;
		operand = NULL;

		if (lineTokens.size() <= pos)
			throw EmptyLineException();
		instruction = _stringToInstruction(lineTokens[pos++]);
		if (instruction == instUnknow)
			throw InvalidInstructionException(lineTokens[0]);
		if (eInstructionRequiredOperand(instruction))
		{
			if (lineTokens.size() <= pos)
				throw MissingExpressionException(lineTokens[0]);
			operand = _stringToOperand(lineTokens[pos++]);
		}
		if (eInstructionShouldRequiredInteger(instruction))
		{
			if (!(lineTokens.size() <= pos))
				operand = _stringNumberToOperand(lineTokens[pos++]);
		}
		if (lineTokens.size() != pos)
			throw TooMuchExpressionException(lineTokens[0]);

		return new AVMInstruction(instruction, operand);
	}

	/*
	** Exceptions
	*/

	const char *AVMParser::EmptyLineException::what() const throw()
	{
		return ("empty line");
	}

	const char *AVMParser::InvalidFormatException::what() const throw()
	{
		return ("expression format is not valid");
	}

	/*
	** Expression Exceptions
	*/
	AVMParser::ExpressionException::ExpressionException(std::string const & instruction) : _invalid_instruction(std::string(instruction))
	{}

	std::string const & AVMParser::ExpressionException::getInstruction() const
	{
			return this->_invalid_instruction;
	}

// Missing parameters
	AVMParser::MissingExpressionException::MissingExpressionException(std::string const & instruction) : ExpressionException(instruction)
	{}

	const char *AVMParser::MissingExpressionException::what() const throw()
	{
		return ("missing parameters");
	}

// To many parameters
	AVMParser::TooMuchExpressionException::TooMuchExpressionException(std::string const & instruction) : ExpressionException(instruction)
	{}

	const char *AVMParser::TooMuchExpressionException::what() const throw()
	{
		return ("too many parameters");
	}

// Invalid instruction
	AVMParser::InvalidInstructionException::InvalidInstructionException(std::string const & instruction) : ExpressionException(instruction)
	{}

	const char *AVMParser::InvalidInstructionException::what() const throw()
	{
		return ("unknown");
	}

}
