#include "unit_test/tests.hpp"

#define SUCCESS "\033[32m[OK]\033[0m "
#define FAIL "\033[31m[FAIL]\033[0m "

#define DISPLAY(X) (X) << std::endl

/*
** CREATE OPERAND
*/
void	testCreateOperand(eOperandType type, std::string const & value, bool should_success)
{
	try
	{
		IOperand const * op = OperandFactory::createOperand(type, value);
		if (should_success)
			DISPLAY(std::cout << SUCCESS
				<< "type : " << eOperandTypeToString(type)
				<< ", value : [" << value
				<< "] create an operand : " << *op);
		else
			DISPLAY(std::cout << FAIL
				<< "type : " << eOperandTypeToString(type)
				<< ", value : [" << value
				<< "] unexpected success : " << *op);
		delete op;
	}
	catch (std::exception & err) {
		if (should_success)
			DISPLAY(std::cout << FAIL
				<< "type : " << eOperandTypeToString(type)
				<< ", value : [" << value
				<< "] throw an unexpected error : "
				<< err.what());
		else
			DISPLAY(std::cout << SUCCESS
				<< "type : " << eOperandTypeToString(type)
				<< ", value : [" << value
				<< "] throw an error as expected : "
				<< err.what());
	}
}

void 		testEqualsOperand(eOperandType type1, std::string const & value1,
								eOperandType type2, std::string const & value2,
								bool should_success)
{
	IOperand const * op1;
	IOperand const * op2;

	try
	{
		op1 = OperandFactory::createOperand(type1, value1);
		op2 = OperandFactory::createOperand(type2, value2);
	}
	catch (std::exception & err)
	{
		DISPLAY(std::cout << FAIL
				<< "unexpected fail on create operand : "
				<< err.what());
		return ;
	}

	if (*op1 == *op2)
	{
		if (should_success)
			DISPLAY(std::cout << SUCCESS
					<< *op1 << " == " << *op2
					<< " - OK");
		else
			DISPLAY(std::cout << FAIL
					<< *op1 << " == " << *op2
					<< " - unexpected equals");
	}
	else
	{
		if (should_success)
			DISPLAY(std::cout << FAIL
				<< *op1 << " != " << *op2
				<< " - unexpected NOT equals");
		else
			DISPLAY(std::cout << SUCCESS
				<< *op1 << " != " << *op2
				<< " - OK");
	}
}

/*
** OPERATIONS
*/
static void testOperation(char const operation,
						eOperandType type1, std::string const & value1,
						eOperandType type2, std::string const & value2,
						bool should_success)
{
	IOperand const * op1;
	IOperand const * op2;

	try
	{
		op1 = OperandFactory::createOperand(type1, value1);
		op2 = OperandFactory::createOperand(type2, value2);
	}
	catch (std::exception & err)
	{
		DISPLAY(std::cout << FAIL
				<< "unexpected fail on create operand : "
				<< err.what());
		return ;
	}

	try
	{
		IOperand const * out;

		switch (operation) {
			case '+': out = (*op2) + (*op1); break;
			case '-': out = (*op2) - (*op1); break;
			case '*': out = (*op2) * (*op1); break;
			case '/': out = (*op2) / (*op1); break;
			case '%': out = (*op2) % (*op1); break;
		}
		if (should_success)
			DISPLAY(std::cout << SUCCESS
					<< "[" << *op2 << "] " << operation << " [" << *op1 << "]"
					<< " = " << *out);
		else
			DISPLAY(std::cout << FAIL
				<< "[" << *op2 << "] " << operation << " [" << *op1 << "]"
				<< "] unexpected success : " << *out);
		delete out;
	}
	catch (std::exception & err)
	{
		if (should_success)
			DISPLAY(std::cout << FAIL
				<< "[" << *op2 << "] " << operation << " [" << *op1 << "]"
				<< " unexpected fail : "
				<< err.what());
		else
			DISPLAY(std::cout << SUCCESS
				<< "[" << *op2 << "] " << operation << " [" << *op1 << "]"
				<< " throw an error as expected : "
				<< err.what());
	}
	delete op1;
	delete op2;
}

void testAddOperand(eOperandType type1, std::string const & value1,
					eOperandType type2, std::string const & value2,
					bool should_success)
{
	testOperation('+', type1, value1, type2, value2, should_success);
}

void testDiffOperand(eOperandType type1, std::string const & value1,
					eOperandType type2, std::string const & value2,
					bool should_success)
{
	testOperation('-', type1, value1, type2, value2, should_success);
}

void testMultOperand(eOperandType type1, std::string const & value1,
					eOperandType type2, std::string const & value2,
					bool should_success)
{
	testOperation('*', type1, value1, type2, value2, should_success);
}

void testDivOperand(eOperandType type1, std::string const & value1,
					eOperandType type2, std::string const & value2,
					bool should_success)
{
	testOperation('/', type1, value1, type2, value2, should_success);
}

