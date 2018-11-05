#ifndef AVMExec_HPP
# define AVMExec_HPP

#include "AbstractVM.hpp"

namespace AVMExec
{
	bool		isEndOfExecution(AVMInstruction const & instruction);
	bool		isRepeatInstruction(AVMInstruction const & instruction);
	void		executeStackInstruction(Stack & onStack, AVMInstruction const & instruction);
	void		execute(Stack & onStack, t_instruction_list const & instructions);
	void		repeat(Stack & onStack, AVMInstruction const & instruction,
						unsigned int nbOfRepeat);

	/* exceptions */
	class NoExitInstructionException: public std::exception {
		public: virtual const char *what() const throw();
	};

	class InvalidRepeatInstructionException: public std::exception {
		public: virtual const char *what() const throw();
	};
}

#endif
