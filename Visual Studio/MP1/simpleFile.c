// simpleFile.c
// resources: cplusplus.com, tutorialspoint.com

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

int main()
{
  FILE* myfile;
  FILE* newfile;
  int ch;

  myfile = fopen("simpleFileInput.txt", "r");
  if (myfile == NULL) 
  {
	printf("Could not open text file\n");
	return 0;
  }
  
  newfile = fopen("simpleFileOutput.txt", "w");
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
  printf("\nOperation complete\n\n");

  fclose(myfile);
  fclose(newfile);
  remove("simpleFileOutput.txt");
  

  return 0;
}
