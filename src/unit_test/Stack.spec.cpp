#include "AbstractVM.hpp"
#include "unit_test/tests.hpp"

void empty_stack()
{
	Stack	my_stack;

	testPop(&my_stack, FAIL_TEST);
	my_stack.dump();
}

void push_and_pop_simple()
{
	Stack			my_stack;
	int					max = 3;

	for (int i = 0; i < max; i++) {
		testPush(&my_stack, opInt16, std::to_string(i), SUCCESS_TEST);
	}

	my_stack.dump();

	for (int i = 0; i < max; i++) {
		testPop(&my_stack, SUCCESS_TEST);
	}

	testPop(&my_stack, FAIL_TEST);
}

void push_and_pop_all_type_of_operand()
{
	Stack			my_stack;

	for (size_t i = opMin; i < opMax; i++) {
		testPush(&my_stack, static_cast<eOperandType>(i), "42", SUCCESS_TEST);
	}

	my_stack.dump();

	for (size_t i = opMin; i < opMax; i++) {
		testPop(&my_stack, SUCCESS_TEST);
	}

}

void stackTest()
{
	line("BasicStack");
	empty_stack();
	line("BasicStack - push and pop");
	push_and_pop_simple();
	line("BasicStack - more push and pop");
	push_and_pop_all_type_of_operand();
}
