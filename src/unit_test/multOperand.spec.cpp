#include "AbstractVM.hpp"
#include "unit_test/tests.hpp"

static void multOperandInt8()
{
	testMultOperand(opInt8, "1", opInt8, "1", SUCCESS_TEST);
	testMultOperand(opInt8, "1", opInt8, "2", SUCCESS_TEST);
	testMultOperand(opInt8, "42", opInt8, "0", SUCCESS_TEST);
	testMultOperand(opInt8, "42", opInt8, "2", SUCCESS_TEST);
	testMultOperand(opInt8, "-1", opInt8, "1", SUCCESS_TEST);
	testMultOperand(opInt8, MAX_INT8, opInt8, "-1", SUCCESS_TEST);
	testMultOperand(opInt8, MIN_INT8, opInt8, "1", SUCCESS_TEST);

	testMultOperand(opInt8, MIN_INT8, opInt8, "-1", FAIL_TEST);		// overflow
	testMultOperand(opInt8, "42", opInt8, "42", FAIL_TEST);			// overflow
	testMultOperand(opInt8, MAX_INT8, opInt8, "2", FAIL_TEST);		// overflow
	testMultOperand(opInt8, MAX_INT8, opInt16, "420", FAIL_TEST);	// overflow
}

static void multOperandInt16()
{
	testMultOperand(opInt16, "1", opInt16, "1", SUCCESS_TEST);
	testMultOperand(opInt16, "1", opInt16, "2", SUCCESS_TEST);
	testMultOperand(opInt16, "42", opInt16, "0", SUCCESS_TEST);
	testMultOperand(opInt16, "42", opInt16, "2", SUCCESS_TEST);
	testMultOperand(opInt16, "42", opInt16, "367", SUCCESS_TEST);
	testMultOperand(opInt16, "-1", opInt16, "1", SUCCESS_TEST);
	testMultOperand(opInt16, MAX_INT16, opInt16, "-1", SUCCESS_TEST);
	testMultOperand(opInt16, MIN_INT16, opInt16, "1", SUCCESS_TEST);

	testMultOperand(opInt16, MIN_INT16, opInt16, "-1", FAIL_TEST);		// overflow
	testMultOperand(opInt16, MAX_INT16, opInt16, "2", FAIL_TEST);		// overflow
	testMultOperand(opInt16, "420", opInt16, "420", FAIL_TEST);			// overflow
	testMultOperand(opInt16, MAX_INT16, opInt32, "98765", FAIL_TEST);	// overflow
}

static void multOperandInt32()
{
	testMultOperand(opInt32, "1", opInt32, "1", SUCCESS_TEST);
	testMultOperand(opInt32, "1", opInt32, "2", SUCCESS_TEST);
	testMultOperand(opInt32, "42", opInt32, "0", SUCCESS_TEST);
	testMultOperand(opInt32, "42", opInt32, "2", SUCCESS_TEST);
	testMultOperand(opInt32, "42", opInt32, "367", SUCCESS_TEST);
	testMultOperand(opInt32, "-1", opInt32, "1", SUCCESS_TEST);
	testMultOperand(opInt32, MAX_INT32, opInt32, "-1", SUCCESS_TEST);
	testMultOperand(opInt32, MIN_INT32, opInt32, "1", SUCCESS_TEST);

	testMultOperand(opInt32, MIN_INT32, opInt32, "-1", FAIL_TEST);		// overflow
	testMultOperand(opInt32, MAX_INT32, opInt32, "2", FAIL_TEST);		// overflow
	testMultOperand(opInt32, "78945", opInt32, "987654", FAIL_TEST);			// overflow
}

static void multOperandFloat()
{
	testMultOperand(opFloat, "1", opFloat, "1", SUCCESS_TEST);
	testMultOperand(opFloat, "1", opFloat, "2", SUCCESS_TEST);
	testMultOperand(opFloat, "42", opFloat, "0", SUCCESS_TEST);
	testMultOperand(opFloat, "42", opFloat, "2", SUCCESS_TEST);
	testMultOperand(opFloat, "42", opFloat, "367", SUCCESS_TEST);
	testMultOperand(opFloat, "-1", opFloat, "1", SUCCESS_TEST);
	testMultOperand(opFloat, "inf", opFloat, "-1", SUCCESS_TEST);
	testMultOperand(opFloat, "inf", opFloat, "1", SUCCESS_TEST);
	testMultOperand(opFloat, "inf", opFloat, "2", SUCCESS_TEST);
	testMultOperand(opFloat, "nan", opFloat, "2", SUCCESS_TEST);
	testMultOperand(opFloat, "nan", opFloat, "inf", SUCCESS_TEST);
	testMultOperand(opFloat, "nan", opFloat, "nan", SUCCESS_TEST);
	testMultOperand(opFloat, "-inf", opFloat, "inf", SUCCESS_TEST);
}

static void multOperandDouble()
{
	testMultOperand(opDouble, "1", opDouble, "1", SUCCESS_TEST);
	testMultOperand(opDouble, "1", opDouble, "2", SUCCESS_TEST);
	testMultOperand(opDouble, "42", opDouble, "0", SUCCESS_TEST);
	testMultOperand(opDouble, "42", opDouble, "2", SUCCESS_TEST);
	testMultOperand(opDouble, "42", opDouble, "367", SUCCESS_TEST);
	testMultOperand(opDouble, "-1", opDouble, "1", SUCCESS_TEST);
	testMultOperand(opDouble, "inf", opDouble, "-1", SUCCESS_TEST);
	testMultOperand(opDouble, "inf", opDouble, "1", SUCCESS_TEST);
	testMultOperand(opDouble, "inf", opDouble, "2", SUCCESS_TEST);
	testMultOperand(opDouble, "nan", opDouble, "2", SUCCESS_TEST);
	testMultOperand(opDouble, "nan", opDouble, "inf", SUCCESS_TEST);
	testMultOperand(opDouble, "nan", opDouble, "nan", SUCCESS_TEST);
	testMultOperand(opDouble, "-inf", opDouble, "inf", SUCCESS_TEST);
	testMultOperand(opInt8, "10", opDouble, "42.42", SUCCESS_TEST);
}

void	multOperand()
{
	line("mult Operand int8");
	multOperandInt8();
	line("mult Operand int16");
	multOperandInt16();
	line("mult Operand int32");
	multOperandInt32();
	line("mult Operand float");
	multOperandFloat();
	line("mult Operand double");
	multOperandDouble();
}
