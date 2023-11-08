/**
 * File:        cs102Hw2-1-6609490062.c
 * Title:       Triangle Type Checker
 *
 * Author:      Krittamet Damthongkam (krittamet.dam@dome.tu.ac.th)
 * Date:        September 14, 2023
 * Course:      PROBLEM SOLVING BASICS AND COMPUTER PROGRAMMING (CS102)
 * Assignment:  2-1
 *
 * Summary of File:
 *   This file contains program code for homework 2-1 assignment.
 *   The program will ask user to input length of each side of triangle.
 *   Then, the program will check if the triangle is equilateral, isosceles,
 *   scalene or not a triangle.
 */

#include <stdio.h>

int main(void) {
  int triagSide1, triagSide2, triagSide3;
  printf("\nPlease enter length of each side of your triangle: ");
  scanf("%d %d %d", &triagSide1, &triagSide2, &triagSide3);

  if ((triagSide1 < (triagSide2 + triagSide3)) &&
      (triagSide2 < (triagSide1 + triagSide3)) &&
      (triagSide3 < (triagSide1 + triagSide2))) {
    if (triagSide1 == triagSide2 && triagSide2 == triagSide3) {
      printf("This is an equilateral triangle.");
    } else if (triagSide1 != triagSide2 && triagSide1 != triagSide3 &&
               triagSide2 != triagSide3) {
      printf("This is a scalene triangle.\n");
    } else {
      printf("This is an isosceles triangle.\n");
    }
  } else {
    printf("This is NOT a triangle.\n");
  }

  return 0;
}