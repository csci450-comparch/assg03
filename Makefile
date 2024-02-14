
# source files in this project (for beautification)
PROJECT_NAME=assg03
assg_src = lc3vm.c \
	   lc3vm_dbg.c

test_src = ${PROJECT_NAME}-tests.cpp \
	   ${assg_src}

sim_src  = ${PROJECT_NAME}-sim.c \
	   ${assg_src}

# template files, list all files that define template classes
# or functions and should not be compiled separately (template
# is included where used)
template-files =

# assignment description documentation
assg_doc = ${PROJECT_NAME}.pdf

# common targets and variables used for all assignments/projects
include include/Makefile.inc

# assignment header file specific dependencies
${OBJ_DIR}/lc3vm.o: ${INC_DIR}/lc3vm.h ${INC_DIR}/lc3vm_dbg.h ${SRC_DIR}/lc3vm.c
${OBJ_DIR}/lc3vm_dbg.o: ${INC_DIR}/lc3vm_dbg.h ${SRC_DIR}/lc3vm_dbg.c
