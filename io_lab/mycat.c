#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include <fcntl.h>
#include <unistd.h>


#define BUFF_SIZE 16

int main(int argc, char* argv[])
{
	int ifd, ofd;
	char* buff;
	ssize_t nreads, nwrites;


	if(argc < 2) {
		fprintf(stdout, "No arguments\n");
		return 0;
	} else if(argc == 2) {
		// printf("dkdk test bob");
		// output to stdout file  

	} else if(argc == 4 && !strcmp(argv[2], "into")) {
		// output to redirection file 

	} else {
		fprintf(stdout, "Wrong arguments\n");
		return 0;
	}

	// Open input file [ Original File ]
	char *fileName = argv[1];
	int fd = open(fileName , O_RDONLY);
	if ( fd < 0 ){
		perror("open");
		exit(1);
	} 


	// Allocate buffer 
	if(!(buff = (char*) malloc (sizeof(char) * BUFF_SIZE))){
		fprintf(stdout, "Failed to allocate memory\n");
		exit(-1);
	}

	// Copy files 
	int nbytes;
	while ((nbytes = read(fd , buff , sizeof(buff)) ) > 0 ){ 
		write(STDOUT_FILENO , buff , nbytes);
	}

    if (nbytes == -1) {
        perror("read");
        close(fd);
        return 1;
    }
	
	

	// Close files 
	int retval;
	if ((retval = close(fd)) < 0){
		perror("close");
		exit(1);
	}

}
