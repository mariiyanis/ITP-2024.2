#include <stdio.h>

int main()
{
    float num1, num2, soma, subtracao, multi, div;
    scanf("%f %f", &num1, &num2);
    
    soma = num1 + num2;
    subtracao = num1 - num2;
    multi = num1 * num2;
    div = num1 / num2;
    
    printf("A soma é: %.2f\n", soma);
    printf("A diferença é: %.2f\n", subtracao);
    printf("A multiplicação é: %.2f\n", multi);
    printf("A divisão é: %.2f\n", div);
    
    return 0;
}
