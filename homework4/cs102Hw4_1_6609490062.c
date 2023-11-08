/**
 * File:        cs102Hw4_1_6609490062.c
 * Title:       Ascii Table
 *
 * Author:      Krittamet Damthongkam (krittamet.dam@dome.tu.ac.th)
 * Date:        November 7, 2023
 * Course:      PROBLEM SOLVING BASICS AND COMPUTER PROGRAMMING (CS102)
 * Assignment:  4-1
 *
 * Summary of File:
 *   This file contains program code for homework 4-1 assignment.
 *   The program will print out the menu and ask user to input their choice.
 *   Then, the program will print the ascii table according to user's choice.
 */

#include <stdio.h>

void Ascii_AIIZ(void);
void Ascii_aIIz(void);
void Ascii_num(void);

void printMenu(void);
void printSeperator(int length);
void printAsciiFormat(int minAsciiNumber, int maxAsciiNumber, char format[]);

int main(void) {
  printMenu();
  int choice;

  do {
    printf("Enter your choice <1, 2, 3 or 0>: ");
    scanf("%d", &choice);

    if (choice > 3 || choice < 0) {
      printf("Invalid choice!\n");
      continue;
    }

  } while (choice > 3 || choice < 0);

  switch (choice) {
    case 1:
      Ascii_AIIZ();
      break;

    case 2:
      Ascii_aIIz();
      break;

    case 3:
      Ascii_num();
      break;

    default:
      printf("Bye!!\n");
      return 0;
  }
  main();
}

void printMenu(void) {
  printf("############# MENU #############\n");
  printf("1. Ascii table of characters A-Z\n");
  printf("2. Ascii table of characters a-z\n");
  printf("3. Ascii table of code 65-90\n");
  printf("0. Quit Program\n");
}

void Ascii_AIIZ(void) {
  printSeperator(42);
  printf("Ascii Table for A-Z\n");
  printSeperator(42);
  printAsciiFormat(65, 90, "%c - %d\n");
  printSeperator(42);
}

void Ascii_aIIz(void) {
  printSeperator(42);
  printf("Ascii Table for a-z\n");
  printSeperator(42);
  printAsciiFormat(97, 122, "%c - %d\n");
  printSeperator(42);
}

void Ascii_num(void) {
  printSeperator(42);
  printf("Ascii Table for code 65-90\n");
  printSeperator(42);
  printAsciiFormat(65, 90, "%d - %c\n");
  printSeperator(42);
}

void printSeperator(int length) {
  for (int i = 0; i < length; i++) printf("-");
  printf("\n");
}

void printAsciiFormat(int minAsciiNumber, int maxAsciiNumber, char format[]) {
  for (int i = minAsciiNumber; i <= maxAsciiNumber; i++) printf(format, i, i);
}
