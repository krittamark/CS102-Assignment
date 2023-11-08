/**
 * File:        cs102Hw3-1-6609490062.c
 * Title:       Table of "O", "X"
 *
 * Author:      Krittamet Damthongkam (krittamet.dam@dome.tu.ac.th)
 * Date:        October 13, 2023
 * Course:      PROBLEM SOLVING BASICS AND COMPUTER PROGRAMMING (CS102)
 * Assignment:  3-1
 *
 * Summary of File:
 *  This file contains code which creates table of "O", "X"
 *  which column length and row length depend on user input
 */

#include <stdio.h>

int main() {
  int col, row = 0;
  printf("Enter size of your rectangle: ");
  scanf("%d %d", &row, &col);

  // Row loop
  for (int i = 0; i < row; i++) {
    // Column loop
    for (int j = 0; j < col; j++)

      // Which character should be print every row must start
      // with difference first character of previous row
      if ((i + j) % 2 == 0)
        printf("O");
      else
        printf("X");

    // Create new line
    printf("\n");
  }
  return 0;
}