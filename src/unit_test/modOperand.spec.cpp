#include "AbstractVM.hpp"
#include "unit_test/tests.hpp"

void modOperandInt8()
{
	testModOperand(opInt8, "4", opInt8, "2", SUCCESS_TEST);
	testModOperand(opInt8, "0", opInt8, "2", SUCCESS_TEST);
	testModOperand(opInt8, "75", opInt8, "7", SUCCESS_TEST);
	testModOperand(opInt8, "7", opInt8, "78", SUCCESS_TEST);
	testModOperand(opInt8, "4", opInt8, "-1", SUCCESS_TEST);
	testModOperand(opInt8, "75", opInt8, "-7", SUCCESS_TEST);
	testModOperand(opInt8, "0", opInt8, "7", SUCCESS_TEST);
	testModOperand(opInt8, "-100", opInt8, "7", SUCCESS_TEST);
	testModOperand(opInt8, "-42", opInt8, "-2", SUCCESS_TEST);
	testModOperand(opInt8, MAX_INT8, opInt8, "2", SUCCESS_TEST);
	testModOperand(opInt8, MIN_INT8, opInt8, "2", SUCCESS_TEST);

	testModOperand(opInt8, MAX_INT8, opFloat, "0.2", SUCCESS_TEST);

	testModOperand(opInt8, "4", opInt8, "0", FAIL_TEST);
	testModOperand(opInt8, "42", opInt32, "0", FAIL_TEST);
}

void modOperandInt16()
{
	testModOperand(opInt16, "4", opInt16, "2", SUCCESS_TEST);
	testModOperand(opInt16, "0", opInt16, "2", SUCCESS_TEST);
	testModOperand(opInt16, "75", opInt16, "7", SUCCESS_TEST);
	testModOperand(opInt16, "7", opInt16, "78", SUCCESS_TEST);
	testModOperand(opInt16, "4", opInt16, "-1", SUCCESS_TEST);
	testModOperand(opInt16, "75", opInt16, "-7", SUCCESS_TEST);
	testModOperand(opInt16, "0", opInt16, "7", SUCCESS_TEST);
	testModOperand(opInt16, "-100", opInt16, "7", SUCCESS_TEST);
	testModOperand(opInt16, "-42", opInt16, "-2", SUCCESS_TEST);
	testModOperand(opInt16, "10258", opInt16, "25", SUCCESS_TEST);
	testModOperand(opInt16, MAX_INT16, opInt16, "2", SUCCESS_TEST);
	testModOperand(opInt16, MIN_INT16, opInt16, "2", SUCCESS_TEST);

	testModOperand(opInt16, MAX_INT16, opFloat, "0.2", SUCCESS_TEST);

	testModOperand(opInt16, "4", opInt16, "0", FAIL_TEST);
	testModOperand(opInt16, "42", opInt32, "0", FAIL_TEST);
	testModOperand(opInt16, "21474", opInt32, "0", FAIL_TEST);
}

void modOperandInt32()
{
	testModOperand(opInt32, "4", opInt32, "2", SUCCESS_TEST);
	testModOperand(opInt32, "0", opInt32, "2", SUCCESS_TEST);
	testModOperand(opInt32, "75", opInt32, "7", SUCCESS_TEST);
	testModOperand(opInt32, "7", opInt32, "78", SUCCESS_TEST);
	testModOperand(opInt32, "4", opInt32, "-1", SUCCESS_TEST);
	testModOperand(opInt32, "75", opInt32, "-7", SUCCESS_TEST);
	testModOperand(opInt32, "0", opInt32, "7", SUCCESS_TEST);
	testModOperand(opInt32, "-100", opInt32, "7", SUCCESS_TEST);
	testModOperand(opInt32, "-42", opInt32, "-2", SUCCESS_TEST);
	testModOperand(opInt32, "10258", opInt32, "25", SUCCESS_TEST);
	testModOperand(opInt32, MAX_INT32, opInt32, "2", SUCCESS_TEST);
	testModOperand(opInt32, MIN_INT32, opInt32, "2", SUCCESS_TEST);

	testModOperand(opInt32, MAX_INT32, opFloat, "0.2", SUCCESS_TEST);

	testModOperand(opInt32, "4", opInt32, "0", FAIL_TEST);
	testModOperand(opInt32, "42", opFloat, "0", FAIL_TEST);
}

