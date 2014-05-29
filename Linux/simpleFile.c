
// simpleFile.c
// resources: cplusplus.com, tutorialspoint.com

// #ifdef _MSC_VER
// #define _CRT_SECURE_NO_WARNINGS
// #endif

#include <stdio.h>

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    printf("Provide input and output files as parameters\n");
    return 0;
  }

  // Declare new files and an int to read characters
  FILE* myfile;
  FILE* newfile;
  int ch;

  // open input file for reading
  myfile = fopen(argv[1], "r");
  if (myfile == NULL) 
  {
	printf("Could not open text file\n");
	return 0;
  }
  
  // create new output file for writing
  newfile = fopen(argv[2], "w");
  if (newfile == NULL)
  {
	printf("Could not create new text file\n");
	return 0;
  }

  while (ch = fgetc(myfile))
  { // print each character from input file to screen and to the output file
	if (feof(myfile)) break;
	
    putchar(ch);
    fputc(ch, newfile);
  }

  // close both files and delete the output file
  fclose(myfile);
  fclose(newfile);
  remove(argv[2]);
  

  return 0;
}
