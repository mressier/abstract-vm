#ifndef STACK_MANIPULATION_HPP
# define STACK_MANIPULATION_HPP

#include "BasicStack.hpp"

class Stack : public BasicStack
{
	public:
		Stack(void);				// default constructor
		Stack(Stack const & src);	// copy constructor
		~Stack(void);				//destructor

		/* manipulations */
		void				add_front();
		void				sub_front();
		void				mul_front();
		void				div_front();
		void				mod_front();
		void				print_front() const;
		void				assert_front(IOperand const &) const;

		/* exceptions */
		class AssertFailException: public std::exception {
			public: virtual const char *what() const throw();
		};
		class PrintOperandException: public std::exception {
			public: virtual const char *what() const throw();
		};

	private:
		/* operators */
		Stack & operator=(Stack const & rhs);
};

#endif
