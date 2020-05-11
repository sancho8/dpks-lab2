#include <stdlib.h>
#include <stdio.h>
#include <string>
#include "getopt.h"
using namespace std;

int main(int argc, char* argv[]) {

	const int num = 5;
	const char* args = ":hsd:v:S::";
	const struct option args_long[] = {
		{"help", no_argument, 0, 'h'},  // -h or --help
		{"show", no_argument, 0, 's'}, // -s or --show
		{"disk", required_argument, 0, 'd'}, // -d or --disk
		{"version", required_argument, 0, 'v'}, // -v or --version
		{"Size", optional_argument, 0, 'S'}, // -S or --Size
		{ 0, 0, 0, 0 }
	};

	int counter;
	int index;
	//Check repeats
	bool isPresenth = false;
	bool isPresents = false;
	bool isPresentd = false;
	bool isPresentv = false;
	bool isPresent_S = false;

	while ((counter = getopt_long(argc, argv, args, args_long, &index)) != -1)
	{
		switch (counter) {
		    
		    case ':': {
			printf("Missing argument %c\n", optopt);
			break;
		    }
		    
		    case '?': {
			printf("Option not known %c\n", optopt);
			break;
		    }

            //no arg
			case 'h': {
			    if (isPresenth == false) {
				    printf("You have called help.\n");
				    isPresenth = true;
			    }
			    break;
		    };
            
            //no arg
		    case 's': {
			    if (isPresents == false) {
				    printf("This is a show command.\n");
				    isPresents = true;
			    }
			    break;
		    };
		    
		    //required arg - any
		    case 'd': {
			    if (isPresentd == false) {
					    printf("Disk = %s\n", optarg);
					    isPresentd = true;
				    }
			    break;
		    };
            
            //required arg - only num
		    case 'v': {
			    if (isPresentv == false) {
				    if ((optarg[0] < '0') || (optarg[0] > '9')) {
					    printf("Missing numeric argument (version)\n");
					    break;
				    }
				    else {
					    printf("Version = %s\n", optarg);
					    isPresentv = true;
				    }
			    }
			    break;
		    };
		
		    //optional arg - any
		    case 'S': {
			    if (isPresent_S == false) {
				    if (optarg == NULL) {
					    printf("We see the size.\n");
					    isPresent_S = true;
				    }
				    else {
					    printf("We see the size = %s\n", optarg);
					    isPresent_S = true;
				    }
			    }
			break;
		    };
		};
	};
	
	return 0;
	
};
