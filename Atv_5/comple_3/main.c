#include <stdio.h>
#include <stdlib.h>
long long fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Digite o valor de n para calcular Fibonacci: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Valor invalido! Digite um numero maior ou igual a 0.\n");
        return 1;
    }

    long long resultado = fibonacci(n);

    printf("Fibonacci(%d) = %lld\n", n, resultado);

    return 0;
}