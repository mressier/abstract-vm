#ifndef TESTS_HPP
# define TESTS_HPP

#include <cfloat>
#include <climits>
#include <sstream>
#include "AbstractVM.hpp"

# define SUCCESS_TEST true
# define FAIL_TEST false

/*
** limits
*/

# define MIN_INT8		"-128"
# define MAX_INT8		"127"
# define UNDERFLOW_INT8	"-129"
# define OVERFLOW_INT8	"128"

# define MIN_INT16			"-32768"
# define MAX_INT16			"32767"
# define UNDERFLOW_INT16	"-32769"
# define OVERFLOW_INT16		"32768"

# define MIN_INT32			"-2147483648"
# define MAX_INT32			"2147483647"
# define UNDERFLOW_INT32	"-2147483649"
# define OVERFLOW_INT32		"2147483648"

# define BEFORE_OVERFLOW_FLOAT		"99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999"
# define OVERFLOW_FLOAT		BEFORE_OVERFLOW_FLOAT"9"

/*
** tools
*/
void	testCreateOperand(eOperandType type, std::string const & value,
							bool should_success);
void 	testEqualsOperand(eOperandType type1, std::string const & value1,
							eOperandType type2, std::string const & value2,
							bool should_success);
void 	testAddOperand(eOperandType type1, std::string const & value1,
						eOperandType type2, std::string const & value2,
						bool should_success);
void 	testDiffOperand(eOperandType type1, std::string const & value1,
						eOperandType type2, std::string const & value2,
						bool should_success);
void 	testMultOperand(eOperandType type1, std::string const & value1,
						eOperandType type2, std::string const & value2,
						bool should_success);
void 	testDivOperand(eOperandType type1, std::string const & value1,
						eOperandType type2, std::string const & value2,
						bool should_success);
void 	testModOperand(eOperandType type1, std::string const & value1,
						eOperandType type2, std::string const & value2,
						bool should_success);
void	testPush(Stack * BasicStack,
					eOperandType type, std::string const & value,
					bool should_success);
void	testPop(Stack * BasicStack, bool should_success);
void 	testErrorParser(std::vector<std::string> const & strings,
					bool should_success);
void	testErrorLexer(std::string const & input, t_tokens const & output);
void	testExecInstructions(t_avm_input_list & instructions,
							bool should_success);
/*
** tests
*/
void createOperands();

void addOperand();
void diffOperand();
void multOperand();
void divOperand();
void modOperand();

void stackTest();

void parserTest();
void lexerTest();

void execTest();

/*
** Tools
*/
void 				line(std::string const & detail);


#endif
