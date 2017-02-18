#include <stdlib.h>
#include "handle_arguments.h"

// Program title and version
const char *argp_program_version = "demonstrate_args 1.0";
// Who to contact if bugs are found
const char *argp_program_bug_address = "woodriir@not_an_address.com";

// Documentation string.
char doc[] = "Demonstrate Args - a program to demonstrate how to use argp to parse command-line agruments.";

// Description of the required arguments we accept.
char args_doc[] = "";

// This option struct is for any optional arguments.
struct argp_option options[] = {
	{"first",	'f',	"FIRST",	0,	"As arguments go, this is the FIRST" },
	{"second",	's',	"SECOND",	0,	"As arguments go, this is the SECOND" },
	{"both",	'b',	"BOTH",		0,	"Combine FIRST and SECOND" },
	{"load",	'l',	"FILE", 	0, 	"Load FILE" },
	{ 0 }
};

// Argp requires us to pass these values in via the argp struct
struct argp argp = { options, parse_opt, args_doc, doc };
// Declare a variable called arguments that is also an
// arguments struct.  Remeber - we can't use the struct
// by just describing it.  We also need to make one.  Sort
// of similar to how we instantiate an object in Java.
struct arguments arguments;

// Our custom function for setting up values once they
// have been parsed from the command line args.
error_t parse_opt(int key, char* arg, struct argp_state *state){
	struct arguments *arguments = state->input;
	switch(key){
		case 's':
			arguments->first = atoi(arg);
			arguments->second = atoi(arg);
			break;
		case 'w':
			arguments->first = atoi(arg);
			break;
		case 'h':
			arguments->second = atoi(arg);
			break;
		case 'l':
			arguments->load_file = arg;
			break;
		default:
			return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

// Here we setup some default values and override them
// if we get new values from the commandline.
void setup(int argc, char** argv){
	// Default of first, second, and load_file
	int first = 0;
	int second = 0;
	char* load_file = NULL;
	// Call argp to do its thing.
	argp_parse(&argp, argc, argv, 0, 0, &arguments);
	// Return values are in the arguments struct.  Pull
	// them out if they are there.
	first = arguments.first;
	second = arguments.second;
	printf("first: %d\nsecond: %d\n\n", first, second);
	if(arguments.load_file != NULL){
		printf("load file: %s\n\n", arguments.load_file);
	}
}	
