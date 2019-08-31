#include "stdio.h"

int main(int argc, char * argv[])
{
	if(argc > 2){
		printf("You can only input one param once\n");
	}else if(argc == 2){
		if(cddir(argv[1]) == 0){
			printf("cd succeed\n");
		}
		else{
			printf("cd failed\n");
		}
	}else{
		printf("Please input directory name\n");
	}

	return 0;
}