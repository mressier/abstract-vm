#include "AbstractVM.hpp"
#include "unit_test/tests.hpp"

static void createOperandInt8()
{
	testCreateOperand(opInt8, "0", SUCCESS_TEST);
	testCreateOperand(opInt8, "1", SUCCESS_TEST);
	testCreateOperand(opInt8, "-1", SUCCESS_TEST);
	testCreateOperand(opInt8, "42", SUCCESS_TEST);
	testCreateOperand(opInt8, "-42", SUCCESS_TEST);
	testCreateOperand(opInt8, MAX_INT8, SUCCESS_TEST);		// max valid
	testCreateOperand(opInt8, MIN_INT8, SUCCESS_TEST);		// min valid

	testCreateOperand(opInt8, OVERFLOW_INT8, FAIL_TEST);		// max + 1 not valid
	testCreateOperand(opInt8, UNDERFLOW_INT8, FAIL_TEST);		// min - 1 not valid
	testCreateOperand(opInt8, "255", FAIL_TEST);
	testCreateOperand(opInt8, "-255", FAIL_TEST);
	testCreateOperand(opInt8, MAX_INT32, FAIL_TEST);
	testCreateOperand(opInt8, MIN_INT32, FAIL_TEST);
	testCreateOperand(opInt8, "a", FAIL_TEST);
	testCreateOperand(opInt8, "1a", FAIL_TEST);
	testCreateOperand(opInt8, "1.1", FAIL_TEST);
	testCreateOperand(opInt8, "127.0", FAIL_TEST);
	testCreateOperand(opInt8, "", FAIL_TEST);
}

static void createOperandInt16()
{
	testCreateOperand(opInt16, "0", SUCCESS_TEST);
	testCreateOperand(opInt16, "1", SUCCESS_TEST);
	testCreateOperand(opInt16, "-1", SUCCESS_TEST);
	testCreateOperand(opInt16, "42", SUCCESS_TEST);
	testCreateOperand(opInt16, "-42", SUCCESS_TEST);
	testCreateOperand(opInt16, "127", SUCCESS_TEST);
	testCreateOperand(opInt16, "-128", SUCCESS_TEST);
	testCreateOperand(opInt16, MAX_INT16, SUCCESS_TEST);		// max valid
	testCreateOperand(opInt16, MIN_INT16, SUCCESS_TEST);		// min valid

	testCreateOperand(opInt16, OVERFLOW_INT16, FAIL_TEST);		// max + 1 not valid
	testCreateOperand(opInt16, UNDERFLOW_INT16, FAIL_TEST);		// min - 1 not valid
	testCreateOperand(opInt16, MAX_INT32"7", FAIL_TEST);
	testCreateOperand(opInt16, MIN_INT32"8", FAIL_TEST);
	testCreateOperand(opInt16, ",", FAIL_TEST);
	testCreateOperand(opInt16, "-", FAIL_TEST);
	testCreateOperand(opInt16, "1a", FAIL_TEST);
	testCreateOperand(opInt16, "1.1", FAIL_TEST);
	testCreateOperand(opInt16, "127,0", FAIL_TEST);
	testCreateOperand(opInt16, "   ", FAIL_TEST);
}

static void createOperandInt32()
{
	testCreateOperand(opInt32, "0", SUCCESS_TEST);
	testCreateOperand(opInt32, "1", SUCCESS_TEST);
	testCreateOperand(opInt32, "-1", SUCCESS_TEST);
	testCreateOperand(opInt32, "42", SUCCESS_TEST);
	testCreateOperand(opInt32, "-42", SUCCESS_TEST);
	testCreateOperand(opInt32, "32767", SUCCESS_TEST);
	testCreateOperand(opInt32, "-32768", SUCCESS_TEST);
	testCreateOperand(opInt32, MAX_INT32, SUCCESS_TEST);		// max valid
	testCreateOperand(opInt32, MIN_INT32, SUCCESS_TEST);		// min valid

	testCreateOperand(opInt32, OVERFLOW_INT32, FAIL_TEST);		// max + 1 not valid
	testCreateOperand(opInt32, UNDERFLOW_INT32, FAIL_TEST);		// min - 1 not valid
	testCreateOperand(opInt32, MAX_INT32"7", FAIL_TEST);
	testCreateOperand(opInt32, MIN_INT32"8", FAIL_TEST);
	testCreateOperand(opInt32, "1.1", FAIL_TEST);
	testCreateOperand(opInt32, "25555,00019", FAIL_TEST);
}

