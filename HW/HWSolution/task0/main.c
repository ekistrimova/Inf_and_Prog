#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "russian");
	printf("Задача с двумя окружностями. \n");


	float x1, x2, y1, y2, r1, r2;
	float d;

	printf("Введите параметры 1-й окружности (в виде x y r): ");
	scanf_s("%f %f %f", &x1, &y1, &r1);
	printf("Введите параметры 2-й окружности (в виде x y r): ");
	scanf_s("%f %f %f", &x2, &y2, &r2);

	// pow(number, degree)
	d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

	//1
	if (d == r1 + r2) {
		printf("Касаются");;
	}
	//  2
	if (d < r1 + r2) {
		//2.1
		if (d == 0 && r1 == r2) {
			printf("Совпадают");
		}
		//2.2
		else if (d + r1 < r2 || d + r2 < r1) {
			printf("Одна лежит внутри другой");
		}
		//2.3
		else if (d == abs(r1 - r2)) {
			printf("Внутренне касание");
		}
		//2.4
		else {
			printf("Пересекаются");
		}
	}
	// 3
	if (d > r1 + r2) {
		printf("Никак не связаны");
	}
	return 0;
}