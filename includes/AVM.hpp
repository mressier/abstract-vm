#ifndef AVM_HPP
# define AVM_HPP

# define AVM_INPUT_DEFAULT std::cin
# define AVM_OUTPUT_DEFAULT std::cout

#define COLOR_BOLD_CYAN     "\033[1;36m"
#define COLOR_BOLD_RED      "\033[1;31m"
#define COLOR_BOLD_YELLOW   "\033[1;33m"
#define COLOR_BOLD_GREY     "\033[1;90m"
#define COLOR_RESET         "\033[0;0m"

#define AVM_TITLE			"\n\
           _         _                  _    __      ____  __ \n\
     /\\   | |       | |                | |   \\ \\    / /  \\/  | \n\
    /  \\  | |__  ___| |_ _ __ __ _  ___| |_   \\ \\  / /| \\  / | \n\
   / /\\ \\ | '_ \\/ __| __| '__/ _` |/ __| __|   \\ \\/ / | |\\/| | \n\
  / ____ \\| |_) \\__ \\ |_| | | (_| | (__| |_     \\  /  | |  | | \n\
 /_/    \\_\\_.__/|___/\\__|_|  \\__,_|\\___|\\__|     \\/   |_|  |_| \n\
\n\
\n\
"

#include <string>
#include <vector>

typedef std::vector<std::string>        t_avm_input_list;
typedef std::vector<std::string>        t_tokens;

#include "eOperandType.hpp"
#include "eInstruction.hpp"

#include "IOperand.hpp"

#endif