static void createOperandFloat()
{
	testCreateOperand(opFloat, "0", SUCCESS_TEST);
	testCreateOperand(opFloat, "1", SUCCESS_TEST);
	testCreateOperand(opFloat, "-1", SUCCESS_TEST);
	testCreateOperand(opFloat, "42", SUCCESS_TEST);
	testCreateOperand(opFloat, "-42", SUCCESS_TEST);
	testCreateOperand(opFloat, "32767", SUCCESS_TEST);
	testCreateOperand(opFloat, "-32768", SUCCESS_TEST);
	testCreateOperand(opFloat, OVERFLOW_INT32, SUCCESS_TEST);
	testCreateOperand(opFloat, UNDERFLOW_INT32, SUCCESS_TEST);
	testCreateOperand(opFloat, "-333444555666", SUCCESS_TEST);
	testCreateOperand(opFloat, BEFORE_OVERFLOW_FLOAT, SUCCESS_TEST);
	testCreateOperand(opFloat, "0.12", SUCCESS_TEST);
	testCreateOperand(opFloat, "1.0", SUCCESS_TEST);
	testCreateOperand(opFloat, "-1.56", SUCCESS_TEST);
	testCreateOperand(opFloat, "42.42", SUCCESS_TEST);
	testCreateOperand(opFloat, "-42.042", SUCCESS_TEST);
	testCreateOperand(opFloat, "32767.42", SUCCESS_TEST);
	testCreateOperand(opFloat, "-32768.77777777777777", SUCCESS_TEST);
	testCreateOperand(opFloat, "2147483648.2", SUCCESS_TEST);
	testCreateOperand(opFloat, "-2147483649.3", SUCCESS_TEST);
	testCreateOperand(opFloat, "-649.", SUCCESS_TEST);

	testCreateOperand(opFloat, OVERFLOW_FLOAT, FAIL_TEST);
	testCreateOperand(opFloat, "-3649.3a", FAIL_TEST);
	testCreateOperand(opFloat, "36a49.3", FAIL_TEST);
	testCreateOperand(opFloat, "36a49.3", FAIL_TEST);
	testCreateOperand(opFloat, "3649.a", FAIL_TEST);
	testCreateOperand(opFloat, "3649f", FAIL_TEST);
}

static void createOperandDouble()
{
	testCreateOperand(opDouble, "0", SUCCESS_TEST);
	testCreateOperand(opDouble, "1", SUCCESS_TEST);
	testCreateOperand(opDouble, "-1", SUCCESS_TEST);
	testCreateOperand(opDouble, "42", SUCCESS_TEST);
	testCreateOperand(opDouble, "-42", SUCCESS_TEST);
	testCreateOperand(opDouble, "32767", SUCCESS_TEST);
	testCreateOperand(opDouble, "-32768", SUCCESS_TEST);
	testCreateOperand(opDouble, OVERFLOW_INT32, SUCCESS_TEST);
	testCreateOperand(opDouble, UNDERFLOW_INT32, SUCCESS_TEST);
	testCreateOperand(opDouble, "-333444555666", SUCCESS_TEST);
	testCreateOperand(opDouble, BEFORE_OVERFLOW_FLOAT, SUCCESS_TEST);
	testCreateOperand(opDouble, "0.12", SUCCESS_TEST);
	testCreateOperand(opDouble, "1.0", SUCCESS_TEST);
	testCreateOperand(opDouble, "-1.56", SUCCESS_TEST);
	testCreateOperand(opDouble, "42.42", SUCCESS_TEST);
	testCreateOperand(opDouble, "-42.042", SUCCESS_TEST);
	testCreateOperand(opDouble, "32767.42", SUCCESS_TEST);
	testCreateOperand(opDouble, "-32768.77777777777777", SUCCESS_TEST);
	testCreateOperand(opDouble, "2147483648.2", SUCCESS_TEST);
	testCreateOperand(opDouble, "-2147483649.3", SUCCESS_TEST);
	testCreateOperand(opDouble, "-649.", SUCCESS_TEST);
	testCreateOperand(opDouble, "inf", SUCCESS_TEST);
	testCreateOperand(opDouble, "-inf", SUCCESS_TEST);
	testCreateOperand(opDouble, "nan", SUCCESS_TEST);
	testCreateOperand(opDouble, "-nan", SUCCESS_TEST);

	testCreateOperand(opDouble, OVERFLOW_FLOAT, FAIL_TEST);
	testCreateOperand(opDouble, "-3649.3a", FAIL_TEST);
	testCreateOperand(opDouble, "36a49.3", FAIL_TEST);
	testCreateOperand(opDouble, "36a49.3", FAIL_TEST);
	testCreateOperand(opDouble, "3649.a", FAIL_TEST);
}

