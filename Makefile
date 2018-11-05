NAME=abstract_vm

CPP_DIR = src/
TEST_DIR = unit_test/
INC_DIR = includes/
O_DIR = .tmp/

INCLUDES= -I $(INC_DIR)
COMPILE = clang++

### TO COMPLETE ###

INC_FILES = AbstractVM.hpp \
				eOperandType.hpp \
				eInstruction.hpp \
				IOperand.hpp \
				OperandFactory.hpp \
				Operand.hpp \
				Operand.tpp \
				BasicStack.hpp \
				Stack.hpp \
				AVMInstruction.hpp \
				AVMParser.hpp \
				AVMLexer.hpp \
				AVMExec.hpp \
				AVMReader.hpp \
				AVMLog.hpp \
				AVM.hpp

SRC_FILES = OperandFactory.cpp \
			eInstruction.cpp \
			eOperandType.cpp \
			BasicStack.cpp \
			Stack.cpp \
			AVMInstruction.cpp \
			AVMParser.cpp \
			AVMLexer.cpp \
			AVMExec.cpp \
			AVMReader.cpp \
			AVMLog.cpp \
			AbstractVM.cpp \
			AVMOperators.cpp

SRC_TESTS_FILES = main.cpp \
				testFunctions.cpp \
				tools.cpp \
				createOperand.spec.cpp \
				addOperand.spec.cpp \
				diffOperand.spec.cpp \
				multOperand.spec.cpp \
				divOperand.spec.cpp \
				modOperand.spec.cpp \
				Stack.spec.cpp \
				AVMParser.spec.cpp \
				AVMLexer.spec.cpp \
				AVMExec.spec.cpp

INC_TESTS_FILES = tests.hpp

### END ###

ifdef TEST
	FLAGS = -Wall -Wextra -Werror -std=c++11 -DTEST=1
	CPP_SRC = $(addprefix $(CPP_DIR), $(SRC_FILES)) $(addprefix $(CPP_DIR)$(TEST_DIR), $(SRC_TESTS_FILES))
	CPP_INC = $(addprefix $(INC_DIR), $(INC_FILES)) $(addprefix $(INC_DIR)$(TEST_DIR), $(INC_TESTS_FILES))
else
	FLAGS = -Wall -Wextra -Werror -std=c++11
	CPP_SRC = $(addprefix $(CPP_DIR), $(SRC_FILES) main.cpp)
	CPP_INC = $(addprefix $(INC_DIR), $(INC_FILES))
endif


O_FILES = $(CPP_SRC:%.cpp=$(O_DIR)%.o)

all: $(O_DIR) $(NAME)

$(O_DIR):
	@mkdir -p $(O_DIR)
	@mkdir -p $(O_DIR)$(CPP_DIR)
	@mkdir -p $(O_DIR)$(CPP_DIR)$(TEST_DIR)

$(O_DIR)%.o: %.cpp $(CPP_INC)
	@printf "[\033[32;1m $(NAME) \033[0m]\t\033[31;1m$<\033[0m\\n"
	@$(COMPILE) $(FLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(O_FILES)
	@$(COMPILE) $(FLAGS) -o $(NAME) $(O_FILES)
	@printf "[\033[32;1m Run \033[0m]\033[31;1m $(NAME) \033[0m\\n"

clean:
	@rm -rf $(O_DIR)
	@printf "[\033[32;1m Delete \033[0m] $(O_FILES) \033[0m\\n"

fclean: clean
	@rm -f $(NAME)
	@printf "[\033[32;1m Delete \033[0m] $(NAME) \033[0m\\n"

re: fclean all

.PHONY: all clean fclean re
