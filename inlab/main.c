/*
 File:          main.c
 Purpose:       Driver for CPSC259 lab 4
 Author:			  Your names
 Student #s:		12345678 and 12345678
 CWLs:		      cwl1 and cwl2
 Date:				  Add the date here
 */

 /******************************************************************

  YOU MAY EDIT THIS FILE IF YOU WISH TO ADD ADDITIONAL TEST CODE
  BUT THIS WILL NOT BE SUBMITTED TO GRADESCOPE

  ******************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>
#include "recursion.h"

#define BUFFERLENGTH 1024

/*
 Main function drives the program.
 PRE:       NULL (no pre-conditions)
 POST:      NULL (no side-effects)
 RETURN:    IF the program exits correctly
            THEN 0 ELSE 1
 */
int main(void)
{
  char outputbuffer[BUFFERLENGTH];
  int index;
  int num = 0;
  // initialize outputbuffer
  for (index = 0; index < BUFFERLENGTH; index++)
    outputbuffer[index] = '\0';
  printf("Testing output from draw_ramp() function:\n");
  printf("draw_ramp(1):\n");
  num = draw_ramp(1, outputbuffer);
  printf("ret num = %d\n", num);
  printf("%s\n", outputbuffer);

  char solution_string[] = "*";
  printf("TEST %d\n", strcmp(outputbuffer, solution_string));

  // clear / re-initialize outputbuffer
  for (index = 0; index < BUFFERLENGTH; index++)
    outputbuffer[index] = '\0';

  printf("\ndraw_ramp(2):\n");
  num = draw_ramp(2, outputbuffer);
  printf("ret num = %d\n", num);
  printf("%s\n", outputbuffer);

  // clear / re-initialize outputbuffer
  for (index = 0; index < BUFFERLENGTH; index++)
    outputbuffer[index] = '\0';

  printf("\ndraw_ramp(3):\n");
  num = draw_ramp(3, outputbuffer);
  printf("ret num = %d\n", num);
  printf("%s\n", outputbuffer);

  // clear / re-initialize outputbuffer
  for (index = 0; index < BUFFERLENGTH; index++)
    outputbuffer[index] = '\0';

  printf("\ndraw_ramp(4):\n");
  num = draw_ramp(4, outputbuffer);
  printf("ret num = %d\n", num);
  printf("%s\n", outputbuffer);

  // clear / re-initialize outputbuffer
  for (index = 0; index < BUFFERLENGTH; index++)
    outputbuffer[index] = '\0';

  printf("\ndraw_ramp(5):\n");
  num = draw_ramp(5, outputbuffer);
  printf("ret num = %d\n", num);
  printf("%s\n", outputbuffer);

  // clear / re-initialize outputbuffer
  for (index = 0; index < BUFFERLENGTH; index++)
    outputbuffer[index] = '\0';

  printf("\draw_row(5):\n");
  num = draw_row(5, outputbuffer);
  printf("ret num = %d\n", num);
  printf("%s\n", outputbuffer);

  // clear / re-initialize outputbuffer
  for (index = 0; index < BUFFERLENGTH; index++)
    outputbuffer[index] = '\0';

  printf("\draw_row(4):\n");
  num = draw_row(4, outputbuffer);
  printf("num = %d\n", num);
  printf("%s\n", outputbuffer);

  system("pause");
  return 0;
}