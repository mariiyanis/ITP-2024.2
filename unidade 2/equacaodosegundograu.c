#include <stdio.h>
#include <math.h>

/* Programa que calcula as raízes da equação do segundo grau */

int raizes(double A, double B, double C, double *x1, double *x2) {
    double D = B * B - 4 * A * C; 

    if (D < 0) {
        return 0;
    } else if (D == 0) {
        *x1 = -B / (2 * A);
        return 1;
    } else {
        *x1 = (-B + sqrt(D)) / (2 * A);
        *x2 = (-B - sqrt(D)) / (2 * A);
        return 2;
    }
}

int main() {
    double A, B, C;
    double x1, x2;

    scanf("%lf %lf %lf", &A, &B, &C);

    if (A == 0) {
        return 1;
    }

    int num_raizes = raizes(A, B, C, &x1, &x2);

    printf("%d\n", num_raizes);
    if (num_raizes == 1) {
        printf("%.3f\n", x1);
    } else if (num_raizes == 2) {
        printf("%.3f %.3f\n", x1, x2);
    }

    return 0;
}
