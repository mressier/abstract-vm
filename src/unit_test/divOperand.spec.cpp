#include "AbstractVM.hpp"
#include "unit_test/tests.hpp"

static void divOperandInt8()
{
	testDivOperand(opInt8, "4", opInt8, "2", SUCCESS_TEST);
	testDivOperand(opInt8, "0", opInt8, "2", SUCCESS_TEST);
	testDivOperand(opInt8, "75", opInt8, "7", SUCCESS_TEST);
	testDivOperand(opInt8, "7", opInt8, "78", SUCCESS_TEST);
	testDivOperand(opInt8, "4", opInt8, "-1", SUCCESS_TEST);
	testDivOperand(opInt8, "75", opInt8, "-7", SUCCESS_TEST);
	testDivOperand(opInt8, "0", opInt8, "7", SUCCESS_TEST);
	testDivOperand(opInt8, "-100", opInt8, "7", SUCCESS_TEST);
	testDivOperand(opInt8, "-42", opInt8, "-2", SUCCESS_TEST);
	testDivOperand(opInt8, MAX_INT8, opInt8, "2", SUCCESS_TEST);
	testDivOperand(opInt8, MIN_INT8, opInt8, "2", SUCCESS_TEST);

	testDivOperand(opInt8, MAX_INT8, opFloat, "0.2", SUCCESS_TEST);

	testDivOperand(opInt8, "4", opInt8, "0", FAIL_TEST);
	testDivOperand(opInt8, "42", opInt32, "0", FAIL_TEST);
}

static void divOperandInt16()
{
	testDivOperand(opInt16, "4", opInt16, "2", SUCCESS_TEST);
	testDivOperand(opInt16, "0", opInt16, "2", SUCCESS_TEST);
	testDivOperand(opInt16, "75", opInt16, "7", SUCCESS_TEST);
	testDivOperand(opInt16, "7", opInt16, "78", SUCCESS_TEST);
	testDivOperand(opInt16, "4", opInt16, "-1", SUCCESS_TEST);
	testDivOperand(opInt16, "75", opInt16, "-7", SUCCESS_TEST);
	testDivOperand(opInt16, "0", opInt16, "7", SUCCESS_TEST);
	testDivOperand(opInt16, "-100", opInt16, "7", SUCCESS_TEST);
	testDivOperand(opInt16, "-42", opInt16, "-2", SUCCESS_TEST);
	testDivOperand(opInt16, MAX_INT16, opFloat, "0.2", SUCCESS_TEST);

	testDivOperand(opInt16, "4", opInt16, "0", FAIL_TEST);
	testDivOperand(opInt16, "42", opInt32, "0", FAIL_TEST);
}

static void divOperandInt32()
{
	testDivOperand(opInt32, "4", opInt32, "2", SUCCESS_TEST);
	testDivOperand(opInt32, "0", opInt32, "2", SUCCESS_TEST);
	testDivOperand(opInt32, "75", opInt32, "7", SUCCESS_TEST);
	testDivOperand(opInt32, "7", opInt32, "78", SUCCESS_TEST);
	testDivOperand(opInt32, "4", opInt32, "-1", SUCCESS_TEST);
	testDivOperand(opInt32, "75", opInt32, "-7", SUCCESS_TEST);
	testDivOperand(opInt32, "0", opInt32, "7", SUCCESS_TEST);
	testDivOperand(opInt32, "-100", opInt32, "7", SUCCESS_TEST);
	testDivOperand(opInt32, "-42", opInt32, "-2", SUCCESS_TEST);
	testDivOperand(opInt32, MAX_INT32, opFloat, "0.2", SUCCESS_TEST);

	testDivOperand(opInt32, "4", opInt32, "0", FAIL_TEST);
	testDivOperand(opInt32, "42", opFloat, "0", FAIL_TEST);
}

