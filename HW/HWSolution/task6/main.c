#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct answer {  // �������� ��������� answer � ���������� ���� ������ Answer
    double value;
    double error;
    int count;
} Answer;

long long factorial(int n) { // ������� ���������� ����������
    return (n < 2) ? 1 : n * factorial(n - 1);  // �������� �������� 
}

Answer sinTalor(double x, int N, double eps, double* etalon) {  // ���������� ������ �� ���� �������
    int i;
    Answer result;
    result.value = 0;
    *etalon = sin(x);
    for (i = 0; i < N; i++) {
        result.value += pow(-1, i) * pow(x, 2 * i + 1) / (double)factorial(2 * i + 1);
        if (fabs(*etalon - result.value) < eps) break;
    }
    result.error = fabs(*etalon - result.value);
    result.count = i;
    return result;
}

Answer cosTalor(double x, int N, double eps, double* etalon) {  // ���������� �������� �� ���� �������
    int i;
    Answer result;
    result.value = 0;
    *etalon = cos(x);
    for (i = 0; i < N; i++) {
        result.value += pow(-1, i) * pow(x, 2 * i) / (double)factorial(2 * i);
        if (fabs(*etalon - result.value) < eps) break;
    }
    result.error = fabs(*etalon - result.value);
    result.count = i;
    return result;
}

Answer expTalor(double x, int N, double eps, double* etalon) {  // ���������� ���������� �� ���� �������
    int i;
    Answer result;
    result.value = 0;
    *etalon = exp(x);
    for (i = 0; i < N; i++) {
        result.value += pow(x, i) / (long double)factorial(i);
        if (fabs(*etalon - result.value) < eps) break;
    }
    result.error = fabs(*etalon - result.value);
    result.count = i;
    return result;
}

Answer cscTalor(double x, int N, double eps, double* etalon) {   // ���������� ��������� �� ���� ������� ( 1 / sin(x) )
    int i;
    Answer result;
    result.value = 0;
    *etalon = sin(x);
    for (i = 0; i < N; i++) {
        result.value += pow(-1, i) * pow(x, 2 * i + 1) / (double)factorial(2 * i + 1);
        if (fabs(*etalon - result.value) < eps) break;
    }
    *etalon = 1 / *etalon;
    result.value = 1 / result.value;
    result.error = fabs(*etalon - result.value);
    result.count = i;
    return result;
}

void functions(Answer* answer, double x, int func, int n, double* etalon, double eps) {  // ������� � ���������
    switch (func) {
    case 1:
        *answer = sinTalor(x, n, eps, etalon);
        break;
    case 2:
        *answer = cosTalor(x, n, eps, etalon);
        break;
    case 3:
        *answer = expTalor(x, n, eps, etalon);
        break;
    case 4:
        *answer = cscTalor(x, n, eps, etalon);
        break;
    default:
        break;
    }
}

int main() {
    Answer answer;
    double etalon;
    double eps = 0.000001;

    void (*funcs)(Answer*, double, int, int, double*, double);  // ��������� �� ������� � ���������
    funcs = functions;

    printf("Mode 1 (single) 2 (multi): ");  // ����� ������ ������
    int mode;
    while (1) {
        scanf_s("%d", &mode);
        if (mode != 1 && mode != 2) printf("1 or 2: ");
        else break;
    }
    printf("Func 1 (sin) 2 (cos) 3 (exp) 4 (csc): ");  // ����� �������
    int func;
    while (1) {
        scanf_s("%d", &func);
        if (func < 1 || func > 4) printf("1 2 3 or 4: ");
        else break;
    }
    printf("x from -1 to 1: ");  // ����� �����
    double x;
    while (1) {
        scanf_s("%lf", &x);
        if (x < -1 || x > 1) printf("from -1 to 1: ");
        else break;
    }
    switch (mode) {  // ������ ������
    case 1:  // ���������
        printf("n form 1 to 100: ");  // ����� ������������� ���������� ���������
        int n;
        while (1) {
            scanf_s("%d", &n);
            if (n < 1 || n > 100) printf("from 1 to 100: ");
            else break;
        }
        funcs(&answer, x, func, n, &etalon, eps);  // ����� ������� � ���������
        printf("etalon: %.12lf\nfunction: %.12lf\nerror: %.12lf\ncount: %d",   // ����� ������
            etalon, answer.value, answer.error, answer.count);
        break;
    case 2:  // �������
        printf("amount of experiments from 1 to 999: ");  // ���������� ������������� (����� �������)
        int nexp;
        while (1) {
            scanf_s("%d", &nexp);
            if (nexp < 1 || nexp > 999) printf("from 1 to 999: ");
            else break;
        }
        printf("    | %-15s| %-15s| %-15s| %-s |\n", "etalon", "function", "error", "count");
        for (int i = 0; i < nexp; i++) {   // ����� ������� (��������)
            n = i + 1;
            eps = 0;
            funcs(&answer, x, func, n, &etalon, eps);
            printf("%3d | %.12lf | %.12lf | %.12lf | %-5d |\n",
                i + 1, etalon, answer.value, answer.error, answer.count);
        }
        break;
    }
}