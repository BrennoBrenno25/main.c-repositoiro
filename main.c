
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
