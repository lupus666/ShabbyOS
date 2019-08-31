#include "stdio.h"
#include "const.h"

int main(int argc, char * argv[])
{
	int fd = -1;
	void * buf;
	if(argc > 2){
		printf("You can only read one file once\n");
	}else if(argc == 2){
		fd = open(argv[1], O_RDWR, 0);
	}
	if(fd == -1){
		printf("Open file failed\n");
	}else{
		read(fd, buf, 512);
		printf("%s\n", buf);
	}
	close(fd);

	return 0;
}