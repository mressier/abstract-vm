#include "AVMLog.hpp"
#include <sstream>

AVMLog::AVMLog() : _in(std::cin),
					_err(std::cerr),
					_out(std::cout),
					_text(std::string(DEFAULT_PROMPT)),
					_is_counting(false),
					_line(true)
{}

AVMLog::~AVMLog()
{}

void AVMLog::prompt()
{
	this->_out << this->_text;
}

/*
** Errors
*/
void AVMLog::error(std::string const & error) const
{
	(this->_err) << DEFAULT_ERROR << _lineCount()
					<< error << std::endl;
}

void AVMLog::error(std::string const & message, std::exception const & exc) const
{
	(this->_err) << DEFAULT_ERROR << _lineCount()
					<< message << ": "
					<< exc.what() << std::endl;
}

void AVMLog::error(std::string const & message, AVMParser::ExpressionException const & exc) const
{
	(this->_err) << DEFAULT_ERROR << _lineCount()
					<< message
					<< ": \"" << exc.getInstruction() << "\": "
					<< exc.what() << std::endl;
}

void AVMLog::error(std::stringstream const & error) const
{
	(this->_err) << DEFAULT_ERROR << _lineCount()
			<< error.str() << std::endl;
}

std::ostream &	AVMLog::out() const
{
	return this->_out;
}

std::ostream &	AVMLog::err() const
{
	return this->_err;
}

std::istream &	AVMLog::in() const
{
	return this->_in;
}

bool			AVMLog::isDebug() const
{
	return this->_debug;
}

void AVMLog::increaseLine()
{
	this->_line++;
}

void AVMLog::startLineCount()
{
	this->_is_counting = true;
	this->_line = 0;
}

void AVMLog::endLineCount()
{
	this->_is_counting = false;
}

void AVMLog::setDebug(bool is_debug)
{
	this->_debug = is_debug;
}

/*
** Private
*/

std::string AVMLog::_lineCount() const
{
	std::stringstream line;

	if (this->_is_counting)
		line << DEFAULT_LINE(this->_line);
	return (line.str());
}

/*
** Static
*/
AVMLog AVMLog::log = AVMLog();
