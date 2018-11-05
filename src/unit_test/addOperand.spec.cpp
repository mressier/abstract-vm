#include "AbstractVM.hpp"
#include "unit_test/tests.hpp"

static void addOperandInt8()
{
	testAddOperand(opInt8, "1", opInt8, "1", SUCCESS_TEST);
	testAddOperand(opInt8, "10", opInt8, "32", SUCCESS_TEST);
	testAddOperand(opInt8, "1", opInt8, "126", SUCCESS_TEST);		// max limit
	testAddOperand(opInt8, "-1", opInt8, "-127", SUCCESS_TEST);		// min limit

	testAddOperand(opInt8, "1", opInt8, MAX_INT8, FAIL_TEST);		// overflow
	testAddOperand(opInt8, "-1", opInt8, MIN_INT8, FAIL_TEST);		// underflow
	testAddOperand(opInt8, "-1", opInt32, MIN_INT32, FAIL_TEST);	// undeflow
	testAddOperand(opInt8, "1", opInt32, MAX_INT32, FAIL_TEST);		// overflow
	testAddOperand(opInt16, MAX_INT16, opInt8, "2", FAIL_TEST);		// overflow
	testAddOperand(opInt32, MAX_INT32, opInt8, "2", FAIL_TEST);		// overflow

	testAddOperand(opInt8, "-2", opInt16, "-127", SUCCESS_TEST);
	testAddOperand(opInt16, "-2", opInt8, "-127", SUCCESS_TEST);
	testAddOperand(opInt8, "-2", opDouble, "42.42", SUCCESS_TEST);
	testAddOperand(opInt8, "-2", opFloat, "42.42", SUCCESS_TEST);
	testAddOperand(opInt8, "-2", opDouble, "nan", SUCCESS_TEST);
	testAddOperand(opInt8, "-2", opFloat, "-nan", SUCCESS_TEST);
	testAddOperand(opInt8, "-2", opDouble, "inf", SUCCESS_TEST);
	testAddOperand(opInt8, "-2", opFloat, "-inf", SUCCESS_TEST);
}

static void addOperandInt16()
{
	testAddOperand(opInt16, "1", opInt16, "1", SUCCESS_TEST);
	testAddOperand(opInt16, "10", opInt16, "32", SUCCESS_TEST);
	testAddOperand(opInt16, "1000", opInt16, "232", SUCCESS_TEST);
	testAddOperand(opInt16, "1", opInt16, "32766", SUCCESS_TEST);		// max limit
	testAddOperand(opInt16, "-1", opInt16, "-32767", SUCCESS_TEST);		// min limit

	testAddOperand(opInt16, "1", opInt16, MAX_INT16, FAIL_TEST);		// overflow
	testAddOperand(opInt16, "-1", opInt16, MIN_INT16, FAIL_TEST);		// underflow
	testAddOperand(opInt16, "1", opInt32, MAX_INT32, FAIL_TEST);		// overflow
	testAddOperand(opInt16, "-1", opInt32, MIN_INT32, FAIL_TEST);		// underflow

	testAddOperand(opInt16, "-2", opDouble, "42.42", SUCCESS_TEST);
	testAddOperand(opDouble, "42.42", opInt16, "2", SUCCESS_TEST);
	testAddOperand(opDouble, MAX_INT32".42", opInt16, "2", SUCCESS_TEST);
	testAddOperand(opInt16, "2", opInt8, "42", SUCCESS_TEST);
}

static void addOperandInt32()
{
	testAddOperand(opInt32, "1", opInt32, "1", SUCCESS_TEST);
	testAddOperand(opInt32, "10", opInt32, "32", SUCCESS_TEST);
	testAddOperand(opInt32, "1000", opInt32, "232", SUCCESS_TEST);
	testAddOperand(opInt32, "1", opInt32, "32766", SUCCESS_TEST);
	testAddOperand(opInt32, "0", opInt32, MAX_INT32, SUCCESS_TEST);			// max limit
	testAddOperand(opInt32, "0", opInt32, MIN_INT32, SUCCESS_TEST);			// min limit
	testAddOperand(opInt32, "1", opInt32, "2147483646", SUCCESS_TEST);		// max limit
	testAddOperand(opInt32, "-1", opInt32, "-2147483647", SUCCESS_TEST);	// min limit

	testAddOperand(opInt32, "1", opInt32, MAX_INT32, FAIL_TEST);			// overflow
	testAddOperand(opInt32, "-1", opInt32, MIN_INT32, FAIL_TEST);			// underflow
	testAddOperand(opInt32, MAX_INT8, opInt32, MAX_INT32, FAIL_TEST);		// overflow
	testAddOperand(opInt32, MIN_INT8, opInt32, MIN_INT32, FAIL_TEST);		// underflow

	testAddOperand(opInt32, "-2", opDouble, "42.42", SUCCESS_TEST);
	testAddOperand(opDouble, "42.42", opInt32, "2", SUCCESS_TEST);
	testAddOperand(opDouble, MAX_INT32".42", opInt32, "2", SUCCESS_TEST);
	testAddOperand(opInt32, "2", opInt8, "42", SUCCESS_TEST);
}

