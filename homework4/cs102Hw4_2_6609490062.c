/**
 * File:        cs102Hw4_2_6609490062.c
 * Title:       Magic Square with File I/O
 *
 * Author:      Krittamet Damthongkam (krittamet.dam@dome.tu.ac.th)
 * Date:        November 9, 2023
 * Course:      PROBLEM SOLVING BASICS AND COMPUTER PROGRAMMING (CS102)
 * Assignment:  4-2
 *
 * Summary of File:
 *   This file contains solution code to Problem 4-2.
 *   The program reads a square from the user and determines if it is a magic
 *   square. If it is, the program writes the square to a file.
 */

#include <stdio.h>

#define MIN_SQUARE_SIZE 3
#define MAX_SQUARE_SIZE 20

void readSquare(int squareSize, int square[][squareSize]);
int findMaxSum(int squareSize, int square[][squareSize]);
int isMagicSquare(int squareSize, int square[][squareSize], int magicConstant);
void writeMyMagicFile(int squareSize, int square[][squareSize],
                      int maxSummation);

int main(void) {
  int squareSize;

  do {
    printf("Enter size of your square: ");
    scanf("%d", &squareSize);
  } while (squareSize < MIN_SQUARE_SIZE || squareSize > MAX_SQUARE_SIZE);

  int square[squareSize][squareSize];
  readSquare(squareSize, square);

  int maxSummation = findMaxSum(squareSize, square);

  if (isMagicSquare(squareSize, square, maxSummation)) {
    printf("Your square is a magic square!!\n");
    printf("The magic constant is %d.", maxSummation);
    writeMyMagicFile(squareSize, square, maxSummation);
  } else {
    printf("Your square is NOT a magic square.\n");
    printf("The maximum sum is %d.", maxSummation);
  }
}

/****************************
 * Function Implementations *
 ****************************/
void readSquare(int squareSize, int square[][squareSize]) {
  printf("Enter your square: \n");
  for (int row = 0; row < squareSize; row++) {
    for (int column = 0; column < squareSize; column++)
      scanf("%d", &square[row][column]);
  }
}

int findMaxSum(int squareSize, int square[][squareSize]) {
  int summation = 0;
  int leftDiagonalSummation = 0;
  int rightDiagonalSummation = 0;
  int columnSum = 0;
  int rowSum = 0;

  for (int i = 0; i < squareSize; i++) {
    rowSum = 0, columnSum = 0;
    for (int j = 0; j < squareSize; j++) {
      rowSum += square[i][j];
      columnSum += square[j][i];
    }
    if (rowSum > summation) summation = rowSum;
    if (columnSum > summation) summation = columnSum;

    leftDiagonalSummation += square[i][i];
    rightDiagonalSummation += square[i][squareSize - i - 1];
  }

  if (leftDiagonalSummation > summation) summation = leftDiagonalSummation;
  if (rightDiagonalSummation > summation) summation = rightDiagonalSummation;

  return summation;
}

int isMagicSquare(int squareSize, int square[][squareSize], int magicConstant) {
  int columnSum, rowSum;
  int leftDiagonalSum = 0;
  int rightDiagonalSum = 0;

  for (int i = 0; i < squareSize; i++) {
    // Reset row and column summation every loop cycle
    rowSum = 0, columnSum = 0;

    for (int j = 0; j < squareSize; j++) {
      rowSum += square[i][j];
      columnSum += square[j][i];
    }
    if (rowSum != magicConstant || columnSum != magicConstant) return 0;

    leftDiagonalSum += square[i][i];
    rightDiagonalSum += square[i][squareSize - i - 1];
  }
  if (leftDiagonalSum != magicConstant || rightDiagonalSum != magicConstant)
    return 0;
  return 1;
}

void writeMyMagicFile(int squareSize, int square[][squareSize],
                      int maxSummation) {
  FILE *magicFile = fopen("myMagic.txt", "w");

  fprintf(magicFile, "This is a %dx%d magic square.\n", squareSize, squareSize);
  fprintf(magicFile, "The magic constant is %d.\n", maxSummation);

  for (int i = 0; i < squareSize; i++) {
    for (int j = 0; j < squareSize; j++) {
      fprintf(magicFile, "%d ", square[i][j]);
    }
    fprintf(magicFile, "\n");
  }
}