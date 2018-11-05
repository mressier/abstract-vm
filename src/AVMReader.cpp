#include "AVMReader.hpp"
#include <fstream>
#include <istream>

/*
** Constructor
*/
AVMReader::AVMReader()
{}

/*
** Destructor
*/
AVMReader::~AVMReader()
{
}

/*
** Public methods
*/
t_avm_input_list	AVMReader::read(std::string const & filename)
{
	std::ifstream			input(filename);
	t_avm_input_list		list;
	std::string 			line;

	if (!input.is_open())
		throw InvalidFileException();
	while (std::getline(input, line))
		list.push_back(line);
	input.close();
	return list;
}

t_avm_input_list	AVMReader::read(std::istream & stream)
{
	t_avm_input_list		list;
	std::string 			line;
	bool					end;

	end = false;
	AVMLog::log.prompt();
	while (std::getline(stream, line))
	{
		if (line == END_OF_STDOUT)
		{
			end = true;
			break ;
		}
		list.push_back(line);
		AVMLog::log.prompt();
	}
	if (!end)
		throw InvalidEndOfInputException();
	return list;
}


/*
** Exceptions
*/
const char *AVMReader::InvalidFileException::what() const throw()
{
	return ("cannot open file");
}

const char *AVMReader::InvalidEndOfInputException::what() const throw()
{
	return ("input must end with \";;\"");
}
