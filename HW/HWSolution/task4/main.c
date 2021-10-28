// Copyright 2021 Kistrimova Ekaterina

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define SIZE 15

char product[SIZE][255] = { "Mona Lisa (Leonardo da Vinci, 1503)",
								"Girl with a Pearl Earring (Johannes Vermeer, 1665)",
								"The Scream (Edvard Munch, 1893)",
								"Creation of Adam (Michelagnelo, 1510)",
								"The Birth of Venus (Sandro Botticelli, 1486)",
								"Portrait of Dora Maar (Pablo Picasso, 1937)",
								"Dogs Playing Poker (Cassius Marcellus Coolidge, 1894)",
								"Napoleon crossing the Alps (Jacques-Louis David, 1801)",
								"The Son of Man (Rene Magritte, 1964)",
								"The Kiss (Gustav Klimt, 1907)",
								"The Dance (Henri Matisse, 1909)",
								"The Tower of Babel (Pieter Bruegel the Elder, 1563)",
								"Water Lilies (Claude Monet, 1840)",
								"Starry Night (Vincent van Gogh, 1889)",
								"The Persistence of Memory (‎Salvador Dali, 1931)" };
int price[SIZE] = { 2020, 500, 1000, 830, 970, 480, 600, 700, 640, 550, 670, 430, 1050, 1500, 1730 };
int barcode[SIZE] = { 1041, 1467, 7334, 9500, 2169, 7724, 3478, 3358, 9962, 7464, 6705, 2145, 6281, 8827, 1961 };
double sale[SIZE] = { 0 };
double sum = 0, sumOrig = 0, sumSale = 0;
int list[SIZE];

void welcomeMessage() {
	printf("Добро пожаловать!\n\
Для сканирования товара нажмите 1\n\
Для получения информации о товаре нажмите 2\n\
Для добавлния данных о товаре в чек нажмите 3\n\
Для вывода чека за покупку нажмите 4\n\
Для рассчёта итоговой суммы к оплате нажмите 5\n\
Для вывода финального чека нажмите 6\n\
Для отмены последнего товара используйте 0\n\
Для повторного вывода меню нажмите +\n");
}

int getBarcode() {
	int code;
	int check = 0;
	int index = 0;
	printf("Введите штрих-код: ");
	do {
		scanf_s("%d", &code);
		for (int i = 0; i < SIZE; i++) if (code == barcode[i]) { check = 1; index = i; break; }
		if (check) {
			printf("Товар отсканирован\n");
			return index;
		}
		printf("Товар не найден\nПовторите попытку: ");
	} while (!check);
}

void getInfo(int index) {
	printf("Наименование: %s | Цена: %d | Текущая скидка: %d%%\n", product[index], price[index], (int)(sale[index] * 100));
}

void addToList(int choice) {
	printf("Товар добавлен\n");
	list[choice]++;
	sum += price[choice] - price[choice] * sale[choice];
	sumSale += price[choice] * sale[choice];
	sumOrig += price[choice];
}

void showList() {
	printf("Текущий список покупок:\n");
	for (int i = 0; i < SIZE; i++) {
		if (list[i] != 0) {
			printf("Наименование: %s | Цена: %d | Текущая скидка: %d%% | Количество: %d шт.\n", product[i], price[i], (int)(sale[i] * 100), list[i]);
		}
	}
}

void printSum() {
	printf("Сумма к оплате: %.2lf\n", sum);
}

void cancelList(int choice) {
	printf("Последний товар удален\n");
	list[choice]--;
	sum -= price[choice] - price[choice] * sale[choice];
	sumSale -= price[choice] * sale[choice];
}

void printList() {
	int index = 1;
	printf("Ваши товары: \n");
	for (int i = 0; i < SIZE; i++) {
		if (list[i] != 0) {
			printf("%2d. %s\n", index, product[i]);
			printf("%-45s %6d x %4d\n", "Количество:", list[i], price[i]);
			printf("%-48s %10d\n", "Стоимость:", price[i] * list[i]);
			printf("%s %2d%%: %47.2lf\n", "Скидка", (int)(sale[i] * 100), list[i] * price[i] * sale[i]);
			printf("%-48s %10.2lf\n", "Итоговая стоимость:", list[i] * (price[i] - price[i] * sale[i]));
			index++;
		}
	}
	printf("===========================================================\n");
	printf("%-48s %10.2lf\n", "Всего:", sumOrig);
	printf("%-48s %10.2lf\n", "Суммарная скидка:", sumSale);
	printf("%-48s %10.2lf", "Итого:", sum);
}

int main() {
	setlocale(LC_ALL, "russian");
	for (int i = 0; i < SIZE; i++) sale[i] = (double)(rand() & 70 + 1) / 100;
	int choice = 0;
	welcomeMessage();
	char state = '0';
	while (state != '6') {
		printf("Выберите опцию: ");
		scanf_s("%c", &state);
		switch (state) {
		case '1':
			choice = getBarcode(barcode);
			break;
		case '2':
			getInfo(choice);
			break;
		case '3':
			addToList(choice);
			break;
		case '4':
			showList();
			break;
		case '5':
			printSum();
			break;
		case '0':
			cancelList(choice);
			break;
		case '+':
			welcomeMessage();
			break;
		}
		while (getchar() != '\n');
	}
	printList();
}