static void divOperandFloat()
{
	testDivOperand(opDouble, "4", opDouble, "2", SUCCESS_TEST);
	testDivOperand(opDouble, "0", opDouble, "2", SUCCESS_TEST);
	testDivOperand(opDouble, "75", opDouble, "7", SUCCESS_TEST);
	testDivOperand(opDouble, "7", opDouble, "78", SUCCESS_TEST);
	testDivOperand(opDouble, "4", opDouble, "-1", SUCCESS_TEST);
	testDivOperand(opDouble, "75", opDouble, "-7", SUCCESS_TEST);
	testDivOperand(opDouble, "0", opDouble, "7", SUCCESS_TEST);
	testDivOperand(opDouble, "-100", opDouble, "7", SUCCESS_TEST);
	testDivOperand(opDouble, "-42", opDouble, "-2", SUCCESS_TEST);
	testDivOperand(opDouble, MAX_INT32, opDouble, "0.00009", SUCCESS_TEST);
	testDivOperand(opDouble, "inf", opDouble, "inf", SUCCESS_TEST);
	testDivOperand(opDouble, "inf", opDouble, "inf", SUCCESS_TEST);
	testDivOperand(opDouble, "inf", opDouble, "-inf", SUCCESS_TEST);
	testDivOperand(opDouble, "inf", opDouble, "nan", SUCCESS_TEST);
	testDivOperand(opDouble, "nan", opDouble, "nan", SUCCESS_TEST);
	testDivOperand(opDouble, "nan", opDouble, "inf", SUCCESS_TEST);
	testDivOperand(opDouble, "42", opDouble, "inf", SUCCESS_TEST);
	testDivOperand(opDouble, "inf", opDouble, "42", SUCCESS_TEST);

	testDivOperand(opDouble, "inf", opInt32, "0", FAIL_TEST);
	testDivOperand(opDouble, "nan", opInt32, "0", FAIL_TEST);
	testDivOperand(opDouble, "42", opInt32, "0", FAIL_TEST);
}

static void divOperandDouble()
{
	testDivOperand(opFloat, "4", opFloat, "2", SUCCESS_TEST);
	testDivOperand(opFloat, "0", opFloat, "2", SUCCESS_TEST);
	testDivOperand(opFloat, "75", opFloat, "7", SUCCESS_TEST);
	testDivOperand(opFloat, "7", opFloat, "78", SUCCESS_TEST);
	testDivOperand(opFloat, "4", opFloat, "-1", SUCCESS_TEST);
	testDivOperand(opFloat, "75", opFloat, "-7", SUCCESS_TEST);
	testDivOperand(opFloat, "0", opFloat, "7", SUCCESS_TEST);
	testDivOperand(opFloat, "-100", opFloat, "7", SUCCESS_TEST);
	testDivOperand(opFloat, "-42", opFloat, "-2", SUCCESS_TEST);
	testDivOperand(opFloat, MAX_INT32, opFloat, "0.2", SUCCESS_TEST);
	testDivOperand(opFloat, "inf", opFloat, "inf", SUCCESS_TEST);
	testDivOperand(opFloat, "inf", opFloat, "inf", SUCCESS_TEST);
	testDivOperand(opFloat, "inf", opFloat, "-inf", SUCCESS_TEST);
	testDivOperand(opFloat, "inf", opFloat, "nan", SUCCESS_TEST);
	testDivOperand(opFloat, "nan", opFloat, "nan", SUCCESS_TEST);
	testDivOperand(opFloat, "nan", opFloat, "inf", SUCCESS_TEST);
	testDivOperand(opFloat, "42", opFloat, "inf", SUCCESS_TEST);
	testDivOperand(opFloat, "inf", opFloat, "42", SUCCESS_TEST);

	testDivOperand(opFloat, "inf", opInt32, "0", FAIL_TEST);
	testDivOperand(opFloat, "nan", opInt32, "0", FAIL_TEST);
	testDivOperand(opFloat, "42", opInt32, "0", FAIL_TEST);
}

void	divOperand()
{
	line("div Operand int8");
	divOperandInt8();
	line("div Operand int16");
	divOperandInt16();
	line("div Operand int32");
	divOperandInt32();
	line("div Operand float");
	divOperandFloat();
	line("div Operand double");
	divOperandDouble();
}
