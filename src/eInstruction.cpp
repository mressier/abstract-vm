#include "eInstruction.hpp"
#include <string>

static void			_getEInstructionStrings(std::string strings[])
{
	strings[instPush] = "push";
	strings[instPop] = "pop";
	strings[instDump] = "dump";
	strings[instHyperDump] = "hdump";
	strings[instAssert] = "assert";
	strings[instAdd] = "add";
	strings[instSub] = "sub";
	strings[instMul] = "mul";
	strings[instDiv] = "div";
	strings[instMod] = "mod";
	strings[instPrint] = "print";
	strings[instExit] = "exit";
	strings[instRepeat] = "rep";
}

eInstruction		eInstructionFromString(std::string const & string)
{
	std::string strings[instMax];

	_getEInstructionStrings(strings);
	for (unsigned int i = instMin; i < instMax; i++)
	{
		if (strings[i] == string)
			return (static_cast<eInstruction>(i));
	}
	return instUnknow;
}

std::string 		eInstructionToString(eInstruction const type)
{
	std::string enums[instMax];

	_getEInstructionStrings(enums);
	if (type < instMax)
		return (enums[type]);
	return "unknow";
}

bool				eInstructionRequiredOperand(eInstruction instruction)
{
	return (instruction == instPush || instruction == instAssert);
}

bool				eInstructionShouldRequiredInteger(eInstruction instruction)
{
	return (instruction == instRepeat);
}
