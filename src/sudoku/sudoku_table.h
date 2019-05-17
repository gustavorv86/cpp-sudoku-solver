
/* 
 * File:   sudoku.h
 * Author: gustavorv86
 *
 * Created on 10 de octubre de 2018, 7:59
 */

#ifndef SUDOKU_H
#define SUDOKU_H

#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include "sudoku_option.h"

using namespace std;

namespace sudoku {

	static const int MAX_SUDOKU = 9;
	static const int CELL_EMPTY = 0;
	
	class sudoku_table {
	private:
		array<array<int, MAX_SUDOKU>, MAX_SUDOKU> table;

		int convert_value(char cvalue);
		bool is_in_row(int row, int value);
		bool is_in_column(int col, int value);
		bool is_in_grid(int row, int col, int value);
		bool is_valid_value(int row, int col, int value);
		bool is_valid_grid(int i_min, int i_max, int j_min, int j_max);
		list<int> get_valid_values(int row, int col);
		bool list_contains(list<int> values, int value);
		
	public:
		sudoku_table();
		sudoku_table(const sudoku_table& other);
		virtual ~sudoku_table();
		
		bool read_file(const string filename);
		void write_file(const string filename);
		bool is_full();
		bool is_valid();
		void set_value(int i, int j, int value);
		sudoku_option get_best_option();
		
		string to_str();
	};

}

#endif
