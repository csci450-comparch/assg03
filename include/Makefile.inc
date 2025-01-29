# compiler flags, tools and include variables
GCC=gcc
GCC_FLAGS=-Wall -Werror -pedantic -g -std=c18
GPP=g++
GPP_FLAGS=-Wall -Werror -pedantic
INCLUDES=-Iinclude
LINKS=

FORMATTER=clang-format
FORMATTER_FLAGS=-i

FORMATTER=clang-format
DOC=doxygen
PANDOC=pandoc
RM=rm -rf

FORMATTER_FLAGS=-i
DOC_FLAGS=config/Doxyfile
PANDOC_FLAGS=-s --variable geometry:margin=0.75in --variable urlcolor:NavyBlue --variable colorlinks:true
PANDOC_HIGHLIGHT=--highlight-style tango

SRC_DIR := src
OBJ_DIR := obj
DOC_DIR := doc
BIN_DIR := .
INC_DIR := include
TEST_TARGET=$(BIN_DIR)/test
SIM_TARGET=$(BIN_DIR)/sim


# sources and objects needed to be linked together for unit test executable
# careful, repetition of test_obj needs to use test_obj in second repeated call
test_src := $(patsubst %.c, $(SRC_DIR)/%.c, $(test_src))
test_src := $(patsubst %.cpp, $(SRC_DIR)/%.cpp, $(test_src))
test_obj := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(test_src))
test_obj := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(test_obj))
catch_test_obj := $(OBJ_DIR)/catch2-main.o

# objects needed to be linked together for main simulation executable
sim_src := $(patsubst %.c, $(SRC_DIR)/%.c, $(sim_src))
sim_obj := $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(sim_src))

# pdf files for assignment description documentation
assg_doc := $(patsubst %.pdf, $(DOC_DIR)/%.pdf, $(assg_doc))

## List of all valid targets in this project:
## ------------------------------------------
## all          : by default generate all executables
##                (test and debug)
##
.PHONY : all
all : $(TEST_TARGET) $(SIM_TARGET)


## test         : Build and link together unit test executable
##
$(TEST_TARGET) : $(test_obj) $(catch_test_obj)
	$(GPP) $(GPP_FLAGS) $(test_obj) $(catch_test_obj) -o $@


## sim          : Build and link together the main simulation executable
##
$(SIM_TARGET) : $(sim_obj)
	$(GCC) $(GCC_FLAGS) $(sim_obj) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(GCC) $(GCC_FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(GPP) $(GPP_FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@


## unit-tests   : Run the unit tests showing failing tests only
##
unit-tests : $(TEST_TARGET)
	./$(TEST_TARGET) --use-colour yes

## system-tests : Run the system tests on the full simulation
##
system-tests: $(SIM_TARAGET)
	./scripts/run-system-tests

## format       : Run the code formatter/beautifier by hand if needed
##
.PHONY : format
format :
	$(FORMATTER) $(FORMATTER_FLAGS) include/*.hpp src/*.cpp


## refdocs      : Create doxygen reference documentation from
##                doc comments.
##
.PHONY : refdocs
refdocs :
	@echo "Generating doxygen documentation..."
	$(DOC) $(DOC_FLAGS) 2>&1 | grep -A 1 warning | egrep -v "assg.*\.md" | grep -v "Found unknown command" | grep -v "Searching for include" | sed -e "s|${PWD}/||g"


## assgdocs     : Create assignment description documentation from
##                README.md project markdown file.
##
.PHONY : assgdocs
assgdocs : $(assg_doc)

$(assg_doc) : README.md
	${PANDOC} ${PANDOC_FLAGS} ${PANDOC_HIGHLIGHT} -o $@ $^


## clean        : Remove auto-generated files for a completely
##                clean rebuild
##
.PHONY : clean
clean  :
	$(RM) $(TEST_TARGET) $(SIM_TARGET) *.o *.gch
	$(RM) output html latex
	$(RM) $(test_obj) $(sim_obj)

## help         : Get all build targets supported by this build.
##
.PHONY : help
help : Makefile include/Makefile.inc
	@sed -n 's/^##//p' $^


## targets      : Debug targets
##
.PHONY : targets
targets :
	@echo "test_src= $(test_src)"
	@echo "test_obj= $(test_obj)"
	@echo "sim_src = $(sim_src)"
	@echo "sim_obj = $(sim_obj)"	