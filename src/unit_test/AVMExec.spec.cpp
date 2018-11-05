#include "unit_test/tests.hpp"

static void		simpleExecTest()
{
	t_avm_input_list			instructions = {
		"push int8(42)",
		"print",
		"push int8(10)",
		"print",
		"push int16(32458)",
		"push int32(2147568)",
		"push double(42.42)",
		"push float(0.02)",
		"dump",
		"div",
		"add",
		"sub",
		"mul",
		"mod",
		"dump",
		"pop",
		"dump",
		"exit"
	};

	testExecInstructions(instructions, SUCCESS_TEST);
}

static void		simpleSpacesExecTest()
{
	t_avm_input_list			instructions = {
		"push        int8(42)",
		" print ",
		"	push  int8(10)      ",
		"	 print",
		" push int16(32458)		 ",
		" push int32(2147568) ",
		"push double(42.42) ",
		" push  float(0.02) ",
		"	div	",
		"	dump",
		"add	",
		" sub",
		"mul ",
		" mod ",
		" 	dump	 ",
		"	 pop 	",
		"                                   dump    ",
		"exit 									"
	};

	testExecInstructions(instructions, SUCCESS_TEST);
}

static void		emptyStackExecTest()
{
	std::string									fails[] = {"add", "sub", "mul", "div", "mod", "pop", "print", "assert int8(0)", ""};
	std::string									success[] = {"dump", "push int8(0)", "exit", ""};
	t_avm_input_list							instructions;

	for (size_t i = 0; fails[i].size() != 0; i++) {
		instructions = {fails[i]};
		testExecInstructions(instructions, FAIL_TEST);
	}

	for (size_t i = 0; success[i].size() != 0; i++) {
		instructions = {success[i], "exit"};
		testExecInstructions(instructions, SUCCESS_TEST);
	}
}

static void		invalidSyntaxExec()
{
	t_avm_input_list			instructions = {
		"",
		"hello world",
		"push toto",
		"assert",
		"pop truc",
		"pushint8(42)",
		// missing parameters
		"push",
		"assert",
		// too much parameters
		"add int8(0)",
		"sub plop",
		"mul pop ",
		" div test(0) test(2)",
		"mod int8(12) ",
		"dump int8;)",
		"pop truc",
		// with comment
		"push int8(;42)",
		"push ;int8(;42)",
		"push int8(42;)",
		"push int8(4;2)",
		// with invalid spaces
		"push int8(4 2)",
		"push int8(42 )",
		"push int8( 42)",
		"push int8 (42)",
		"push double(42. 2)",
		"push double(42. .2)",
		// garbage
		"                    ",
		"      Y",
		" pop pop",
		" plop ",
	};

	testExecInstructions(instructions, FAIL_TEST);
}

static void		errorDuringExecution()
{
	t_avm_input_list instructions[] = {
		// invalid operand action
		{"push int8(0)", "push int8(0)", "div"},
		{"push int8(0)", "push int8(0)", "mod"},
		// assert fail
		{"push double(42.0)", "assert double(28.2)", "exit"},
		{"push double(42.0)", "assert int8(42)", "exit"},
		// print on invalid operand
		{"push double(42.42)", "print", "exit"},
		{"push int16(42)", "print", "exit"},
		// bad value for operand
		{"push int8(255)"},
		{"push int16(255)"},
		{""}
	};

	for (size_t i = 0; instructions[i][0].size() != 0; i++) {
		testExecInstructions(instructions[i], FAIL_TEST);
	}
}

void			execTest()
{
	line("Execution - no error");
	simpleExecTest();
	line("Execution - no error - with spaces");
	simpleSpacesExecTest();
	line("Execution - empty stack");
	emptyStackExecTest();
	line("Execution - error : invalid syntax");
	invalidSyntaxExec();
	line("Execution - error during execution");
	errorDuringExecution();
}
