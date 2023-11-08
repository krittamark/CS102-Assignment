#include <stdio.h>

int main(void) {

  int budget;
  printf("\nPlease enter budget amount: ");
  scanf("%d", &budget);

  int pizza = budget / 599;
  int pieceOfPizza = pizza * 8;
  int studentProvided = pieceOfPizza / 2;

  int change = budget % 599;

  printf("\nWe can provide support for %d students.", studentProvided);
  printf("\nThe amount of budget remains %d bahts.", change);

  return 0;
}