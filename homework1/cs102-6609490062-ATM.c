#include <stdio.h>

int main() {
	int money, note1000, note500, note100;

	printf("Please enter your withdrawl amount: ");
	scanf("%d", &money);

	note1000 = money / 1000;
	note500 = (money % 1000) / 500;
	note100 = (money % 500) / 100;

	printf("You will get :-\n");
	printf("#1000-Baht notes: %d\n", note1000);
	printf("#500-Baht notes: %d\n", note500);
	printf("#100-Baht notes: %d\n", note100);

	return 0;
}