void modOperandFloat()
{
	testModOperand(opFloat, "4", opFloat, "2", SUCCESS_TEST);
	testModOperand(opFloat, "3", opFloat, "2", SUCCESS_TEST);
	testModOperand(opFloat, "0", opFloat, "2", SUCCESS_TEST);
	testModOperand(opFloat, "75", opFloat, "7", SUCCESS_TEST);
	testModOperand(opFloat, "7", opFloat, "78", SUCCESS_TEST);
	testModOperand(opFloat, "4", opFloat, "-1", SUCCESS_TEST);
	testModOperand(opFloat, "75", opFloat, "-7", SUCCESS_TEST);
	testModOperand(opFloat, "0", opFloat, "7", SUCCESS_TEST);
	testModOperand(opFloat, "-100", opFloat, "7", SUCCESS_TEST);
	testModOperand(opFloat, "-42", opFloat, "-2", SUCCESS_TEST);
	testModOperand(opFloat, "10258", opFloat, "25", SUCCESS_TEST);
	testModOperand(opFloat, MAX_INT32, opFloat, "2", SUCCESS_TEST);
	testModOperand(opFloat, MIN_INT32, opFloat, "2", SUCCESS_TEST);
	testModOperand(opFloat, BEFORE_OVERFLOW_FLOAT, opFloat, "2", SUCCESS_TEST);
	testDivOperand(opFloat, "inf", opFloat, "inf", SUCCESS_TEST);
	testDivOperand(opFloat, "inf", opFloat, "inf", SUCCESS_TEST);
	testDivOperand(opFloat, "inf", opFloat, "-inf", SUCCESS_TEST);
	testDivOperand(opFloat, "inf", opFloat, "nan", SUCCESS_TEST);
	testDivOperand(opFloat, "nan", opFloat, "nan", SUCCESS_TEST);
	testDivOperand(opFloat, "nan", opFloat, "inf", SUCCESS_TEST);
	testDivOperand(opFloat, "42", opFloat, "inf", SUCCESS_TEST);
	testDivOperand(opFloat, "inf", opFloat, "42", SUCCESS_TEST);

	testModOperand(opFloat, MAX_INT32, opFloat, "0.2", SUCCESS_TEST);

	testModOperand(opFloat, "4", opFloat, "0", FAIL_TEST);
	testModOperand(opFloat, "42", opFloat, "0", FAIL_TEST);
}

void modOperandDouble()
{
	testModOperand(opDouble, "4", opDouble, "2", SUCCESS_TEST);
	testModOperand(opDouble, "3", opDouble, "2", SUCCESS_TEST);
	testModOperand(opDouble, "0", opDouble, "2", SUCCESS_TEST);
	testModOperand(opDouble, "75", opDouble, "7", SUCCESS_TEST);
	testModOperand(opDouble, "7", opDouble, "78", SUCCESS_TEST);
	testModOperand(opDouble, "4", opDouble, "-1", SUCCESS_TEST);
	testModOperand(opDouble, "75", opDouble, "-7", SUCCESS_TEST);
	testModOperand(opDouble, "0", opDouble, "7", SUCCESS_TEST);
	testModOperand(opDouble, "-100", opDouble, "7", SUCCESS_TEST);
	testModOperand(opDouble, "-42", opDouble, "-2", SUCCESS_TEST);
	testModOperand(opDouble, "10258", opDouble, "25", SUCCESS_TEST);
	testModOperand(opDouble, MAX_INT32, opDouble, "2", SUCCESS_TEST);
	testModOperand(opDouble, MIN_INT32, opDouble, "2", SUCCESS_TEST);
	testModOperand(opDouble, BEFORE_OVERFLOW_FLOAT, opDouble, "2", SUCCESS_TEST);
	testDivOperand(opDouble, "inf", opDouble, "inf", SUCCESS_TEST);
	testDivOperand(opDouble, "inf", opDouble, "inf", SUCCESS_TEST);
	testDivOperand(opDouble, "inf", opDouble, "-inf", SUCCESS_TEST);
	testDivOperand(opDouble, "inf", opDouble, "nan", SUCCESS_TEST);
	testDivOperand(opDouble, "nan", opDouble, "nan", SUCCESS_TEST);
	testDivOperand(opDouble, "nan", opDouble, "inf", SUCCESS_TEST);
	testDivOperand(opDouble, "42", opDouble, "inf", SUCCESS_TEST);
	testDivOperand(opDouble, "inf", opDouble, "42", SUCCESS_TEST);

	testModOperand(opDouble, MAX_INT32, opDouble, "0.2", SUCCESS_TEST);

	testModOperand(opDouble, "4", opDouble, "0", FAIL_TEST);
	testModOperand(opDouble, "42", opDouble, "0", FAIL_TEST);
}

void	modOperand()
{
	line("mod Operand int8");
	modOperandInt8();
	line("mod Operand int16");
	modOperandInt16();
	line("mod Operand int32");
	modOperandInt32();
	line("mod Operand float");
	modOperandFloat();
	line("mod Operand double");
	modOperandDouble();
}
