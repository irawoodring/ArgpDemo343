#ifndef H_HANDLE_ARGUMENTS
#define H_HANDLE_ARGUMENTS

#include <argp.h>

const char *argp_program_version = "demonstrate_args 1.0";
const char *argp_program_bug_address = "woodriir@not_an_address.com";

static char doc[] = "Demonstrate Args - a program to demonstrate how to use argp to parse command-line agruments.";

static char args_doc[] = "";

static struct argp_option options[] = {
	{"square",	"s",	0,	0,	"Create a square board of n x n size" },
	{"load",	"l",	"FILE", 0, "Load FILE" },
	{ 0 }
};

struct arguments {
	int width,
	int height
	char *load_file;
};

static error_t parse_opt(int key, char* arg, struct argp_state *state);

static struct argp argp = { options, parse_opt, args_doc, doc };


#endif
