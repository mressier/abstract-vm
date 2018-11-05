#include "AbstractVM.hpp"
#include "unit_test/tests.hpp"

static void diffOperandInt8()
{
	testDiffOperand(opInt8, "1", opInt8, "1", SUCCESS_TEST);
	testDiffOperand(opInt8, "10", opInt8, "32", SUCCESS_TEST);
	testDiffOperand(opInt8, "-127", opInt8, "1", SUCCESS_TEST);		// min limit
	testDiffOperand(opInt8, "126", opInt8, "-1", SUCCESS_TEST);		// max limit

	// overflow, underflow
	testDiffOperand(opInt8, MIN_INT8, opInt8, "1", FAIL_TEST);		// underflow
	testDiffOperand(opInt8, MAX_INT8, opInt8, "-1", FAIL_TEST);		// overflow
	testDiffOperand(opInt16, MIN_INT16, opInt8, "1", FAIL_TEST);	// underflow
	testDiffOperand(opInt16, MAX_INT16, opInt8, "-1", FAIL_TEST);	// overflow

	testDiffOperand(opInt16, MIN_INT8, opInt8, MAX_INT8, SUCCESS_TEST);
	testDiffOperand(opInt16, MAX_INT8, opInt8, MIN_INT8, SUCCESS_TEST);

	testDiffOperand(opInt8, "-2", opInt16, "-127", SUCCESS_TEST);
	testDiffOperand(opInt16, "-2", opInt8, "-127", SUCCESS_TEST);
	testDiffOperand(opInt8, "-2", opDouble, "42.42", SUCCESS_TEST);
	testDiffOperand(opInt8, "-2", opFloat, "42.42", SUCCESS_TEST);
	testDiffOperand(opInt8, "-2", opDouble, "nan", SUCCESS_TEST);
	testDiffOperand(opInt8, "-2", opFloat, "-nan", SUCCESS_TEST);
	testDiffOperand(opInt8, "-2", opDouble, "inf", SUCCESS_TEST);
	testDiffOperand(opInt8, "-2", opFloat, "-inf", SUCCESS_TEST);
}

static void diffOperandInt16()
{
	testDiffOperand(opInt16, "1", opInt16, "1", SUCCESS_TEST);
	testDiffOperand(opInt16, "10", opInt16, "32", SUCCESS_TEST);
	testDiffOperand(opInt16, "1000", opInt16, "232", SUCCESS_TEST);
	// limits

	// overflow, underflow
	testDiffOperand(opInt16, MIN_INT16, opInt16, "1", FAIL_TEST);		// underflow
	testDiffOperand(opInt16, MAX_INT16, opInt16, "-1", FAIL_TEST);		// overflow
	testDiffOperand(opInt32, MIN_INT32, opInt16, "1", FAIL_TEST);		// underflow
	testDiffOperand(opInt32, MAX_INT32, opInt16, "-1", FAIL_TEST);		// overflow

	testDiffOperand(opInt32, MIN_INT16, opInt16, MAX_INT16, SUCCESS_TEST);
	testDiffOperand(opInt32, MAX_INT16, opInt16, MIN_INT16, SUCCESS_TEST);

	testDiffOperand(opInt16, "-2", opDouble, "42.42", SUCCESS_TEST);
	testDiffOperand(opDouble, "42.42", opInt16, "2", SUCCESS_TEST);
	testDiffOperand(opDouble, MAX_INT32".42", opInt16, "2", SUCCESS_TEST);
	testDiffOperand(opInt16, "2", opInt8, "42", SUCCESS_TEST);
}

static void diffOperandInt32()
{
	testDiffOperand(opInt32, "1", opInt32, "1", SUCCESS_TEST);
	testDiffOperand(opInt32, "10", opInt32, "32", SUCCESS_TEST);
	testDiffOperand(opInt32, "1000", opInt32, "232", SUCCESS_TEST);
	testDiffOperand(opInt32, "1", opInt32, "32766", SUCCESS_TEST);
	// limits

	// overflow, underflow
	testDiffOperand(opInt32, MIN_INT32, opInt32, "1", FAIL_TEST);		// underflow
	testDiffOperand(opInt32, MAX_INT32, opInt32, "-1", FAIL_TEST);		// overflow
	testDiffOperand(opInt32, "0", opInt32, MIN_INT32, FAIL_TEST);		// overflow

	testDiffOperand(opInt32, MIN_INT32, opFloat, "1", SUCCESS_TEST);
	testDiffOperand(opInt32, MAX_INT32, opFloat, "-1", SUCCESS_TEST);

	testDiffOperand(opInt32, "-2", opDouble, "42.42", SUCCESS_TEST);
	testDiffOperand(opDouble, "42.42", opInt32, "2", SUCCESS_TEST);
	testDiffOperand(opDouble, MAX_INT32".42", opInt32, "2", SUCCESS_TEST);
	testDiffOperand(opInt32, "2", opInt8, "42", SUCCESS_TEST);
}

