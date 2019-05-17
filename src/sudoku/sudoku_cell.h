
/* 
 * File:   sudoku_cell.h
 * Author: gustavorv86
 */

#ifndef SUDOKU_CELL_H
#define SUDOKU_CELL_H

namespace sudoku {

	class sudoku_cell {
	private:
		int i;
		int j;
	public:
		sudoku_cell();
		sudoku_cell(const sudoku_cell& orig);
		virtual ~sudoku_cell();
	
		int get_row();
		int get_column();
		
		void set(int i, int j);
		void set_row(int i);
		void set_column(int j);
	};
}

#endif
