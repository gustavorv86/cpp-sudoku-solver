
#include "sudoku_table.h"

using namespace sudoku;

sudoku_table::sudoku_table() {
	for(int i=0; i<MAX_SUDOKU; i++) {
		for(int j=0; j<MAX_SUDOKU; j++) {
			this->table[i][j] = CELL_EMPTY;
		}
	}
}

sudoku_table::sudoku_table(const sudoku_table& other) {
	for(int i=0; i<MAX_SUDOKU; i++) {
		for(int j=0; j<MAX_SUDOKU; j++) {
			this->table[i][j] = other.table[i][j];
		}
	}
}

sudoku_table::~sudoku_table() {
}

int sudoku_table::convert_value(char cvalue) {
	if(cvalue == '.') {
		return CELL_EMPTY;
	}
	int ivalue = cvalue - '0';
	if(0 <= ivalue && ivalue <= 9) {
		return ivalue;
	}
	return -1;
}

bool sudoku_table::is_in_row(int row, int value) {
	for(int j=0; j<MAX_SUDOKU; j++) {
		if(this->table[row][j] == value) {
			return true;
		}
	}
	return false;
}

bool sudoku_table::is_in_column(int col, int value) {
	for(int i=0; i<MAX_SUDOKU; i++) {
		if(this->table[i][col] == value) {
			return true;
		}
	}
	return false;
}

bool sudoku_table::is_in_grid(int row, int col, int value) {
	int i_min, i_max, j_min, j_max;
	if(0 <= row && row <= 2) {
		i_min = 0;
		i_max = 2;
	} else if(3 <= row && row <= 5) {
		i_min = 3;
		i_max = 5;
	} else {
		i_min = 6;
		i_max = 8;
	}
	if(0 <= col && col <= 2) {
		j_min = 0;
		j_max = 2;
	} else if(3 <= col && col <= 5) {
		j_min = 3;
		j_max = 5;
	} else {
		j_min = 6;
		j_max = 8;
	}
	for(int i=i_min; i<=i_max; i++) {
		for(int j=j_min; j<=j_max; j++) {
			if(this->table[i][j] == value) {
				return true;
			}
		}
	}
	return false;
}

bool sudoku_table::is_valid_value(int row, int col, int value) {
	return 
		! this->is_in_row(row, value) &&
		! this->is_in_column(col, value) &&
		! this->is_in_grid(row, col, value);
}

list<int> sudoku_table::get_valid_values(int row, int col) {
	list<int> values;
	
	for(int value=1; value<=9; value++) {
		if(this->is_valid_value(row, col, value)) {
			values.push_back(value);
		}
	}
	return values;
}

bool sudoku_table::list_contains(list<int> values, int value) {
	return find(values.begin(), values.end(), value) != values.end();
}

bool sudoku_table::read_file(const string filename) {
	
	ifstream file(filename);
	
	if(! file.good()) {
		cerr << "Cannot open file: " << filename << endl;
		return false;
	}
	
	char ctmp;
	int itmp;
		
	const int max_array = MAX_SUDOKU * MAX_SUDOKU;
	array<int, max_array> values = {}; // Zero initialization
	int count = 0;
	while(!file.eof() && count < max_array) {
		file.get(ctmp);
		itmp = convert_value(ctmp);
		if(itmp != -1) {
			values[count++] = itmp;
		}
	}
	file.close();
	
	count = 0;
	for(int i=0; i<MAX_SUDOKU; i++) {
		for(int j=0; j<MAX_SUDOKU; j++) {
			this->table[i][j] = values[count++];
		}
	}
	
	return true;
}

void sudoku_table::write_file(const string filename) {
	ofstream file(filename);
	
	file << this->to_str();
	file.close();
}

bool sudoku_table::is_full() {
	for(int i=0; i<MAX_SUDOKU; i++) {
		for(int j=0; j<MAX_SUDOKU; j++) {
			if(this->table[i][j] == CELL_EMPTY) {
				return false;
			}
		}
	}
	return true;
}

bool sudoku_table::is_valid_grid(int i_min, int i_max, int j_min, int j_max) {
	list<int> values;
	
	for(int i=i_min; i<=i_max; i++) {
		for(int j=j_min; j<=j_max; j++) {
			if(this->table[i][j] != CELL_EMPTY) {
				if(list_contains(values, this->table[i][j])) {
					cerr << "Invalid sudoku grid: [" << i << ", " << j <<" ] = " << this->table[i][j];
					return false;
				} else {
					values.push_back(this->table[i][j]);
				}
			}
		}
	}
	
	return true;
}

bool sudoku_table::is_valid() {
	list<int> values;
		
	// Check rows
	for(int i=0; i<MAX_SUDOKU; i++) {
		values.clear();
		for(int j=0; j<MAX_SUDOKU; j++) {
			if(this->table[i][j] != CELL_EMPTY) {
				if(list_contains(values, this->table[i][j])) {
					cerr << "Invalid sudoku row: [" << i << ", " << j <<" ] = " << this->table[i][j];
					return false;
				} else {
					values.push_back(this->table[i][j]);
				}
			}
		}
	}
	
	// Check columns
	for(int j=0; j<MAX_SUDOKU; j++) {
		values.clear();
		for(int i=0; i<MAX_SUDOKU; i++) {
			if(this->table[i][j] != CELL_EMPTY) {
				if(list_contains(values, this->table[i][j])) {
					cerr << "Invalid sudoku column: [" << i << ", " << j <<" ] = " << this->table[i][j];
					return false;
				} else {
					values.push_back(this->table[i][j]);
				}
			}
		}
	}
	
	// Check grids	
	return
		is_valid_grid(0, 2, 0, 2) ||
		is_valid_grid(0, 2, 3, 5) ||
		is_valid_grid(0, 2, 6, 8) ||
		is_valid_grid(3, 5, 0, 2) ||
		is_valid_grid(3, 5, 3, 4) ||
		is_valid_grid(3, 5, 6, 8) ||
		is_valid_grid(6, 8, 0, 2) ||
		is_valid_grid(6, 8, 3, 5) ||
		is_valid_grid(6, 8, 6, 8);
	
}

sudoku_option sudoku_table::get_best_option() {
	sudoku_option best_option;

	best_option.set_row(-1);
	best_option.set_column(-1);
	// initialize to the worst option
	for(int i=1; i<=MAX_SUDOKU; i++) {
		best_option.set_value(i);
	}
	
	for(int i=0; i<MAX_SUDOKU; i++) {
		for(int j=0; j<MAX_SUDOKU; j++) {
			if(this->table[i][j] == CELL_EMPTY) {
				list<int> valid_values = this->get_valid_values(i, j);
				if(valid_values.size() < best_option.get_values().size()) {
					best_option.set_row(i);
					best_option.set_column(j);
					best_option.set_values(valid_values);
				}
				
				if(valid_values.empty()) {
					// this sudoku has no solution
					return best_option;
				}
			}
		}
	}
	
	return best_option;
}

void sudoku_table::set_value(int i, int j, int value) {
	this->table[i][j] = value;
}

string sudoku_table::to_str() {
	ostringstream oss;
	
	for(int i=0; i<MAX_SUDOKU; i++) {
		for(int j=0; j<MAX_SUDOKU; j++) {
			oss << this->table[i][j] << " ";
			if(j == 2 || j == 5) {
				oss << "| ";
			}
		}
		oss << endl;
		if(i == 2 || i == 5) {
			oss << "---------------------" << endl;
		}
	}
	return oss.str();
}
