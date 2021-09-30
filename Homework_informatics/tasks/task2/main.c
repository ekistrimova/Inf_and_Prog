#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "russian");
	int numbers = 0, words = 0;
	char last_symbol = '.';
	char symbol = '.';
	while (symbol != '\n') {
		last_symbol = symbol;
		symbol = getchar();
		if (symbol == ' ' || symbol == '\t') continue;
		if (48 <= symbol && symbol <= 57)           //  диапазон цифр
			if (!(48 <= last_symbol && last_symbol <= 57)) 
				numbers++;
		if (-128 <= symbol && symbol <= -17 || 65 <= symbol && symbol <= 122)            // диапазон русских и английских букв
			if (!(-128 <= last_symbol && last_symbol <= -17 || 65 <= last_symbol && last_symbol <= 122)) 
				words++;      
	}
	printf("%d numbers and %d words", numbers, words);
}