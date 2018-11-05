#ifndef ABSTRACT_VM_HPP
# define ABSTRACT_VM_HPP

#include "AVM.hpp"

#include "OperandFactory.hpp"
#include "Stack.hpp"

#include "AVMInstruction.hpp"
#include "AVMParser.hpp"
#include "AVMLexer.hpp"
#include "AVMExec.hpp"
#include "AVMReader.hpp"
#include "AVMLog.hpp"

namespace AVM
{
	void	displayHelp();
	void	displayStartHelp();
	int		setOptions(int ac, char **av, int *nextIndex);
	int		readFromFile(std::string const & filename, t_avm_input_list *list);
	int		readFromInput(std::istream & input, t_avm_input_list *list);
	int		stringToInstructionList(t_avm_input_list const & inputs,
									t_instruction_list *to_fill);
	int		executeInstructionList(Stack & onStack, t_instruction_list list);


}

std::ostream &		operator<<(std::ostream& o, std::vector<std::string>const & rhs);
std::string &		operator+(std::string& str, char const *c_str);

#endif
