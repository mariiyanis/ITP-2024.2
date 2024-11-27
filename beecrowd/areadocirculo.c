#include <stdio.h>

//Exercício Beecrowd 1002

int main() {
 
    double raio, area;
    const double pi = 3.14159;
    
    // Ler o raio
    scanf("%lf", &raio);
 
    // Área do círculo
    area = pi * raio * raio;
    
    //Saída
    printf("A=%.4lf\n", area);
    
    return 0;
}