void testModOperand(eOperandType type1, std::string const & value1,
					eOperandType type2, std::string const & value2,
					bool should_success)
{
	testOperation('%', type1, value1, type2, value2, should_success);
}

/*
** BasicStack TESTS
*/

void		testPop(Stack * BasicStack, bool should_success)
{
	try
	{
		IOperand const *	op = BasicStack->pop();

		if (should_success)
			DISPLAY(std::cout << SUCCESS
					<< "pop on BasicStack : "
					<< *op);
		else
			DISPLAY(std::cout << FAIL
				<< "pop on BasicStack : "
				<< *op);
		delete op;
	}
	catch (std::exception const & err)
	{
		if (should_success)
			DISPLAY(std::cout << FAIL
				<< "pop on BasicStack"
				<< " unexpected fail : "
				<< err.what());
		else
			DISPLAY(std::cout << SUCCESS
				<< "pop on BasicStack"
				<< " throw an error as expected : "
				<< err.what());
	}
	return ;
}


void		testPush(Stack * BasicStack,
					eOperandType type, std::string const & value,
					bool should_success)
{
	IOperand const *	op;

	try
	{
		op = OperandFactory::createOperand(type, value);
	}
	catch (std::exception & err)
	{
		DISPLAY(std::cout << FAIL
				<< "unexpected fail on create operand : "
				<< err.what());
		return ;
	}

	try
	{
		BasicStack->push(op);

		if (should_success)
			DISPLAY(std::cout << SUCCESS
					<< "pop on BasicStack : "
					<< *op);
		else
			DISPLAY(std::cout << FAIL
				<< "pop on BasicStack : "
				<< *op);
	}
	catch (std::exception const & err)
	{
		if (should_success)
			DISPLAY(std::cout << FAIL
				<< "pop on BasicStack"
				<< " unexpected fail : "
				<< err.what());
		else
			DISPLAY(std::cout << SUCCESS
				<< "pop on BasicStack"
				<< " throw an error as expected : "
				<< err.what());
	}
	return ;
}

void	testErrorParser(t_tokens const & strings,
					bool should_success)
{
	try
	{
		AVMInstruction const * instruction =  AVMParser::tokensToInstruction(strings);

		if (should_success)
			DISPLAY(std::cout << SUCCESS
					<< "create instruction : "
					<< *instruction);
		else
			DISPLAY(std::cout << FAIL
					<< "unexpected success, create instruction : "
					<< *instruction);
		delete instruction;
	}
	catch (std::exception & err)
	{
		if (should_success)
			DISPLAY(std::cout << FAIL
					<< "unexpected fail : '"  << err.what()
					<< "' on strings "
					<< strings);
		else
			DISPLAY(std::cout << SUCCESS
					<< "fail with error : '" << err.what()
					<< "' as expected on strings "
					<< strings);
	}
}

void	testErrorLexer(std::string const & input, t_tokens const & output)
{
	try
	{
		t_tokens	lexerOutput = AVMLexer::inputToTokens(input);
		bool		isError = false;

		if (lexerOutput.size() == output.size())
		{
			for (size_t i = 0; i < lexerOutput.size(); i++)
			{
				if (lexerOutput[i] != output[i])
					isError = true;
			}
		}

		if (isError)
			DISPLAY(std::cout << FAIL
					<< "unexpected fail on input '"
					<< input << "'"
					<< ", get : " << lexerOutput);
		else
			DISPLAY(std::cout << SUCCESS
					<< "on input '" << input
					<< "', get : " << lexerOutput);
	}
	catch (std::exception & err)
	{
		DISPLAY(std::cout << FAIL
			<< "unexpected error on lexer : "
			<< err.what());
	}
}

static int		execute(t_avm_input_list const & instructions)
{
	t_instruction_list		list;
	Stack					stack;

	if (AVM::stringToInstructionList(instructions, &list) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	if (AVM::executeInstructionList(stack, list) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

void	testExecInstructions(t_avm_input_list & instructions,
							bool should_success)
{
	int		result;

	result = execute(instructions);

	if (result == EXIT_SUCCESS)
	{
		if (should_success)
			DISPLAY(std::cout << SUCCESS
					<< "set of "
					<< instructions.size() << " instr "
					<< "starting with \"" << instructions[0] << "\"");
		else
			DISPLAY(std::cout << FAIL
				<< "unexpected success on a set of "
				<< instructions.size() << " instr "
				<< "starting with \"" << instructions[0] << "\"");
	}
	else
	{
		if (should_success)
			DISPLAY(std::cout << FAIL
					<< "unexpected fail on a set of "
					<< instructions.size() << " instr "
					<< "starting with \"" << instructions[0] << "\"");
		else
			DISPLAY(std::cout << SUCCESS
				<< "fail as expected on a set of "
				<< instructions.size() << " instr "
				<< "starting with \"" << instructions[0] << "\"");
	}

	for (size_t i = 0; i < instructions.size(); i++) {
		instructions.erase(instructions.begin() + i);
	}

}
