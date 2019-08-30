#include "stdio.h"

int main(int argc, char * argv[])
{
	if(argc > 2){
		printf("You can only make one directory once\n");
	}else if(argc = 2){
		if(mkdir(argv[1]) != 0){
			printf("Mkdir succeed\n");
		}
	}else{
		printf("Please input directory name\n");
	}

	return 0;
}