#include "AbstractVM.hpp"

Stack::Stack() : BasicStack()
{}

Stack::Stack(Stack const & src) : BasicStack(src)
{}

/*
** Destructors
*/
Stack::~Stack() {}

/*
** Public methods
*/
void	Stack::add_front()
{
	IOperand const * op = (*this->pop()) + (*this->pop());

	this->push(op);
}

void	Stack::sub_front()
{
	IOperand const * op = (*this->pop()) - (*this->pop());

	this->push(op);
}

void	Stack::mul_front()
{
	IOperand const * op = (*this->pop()) * (*this->pop());

	this->push(op);
}

void	Stack::div_front()
{
	IOperand const * op = (*this->pop()) / (*this->pop());

	this->push(op);
}

void	Stack::mod_front()
{
	IOperand const * op = (*this->pop()) % (*this->pop());

	this->push(op);
}

void	Stack::print_front() const
{
	IOperand const *	front;
	char				ascii;

	front = this->_get_front();
	if (front->getType() != opInt8)
		throw PrintOperandException();
	ascii = stoi(front->toString());
	AVM_OUTPUT_DEFAULT << ascii;
}

void	Stack::assert_front(IOperand const & op) const
{
	IOperand const *	front;

	front = this->_get_front();
	if (op == *front)
		return ;
	throw AssertFailException();
}

/*
** Exceptions
*/
const char * Stack::AssertFailException::what() const throw()
{
	return ("Assertion failed");
}

const char * Stack::PrintOperandException::what() const throw()
{
	return ("Try to print on non-int8 value");
}
