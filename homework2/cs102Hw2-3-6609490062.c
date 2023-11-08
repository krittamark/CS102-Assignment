/**
 * File:        cs102Hw2-3-6609490062.c
 * Title:       Summation of Multiples of 6 and 9
 *
 * Author:      Krittamet Damthongkam (krittamet.dam@dome.tu.ac.th)
 * Date:        September 19, 2023
 * Course:      PROBLEM SOLVING BASICS AND COMPUTER PROGRAMMING (CS102)
 * Assignment:  2-3
 *
 * Summary of File:
 *   This file contains program code for homework 2-3 assignment.
 *   The program will ask user to input two numbers.
 *   Then, the program will calculate and print out the summation of multiples
 *   of 6 and 9 between those two numbers.
 */

#include <stdio.h>

int main() {
  int Num1, Num2, summation = 0;

  printf("Please enter Num1: ");
  scanf("%d", &Num1);

  printf("Please enter Num2: ");
  scanf("%d", &Num2);

  for (int i = Num1; i <= Num2; i++) {
    if (((i % 6) == 0) && ((i % 9) == 0)) {
      summation = summation + i;
      printf("%d ", i);
    }
  }

  printf("\nTotal is %d", summation);

  return 0;
}