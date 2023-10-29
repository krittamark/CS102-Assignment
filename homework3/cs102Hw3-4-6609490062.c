/**
 * File:    cs102Hw3-4-6609490062.c
 *
 * Author:      Krittamet Damthongkam (krittamet.dam@dome.tu.ac.th)
 * Date:        October 29, 2023
 * Course:      PROBLEM SOLVING BASICS AND COMPUTER PROGRAMMING (CS102)
 * Assignment:  3-4
 *
 * Summary of File:
 *
 */

#include <stdio.h>

int main() {
	int metricSize;
	int maxSum = 0;
	int verticalSummation = 0;
	int horizontalSummation = 0;
	int leftDiagonalSummation = 0;
	int rightDiagonalSummation = 0;

	scanf("%d", &metricSize);

	int metric[metricSize][metricSize];
	for (int i = 0; i < metricSize; i++) {
		for (int j = 0; j < metricSize; j++) {
			scanf("%d", &metric[i][j]);
		}
	}

	if ((metricSize % 2) == 1) {
		int centerPosition = metricSize / 2;
		for (int i = 0; i < metricSize; i++) {
			verticalSummation += metric[i][centerPosition];
			horizontalSummation += metric[centerPosition][i];	
			leftDiagonalSummation += metric[i][i];
			rightDiagonalSummation += metric[i][metricSize - i - 1];
		}

	} else {
			int centerPosition = (metricSize / 2) - 1;
			for (int i = 0; i < metricSize; i++) {
				verticalSummation += (metric[i][centerPosition] + metric[i][centerPosition + 1]) / 2;
				horizontalSummation += (metric[centerPosition][i] + metric[centerPosition + 1][i]) / 2;
				leftDiagonalSummation += metric[i][i];
				rightDiagonalSummation += metric[i][metricSize - i - 1];	
			}
	}

	if (verticalSummation > maxSum)
		maxSum = verticalSummation;
	if (horizontalSummation > maxSum)
		maxSum = horizontalSummation;
	if (leftDiagonalSummation > maxSum)
		maxSum = leftDiagonalSummation;
	if (rightDiagonalSummation > maxSum)
		maxSum = rightDiagonalSummation;
		
	printf("%d\n", maxSum);

	return 0;
}