static void equalsOperand()
{
	/* int 8 */
	testEqualsOperand(opInt8, "42", opInt8, "42", SUCCESS_TEST);
	testEqualsOperand(opInt8, MAX_INT8, opInt8, MAX_INT8, SUCCESS_TEST);
	testEqualsOperand(opInt8, "0", opInt8, "0", SUCCESS_TEST);

	testEqualsOperand(opInt8, "42", opInt8, "43", FAIL_TEST);
	testEqualsOperand(opInt8, "42", opInt16, "42", FAIL_TEST);
	testEqualsOperand(opInt8, "42", opInt32, "42", FAIL_TEST);
	testEqualsOperand(opInt8, "42", opDouble, "42", FAIL_TEST);
	testEqualsOperand(opInt8, "42", opFloat, "42", FAIL_TEST);


	/* int 16 */
	testEqualsOperand(opInt16, "42", opInt16, "42", SUCCESS_TEST);
	testEqualsOperand(opInt16, MAX_INT16, opInt16, MAX_INT16, SUCCESS_TEST);
	testEqualsOperand(opInt16, MIN_INT16, opInt16, MIN_INT16, SUCCESS_TEST);
	testEqualsOperand(opInt16, "0", opInt16, "0", SUCCESS_TEST);

	testEqualsOperand(opInt16, "42", opInt16, "-42", FAIL_TEST);
	testEqualsOperand(opInt16, "42", opFloat, "42.2", FAIL_TEST);
	testEqualsOperand(opInt16, "42", opDouble, "42.0", FAIL_TEST);
	testEqualsOperand(opInt16, "42", opDouble, "42", FAIL_TEST);

	/* int 32 */
	testEqualsOperand(opInt32, "42", opInt32, "42", SUCCESS_TEST);
	testEqualsOperand(opInt32, MAX_INT32, opInt32, MAX_INT32, SUCCESS_TEST);
	testEqualsOperand(opInt32, MIN_INT32, opInt32, MIN_INT32, SUCCESS_TEST);
	testEqualsOperand(opInt32, "0", opInt32, "0", SUCCESS_TEST);

	testEqualsOperand(opInt32, "42", opInt32, "-42", FAIL_TEST);
	testEqualsOperand(opInt32, "42", opInt32, "0", FAIL_TEST);
	testEqualsOperand(opInt32, "42", opFloat, "42", FAIL_TEST);
	testEqualsOperand(opInt32, "42", opDouble, "42", FAIL_TEST);

	/* float */
	testEqualsOperand(opFloat, "42", opFloat, "42", SUCCESS_TEST);
	testEqualsOperand(opFloat, "42", opFloat, "42.0", SUCCESS_TEST);
	testEqualsOperand(opFloat, "42.1001", opFloat, "42.100100", SUCCESS_TEST);
	testEqualsOperand(opFloat, "0", opFloat, "0", SUCCESS_TEST);
	testEqualsOperand(opFloat, "42.02", opFloat, "42.02", SUCCESS_TEST);
	testEqualsOperand(opFloat, "inf", opFloat, "inf", SUCCESS_TEST);
	testEqualsOperand(opFloat, "nan", opFloat, "nan", SUCCESS_TEST);
	testEqualsOperand(opFloat, "nan", opFloat, "-nan", SUCCESS_TEST);
	testEqualsOperand(opFloat, "154793.021456", opFloat, "154793.021456", SUCCESS_TEST);

	testEqualsOperand(opFloat, "42", opFloat, "41", FAIL_TEST);
	testEqualsOperand(opFloat, "0", opFloat, "0.02", FAIL_TEST);
	testEqualsOperand(opFloat, "42.1", opFloat, "42.2", FAIL_TEST);
	testEqualsOperand(opFloat, "42.02", opFloat, "42.03", FAIL_TEST);
	testEqualsOperand(opFloat, "inf", opFloat, "-inf", FAIL_TEST);
	testEqualsOperand(opFloat, "154793.021456", opFloat, "154793.021457", FAIL_TEST);

	testEqualsOperand(opFloat, "42", opDouble, "42", FAIL_TEST);

	/* double */
	testEqualsOperand(opDouble, "42", opDouble, "42", SUCCESS_TEST);
	testEqualsOperand(opDouble, "42", opDouble, "42.0", SUCCESS_TEST);
	testEqualsOperand(opDouble, "42.1001", opDouble, "42.100100", SUCCESS_TEST);
	testEqualsOperand(opDouble, "0", opDouble, "0", SUCCESS_TEST);
	testEqualsOperand(opDouble, "42.02", opDouble, "42.02", SUCCESS_TEST);
	testEqualsOperand(opDouble, "inf", opDouble, "inf", SUCCESS_TEST);
	testEqualsOperand(opDouble, "nan", opDouble, "nan", SUCCESS_TEST);
	testEqualsOperand(opDouble, "nan", opDouble, "-nan", SUCCESS_TEST);
	testEqualsOperand(opDouble, "154793.021456", opDouble, "154793.021456", SUCCESS_TEST);

	testEqualsOperand(opDouble, "42", opDouble, "41", FAIL_TEST);
	testEqualsOperand(opDouble, "0", opDouble, "0.02", FAIL_TEST);
	testEqualsOperand(opDouble, "42.1", opDouble, "42.2", FAIL_TEST);
	testEqualsOperand(opDouble, "42.02", opDouble, "42.03", FAIL_TEST);
	testEqualsOperand(opDouble, "inf", opDouble, "-inf", FAIL_TEST);
	testEqualsOperand(opDouble, "154793.021456", opDouble, "154793.021457", FAIL_TEST);
}

void createOperands()
{
	line("create Operand int8");
	createOperandInt8();
	line("create Operand int16");
	createOperandInt16();
	line("create Operand int32");
	createOperandInt32();
	line("create Operand float");
	createOperandFloat();
	line("create Operand double");
	createOperandDouble();
	line("Operands equals");
	equalsOperand();
}
