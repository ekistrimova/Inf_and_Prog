#include <Stdio.h>


int main() {
	float S;
	int x, y;
	printf("Enter data of rectangle(x, y(separated by a space)): ");
	scanf_s("%d %d", &x, &y);

	S = x * y;

	printf("Square of rectangle is: %.2f", S);

	return 0;
}