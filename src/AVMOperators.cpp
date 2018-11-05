#include "AbstractVM.hpp"

/*
** Operators
*/
std::ostream &		operator<<(std::ostream& o, std::vector<std::string> const & rhs)
{
	o << std::endl << "{" << std::endl;
	for (size_t i = 0; i < rhs.size(); i++) {
		o << "\"" << rhs[i] << "\"" << std::endl;
	}
	return o << "}";
}

std::string &		operator+(std::string& str, char const *c_str)
{
	str += std::string(c_str);
	return str;
}
