#include "AbstractVM.hpp"
#include "unit_test/tests.hpp"

int     main(void)
{
	// createOperands();
	addOperand();
	diffOperand();
	multOperand();
	divOperand();
	modOperand();
	stackTest();
	parserTest();
	lexerTest();
	execTest();
}
