#include "unit_test/tests.hpp"

static void		testErrorsNumberOfArguments()
{
	// invalid instruction
	testErrorParser(t_tokens({""}), FAIL_TEST);
	testErrorParser(t_tokens({" "}), FAIL_TEST);
	testErrorParser(t_tokens({" push"}), FAIL_TEST);
	testErrorParser(t_tokens({"push "}), FAIL_TEST);
	testErrorParser(t_tokens({"pushassert"}), FAIL_TEST);
	testErrorParser(t_tokens({"push assert"}), FAIL_TEST);
	testErrorParser(t_tokens({"push|assert"}), FAIL_TEST);
	testErrorParser(t_tokens({"addump"}), FAIL_TEST);
	testErrorParser(t_tokens({"int8(16)"}), FAIL_TEST);

	// not enough value
	testErrorParser(t_tokens({}), FAIL_TEST);
	testErrorParser(t_tokens({"push"}), FAIL_TEST);
	testErrorParser(t_tokens({"assert"}), FAIL_TEST);

	// bad value after
	testErrorParser(t_tokens({"push", "lolilol"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "push"}), FAIL_TEST);
	testErrorParser(t_tokens({"assert", "lolilol"}), FAIL_TEST);

	// too much value
	testErrorParser(t_tokens({"push", "int8(12)", "int16(32)"}), FAIL_TEST);
	testErrorParser(t_tokens({"assert", "int8(12)", "int16(32)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "kaka", "int16(32)"}), FAIL_TEST);
	testErrorParser(t_tokens({"assert", "int8(12)", "kaka"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(12)", "int16(32)", "int8(12)", "int16(32)", "int8(12)", "int16(32)", "int8(12)", "int16(32)", "int8(12)", "int16(32)", "int8(12)", "int16(32)"}), FAIL_TEST);
	testErrorParser(t_tokens({"assert", "int8(12)", "int16(32)", "int8(12)", "int16(32)", "int8(12)", "int16(32)", "int8(12)", "int16(32)", "int8(12)", "int16(32)", "int8(12)", "int16(32)"}), FAIL_TEST);
	testErrorParser(t_tokens({"pop", "int8(12)", "int16(32)"}), FAIL_TEST);
	testErrorParser(t_tokens({"dump", "int16(32)"}), FAIL_TEST);
	testErrorParser(t_tokens({"add", "int32(42)"}), FAIL_TEST);
	testErrorParser(t_tokens({"sub", "int32(42)"}), FAIL_TEST);
	testErrorParser(t_tokens({"mul", "int32(42)"}), FAIL_TEST);
	testErrorParser(t_tokens({"div", "int32(42)"}), FAIL_TEST);
	testErrorParser(t_tokens({"mod", "int32(42)"}), FAIL_TEST);
	testErrorParser(t_tokens({"print", "int32(42)"}), FAIL_TEST);
	testErrorParser(t_tokens({"exit", "int32(42)"}), FAIL_TEST);
	testErrorParser(t_tokens({"dump", "int16(32)", "double(42.2)"}), FAIL_TEST);
	testErrorParser(t_tokens({"add", "int32(42)", "double(42.2)"}), FAIL_TEST);
	testErrorParser(t_tokens({"sub", "int32(42)", "double(42.2)"}), FAIL_TEST);
	testErrorParser(t_tokens({"mul", "int32(42)", "double(42.2)"}), FAIL_TEST);
	testErrorParser(t_tokens({"div", "int32(42)", "double(42.2)"}), FAIL_TEST);
	testErrorParser(t_tokens({"mod", "int32(42)", "double(42.2)"}), FAIL_TEST);
	testErrorParser(t_tokens({"print", "int32(42)", "double(42.2)"}), FAIL_TEST);
	testErrorParser(t_tokens({"exit", "int32(42)", "double(42.2)"}), FAIL_TEST);
}

static void		testErrorBadFormat()
{
	testErrorParser(t_tokens({"push", ""}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "       "}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "kaka"}), FAIL_TEST);

	// invalid content
	testErrorParser(t_tokens({"push", "int8()"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(a)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(12a)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(int16(12))"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(())"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(0 )"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8( 0)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8( 0 )"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(@)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "double(42.a)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "double(42.42f)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "double(42.42.42)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "double(42.)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "double(42..4)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(42.4)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int32(42.01)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(+42)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(--42)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "float(-4.-2)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int16(-4 -2)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int16(4 2)"}), FAIL_TEST);

	// valid but not allowed by the syntax
	testErrorParser(t_tokens({"push", "double(42)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "float(42)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "double(inf)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "float(-inf)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "double(nan)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "float(-nan)"}), FAIL_TEST);


	// unknow operand
	testErrorParser(t_tokens({"push", "int(12)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "floatt(12)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "floatfloat(12)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "(12)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "()"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int31(12)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int1(12)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "18int(12)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8 (12)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "8(12)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "@(12)"}), FAIL_TEST);

	// bad parenthesis
	testErrorParser(t_tokens({"push", "int8(12"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int812)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(12))"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8((12)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8((12))"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8((12 12"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8{12}"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int812"}), FAIL_TEST);

	testErrorParser(t_tokens({"push", "(int8(12))"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", ":int8(12):"}), FAIL_TEST);

	// garbage
	testErrorParser(t_tokens({"push", "int8(12) "}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(12) int8(12)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", " int8(12) "}), FAIL_TEST);
	testErrorParser(t_tokens({"push", " int8(12) :D"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", " int8(12) 16 32"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", " int8(12)(23)"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", " int8(12)23"}), FAIL_TEST);
}

static void		testSuccess()
{
	testErrorParser(t_tokens({"push", "int8(12)"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"push", "int16(1254)"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"push", "int32(452)"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"push", "float(12.2)"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"push", "double(-42456218.42)"}), SUCCESS_TEST);

	testErrorParser(t_tokens({"assert", "int8(12)"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"assert", "int16(-56)"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"assert", "int32(412)"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"assert", "float(-12.2)"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"assert", "double(42.42)"}), SUCCESS_TEST);

	testErrorParser(t_tokens({"dump"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"add"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"sub"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"mul"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"div"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"mod"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"print"}), SUCCESS_TEST);
	testErrorParser(t_tokens({"exit"}), SUCCESS_TEST);
}

static void		testInvalidOperand()
{
	testErrorParser(t_tokens({"push", "int8(" OVERFLOW_INT8 ")"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int8(" UNDERFLOW_INT8 ")"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int16(" OVERFLOW_INT16 ")"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int16(" UNDERFLOW_INT16 ")"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int32(" OVERFLOW_INT32 ")"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "int32(" UNDERFLOW_INT32 ")"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "float(" OVERFLOW_FLOAT ")"}), FAIL_TEST);
	testErrorParser(t_tokens({"push", "double(" OVERFLOW_FLOAT ")"}), FAIL_TEST);
}

void			parserTest()
{
	line("Parser - invalid arguments");
	testErrorsNumberOfArguments();
	line("Parser - invalid format");
	testErrorBadFormat();
	line("Parser - success");
	testSuccess();
	line("Parser - good syntax but invalid operands values");
	testInvalidOperand();
}
