#include <stdio.h>
#define _USE_MATH_DEFINES 
#include <math.h>

int main() {
	int R;
	float S;
	printf("Enter circle radius: ");
	scanf_s("%d", &R);

	S = M_PI * R * R * 0.5;

	printf("Square of circle is: %.2f", S);
	return 0;
}