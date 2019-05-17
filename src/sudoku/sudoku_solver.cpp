
/* 
 * File:   sudoku_solver.cpp
 * Author: gustavorv86
 * 
 * Created on 11 de octubre de 2018, 8:41
 */

#include "sudoku_solver.h"

using namespace sudoku;

sudoku_solver::sudoku_solver(sudoku_table table) {
	this->count_iterations = 0;
	this->table = table;
}

sudoku_solver::~sudoku_solver() {
}

void sudoku_solver::solver(bool debug=false) {
	if(! this->table.is_valid()) {
		return;
	}
	
	this->sudoku_temporal_list.push_front(this->table);
	
	this->count_iterations = 0;
	while(! this->sudoku_temporal_list.empty()) {
		// pop the first sudoku table
		sudoku_table sudoku_first = this->sudoku_temporal_list.front();
		this->sudoku_temporal_list.pop_front();
		
		if(sudoku_first.is_full()) {
			// if the sudoku table is full, insert into the solution list
			this->sudoku_solution_list.push_back(sudoku_first);
			
		} else {
			
			// get the best option
			sudoku_option best_option = sudoku_first.get_best_option();
			int i = best_option.get_row();
			int j = best_option.get_column();
			
			if(debug) {
				cout << "Number of sudokus into the list: " << this->sudoku_temporal_list.size() << endl;
				cout << "Number of founded solutions: " << this->sudoku_solution_list.size() << endl;
				cout << "Sudoku: " << endl << sudoku_first.to_str() << endl;
			}
			
			if(i != -1 && j != -1 && !best_option.get_values().empty()) {

				if(debug) {
					cout << "Best option: [" << i << ", " << j << "] = ";
					for(int val : best_option.get_values()) {
						cout << val << " ";
					}
					cout << endl;
				}
				
				// create the new childs and inserts into the temporal list
				for(int value : best_option.get_values()) {
					// create the new child sudoku table
					sudoku_table sudoku_new_child(sudoku_first);
					sudoku_new_child.set_value(i, j, value);

					// Insert the new child into the temporal list
					this->sudoku_temporal_list.push_front(sudoku_new_child);
				}
			} else {
				if(debug) {
					cout << "Sudoku has not solution" << endl;
				}	
			}
			
			if(debug) {
				cout << "----------------------------------" << endl;
			}
			
			this->count_iterations++;
		}
	}
}

list<sudoku_table> sudoku_solver::get_solutions() {
	return this->sudoku_solution_list;
}

int sudoku_solver::get_iterations() {
	return this->count_iterations;
}
