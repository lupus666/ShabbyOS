#include "stdio.h"

int main(int argc, char * argv[])
{
	if(argc > 2){
		printf("You can only create one file once\n");
	}else if(argc = 2){
		if(open(argv[1], O_CREAT) != 0){
			printf("Create file succeed\n");
		}
	}else{
		printf("Please input file name\n");
	}

	return 0;
}