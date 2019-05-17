
#include "parse_args.h"

using namespace arguments;

parse_args::parse_args(int argc, char** argv) {
	this->progname = argv[0];

	int option_index = 0;
	static struct option s_options[] = {
		{"file",   required_argument, 0, 'f'},
		{"debug",  no_argument,       0, 'd'},
		{"help",   no_argument,       0, 'h'},
		{0, 0, 0, 0}
	};
	
	this->args["file"] = "";
	this->args["debug"] = "false";
	
	int c = 0;
	while (c != -1) {

		c = getopt_long(argc, argv, OPTIONS.c_str(), s_options, &option_index);
				
		const char * name = nullptr;
		const char * argument = nullptr;
		
		switch(c) {
			case -1:
				break;
				
			case 0:
				name = s_options[option_index].name;
				argument = optarg;
				break;
			
			case 'f':
				name = "file";
				argument = optarg;
				break;
							
			case 'd':
				name = "debug";
				argument = "true";
				break;
				
			case 'h':
				name = "help";
				argument = "true";
				
			default:
				break;
		}
		
		if(name != nullptr) {
			this->args[name] = argument;
		}
	}

	if(this->args["help"] == "true") {
		this->help_and_exit();
	}
	
	if(this->args["file"].empty()) {
		this->help_and_exit();
	}
	
}

parse_args::~parse_args() {
}

void parse_args::help_and_exit() {
	cout << "USAGE: " << this->progname << " [" << OPTIONS << "]" << endl;
	cout << "\t" << "-f, --file <input text sudoku file> " << endl;
	cout << "\t" << "-d, --debug" << endl;
	cout << "\t" << "-h, --help" << endl;
	cout << endl;
	exit(0);
}

string parse_args::get_value(string key) {
	return this->args[key];
}
