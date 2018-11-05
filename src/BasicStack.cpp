#include "AbstractVM.hpp"
#include <vector>
#include <sstream>

/*
** Constructors
*/
BasicStack::BasicStack() {}

BasicStack::BasicStack(BasicStack const & src)
{
	*this = src;
}


/*
** Destructors
*/
BasicStack::~BasicStack() {}

/*
** Public methods
*/
void				BasicStack::push(IOperand const * op)
{
	this->_stack.push_back(op);
}

IOperand const *	BasicStack::pop(void)
{
	IOperand const * front = this->_get_front();

	this->_stack.pop_back();
	return front;
}

void				BasicStack::dump(void) const
{
	this->dump(AVMLog::log.out());
}

void				BasicStack::dump(std::ostream& o) const
{
	std::vector<IOperand const *>::const_reverse_iterator it;

	for (it = this->_stack.rbegin() ; it != this->_stack.rend(); ++it) {
		o << **it << std::endl;
	}
}

void				BasicStack::hyperdump(void) const
{
	this->hyperdump(AVMLog::log.out());
}

void				BasicStack::hyperdump(std::ostream& o) const
{
	std::vector<IOperand const *>::const_reverse_iterator	it;
	unsigned int											index;

	index = 1;
	o << COLOR_BOLD_YELLOW << "-- " << "Stack top" << " --" << COLOR_RESET << std::endl;
	for (it = this->_stack.rbegin(); it != this->_stack.rend(); ++it) {
		o << COLOR_BOLD_GREY << index << ": " << COLOR_RESET
			<< **it << " (" << eOperandTypeToString((**it).getType()) << ")"
			<< std::endl;
		index++;
	}
	o << COLOR_BOLD_CYAN << "-- " << "Stack tail" << " --" << COLOR_RESET << std::endl;
}

IOperand const *	BasicStack::_get_front() const
{
	if (this->_stack.empty())
		throw EmptyStackException();

	return this->_stack.back();
}

/*
** Operator overload
*/
BasicStack const & BasicStack::operator=(BasicStack const & rhs)
{
	this->_stack = rhs._stack;
	return (*this);
}

/*
** Exceptions
*/
const char * BasicStack::EmptyStackException::what() const throw()
{
	return ("Stack is empty");
}
