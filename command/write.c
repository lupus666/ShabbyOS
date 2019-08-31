#include "stdio.h"
#include "const.h"

int main(int argc, char * argv[])
{
	int fd = -1;
	int i;
	char buf[512];
	for(int i = 0; i < 512; i++){
		buf[i] = 0;
	}
	if(argc > 2){
		fd = open(argv[1], O_RDWR, 0);
	}
	if(fd == -1){
		printf("Open file failed\n");
	}else{
		/*
		int m = 0;
		for(int i = 0; i < argc - 2; i++){
			while(*argv[i + 2] != "\0"){
				buf[m++] = *argv[i + 2]++;
				if(m > 2048 * 512){
					break;
				}
			}
			if(m > 2048 * 512){
				break;
			}			
		}
		*/
		printf("Start writing\n");
		write(fd, buf, 512);
		printf("Write file succeed\n");
		close(fd);
	}

	return 0;
}