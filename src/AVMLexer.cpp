#include "AVMLexer.hpp"

/*
** Tools
*/
static std::string		_removeComment(std::string const & input)
{
	size_t		commentCharIndex;
	std::string	cleanInput;

	commentCharIndex = input.find(COMMENT_CHAR);
	if (commentCharIndex != std::string::npos)
		cleanInput = input.substr(0, commentCharIndex);
	else
		cleanInput = input;
	return cleanInput;
}

static t_tokens		_splitTokens(std::string const & input)
{
	std::string		separators(TOKEN_SEPARATOR);
	std::string		string;
	t_tokens		tokens;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (separators.find(input[i]) != std::string::npos)
		{
			if (!string.empty())
			{
				tokens.push_back(string);
				string = std::string();
			}
		}
		else
			string.push_back(input[i]);
	}

	if (!string.empty())
		tokens.push_back(std::string(string));

	return tokens;
}

/*
** AVMLexer
*/
namespace AVMLexer
{
	t_tokens			inputToTokens(std::string const & input)
	{
		std::string		cleanInput;
		t_tokens			token;

		cleanInput = _removeComment(input);
		token = _splitTokens(cleanInput);
		return token;
	}
}
