#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assign2funcs.h"
#include <stdbool.h>
/*
name: cut
purpose: cuts fields from each line of a fiel and writes result to stdout
line[] is each of line of input file
fields[] is array of inputted field numbers
d1 is input delimeter
d2 is output delimeter
*/
const char* cut(char line[], int fields[], char *d1, char *d2) {
  /*
  elem is each field seperated by input delimiter d1
  i iterates only if the inputted field is found
  iter is used to print the inputted field number
  first checks if the first field is found
  */
  char *elem;
  int i = 0; 
  int iter = 0;
  bool first = true;
  
  while ( (elem = strsep(&line, d1)) != NULL) {
    //prints elem of first inputted field number
    if (first) {
      if (iter == fields[i]-1) {
        printf("%s", elem);
        i++;
        first = false;
      }
    }
    //prints output delimiter and all other elems of inputted field numbers
    else {
      if (iter == fields[i]-1) {
        printf("%s%s", d2, elem);
        i++;
      }
    }
    iter++;  
  }
  printf("\n");
}
