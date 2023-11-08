/**
 * File:        cs102-6609490062-ATM.c
 * Title:       ATM withdrawl
 *
 * Author:      Krittamet Damthongkam (krittamet.dam@dome.tu.ac.th)
 * Date:        September 8, 2023
 * Course:      PROBLEM SOLVING BASICS AND COMPUTER PROGRAMMING (CS102)
 * Assignment:  1-3
 *
 * Summary of File:
 *   This file contains program code for homework 1-3 assignment.
 *   The program will ask user to input withdrawl amount.
 *   Then, the program will calculate and print out the number of each note.
 */

#include <stdio.h>

int main() {
  int money, note1000, note500, note100;

  printf("Please enter your withdrawl amount: ");
  scanf("%d", &money);

  note1000 = money / 1000;
  note500 = (money % 1000) / 500;
  note100 = (money % 500) / 100;

  printf("You will get :-\n");
  printf("#1000-Baht notes: %d\n", note1000);
  printf("#500-Baht notes: %d\n", note500);
  printf("#100-Baht notes: %d\n", note100);

  return 0;
}