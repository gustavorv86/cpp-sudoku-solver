
#include <iostream>
#include <parse_args.h>
#include <sudoku_table.h>
#include <sudoku_solver.h>

#include "arguments/parse_args.h"

using namespace arguments;
using namespace std;
using namespace sudoku;

int main(int argc, char** argv) {
	
	parse_args args(argc, argv);
	
	string filename = args.get_value("file");	
	bool debug = args.get_value("debug") == "true";
	
	sudoku_table st;
	if(! st.read_file(filename)) {
		return 1;
	}
	
	cout << "\n\n---------- SUDOKU INPUT ----------\n\n";
	cout << st.to_str() << endl;
	
	cout << "\n\n---------- SUDOKU SOLVER ----------\n\n";
	sudoku_solver ss(st);
	ss.solver(debug);
	
	cout << endl << "Number of iterations: " << ss.get_iterations() << endl;
	
	cout << "\n\n---------- SUDOKU SOLUTIONS ----------\n\n";
	
	int num_solutions = ss.get_solutions().size();
	
	if(num_solutions == 0) {
		cerr << "Sudoku has not solution" << endl << endl;
		return 0;
	} else {
		cout << "Number of solutions: " << num_solutions;
		cout << "\n\n----------------------------------\n\n";
	}
	
	for(sudoku_table sol : ss.get_solutions()) {
		cout << sol.to_str() << endl;
		cout << "\n\n----------------------------------\n\n";
	}
	
	cout << "Done" << endl << endl;;
	
	return 0;
}
