#include <stdio.h>

int main(void) {

  int triagSide1, triagSide2, triagSide3;
  printf("\nPlease enter length of each side of your triangle: ");
  scanf("%d %d %d", &triagSide1, &triagSide2, &triagSide3);

  if ((triagSide1 < (triagSide2 + triagSide3)) && (triagSide2 < (triagSide1 + triagSide3)) && (triagSide3 < (triagSide1 + triagSide2))) {

    if (triagSide1 == triagSide2 && triagSide2 == triagSide3) {
      printf("This is an equilateral triangle.");
    }
    else if (triagSide1 != triagSide2 && triagSide1 != triagSide3 && triagSide2 != triagSide3) {
      printf("This is a scalene triangle.\n");
    }
    else {
      printf("This is an isosceles triangle.\n");
    }
  }
  else {
    printf("This is NOT a triangle.\n");
  }

  return 0;
}