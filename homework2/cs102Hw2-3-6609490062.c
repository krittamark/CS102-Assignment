#include <stdio.h>

int main() {

  int Num1, Num2, summation = 0;
  
  printf("Please enter Num1: ");
  scanf("%d", &Num1);

  printf("Please enter Num2: ");
  scanf("%d", &Num2);

  for (int i = Num1; i <= Num2; i++) {
    
    if (((i % 6) == 0) && ((i % 9) == 0)) {
      summation = summation + i;
      printf("%d ", i);
    }
  }
  
  printf("\nTotal is %d", summation);

  return 0;
}