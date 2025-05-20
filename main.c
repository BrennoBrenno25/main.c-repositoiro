#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

/*
    INTEGRANTES
    Brenno Alves Souza RM 566066
    Casos 3 e 4
    Victor Bagio Gusto RM 566032
    Casos 1 e 2
 */

int main(void) {
    setlocale(LC_ALL, "Portuguese");

    char opcao;
    printf("=====MENU DE EXERCÍCIOS=====\n");
    printf("1 - Sequência de Fibonacci\n");
    printf("2 - Fatoriais\n");
    printf("3 - Verificar Palíndromo\n");
    printf("4 - Verificar Substring\n");
    printf("Escolha uma opção:\n");

    if (scanf(" %c", &opcao) != 1) {
        printf("Entrada inválida. Saindo.\n");
        return 1;
    }

    switch (opcao) {
        case '1': {
            int N;
            printf("Digite um número inteiro entre 1 e 50: ");
            if (scanf("%d", &N) != 1) {
                printf("Entrada inválida. Saindo.\n");
                return 1;
            }
            if (N < 1 || N > 50) {
                printf("Número inválido\n");
                return 1;
            }
            unsigned long long int fibonacci[N];
            fibonacci[0] = 0;
            if (N > 1) {
                fibonacci[1] = 1;
            }
            for (int i = 2; i < N; i++) {
                fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
            }
            printf("Sequência de Fibonacci: \n");
            for (int i = 0; i < N; i++) {
                printf("%llu ", fibonacci[i]);
            }
            printf("\n");
            break;
        }
        case '2': {
            int N;
            printf("Digite um número inteiro entre 1 e 20: ");
            if (scanf("%d", &N) != 1) {
                printf("Entrada inválida. Saindo.\n");
                return 1;
            }
            if (N < 1 || N > 20) {
                printf("Número inválido\n");
                return 1;
            }
            unsigned long long int fatoriais[N];
            for (int i = 1; i <= N; i++) {
                unsigned long long int fatorial = 1;
                for (int j = 1; j <= i; j++) {
                    fatorial *= j;
                }
                fatoriais[i - 1] = fatorial;
            }

            printf("Fatoriais:\n");
            for (int i = 0; i < N; i++) {
                printf("%d! = %llu\n", i + 1, fatoriais[i]);
            }
            break;
        }
        case '3': {
            char palavra[101];
            printf("Digite uma palavra de até 100 caracteres:\n");
            if (scanf("%100s", palavra) != 1) {
                printf("Entrada inválida. Saindo.\n");
                return 1;
            }

            char palavra_limpa[101] = "";
            int j = 0;
            for (int i = 0; palavra[i] != '\0'; i++) {
                if (isalnum(palavra[i])) {
                    palavra_limpa[j++] = tolower(palavra[i]);
                }
            }
            palavra_limpa[j] = '\0';

            const int len = strlen(palavra_limpa);
            int palindromo = 1;

            for (int i = 0; i < len / 2; i++) {
                if (palavra_limpa[i] != palavra_limpa[len - i - 1]) {
                    palindromo = 0;
                    break;
                }
            }
            if (palindromo) {
                printf("A palavra %s é um palíndromo\n", palavra);
            } else {
                printf("A palavra %s NÃO é um palíndromo\n", palavra);
            }
            break;
        }
        case '4': {
            char str1[101], str2[101];

            printf("Digite a primeira string (até 100 caracteres):\n");
            if (scanf("%100s", str1) != 1) {
                printf("Entrada inválida para a primeira string. Saindo.\n");
                return 1;
            }

            printf("Digite a segunda string (até 100 caracteres):\n");
            if (scanf("%100s", str2) != 1) {
                printf("Entrada inválida para a segunda string. Saindo.\n");
                return 1;
            }

            if (strstr(str1, str2) != NULL) {
                printf("A segunda string está contida na primeira.\n");
            } else {
                printf("A segunda string NÃO está contida na primeira.\n");
            }
            break;
        }
        default: {
            printf("Opção inválida.\n");
            return 1;
        }
    }

    return 0;
}
