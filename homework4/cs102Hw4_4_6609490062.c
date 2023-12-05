/**
 * File:        cs102Hw4_4_6609490062.c
 * Title:       Students Score Summation and Grade
 *
 * Author:      Krittamet Damthongkam (krittamet.dam@dome.tu.ac.th)
 * Date:        December 5, 2023
 * Course:      PROBLEM SOLVING BASICS AND COMPUTER PROGRAMMING (CS102)
 * Assignment:  4-4
 *
 * Summary of File:
 *   The program read the data from the file and print the data to the file.
 *   The program also compute the average, minimum, and maximum score of each
 */

#include <stdio.h>

#define MAX_ARRAY_SIZE 100
#define SCORE_COUNT 3

int input_data(char studentId[][11], int studentScore[][SCORE_COUNT + 1],
               FILE *scoreFile);
int print_data(char studentId[][11], int studentScore[][SCORE_COUNT + 1],
               int printCount, FILE *outFile);

char compute_grade(int studentScore[][SCORE_COUNT + 1], int studentIndex);
int average_score(int studentScore[][SCORE_COUNT + 1], int studentCount,
                  int column);
int min_score(int studentScore[][SCORE_COUNT + 1], int studentCount,
              int column);
int max_score(int studentScore[][SCORE_COUNT + 1], int studentCount,
              int column);

int main(void) {
  FILE *scoreFile = fopen("scores.txt", "r");
  FILE *outFile = fopen("Student_Grade.out", "w");

  char studentId[MAX_ARRAY_SIZE][11] = {'\0'};
  int studentScore[MAX_ARRAY_SIZE][SCORE_COUNT + 1] = {0};

  int numStudent = input_data(studentId, studentScore, scoreFile);

  print_data(studentId, studentScore, numStudent, outFile);

  fprintf(outFile, "Average:   %3d %3d %3d %3d\n",
          average_score(studentScore, numStudent, 0),
          average_score(studentScore, numStudent, 1),
          average_score(studentScore, numStudent, 2),
          average_score(studentScore, numStudent, 3));
  fprintf(outFile, "Minimum:   %3d %3d %3d %3d\n",
          min_score(studentScore, numStudent, 0),
          min_score(studentScore, numStudent, 1),
          min_score(studentScore, numStudent, 2),
          min_score(studentScore, numStudent, 3));
  fprintf(outFile, "Maximum:   %3d %3d %3d %3d\n",
          max_score(studentScore, numStudent, 0),
          max_score(studentScore, numStudent, 1),
          max_score(studentScore, numStudent, 2),
          max_score(studentScore, numStudent, 3));
  
  fclose(scoreFile);
  fclose(outFile);
  return 0;
}

int input_data(char studentId[][11], int studentScore[][SCORE_COUNT + 1],
               FILE *scoreFile) {
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

int print_data(char studentId[][11], int studentScore[][SCORE_COUNT + 1],
               int printCount, FILE *outFile) {
  for (int i = 0; i < printCount; i++) {
    fprintf(outFile, "%s ", studentId[i]);
    for (int j = 0; j < SCORE_COUNT + 1; j++) {
      fprintf(outFile, "%3d ", studentScore[i][j]);
    }
    fprintf(outFile, "%c", compute_grade(studentScore, i));
    fprintf(outFile, "\n");
  }
  return 0;
}

char compute_grade(int studentScore[][SCORE_COUNT + 1], int studentIndex) {
  int score = studentScore[studentIndex][SCORE_COUNT];
  if (score >= 80) {
    return 'A';
  } else if (score >= 75) {
    return 'B';
  } else if (score >= 65) {
    return 'C';
  } else if (score >= 55) {
    return 'D';
  } else {
    return 'F';
  }
}

int average_score(int studentScore[][SCORE_COUNT + 1], int studentCount,
                  int column) {
  int sum = 0;
  for (int i = 0; i < studentCount; i++) {
    sum += studentScore[i][column];
  }
  return sum / studentCount;
}

int min_score(int studentScore[][SCORE_COUNT + 1], int studentCount,
              int column) {
  int min = studentScore[0][column];
  for (int i = 1; i < studentCount; i++) {
    if (studentScore[i][column] < min) {
      min = studentScore[i][column];
    }
  }
  return min;
}

int max_score(int studentScore[][SCORE_COUNT + 1], int studentCount,
              int column) {
  int max = studentScore[0][column];
  for (int i = 1; i < studentCount; i++) {
    if (studentScore[i][column] > max) {
      max = studentScore[i][column];
    }
  }
  return max;
}