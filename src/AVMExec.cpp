#include "AbstractVM.hpp"
#include <sstream>

typedef void (Stack::*funcStack)(void);
typedef void (Stack::*funcStackDisplay)(void) const;

static void			_setStackFuncs(funcStack manips[])
{
	for (size_t i = 0; i < instMax; i++) {
		manips[i] = NULL;
	}
	manips[instAdd] = &Stack::add_front;
	manips[instSub] = &Stack::sub_front;
	manips[instMul] = &Stack::mul_front;
	manips[instDiv] = &Stack::div_front;
	manips[instMod] = &Stack::mod_front;
}

static void			_setStackDisplayFuncs(funcStackDisplay manips[])
{
	for (size_t i = 0; i < instMax; i++) {
		manips[i] = NULL;
	}
	manips[instDump] = &Stack::dump;
	manips[instHyperDump] = &Stack::hyperdump;
	manips[instPrint] = &Stack::print_front;
}

static bool			_execManipDisplayFunc(Stack & onStack, AVMInstruction const & instruction)
{
	funcStack			manips[instMax];
	funcStackDisplay		display[instMax];
	eInstruction			inst;

	inst = instruction.getInstruction();
	_setStackFuncs(manips);
	_setStackDisplayFuncs(display);
	if (manips[inst]) {
		(onStack.*manips[inst])();
		return (EXIT_SUCCESS); // execute
	}
	if (display[inst]) {
		(onStack.*display[inst])();
		return (EXIT_SUCCESS); // execute
	}
	return (EXIT_FAILURE); // do not execute
}

static bool			_execOtherFunc(Stack & onStack, AVMInstruction const & instruction)
{
	switch (instruction.getInstruction())
	{
		case instPush:
			onStack.push(instruction.getOperand());
			break ;
		case instAssert:
			onStack.assert_front(*instruction.getOperand());
			break ;
		case instPop:
			onStack.pop();
			break ;
		default:
			return false;
	}
	return true;
}

static void			_displayInstruction(AVMInstruction const & instruction)
{
	if (AVMLog::log.isDebug())
		AVMLog::log.out() << COLOR_BOLD_GREY
						<< instruction
						<< COLOR_RESET
						<< std::endl;
}

static unsigned int	_nbOfRepeatFromInstruction(AVMInstruction const & repeatInstruction)
{
	IOperand const *	number;

	number = repeatInstruction.getOperand();
	if (number)
		return (std::stoi(number->toString()));
	return (1);
}

static void		_executeFromInstructionList(Stack & onStack,
						t_instruction_list::const_iterator const & it,
						t_instruction_list const & instructions)
	{
		if (AVMExec::isRepeatInstruction(**it))
		{
			if (it == instructions.cbegin())
				throw AVMExec::InvalidRepeatInstructionException();
			AVMExec::repeat(onStack, **(it - 1), _nbOfRepeatFromInstruction(**it));
		}
		else
			AVMExec::executeStackInstruction(onStack, **it);
	}

namespace AVMExec
{
	bool		isEndOfExecution(AVMInstruction const & instruction)
	{
		return (instruction.getInstruction() == instExit);
	}

	bool		isRepeatInstruction(AVMInstruction const & instruction)
	{
		return (instruction.getInstruction() == instRepeat);
	}

	void		repeat(Stack & onStack, AVMInstruction const & instruction,
						unsigned int nbOfRepeat)
	{
		for (unsigned int i = 0; i < nbOfRepeat; i++)
			executeStackInstruction(onStack, instruction);
	}

	void		executeStackInstruction(Stack & onStack, AVMInstruction const & instruction)
	{
		_displayInstruction(instruction);
		if (isEndOfExecution(instruction))
			return ;
		if (_execManipDisplayFunc(onStack, instruction) == EXIT_FAILURE)
			_execOtherFunc(onStack, instruction);
	}

	/*
	** Main function
	** execute a list of instructions on a stack
	*/
	void		execute(Stack & onStack, t_instruction_list const & instructions)
	{
		t_instruction_list::const_iterator		it;
		bool									end;

		end = false;
		for (it = instructions.cbegin(); it != instructions.end(); it++)
		{
			if (!(*it))
				break ;
			if (isEndOfExecution(**it))
			{
				end = true;
				break ;
			}
			_executeFromInstructionList(onStack, it, instructions);
		}
		if (!end)
			throw NoExitInstructionException();
	}

	/*
	** Exceptions
	*/

	const char *AVMExec::NoExitInstructionException::what() const throw()
	{
		return ("Exit instruction is missing");
	}

	const char *AVMExec::InvalidRepeatInstructionException::what() const throw()
	{
		return ("Repeat instruction is not preceded by a valid instruction");
	}
}
