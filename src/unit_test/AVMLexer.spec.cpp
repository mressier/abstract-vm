#include "unit_test/tests.hpp"

static void		spaceTest()
{
	testErrorLexer(" hello", t_tokens({"hello"}));
	testErrorLexer("hello ", t_tokens({"hello"}));
	testErrorLexer(" hello ", t_tokens({"hello"}));

	testErrorLexer(" hello world", t_tokens({"hello", "world"}));
	testErrorLexer("   hello world", t_tokens({"hello", "world"}));
	testErrorLexer("hello world ", t_tokens({"hello", "world"}));
	testErrorLexer("hello world   ", t_tokens({"hello", "world"}));
	testErrorLexer(" hello world ", t_tokens({"hello", "world"}));
	testErrorLexer("   hello   world   ", t_tokens({"hello", "world"}));
	testErrorLexer("   hello world   ", t_tokens({"hello", "world"}));
}

static void		tabsTest()
{
	testErrorLexer("	hello", t_tokens({"hello"}));
	testErrorLexer("hello	", t_tokens({"hello"}));
	testErrorLexer("	hello	", t_tokens({"hello"}));

	testErrorLexer("	hello	world", t_tokens({"hello", "world"}));
	testErrorLexer("		hello	world", t_tokens({"hello", "world"}));
	testErrorLexer("hello	world	", t_tokens({"hello", "world"}));
	testErrorLexer("hello	world		", t_tokens({"hello", "world"}));
	testErrorLexer("	hello	world	", t_tokens({"hello", "world"}));
	testErrorLexer("		hello			world			", t_tokens({"hello", "world"}));
	testErrorLexer("			hello	world		", t_tokens({"hello", "world"}));
}

static void		simpleTest()
{
	testErrorLexer("h", t_tokens({"h"}));
	testErrorLexer("h i", t_tokens({"h", "i"}));
	testErrorLexer("h i j k", t_tokens({"h", "i", "j", "k"}));

	testErrorLexer("hello", t_tokens({"hello"}));
	testErrorLexer("hello world", t_tokens({"hello", "world"}));
	testErrorLexer("hello world", t_tokens({"hello", "world"}));

	testErrorLexer("push float(16.0)", t_tokens({"push", "float(16.0)"}));
	testErrorLexer("push   int (16) ", t_tokens({"push", "int", "(16)"}));
	testErrorLexer(" push   int( 16)", t_tokens({"push", "int(", "16)"}));
}

static void 	testWithComment()
{
	testErrorLexer(";", t_tokens({""}));
	testErrorLexer(" ; ", t_tokens({""}));
	testErrorLexer(" ;", t_tokens({""}));
	testErrorLexer(";;", t_tokens({""}));
	testErrorLexer(";h", t_tokens({""}));
	testErrorLexer("; choubidou", t_tokens({""}));
	testErrorLexer("h ; choubidou", t_tokens({"h"}));
	testErrorLexer("h; choubidou", t_tokens({"h"}));
	testErrorLexer("h;choubidou", t_tokens({"h"}));
	testErrorLexer("push;choubidou", t_tokens({"push"}));
	testErrorLexer("push ;choubidou", t_tokens({"push"}));
	testErrorLexer("push int(8;", t_tokens({"push", "int(8"}));
	testErrorLexer("push int(8;)", t_tokens({"push", "int(8"}));
	testErrorLexer("push int(8) ; int16(32) ;int32(64)", t_tokens({"push", "int(8)"}));
	testErrorLexer("push int(8)  int16(32)  ;int32(64)", t_tokens({"push", "int(8)", "int16(32)"}));
}

void			lexerTest()
{
	line("Lexer");
	simpleTest();
	spaceTest();
	tabsTest();
	testWithComment();
}
