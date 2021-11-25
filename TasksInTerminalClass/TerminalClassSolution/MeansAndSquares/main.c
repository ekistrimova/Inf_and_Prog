#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

void Mean() {
	int x, y, z;
	float mean;
	printf("Enter three numbers(separated by a space): ");
	scanf_s("%d %d %d", &x, &y, &z);
	mean = (x + y + z) / 3.0;
	printf("Mean is : %.2f", mean);
}

void MeanOfABS() {
	int x, y, z;
	float mean;
	printf("Enter three numbers (separated by a space): ");
	scanf_s("%d %d %d", &x, &y, &z);
	mean = (abs(x) + abs(y) + abs(z)) / 3.0;
	printf("Mean is : %.2f", mean);
}

void MeanOfRoots() {
	int x, y, z;
	float mean;
	printf("Enter three numbers (separated by a space): ");
	scanf_s("%d %d %d", &x, &y, &z);
	mean = (sqrt(x) + sqrt(y) + sqrt(z)) / 3.0;
	printf("Mean is : %.2f", mean);
}

void MeanOfSquares() {
	int x, y, z;
	float mean;
	printf("Enter three numbers (separated by a space): ");
	scanf_s("%d %d %d", &x, &y, &z);
	mean = (x * x + y * y + z * z) / 3.0;
	printf("Mean is : %.2f", mean);
}

void SquareOfTriangle() {
	float S;
	int x, h;
	printf("Enter width and height of triangle (x, h (separated by space)): ");
	scanf_s("%d %d", &x, &h);
	S = x * h / 2;
	printf("Square of rectangle is: %.2f", S);
}

void SquareOfRectangle() {
	float S;
	int x, y;
	printf("Enter data of rectangle (x, y (separated by a space)): ");
	scanf_s("%d %d", &x, &y);
	S = x * y;
	printf("Square of rectangle is: %.2f", S);
}

void SquareOfCircle() {
	int R;
	float S;
	printf("Enter circle radius: ");
	scanf_s("%d", &R);
	S = M_PI * R * R * 0.5;
	printf("Square of circle is: %.2f", S);
}

int main() {
	int ans = 0;
	printf("Chooe one of variants:\n\t1. Mean of three numbers\n\t2. Mean of abs of three numbers\n\t3. Mean of squares of three numbers\n\t4. Means of roots of three numbers\n\t5. Square of triangle\n\t6. Square of rectangle\n\t7. Square of circle\n");
	printf("Your choise: ");
	scanf_s("%d", &ans);
	switch (ans) {
	case 1:
		Mean();
		break;
	case 2:
		MeanOfABS();
		break;
	case 3:
		MeanOfSquares();
		break;
	case 4:
		MeanOfRoots();
		break;
	case 5:
		SquareOfTriangle();
		break;
	case 6:
		SquareOfRectangle();
		break;
	case 7:
		SquareOfCircle();
		break;
	default:
		break;
	}
	return 0;
}