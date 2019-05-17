
/* 
 * File:   sudoku_option.cpp
 * Author: gustavorv86
 * 
 * Created on 10 de octubre de 2018, 16:14
 */

#include "sudoku_option.h"

using namespace sudoku;

sudoku_option::sudoku_option() {
}

sudoku_option::~sudoku_option() {
}

int sudoku_option::get_row() {
	return this->cell.get_row();
}

int sudoku_option::get_column() {
	return this->cell.get_column();
}

list<int> sudoku_option::get_values() {
	return this->values;
}

void sudoku_option::set_row(int i) {
	this->cell.set_row(i);
}

void sudoku_option::set_column(int j) {
	this->cell.set_column(j);
}

void sudoku_option::set_value(int value) {
	this->values.push_back(value);
}

void sudoku_option::set_values(list<int> values) {
	this->values = values;
}
