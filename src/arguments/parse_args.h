
#ifndef PARSE_ARGS_H
#define PARSE_ARGS_H

#include <cstdlib>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <getopt.h>

using namespace std;

namespace arguments {
	
	static const string OPTIONS = "f:dh";
	
	class parse_args {
	private:
		const char * progname;
		map<string, string> args;
		void help_and_exit();
		
	public:
		parse_args(int argc, char** argv);
		virtual ~parse_args();
		string get_value(string key);
		
	};
}

#endif
