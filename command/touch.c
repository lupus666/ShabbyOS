#include "stdio.h"

int main(int argc, char * argv[])
{
	if(argc > 2){
		printf("You can only create one file once\n");
	}else if(argc == 2){
		int fd = open(argv[1], O_CREAT, 0);
		if(fd != -1){
			printf("Create file succeed\n");
			close(fd);
		}else{
			printf("Create file failed\n");
		}
	}else{
		printf("Please input file name\n");
	}

	return 0;
}