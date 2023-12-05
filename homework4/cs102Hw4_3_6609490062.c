/**
 * File:        cs102Hw4_3_6609490062.c
 * Title:       Students Score Summation
 *
 * Author:      Krittamet Damthongkam (krittamet.dam@dome.tu.ac.th)
 * Date:        November 9, 2023
 * Course:      PROBLEM SOLVING BASICS AND COMPUTER PROGRAMMING (CS102)
 * Assignment:  4-3
 *
 * Summary of File:
 *   The program read the data from the file and print the data to the screen.
 */

#include <stdio.h>

#define MAX_ARRAY_SIZE 100
#define SCORE_COUNT 3

int input_data(char studentId[][11],
               int studentScore[][SCORE_COUNT + 1], FILE *scoreFile);
int print_data(char studentId[][11],
               int studentScore[][SCORE_COUNT + 1], int printCount);

int main(void) {
  FILE *scoreFile = fopen("scores.txt", "r");

  char studentId[MAX_ARRAY_SIZE][11] = {'\0'};
  int studentScore[MAX_ARRAY_SIZE][SCORE_COUNT + 1] = {0};

  int numStudent = input_data(studentId, studentScore, scoreFile);

  print_data(studentId, studentScore, numStudent);
  fclose(scoreFile);
  return 0;
}

int input_data(char studentId[][11],
               int studentScore[][SCORE_COUNT + 1], FILE *scoreFile) {
  int studentCount = 0;

  while (fscanf(scoreFile, "%s", studentId[studentCount]) != EOF) {
    for (int i = 0; i < SCORE_COUNT; i++) {
      fscanf(scoreFile, "%d", &studentScore[studentCount][i]);
      studentScore[studentCount][SCORE_COUNT] += studentScore[studentCount][i];
    }

    studentCount++;
  }

  return studentCount;
}

int print_data(char studentId[][11],
               int studentScore[][SCORE_COUNT + 1], int printCount) {
  for (int i = 0; i < printCount; i++) {
    fprintf("%s ", studentId[i]);
    for (int j = 0; j < SCORE_COUNT + 1; j++) {
      fprintf("%d ", studentScore[i][j]);
    }
    fprintf("\n");
  }
  return 0;
}