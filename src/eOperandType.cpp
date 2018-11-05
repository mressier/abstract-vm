#include <string>
#include <iostream>
#include "eOperandType.hpp"

void			getEOperandTypeStrings(std::string strings[])
{
	strings[opInt8] = "int8";
	strings[opInt16] = "int16";
	strings[opInt32] = "int32";
	strings[opFloat] = "float";
	strings[opDouble] = "double";
}

std::string 	eOperandTypeToString(eOperandType const type)
{
	std::string enums[opMax];

	getEOperandTypeStrings(enums);
	if (type < opMax)
		return (enums[type]);
	return "unknow";
}

eOperandType 	eOperandTypeFromString(std::string const & string)
{
	std::string enums[opMax];

	getEOperandTypeStrings(enums);
	for (int i = opMin; i < opMax; i++) {
		if (enums[i] == string)
			return (static_cast<eOperandType>(i));
	}
	return opUnknow;
}

bool			eOperandTypeIsInteger(eOperandType const type)
{
	return (type <= opInt32);
}

eOperandType	higher(eOperandType e1, eOperandType e2)
{
	if (e1 > e2)
		return e1;
	return e2;
}
