#include <stdio.h>

int main() {
	int num, isWork = 1, choice;
	printf("Option one - inverse numbers\n");
	printf("Option two  - sum numbers\n");
	printf("Choose option (1 or 2): ");
	scanf_s("%d", &choice);

	if (choice > 2 || choice < 1) {
		printf("\nError option number!\n");
		return 0;
	}

	while (isWork) {
		printf("Let's start: \n");
		printf("For exit enter 0\n");
		int isError = 0;
		do {
			if (isError) printf("Wrong input! Try again.");

			printf("\nInput positive number: ");
			scanf_s("%d", &num);
			if (num == 0) isWork = 0;
			break;

			isError = (num <= 0);
		} while (isError);
		int inverse = 0, sum = 0, num2 = num;
		while (num2) {
			sum += num2 % 10;
			num2 = num2 / 10;
		}
		while (num) {
			inverse *= 10;
			inverse += num % 10;
			num = num / 10;
		}
		if (isWork == 1 && choice == 1) printf("\nResult: %d\n\n", inverse);
		if (isWork == 1 && choice == 2) printf("\nResult: %d\n\n", sum);
		if (!isWork) printf("\n\nEXIT\n\n");
	}
	return 0;
}