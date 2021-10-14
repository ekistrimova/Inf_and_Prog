// COPYRIGHT 2021 KISTRIMOVA EKATERINA
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define SIZE 10


int main() {
	setlocale(LC_ALL, "russian");
	int temp;
	int array[SIZE];
	int even_product = 1;
	int odd_product = 1;
	int odd_mean_product = 1;
	int index1, index2;

	printf("Fill array: ");
	for (int i = 0; i < SIZE; i++) {
		scanf_s("%d", &array[i]);
	}

	for (int i = 0; i < SIZE; i++) {
		if (i % 2 == 0) {
			even_product *= array[i];
		}
		else {
			odd_product *= array[i];
		}
		if (abs(array[i]) % 2 != 0) {
			odd_mean_product *= array[i];
		}
	}
	printf("\nEven indexes product: %d\nOdd indexes product: %d\nOdd means product: %d\n\n", even_product, odd_product, odd_mean_product);

	printf("Elements swapping:\n\n");
	printf("Array before:\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array[i]);
	}

	printf("\nEnter the indexes of elements\n");
	scanf_s("%d %d", &index1, &index2);
	temp = array[index2];
	array[index2] = array[index1];
	array[index1] = temp;

	printf("Array after:\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array[i]);
	}
	temp = array[index2];
	array[index2] = array[index1];
	array[index1] = temp;

	printf("\n\nHalfs of array swapping:\n\n");

	printf("Array before:\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array[i]);
	}

	for (int i = 0; i < SIZE / 2; i++) {
		temp = array[i];
		array[i] = array[i + SIZE / 2];
		array[i + SIZE / 2] = temp;
	}

	printf("\nArray after:\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}