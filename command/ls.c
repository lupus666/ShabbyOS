#include "stdio.h"
#include "const.h"

int main(int argc, char * argv[])
{
	struct dir_entry * pde;
	if(argc > 1){
		printf("You dont need to input param\n");
	}
	int nr_files = lsdir(pde);
	printf("No		file name		file type\n");
	for(int i = 0; i < nr_files; i++, pde++){
		printf("%d 		", i + 1);
		printf("%s 		", pde->name);
		if(pde->i_mode == I_DIRECTORY){
			printf("Directory\n");
		}else{
			printf("File\n");
		}
	}

	return 0;
}