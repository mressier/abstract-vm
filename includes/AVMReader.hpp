#ifndef AVMReader_HPP
# define AVMReader_HPP

#include "AbstractVM.hpp"
#include <fstream>

class AVMReader
{
	public:
		AVMReader(void);
		~AVMReader(void);

		/* public methods */
		t_avm_input_list	read(std::string const & filename);
		t_avm_input_list	read(std::istream & stream);

		/* exceptions */
		class InvalidFileException: public std::exception {
			public: virtual const char *what() const throw();
		};

		class InvalidEndOfInputException: public std::exception {
			public: virtual const char *what() const throw();
		};

		/* operators */

	private:
		AVMReader(AVMReader const & src);
		AVMReader & operator=(AVMReader const & rhs);
};

#endif
