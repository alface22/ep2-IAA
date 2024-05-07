#include <stdio.h>

int main()
{
    int numero;
    scanf("%i", &numero);

    for (int i = 0; i < numero; i++) {
        printf("%i", i + 1);
        if (i != numero - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
