#include "AbstractVM.hpp"
#include <unistd.h>

#define VERBOSE 'v'
#define	OPTIONS "v"

static AVMInstruction const *	_stringToInstruction(std::string const & input)
{
	t_tokens				token;
	AVMInstruction const *	instruction;

	token = AVMLexer::inputToTokens(input);
	try
	{
		instruction = AVMParser::tokensToInstruction(token);
	}
	catch (AVMParser::EmptyLineException const & err)
	{
		return (NULL);
	}
	return (instruction);
}

namespace AVM
{
	void	displayHelp()
	{
		AVMLog::log.out() << "abstractvm: [-v] [file]" << std::endl
						<< "\t- v: verbose mode, on execution mode it displays each execution step" << std::endl
						<< "\t- file: the file containing avm instructions. "
						<< "If it's not specified, read on the standard input"
						<< std::endl;
	}

	void		displayStartHelp()
	{
		AVMLog::log.out() << COLOR_BOLD_CYAN << AVM_TITLE << COLOR_RESET << std::endl;
		AVMLog::log.out() << "Instructions available:" << std::endl;
		for (int i = instMin; i < instMax; i++)
		{
			eInstruction inst = static_cast<eInstruction>(i);

			AVMLog::log.out() << "- "
				<< eInstructionToString(inst);
			if (eInstructionRequiredOperand(inst))
				AVMLog::log.out() << " OPERAND";
			if (eInstructionShouldRequiredInteger(inst))
				AVMLog::log.out() << " INTEGER?";
			AVMLog::log.out() << std::endl;
		}
		AVMLog::log.out() << std::endl
							<< COLOR_BOLD_RED
							<< "Enjoy :)"
							<< COLOR_RESET << std::endl;
	}

	int			setOptions(int ac, char **av, int *nextIndex)
	{
		char		c;

		*nextIndex = 1;
		while ((c = getopt(ac, av, OPTIONS)) != -1)
		{
			switch (c)
			{
				case VERBOSE:
					if (!AVMLog::log.isDebug())
					{
						AVMLog::log.setDebug(true);
						(*nextIndex)++;
					}
					break;
				default:
					displayHelp();
					return (EXIT_FAILURE);
			}
		}
		return (EXIT_SUCCESS);
	}

	int			readFromFile(std::string const & filename,
							t_avm_input_list *list)
	{
		AVMReader			reader;

		try
		{
			*list = reader.read(filename);
		}
		catch (std::exception const & err)
		{
			AVMLog::log.error("\"" + filename + "\"", err);
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}

	int			readFromInput(std::istream & input,
									t_avm_input_list *list)
	{
		AVMReader			reader;

		try
		{
			*list = reader.read(input);
		}
		catch (std::exception const & err)
		{
			AVMLog::log.error("Error on STDIN: ", err);
			return (EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}

	// High level execution

	int			stringToInstructionList(t_avm_input_list const & inputs,
										t_instruction_list *to_fill)
	{
		bool					error;
		AVMInstruction const *	instruction;

		error = false;
		AVMLog::log.startLineCount();
		for (size_t i = 0; i < inputs.size(); i++)
		{
			AVMLog::log.increaseLine();
			try
			{
				instruction = _stringToInstruction(inputs[i]);
				if (instruction)
					to_fill->push_back(instruction);
			}
			catch (AVMParser::ExpressionException const & err)
			{
				AVMLog::log.error("instruction", err);
				error = true;
			}
			catch (std::exception const & err)
			{
				AVMLog::log.error("instruction", err);
				error = true;
			}
		}
		AVMLog::log.endLineCount();

		return error ? EXIT_FAILURE : EXIT_SUCCESS;
	}

 	int			executeInstructionList(Stack & onStack, t_instruction_list list)
	{
		try
		{
			AVMExec::execute(onStack, list);
			return (EXIT_SUCCESS);
		}
		catch (std::exception const & err)
		{
			AVMLog::log.error("execution", err);
			return (EXIT_FAILURE);
		}
	}

}
