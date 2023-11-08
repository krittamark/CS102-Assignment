/**
 * File:        cs102Hw2-2-6609490062.c
 * Title:       Pizza Party Calculator
 *
 * Author:      Krittamet Damthongkam (krittamet.dam@dome.tu.ac.th)
 * Date:        September 19, 2023
 * Course:      PROBLEM SOLVING BASICS AND COMPUTER PROGRAMMING (CS102)
 * Assignment:  2-2
 *
 * Summary of File:
 *   This file contains program code for homework 2-2 assignment.
 *   The program will ask user to input budget amount.
 *   Then, the program will calculate and print out the number of students that
 *   can be provided and the amount of budget remains.
 */

#include <stdio.h>

int main(void) {
  int budget;
  printf("\nPlease enter budget amount: ");
  scanf("%d", &budget);

  int pizza = budget / 599;
  int pieceOfPizza = pizza * 8;
  int studentProvided = pieceOfPizza / 2;

  int change = budget % 599;

  printf("\nWe can provide support for %d students.", studentProvided);
  printf("\nThe amount of budget remains %d bahts.", change);

  return 0;
}