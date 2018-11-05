#include "AbstractVM.hpp"
#include <sstream>

/*
** Constructor
*/
AVMInstruction::AVMInstruction(eInstruction const & instruction,
								IOperand const * op) :
								_instruction(instruction),
								_operand(op)
{
	if (instruction == instUnknow || instruction >= instMax || instruction < instMin)
		throw InvalidInstructionException();
	this->_str = eInstructionToString(instruction);
	if (op)
		this->_str += " " + eOperandTypeToString((*op).getType())
					+ "(" + (op->toString()) + ")";
}

AVMInstruction::AVMInstruction(AVMInstruction const & src)
{
	*this = src;
}

/*
** Destructors
*/
AVMInstruction::~AVMInstruction() {}

/*
** Public methods
*/

eInstruction		AVMInstruction::getInstruction() const
{
	return _instruction;
}

IOperand const *	AVMInstruction::getOperand() const
{
	return _operand;
}

std::string const &	AVMInstruction::toString() const
{
	return this->_str;
}

/*
** Operators
*/
AVMInstruction & AVMInstruction::operator=(AVMInstruction const & rhs)
{
	this->_instruction = rhs.getInstruction();
	this->_operand = rhs.getOperand();
	return (*this);
}

std::ostream &	operator<<(std::ostream& o, AVMInstruction const & rhs)
{
	o << rhs.toString();
	return o;
}

/*
** Exceptions
*/

const char *AVMInstruction::InvalidInstructionException::what() const throw()
{
	return ("not valid");
}
