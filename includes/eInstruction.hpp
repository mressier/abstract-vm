#ifndef E_AVM_INSTRUCTION_HPP
# define E_AVM_INSTRUCTION_HPP

# include <string>
# include "eOperandType.hpp"

# define END_OF_STDOUT			";;"

# define LINE_SEPARATOR 		"\n"
# define TOKEN_SEPARATOR 		" \t"

# define COMMENT_CHAR 			';'

# define REG_NUMBER				"[1-9][0-9]{0,2}"
# define REG_INT_NUMBER			"[-]?[0-9]+"
# define REG_FLOAT_NUMBER		"[-]?[0-9]+.[0-9]+"

# define REG_CATCH_INT_NUMBER	"\\((" REG_INT_NUMBER ")\\)"
# define REG_CATCH_FLOAT_NUMBER	"\\((" REG_FLOAT_NUMBER ")\\)"

# define REG_VALUE			"^" OP_INT_8 "\\(" REG_INT_NUMBER "\\)" \
							"|" OP_INT_16 "\\(" REG_INT_NUMBER "\\)" \
							"|" OP_INT_32 "\\(" REG_INT_NUMBER "\\)" \
							"|" OP_FLOAT "\\(" REG_FLOAT_NUMBER "\\)" \
							"|" OP_DOUBLE "\\(" REG_FLOAT_NUMBER "\\)$" \
							"$"

# define REG_OPERANDS 	"^" OP_INT_8 \
						"|" OP_INT_16 \
						"|" OP_INT_32 \
						"|" OP_FLOAT \
						"|" OP_DOUBLE

# define LINE_TOKENS_MAX	2	// instruction + value

enum eInstruction {
	instMin = 0,
	instPush = 0,
	instAssert,
	instPop,
	instDump,
	instHyperDump,
	instAdd,
	instSub,
	instMul,
	instDiv,
	instMod,
	instPrint,
	instExit,
	instRepeat,
	instMax,
	instUnknow
};

eInstruction	eInstructionFromString(std::string const & string);
std::string 	eInstructionToString(eInstruction const type);
bool			eInstructionRequiredOperand(eInstruction instruction);
bool			eInstructionShouldRequiredInteger(eInstruction instruction);

#endif
