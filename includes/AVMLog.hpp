#ifndef AVMLog_HPP
# define AVMLog_HPP

#include <iostream>
#include "AVMParser.hpp"
#include "AVM.hpp"

#define DEFAULT_PROMPT	COLOR_BOLD_CYAN "(avm) > " COLOR_RESET
#define DEFAULT_ERROR	COLOR_BOLD_RED "ERROR: " COLOR_RESET
#define DEFAULT_LINE(X) COLOR_BOLD_GREY "line " << std::to_string(X) << ": " << COLOR_RESET

class AVMLog
{
	public:
		static AVMLog		log;

		/* public methods */
		void	prompt();
		void	error(std::string const & error) const;
		void	error(std::stringstream const & error) const;
		void	error(std::string const & message, std::exception const & exc) const;
		void	error(std::string const & message, AVMParser::ExpressionException const & exc) const;

		std::ostream &	out() const;
		std::ostream &	err() const;
		std::istream &	in() const;
		bool			isDebug() const;

		void	increaseLine();
		void	startLineCount();
		void	endLineCount();
		void	setDebug(bool is_debug);

	private:
		AVMLog();
		AVMLog(AVMLog const & src);
		~AVMLog(void);
		AVMLog & operator=(AVMLog const & rhs);

		std::string _lineCount() const;


		std::istream &		_in;
		std::ostream &		_err;
		std::ostream &		_out;
		std::string	const	_text;

		bool				_is_counting;
		unsigned int		_line;

		bool				_debug;
};

#endif
