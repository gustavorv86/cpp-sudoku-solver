
/* 
 * File:   sudoku_cell.cpp
 * Author: gustavorv86
 * 
 */

#include "sudoku_cell.h"

using namespace sudoku;

sudoku_cell::sudoku_cell() {
	this->i = -1;
	this->j = -1;
}

sudoku_cell::sudoku_cell(const sudoku_cell& other) {
	this->i = other.i;
	this->j = other.j;
}

sudoku_cell::~sudoku_cell() {
}

int sudoku_cell::get_row() {
	return i;
}

int sudoku_cell::get_column() {
	return j;
}

void sudoku_cell::set(int i, int j) {
	this->i = i;
	this->j = j;
}

void sudoku_cell::set_row(int i) {
	this->i = i;
}

void sudoku_cell::set_column(int j) {
	this->j = j;
}