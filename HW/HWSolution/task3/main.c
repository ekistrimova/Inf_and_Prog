#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>

void gen_number(int* num, int n);
void gen_usr_number(int usr_num, int* usr_nums, int n);
int game(int* num, int* usr_nums, int n);

int main() {
	setlocale(LC_ALL, "russian");
	srand(time(0));
	int n = 0;
	int num[5];
	printf("Введите количество цифр в числе (от 2 до 5): ");
	scanf_s("%d", &n);
	while (n < 2 || n > 5) {
		printf("Повторите попытку: ");
		scanf_s("%d", &n);
	}
	printf("\n");
	gen_number(num, n);

	int found = 0;
	int usr_num = 0;
	int usr_nums[5];

	while (!found) {
		printf("Попробуйте угадать число: ");
		scanf_s("%d", &usr_num);
		gen_usr_number(usr_num, usr_nums, n);
		if (game(num, usr_nums, n) == n) found = 1;
	}
}
 
void gen_number(int* num, int n) {
	for (int i = 0; i < n; i++) {
		while (1) {
			int found = 0;
			int x = rand() % 10;
			if (x == 0 && i == 0) found = 1;
			for (int j = 0; j < n; j++) {
				if (x == num[j]) found = 1;
			}
			if (!found) {
				num[i] = x;
				break;
			}
		}
	}
}

void gen_usr_number(int usr_num, int* usr_nums, int n) {
	for (int i = 0; i < n; i++) usr_nums[i] = usr_num / (int)pow(10, n - 1 - i) % 10;
}

int game(int* num, int* usr_nums, int n) {
	int bulls = 0;
	int cows = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (num[i] == usr_nums[j]) {
				if (i == j) bulls++;
				else cows++;
			}
		}
	}
	if (bulls == n) printf("Вы угадали число!\n");
	else printf("Хорошая попытка! Всего %d коров и %d быков.\n\n", cows, bulls);
	return bulls;
}