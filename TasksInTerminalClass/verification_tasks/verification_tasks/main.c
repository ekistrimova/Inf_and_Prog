#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int array[255];
    int new_array[255];
    int A = 0, N = 0, K = 0;
    printf("Enter your numbers: ");
    scanf_s("%d %d %d", &A, &N, &K);
    for (int i = 0; i < N; i++) array[i] = rand() % (2 * A + 1) - A;
    printf("\nRandom array:\n");
    for (int i = 0; i < N; i++) printf("%d ", array[i]);
    printf("\n");
    for (int i = 0; i < N; i++) new_array[(i + K) % N] = array[i];
    printf("\nCyclic shift:\n");
    for (int i = 0; i < N; i++) printf("%d ", new_array[i]);
    printf("\n");
    for (int i = 0; i < N; i++) array[i] = new_array[N - 1 - i];
    printf("\nReverse:\n");
    for (int i = 0; i < N; i++) printf("%d ", array[i]);
    printf("\n");
    return 0;
}

