SHELL=/bin/bash

SRC=./src
BUILD=./build
DIST=./dist
TARGET=${DIST}/sudoku-solver

CXX=/usr/bin/g++
CFLAGS=-ggdb -Wall -Wextra

CFLAGS+=\
	-I${SRC}/arguments\
	-I${SRC}/sudoku

BUILD_OBJS=\
	${BUILD}/arguments_parse_args.o\
	${BUILD}/sudoku_sudoku_cell.o\
	${BUILD}/sudoku_sudoku_option.o\
	${BUILD}/sudoku_sudoku_solver.o\
	${BUILD}/sudoku_sudoku_table.o\
	${BUILD}/main.o

all: make_dirs ${TARGET}

clean:
	@if [[ -d ${BUILD} ]]; then \
		echo "Removing ${BUILD} directory..."; \
		rm -rf ${BUILD}; \
	fi
	@if [[ -d ${DIST} ]]; then \
		echo "Removing ${DIST} directory..."; \
		rm -rf ${DIST}; \
	fi

make_dirs:
	@mkdir -p ${BUILD}
	@mkdir -p ${DIST}

${BUILD}/arguments_parse_args.o: ${SRC}/arguments/parse_args.cpp ${SRC}/arguments/parse_args.h
	${CXX} ${CFLAGS} -c ${SRC}/arguments/parse_args.cpp -o ${BUILD}/arguments_parse_args.o

${BUILD}/sudoku_sudoku_cell.o: ${SRC}/sudoku/sudoku_cell.cpp ${SRC}/sudoku/sudoku_cell.h
	${CXX} ${CFLAGS} -c ${SRC}/sudoku/sudoku_cell.cpp -o ${BUILD}/sudoku_sudoku_cell.o

${BUILD}/sudoku_sudoku_option.o: ${SRC}/sudoku/sudoku_option.cpp ${SRC}/sudoku/sudoku_option.h
	${CXX} ${CFLAGS} -c ${SRC}/sudoku/sudoku_option.cpp -o ${BUILD}/sudoku_sudoku_option.o

${BUILD}/sudoku_sudoku_solver.o: ${SRC}/sudoku/sudoku_solver.cpp ${SRC}/sudoku/sudoku_solver.h
	${CXX} ${CFLAGS} -c ${SRC}/sudoku/sudoku_solver.cpp -o ${BUILD}/sudoku_sudoku_solver.o

${BUILD}/sudoku_sudoku_table.o: ${SRC}/sudoku/sudoku_table.cpp ${SRC}/sudoku/sudoku_table.h
	${CXX} ${CFLAGS} -c ${SRC}/sudoku/sudoku_table.cpp -o ${BUILD}/sudoku_sudoku_table.o

${BUILD}/main.o: ${SRC}/main.cpp
	${CXX} ${CFLAGS} -c ${SRC}/main.cpp -o ${BUILD}/main.o

${TARGET}: ${BUILD_OBJS}
	${CXX} ${CFLAGS} ${BUILD_OBJS} -o ${TARGET}
