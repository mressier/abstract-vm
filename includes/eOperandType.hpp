#ifndef E_OPERAND_TYPE_HPP
# define E_OPERAND_TYPE_HPP

#include <string>

# define OP_INT_8	"int8"
# define OP_INT_16	"int16"
# define OP_INT_32	"int32"
# define OP_FLOAT	"float"
# define OP_DOUBLE	"double"

enum eOperandType {
	opMin = 0,
	opInt8 = 0,
	opInt16,
	opInt32,
	opFloat,
	opDouble,
	opMax,
	opUnknow
};

std::string 	eOperandTypeToString(eOperandType const type);
eOperandType 	eOperandTypeFromString(std::string const & string);
bool			eOperandTypeIsInteger(eOperandType type);
eOperandType	higher(eOperandType e1, eOperandType e2);

#endif
