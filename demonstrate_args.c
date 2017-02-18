#include <stdio.h>
#include "handle_arguments.h"

/**
 * Main program to illustrate usage
 * of argp.  Code separated into main code
 * file and argument handling code.
 */

int main(int argc, char** argv){
	// Pass the commandline arguments
	// on to our handling function.
	setup(argc, argv);
	// Now, do whatever we came here to do.
	// ...
	//
	// ...
	//
	return 0;
} 
