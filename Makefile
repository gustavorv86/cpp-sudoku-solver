SHELL=/bin/bash

########## DIRECTORIES ##########

SRCDIR=src

BUILDDIR=build

DISTDIR=dist

TARGET=${DISTDIR}/sudoku-solver

BUILDOBJS=
BUILDOBJS+=${BUILDDIR}/parse_args.o
BUILDOBJS+=${BUILDDIR}/sudoku_table.o
BUILDOBJS+=${BUILDDIR}/sudoku_cell.o
BUILDOBJS+=${BUILDDIR}/sudoku_option.o
BUILDOBJS+=${BUILDDIR}/sudoku_solver.o
BUILDOBJS+=${BUILDDIR}/main.o

########## COMPILER AND LINKER ############

CXX=/usr/bin/g++

INCLUDEDIRS=
INCLUDEDIRS+=-I${SRCDIR}/arguments
INCLUDEDIRS+=-I${SRCDIR}/sudoku

CXXFLAGS=-std=gnu++14 -ggdb -Wall -Wextra ${INCLUDEDIRS}

CXXFLAGS_RELEASE=-std=gnu++14 -O3 -Wall -Wextra ${INCLUDEDIRS}

LDFLAGS=

########## RULES ##########
.PHONY: clean all

all: make_dirs ${TARGET}

make_dirs:
	@mkdir -p ${BUILDDIR}
	@mkdir -p ${DISTDIR}

clean: 
	@rm -rf ${BUILDDIR}
	@rm -rf ${DISTDIR}

${BUILDDIR}/parse_args.o: ${SRCDIR}/arguments/parse_args.h ${SRCDIR}/arguments/parse_args.cpp
	@echo -e "\n\t"$@
	${CXX} ${CXXFLAGS} -c ${SRCDIR}/arguments/parse_args.cpp -o ${BUILDDIR}/parse_args.o

${BUILDDIR}/sudoku_exception.o: ${SRCDIR}/sudoku/sudoku_exception.h ${SRCDIR}/sudoku/sudoku_exception.cpp
	@echo -e "\n\t"$@
	${CXX} ${CXXFLAGS} -c ${SRCDIR}/sudoku/sudoku_exception.cpp -o ${BUILDDIR}/sudoku_exception.o

${BUILDDIR}/sudoku_table.o: ${SRCDIR}/sudoku/sudoku_table.h ${SRCDIR}/sudoku/sudoku_table.cpp
	@echo -e "\n\t"$@
	${CXX} ${CXXFLAGS} -c ${SRCDIR}/sudoku/sudoku_table.cpp -o ${BUILDDIR}/sudoku_table.o

${BUILDDIR}/sudoku_cell.o: ${SRCDIR}/sudoku/sudoku_cell.h ${SRCDIR}/sudoku/sudoku_cell.cpp
	@echo -e "\n\t"$@
	${CXX} ${CXXFLAGS} -c ${SRCDIR}/sudoku/sudoku_cell.cpp -o ${BUILDDIR}/sudoku_cell.o

${BUILDDIR}/sudoku_option.o: ${SRCDIR}/sudoku/sudoku_option.h ${SRCDIR}/sudoku/sudoku_option.cpp
	@echo -e "\n\t"$@
	${CXX} ${CXXFLAGS} -c ${SRCDIR}/sudoku/sudoku_option.cpp -o ${BUILDDIR}/sudoku_option.o

${BUILDDIR}/sudoku_solver.o: ${SRCDIR}/sudoku/sudoku_solver.h ${SRCDIR}/sudoku/sudoku_solver.cpp
	@echo -e "\n\t"$@
	${CXX} ${CXXFLAGS} -c ${SRCDIR}/sudoku/sudoku_solver.cpp -o ${BUILDDIR}/sudoku_solver.o

${BUILDDIR}/main.o: ${SRCDIR}/main.cpp
	@echo -e "\n\t"$@
	${CXX} ${CXXFLAGS} -c ${SRCDIR}/main.cpp -o ${BUILDDIR}/main.o

${TARGET}: ${BUILDOBJS}
	@echo -e "\n\t"$@
	${CXX} ${CXXFLAGS} -no-pie ${BUILDOBJS} -o ${TARGET} ${LDFLAGS}
	