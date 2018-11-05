#include <iostream>
#include <sstream>
#include "AbstractVM.hpp"

static int		execute(t_avm_input_list const & instructions)
{
	t_instruction_list		list;
	Stack					stack;

	if (AVM::stringToInstructionList(instructions, &list) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (AVM::executeInstructionList(stack, list) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int		read(int ac, char **av, int nextIndex, t_avm_input_list *lines)
{
	int		max = ac;
	int		last = ac - 1;

	if (nextIndex == -1 || nextIndex < last || nextIndex > max)
	{
		AVM::displayHelp();
		return (EXIT_FAILURE);
	}

	if (nextIndex == last)
		return (AVM::readFromFile(av[nextIndex], lines));
	if (nextIndex == max)
	{
		if (AVMLog::log.isDebug())
			AVM::displayStartHelp();
		return (AVM::readFromInput(AVMLog::log.in(), lines));
	}
	return (EXIT_FAILURE);
}

int				main(int ac, char **av)
{
	t_avm_input_list	lines;
	int					nextIndex = 0;

	if (AVM::setOptions(ac, av, &nextIndex) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	if (read(ac, av, nextIndex, &lines) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	return execute(lines);
}
