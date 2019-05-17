
/* 
 * File:   sudoku_option.h
 * Author: gustavorv86
 *
 * Created on 10 de octubre de 2018, 16:14
 */

#ifndef SUDOKU_OPTION_H
#define SUDOKU_OPTION_H

#include <list>

#include "sudoku_cell.h"

using namespace std;

namespace sudoku {

	class sudoku_option {
	private:
		sudoku_cell cell;
		list<int> values;
	public:
		sudoku_option();
		virtual ~sudoku_option();
	
		int get_row();
		int get_column();
		list<int> get_values();
		
		void set_row(int i);
		void set_column(int j);
		void set_value(int value);
		void set_values(list<int> values);
	};

}

#endif /* SUDOKU_OPTION_H */

