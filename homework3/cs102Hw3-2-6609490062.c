/**
 * File:    cs102Hw3-2-6609490062.c
 *
 * Author:      Krittamet Damthongkam (krittamet.dam@dome.tu.ac.th)
 * Date:        October 16, 2023
 * Course:      PROBLEM SOLVING BASICS AND COMPUTER PROGRAMMING (CS102)
 * Assignment:  3-2
 *
 * Summary of File:
 *  This file contains program code for homework 3-2 assignment.
 *  The program will ask user to input size of square and the square itself.
 *  Then, the program will check if the square is a magic square or not.
 *  If it is a magic square, the program will print out the magic constant.
 *  If it is not a magic square, the program will print out the maximum sum.
 */

#include <stdio.h>

int main() {
  int squareSize = 0;
  int minSquareSize = 3;
  int maxSquareSize = 20;
  int summation = 0;
  int maxSummation = 0;

  do {
    printf("Enter size of your square: ");
    scanf("%d", &squareSize);
  } while (squareSize < minSquareSize || squareSize > maxSquareSize);
  
  int square[squareSize][squareSize];
  int summationArray[(squareSize * 2) + 2];


  printf("Enter your square: \n");
  for (int row = 0; row < squareSize; row++)
    for (int column = 0; column < squareSize; column++)
      scanf("%d", &square[row][column]);


  for (int row = 0; row < squareSize; row++) {
    int rowSummation = 0;
    for (int column = 0; column < squareSize; column++)
      rowSummation += square[row][column];
    if (rowSummation > maxSummation)
      maxSummation = rowSummation;
  }
    

  for (int column = 0; column < squareSize; column++) {
    int columnSummation = 0;
    for (int row = 0; row < squareSize; row++)
      columnSummation += square[row][column];
    if (columnSummation > maxSummation)
      maxSummation = columnSummation;
  }

  int diagonalSummation = 0;
  for (int i = 0; i < squareSize; i++)
    diagonalSummation += square[i][i];
  if (diagonalSummation > maxSummation) {
    maxSummation = diagonalSummation;
  }
  

  int diagonalSummation2 = 0;
  for (int i = 0; i < squareSize; i++) 
    diagonalSummation2 += square[i][squareSize - i - 1];
  if (diagonalSummation2 > maxSummation) {
    maxSummation = diagonalSummation2;
  }


  if (maxSummation == diagonalSummation && maxSummation == diagonalSummation2) {
    printf("Your square is a magic square!!\n");
    printf("The magic constant is %d", maxSummation);
  } else {
    printf("Your square is NOT a magic square.\n");
    printf("The maximum sum is %d", maxSummation);
  }
  
  return 0;
}
