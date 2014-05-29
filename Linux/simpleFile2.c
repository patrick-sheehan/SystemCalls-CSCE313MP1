// simpleFile2.c
// resources: cplusplus.com, tutorialspoint.com, stackoverflow.com


#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

static int MAX_BYTES = 2500000;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		printf("Provide input and output files as parameters\n");
		return 0;
	}

	// allocate memory for buffer to store text
	char* buf = malloc(MAX_BYTES); // ~1mb

	// open the file for reading, save file descriptor as inputFD
  int inputFD = open(argv[1], O_RDONLY);
	  // int inputFD = open("simpleFileInput.txt", O_RDONLY);
	  // printf("File Descriptor (fd) = %d\n", inputFD);
  
  // create a file (or clear existing one) for writing(by owner), readable by all
  int outputFD = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0666);

  // read the contents of the file into the buffer
  ssize_t bytesRead = read(inputFD, buf, MAX_BYTES);
  	// printf("Number of bytes read = %zd\n", bytesRead);

  // write contents to standard out
  int bytesToStdOut = write(1, buf, bytesRead);

  // write contents to file
  int bytesToFile = write(outputFD, buf, bytesRead);

  // close both files
  close(inputFD);
	close(outputFD);

	// delete output file
  unlink(argv[2]);

  // free the buffer's allocated memory
  free(buf);

  return 0;
}