static void diffOperandFloat()
{
	testDiffOperand(opFloat, "1", opFloat, "1", SUCCESS_TEST);
	testDiffOperand(opFloat, "10", opFloat, "32", SUCCESS_TEST);
	testDiffOperand(opFloat, "1000", opFloat, "232", SUCCESS_TEST);
	testDiffOperand(opFloat, "1", opFloat, "32766", SUCCESS_TEST);
	testDiffOperand(opFloat, "1", opFloat, "2147483646", SUCCESS_TEST);
	testDiffOperand(opFloat, "-1", opFloat, "-2147483647", SUCCESS_TEST);
	testDiffOperand(opFloat, MAX_INT32, opFloat, MAX_INT32, SUCCESS_TEST);
	testDiffOperand(opFloat, MIN_INT32, opFloat, MIN_INT32, SUCCESS_TEST);
	testDiffOperand(opFloat, MAX_INT32, opFloat, BEFORE_OVERFLOW_FLOAT, SUCCESS_TEST); // inf
	testDiffOperand(opFloat, "inf", opInt8, "42", SUCCESS_TEST);
	testDiffOperand(opFloat, "inf", opFloat, "-inf", SUCCESS_TEST);
	testDiffOperand(opFloat, "inf", opFloat, "nan", SUCCESS_TEST);
	testDiffOperand(opFloat, "nan", opFloat, "nan", SUCCESS_TEST);
	testDiffOperand(opFloat, "nan", opFloat, "-inf", SUCCESS_TEST);
	testDiffOperand(opFloat, "inf", opFloat, MIN_INT32, SUCCESS_TEST);
}

static void diffOperandDouble()
{
	testDiffOperand(opDouble, "1", opDouble, "1", SUCCESS_TEST);
	testDiffOperand(opDouble, "10", opDouble, "32", SUCCESS_TEST);
	testDiffOperand(opDouble, "1000", opDouble, "232", SUCCESS_TEST);
	testDiffOperand(opDouble, "1", opDouble, "32766", SUCCESS_TEST);
	testDiffOperand(opDouble, "1", opDouble, "2147483646", SUCCESS_TEST);
	testDiffOperand(opDouble, "-1", opDouble, "-2147483647", SUCCESS_TEST);
	testDiffOperand(opDouble, MAX_INT32, opDouble, MAX_INT32, SUCCESS_TEST);
	testDiffOperand(opDouble, MIN_INT32, opDouble, MIN_INT32, SUCCESS_TEST);
	testDiffOperand(opDouble, MAX_INT32, opDouble, BEFORE_OVERFLOW_FLOAT, SUCCESS_TEST);
	testDiffOperand(opDouble, BEFORE_OVERFLOW_FLOAT, opDouble, BEFORE_OVERFLOW_FLOAT, SUCCESS_TEST);
	testDiffOperand(opDouble, BEFORE_OVERFLOW_FLOAT, opFloat, BEFORE_OVERFLOW_FLOAT, SUCCESS_TEST);
	testDiffOperand(opDouble, "inf", opInt8, "42", SUCCESS_TEST);
	testDiffOperand(opDouble, "inf", opDouble, "-inf", SUCCESS_TEST);
	testDiffOperand(opDouble, "inf", opDouble, "nan", SUCCESS_TEST);
	testDiffOperand(opDouble, "nan", opDouble, "nan", SUCCESS_TEST);
	testDiffOperand(opDouble, "nan", opDouble, "-inf", SUCCESS_TEST);
	testDiffOperand(opDouble, "inf", opDouble, MIN_INT32, SUCCESS_TEST);
}

void diffOperand()
{
	line("diff Operand int8");
	diffOperandInt8();
	line("diff Operand int16");
	diffOperandInt16();
	line("diff Operand int32");
	diffOperandInt32();
	line("diff Operand float");
	diffOperandFloat();
	line("diff Operand double");
	diffOperandDouble();
}