static void addOperandFloat()
{
	testAddOperand(opFloat, "1", opFloat, "1", SUCCESS_TEST);
	testAddOperand(opFloat, "10", opFloat, "32", SUCCESS_TEST);
	testAddOperand(opFloat, "1000", opFloat, "232", SUCCESS_TEST);
	testAddOperand(opFloat, "1", opFloat, "32766", SUCCESS_TEST);
	testAddOperand(opFloat, "1", opFloat, "2147483646", SUCCESS_TEST);
	testAddOperand(opFloat, "-1", opFloat, "-2147483647", SUCCESS_TEST);
	testAddOperand(opFloat, MAX_INT32, opFloat, MAX_INT32, SUCCESS_TEST);
	testAddOperand(opFloat, MIN_INT32, opFloat, MIN_INT32, SUCCESS_TEST);
	testAddOperand(opFloat, MAX_INT32, opFloat, BEFORE_OVERFLOW_FLOAT, SUCCESS_TEST); // inf
	testAddOperand(opFloat, "inf", opInt8, "42", SUCCESS_TEST);
	testAddOperand(opFloat, "inf", opFloat, "-inf", SUCCESS_TEST);
	testAddOperand(opFloat, "inf", opFloat, "nan", SUCCESS_TEST);
	testAddOperand(opFloat, "nan", opFloat, "nan", SUCCESS_TEST);
	testAddOperand(opFloat, "nan", opFloat, "-inf", SUCCESS_TEST);
	testAddOperand(opFloat, "inf", opFloat, MIN_INT32, SUCCESS_TEST);
}

static void addOperandDouble()
{
	testAddOperand(opDouble, "1", opDouble, "1", SUCCESS_TEST);
	testAddOperand(opDouble, "10", opDouble, "32", SUCCESS_TEST);
	testAddOperand(opDouble, "1000", opDouble, "232", SUCCESS_TEST);
	testAddOperand(opDouble, "1", opDouble, "32766", SUCCESS_TEST);
	testAddOperand(opDouble, "1", opDouble, "2147483646", SUCCESS_TEST);
	testAddOperand(opDouble, "-1", opDouble, "-2147483647", SUCCESS_TEST);
	testAddOperand(opDouble, MAX_INT32, opDouble, MAX_INT32, SUCCESS_TEST);
	testAddOperand(opDouble, MIN_INT32, opDouble, MIN_INT32, SUCCESS_TEST);
	testAddOperand(opDouble, MAX_INT32, opDouble, BEFORE_OVERFLOW_FLOAT, SUCCESS_TEST);
	testAddOperand(opDouble, BEFORE_OVERFLOW_FLOAT, opDouble, BEFORE_OVERFLOW_FLOAT, SUCCESS_TEST);
	testAddOperand(opDouble, BEFORE_OVERFLOW_FLOAT, opFloat, BEFORE_OVERFLOW_FLOAT, SUCCESS_TEST);
	testAddOperand(opDouble, "inf", opInt8, "42", SUCCESS_TEST);
	testAddOperand(opDouble, "inf", opDouble, "-inf", SUCCESS_TEST);
	testAddOperand(opDouble, "inf", opDouble, "nan", SUCCESS_TEST);
	testAddOperand(opDouble, "nan", opDouble, "nan", SUCCESS_TEST);
	testAddOperand(opDouble, "nan", opDouble, "-inf", SUCCESS_TEST);
	testAddOperand(opDouble, "inf", opDouble, MIN_INT32, SUCCESS_TEST);
}

void addOperand()
{
	line("add Operand int8");
	addOperandInt8();
	line("add Operand int16");
	addOperandInt16();
	line("add Operand int32");
	addOperandInt32();
	line("add Operand float");
	addOperandFloat();
	line("add Operand double");
	addOperandDouble();
}
