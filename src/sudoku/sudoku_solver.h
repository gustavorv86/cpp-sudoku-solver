
/* 
 * File:   sudoku_solver.h
 * Author: gustavorv86
 *
 * Created on 11 de octubre de 2018, 8:40
 */

#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include <list>
#include <sstream>
#include <sudoku_option.h>
#include <sudoku_table.h>

using namespace std;

namespace sudoku {

	class sudoku_solver {
	private:
		int count_iterations;
		sudoku_table table;
		list<sudoku_table> sudoku_temporal_list;
		list<sudoku_table> sudoku_solution_list;
		
	public:
		sudoku_solver(sudoku_table table);
		virtual ~sudoku_solver();
	
		void solver(bool debug);
		int get_iterations();
		list<sudoku_table> get_solutions();
	};

}

#endif
