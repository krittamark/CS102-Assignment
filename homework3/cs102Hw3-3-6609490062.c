/**
 * File:    cs102Hw3-3-6609490062.c
 *
 * Author:      Krittamet Damthongkam (krittamet.dam@dome.tu.ac.th)
 * Date:        October 29, 2023
 * Course:      PROBLEM SOLVING BASICS AND COMPUTER PROGRAMMING (CS102)
 * Assignment:  3-3
 *
 * Summary of File:
 *  A program to tally the blooming wild orchid species each month
 *  and determine the month with the most blooming species,
 *  showing the count for that month.
 */

#include <stdio.h>
#include <string.h>

int main() {
    char input[255];
    scanf("%s", input);

    int orchidCount[13][26] = {0};
    for (int i = 0; i < strlen(input); i += 2) {
        int month = input[i] - '0';
        if (input[i] >= 'A' && input[i] <= 'F') {
            month = 10 + (input[i] - 65);
        }

        int orchidSpecies = input[i + 1] - 65;
        orchidCount[month][orchidSpecies]++;
    }

    int maxOrchidCount = 0;
    for (int i = 1; i <= 12; i++) {
        int monthOrchidCount = 0;
        for (int j = 0; j < 26; j++) {
            if (orchidCount[i][j] > 0) {
                monthOrchidCount++;
            }
        }
        printf("%d\n", monthOrchidCount);

        if (monthOrchidCount > maxOrchidCount) {
            maxOrchidCount = monthOrchidCount;
        }
    }
    printf("%d", maxOrchidCount);
    
    return 0;
}