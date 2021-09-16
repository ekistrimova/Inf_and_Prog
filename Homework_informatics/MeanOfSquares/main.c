#include <stdio.h>
#include <math.h>

int main() {
	int x, y, z;
	float mean;
	printf("Enter three numbers(separated by a space): ");
	scanf_s("%d %d %d", &x, &y, &z);

	mean = (x * x + y * y + z * z) / 3.0;

	printf("Mean is : %.2f", mean);
	return 0;
}