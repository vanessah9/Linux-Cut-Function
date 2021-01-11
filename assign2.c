#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "assign2funcs.h"
#define MAX 100
/*
name: main
purpose: checks user input errors and calls cut function
argc is number of CLAs
*argv[] contains the CLAs
input: delimeters, field arguments, file name
output:
1. INCORRECT INPUT: redirects to stderr with errorMessage 
2. CORRECT INPUT: prints cut fields and returns 0
*/
int main( int argc, char *argv[] ) {
  char errorMessage[]="%s: specify input_delimeter output_delimeter and 1-%d fields in order.\n";
  // checks if there are at least 4 arguments
  if (argc < 4 || argc > 103) {
    fprintf(stderr, errorMessage, argv[0], MAX);
    return 1;
  } 
  // checks if delimeters are only one char
  else if (strlen(argv[1]) != 1 || strlen(argv[2]) != 1) {
    fprintf(stderr, errorMessage, argv[0], MAX);
    return 1;
  }
  // checks if field arguments are digits
  for (int i=3; i < argc-1; i++ ) {
    for (int j=0; j < strlen(argv[i]); j++) {
      if ( !isdigit(argv[i][j]) ) {
        fprintf(stderr, errorMessage, argv[0], MAX);
        return 1;
      }
    }
  }
  // checks if field numbers are ascending
  for (int i=3; i < argc-1; i++) {
    if (atoi(argv[i]) >= atoi(argv[i+1])) {
      fprintf(stderr, errorMessage, argv[0], MAX);
      return 1;
    }
  }
  
  // fields is array of field numbers
  // count starts at index 0 to add field arguments into fields
  int fields[argc-3];
  int count = 0;
  // add field numbers into array
  for (int i=3; i < argc; i++) {
    fields[count] = atoi(argv[i]);
    count++;
  }
  // filename is each line of input file
  // pos iterates through each character in a line to check for \n
  char filename[1000];
  char *pos;
  
  // gets each line in input file from stdin
  while (fgets(filename, MAX, stdin)) {
    //if newline character at end of line in file, set \n to \0
    if ((pos=strchr(filename, '\n')) != NULL) {
      *pos = '\0';
    }
    cut(filename, fields, argv[1], argv[2]);
  }
  return 0;
}
