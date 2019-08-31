#include "stdio.h"

int main(int argc, char * argv[])
{
	if(argc > 2){
		printf("You can only remove one file once\n");
	}else if(argc == 2){
		if(unlink(argv[1]) == 0){
			printf("Remove file succeed\n");
		}
		else{
			printf("Remove file failed\n");
		}
	}else{
		printf("Please input file name\n");
	}

	return 0;
}