#include <stdio.h>
#include <math.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "russian");
	printf("Задача с нахождением массы шкафа. \n");

	float h, w, d;
	float stenka, bokovina, kryshka, dver, polka, shkaf;
	float tolshina_stenki = 0.005, tolshina_bokovini = 0.015, tolshina_kryshki = 0.015, tolshina_dveri = 0.01, rasstoyanie = 0.4;
	float dsp, dvp, derevo;
	int check = 0;

	while (check == 0) {
		printf("Ведите высоту (от 1.8 м до 2.2 м), ширину (от 0.8 м до 1.2 м) и глубину (от 0.5 м до 0.9 м): ");
		scanf_s("%f %f %f", &h, &w, &d);
		if (h < 1.8 || h > 2.2 || w < 0.8 || w > 1.2 || d < 0.5 || d > 0.9) printf("Повторите ввод\n");
		else check = 1;
	}
	printf("Введите плотность ДСП, ДВП и дерева: ");
	scanf_s("%f %f %f", &dsp, &dvp, &derevo);

	stenka = (h * w * tolshina_stenki) * dvp;
	bokovina = (h * d * tolshina_bokovini) * dsp;
	kryshka = (w * d * tolshina_kryshki) * dsp;
	dver = (h * w * 0.5 * tolshina_dveri) * derevo;
	polka = ((w - 2 * tolshina_bokovini) * d * tolshina_kryshki) * dsp;

	shkaf = stenka + 2 * bokovina + 2 * kryshka + 2 * dver + ((int)h / rasstoyanie - 1) * polka;
	printf("Масса шкафа = %.1f кг.", shkaf);

	return 0;
}