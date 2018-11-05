#ifndef STACK_HPP
# define STACK_HPP

#include "AVM.hpp"

class BasicStack
{
	public:
		BasicStack(void);
		BasicStack(BasicStack const & src);
		virtual ~BasicStack(void);

		/* modifications */
		IOperand const *	pop(void);
		void				push(IOperand const * op);

		/* display */
		void				dump(void) const;
		void				dump(std::ostream & o) const;
		void				hyperdump(std::ostream & o) const;
		void				hyperdump(void) const;

		/* operators */
		BasicStack const & operator=(BasicStack const & rhs);

		/* exceptions */
		class EmptyStackException: public std::exception {
			public: virtual const char *what() const throw();
		};

	protected:
		IOperand const *					_get_front() const;

	private:
		std::vector<IOperand const *>		_stack;
};

#endif
