#include <stdio.h>

int maxndel(int* index, int* first, int* second, int* third, int n) {
    int maxindex = 0;
    int maxpoints = 0;
    for (int i = 0; i < n; i++) {
        int sumpoints = first[i] + second[i] + third[i];
        if (sumpoints >= maxpoints) {
            maxindex = i;
            maxpoints = sumpoints;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int flag = 0;
        if (i == maxindex) flag = 1;
        index[i] = index[i + flag];
    }
    first[maxindex] = 0; second[maxindex] = 0; third[maxindex] = 0;
    return maxindex;
}

int main() {
    int student_index[255];
    int received_index[255];
    int accepted_index[255];
    int first[255];
    int second[255];
    int third[255];
    int points[255];
    int K, N;
    printf("Enter two numbers: ");
    scanf_s("%d %d", &K, &N);
    for (int i = 0; i < N; i++) scanf_s("%d %d %d %d", &received_index[i], &first[i], &second[i], &third[i]);
    for (int i = 0; i < N; i++) student_index[i] = received_index[i];
    for (int i = 0; i < N; i++) points[i] = first[i] + second[i] + third[i];
    for (int k = 0; k < K; k++) {
        accepted_index[k] = maxndel(received_index, first, second, third, N);
    }
    printf("\nAccepted students (descending): \n");
    for (int k = 0; k < K; k++) printf("%d ", student_index[accepted_index[k]]);
    printf("\n");
    printf("\nPassing score: %d\n", points[accepted_index[K - 1]]);
    return 0;
}