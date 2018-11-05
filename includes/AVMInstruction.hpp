#ifndef AVMInstruction_HPP
# define AVMInstruction_HPP

#include "eInstruction.hpp"
#include "IOperand.hpp"
#include <vector>

class AVMInstruction
{
	public:
		AVMInstruction(eInstruction const & instruction, IOperand const * op);
		AVMInstruction(AVMInstruction const & src);
		~AVMInstruction(void);

		eInstruction		getInstruction() const;
		IOperand const *	getOperand() const;
		std::string const &	toString() const;

		/* exceptions */
		class InvalidInstructionException: public std::exception {
			public: virtual const char *what() const throw();
		};

		/* operators */
		AVMInstruction & operator=(AVMInstruction const & rhs);

	private:
		AVMInstruction(void);

		eInstruction	_instruction;
		IOperand const *	_operand;
		std::string			_str;
};

/* operators */
std::ostream &		operator<<(std::ostream& o, AVMInstruction const & rhs);

/* defined types */
typedef std::vector<AVMInstruction const *>		t_instruction_list;

#endif
