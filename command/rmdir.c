#include "stdio.h"

int main(int argc, char * argv[])
{
	if(argc > 2){
		printf("You can only remove one directory once\n");
	}else if(argc == 2){
		if(rmdir(argv[1]) == 0){
			printf("Rmdir succeed\n");
		}
		else{
			printf("Rmdir failed\n");
		}
	}else{
		printf("Please input directory name\n");
	}

	return 0;
}