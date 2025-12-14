#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <stdbool.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void mostrarMenu() {
    printf("===============================\n");
    printf("   Calculadora Simples\n");
    printf("===============================\n");
    printf("Selecione uma operação:\n");
    printf("1. Adição\n");
    printf("2. Subtração\n");
    printf("3. Multiplicação\n");
    printf("4. Divisão\n");
    printf("5. Sair\n");
    printf("Opção: ");
}

double lerNumero() {
    double num;
    while (scanf("%lf", &num) != 1) {
        printf("Entrada inválida. Digite um número válido: ");
        limparBuffer();
    }
    limparBuffer();
    return num;
}

void soma() {
    double n1, n2;
    printf("Digite o primeiro número: ");
    n1 = lerNumero();
    printf("Digite o segundo número: ");
    n2 = lerNumero();
    printf("Resultado: %.2lf + %.2lf = %.2lf\n", n1, n2, n1 + n2);
}

void subtracao() {
    double n1, n2;
    printf("Digite o primeiro número: ");
    n1 = lerNumero();
    printf("Digite o segundo número: ");
    n2 = lerNumero();
    printf("Resultado: %.2lf - %.2lf = %.2lf\n", n1, n2, n1 - n2);
}

void multiplicacao() {
    double n1, n2;
    printf("Digite o primeiro número: ");
    n1 = lerNumero();
    printf("Digite o segundo número: ");
    n2 = lerNumero();
    printf("Resultado: %.2lf * %.2lf = %.2lf\n", n1, n2, n1 * n2);
}

void divisao() {
    double n1, n2;
    printf("Digite o primeiro número: ");
    n1 = lerNumero();

    do {
        printf("Digite o segundo número (não pode ser zero): ");
        n2 = lerNumero();
        if (n2 == 0)
            printf("Erro: divisão por zero.\n");
    } while (n2 == 0);

    printf("Resultado: %.2lf / %.2lf = %.2lf\n", n1, n2, n1 / n2);
}

int main() {
    setlocale(LC_ALL, ".UTF-8");

    bool continuar = true;

    while (continuar) {
        int escolha;

        while (1) {
            mostrarMenu();
            if (scanf("%d", &escolha) != 1) {
                printf("Opção inválida.\n");
                limparBuffer();
                continue;
            }
            limparBuffer();
            if (escolha >= 1 && escolha <= 5) break;
            printf("Opção inválida.\n");
        }

        system("cls");

        switch (escolha) {
            case 1: soma(); break;
            case 2: subtracao(); break;
            case 3: multiplicacao(); break;
            case 4: divisao(); break;
            case 5: continuar = false; continue;
        }

        char repetir;
        while (1) {
            printf("\nDeseja realizar outra operação? (s/n): ");
            if (scanf(" %c", &repetir) != 1) {
                limparBuffer();
                continue;
            }
            limparBuffer();
            repetir = tolower(repetir);

            if (repetir == 's') {
                break;
            } else if (repetir == 'n') {
                continuar = false;
                break;
            } else {
                printf("Resposta inválida. Use 's' ou 'n'.\n");
            }
        }

        system("cls");
    }

    printf("Obrigado por usar a calculadora! Até a próxima.\n");
    return 0;
}
