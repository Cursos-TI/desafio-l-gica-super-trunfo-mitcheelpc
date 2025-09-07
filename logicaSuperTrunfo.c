#include <stdio.h>
#include <string.h>

// Função para limpar ENTER que sobra no buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função que retorna o nome do atributo pelo número
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos turísticos";
        case 5: return "Densidade populacional";
        default: return "Desconhecido";
    }
}

int main() {
    int opcao, atributo1, atributo2;

    // Variáveis da carta 1
    char estado1;
    char codigo_da_carta1[10];
    char nome_da_cidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade_populacional1;
    float pib_per_capita1;

    // Variáveis da carta 2
    char estado2;
    char codigo_da_carta2[10];
    char nome_da_cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade_populacional2;
    float pib_per_capita2;

    // --- MENU PRINCIPAL ---
    do {
        printf("\n===== MENU SUPER TRUNFO =====\n");
        printf("1 - Cadastrar cartas\n");
        printf("2 - Comparar cartas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
        case 1:
            // --- Cadastro carta 1 ---
            printf("Cadastro de cartas do Super Trunfo\n");
            printf("Insira os dados da carta 1\n");

            printf("Estado: ");
            scanf(" %c", &estado1);
            limparBuffer();

            printf("Código da carta: ");
            scanf("%s", codigo_da_carta1);
            limparBuffer();

            printf("Nome da cidade: ");
            fgets(nome_da_cidade1, sizeof(nome_da_cidade1), stdin);
            nome_da_cidade1[strcspn(nome_da_cidade1, "\n")] = 0;

            printf("População: ");
            scanf("%lu", &populacao1);
            limparBuffer();

            printf("Área: ");
            scanf("%f", &area1);
            limparBuffer();

            printf("PIB em bilhões: ");
            scanf("%f", &pib1);
            limparBuffer();

            printf("Pontos turísticos: ");
            scanf("%d", &pontos_turisticos1);
            limparBuffer();

            densidade_populacional1 = populacao1 / area1;
            pib_per_capita1 = pib1 / populacao1;

            // --- Cadastro carta 2 ---
            printf("\nInsira os dados da carta 2\n");

            printf("Estado: ");
            scanf(" %c", &estado2);
            limparBuffer();

            printf("Código da carta: ");
            scanf("%s", codigo_da_carta2);
            limparBuffer();

            printf("Nome da cidade: ");
            fgets(nome_da_cidade2, sizeof(nome_da_cidade2), stdin);
            nome_da_cidade2[strcspn(nome_da_cidade2, "\n")] = 0;

            printf("População: ");
            scanf("%lu", &populacao2);
            limparBuffer();

            printf("Área: ");
            scanf("%f", &area2);
            limparBuffer();

            printf("PIB em bilhões: ");
            scanf("%f", &pib2);
            limparBuffer();

            printf("Pontos turísticos: ");
            scanf("%d", &pontos_turisticos2);
            limparBuffer();

            densidade_populacional2 = populacao2 / area2;
            pib_per_capita2 = pib2 / populacao2;

            printf("\nCartas cadastradas com sucesso!\n");
            break;

        case 2:
            printf("\n--- Comparação das cartas ---\n");
            printf("Escolha o PRIMEIRO atributo:\n");
            printf("1. População\n");
            printf("2. Área\n");
            printf("3. PIB\n");
            printf("4. Pontos turísticos\n");
            printf("5. Densidade populacional\n");
            scanf("%d", &atributo1);
            limparBuffer();

            printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");
            for (int i = 1; i <= 5; i++) {
                if (i != atributo1) {
                    printf("%d. %s\n", i, nomeAtributo(i));
                }
            }
            scanf("%d", &atributo2);
            limparBuffer();

            if (atributo1 == atributo2) {
                printf("Erro: Os dois atributos devem ser diferentes!\n");
                break;
            }

            float valor1_carta1 = 0, valor1_carta2 = 0;
            float valor2_carta1 = 0, valor2_carta2 = 0;

            // --- Comparação do primeiro atributo ---
            switch (atributo1) {
            case 1: valor1_carta1 = populacao1; valor1_carta2 = populacao2; break;
            case 2: valor1_carta1 = area1; valor1_carta2 = area2; break;
            case 3: valor1_carta1 = pib1; valor1_carta2 = pib2; break;
            case 4: valor1_carta1 = pontos_turisticos1; valor1_carta2 = pontos_turisticos2; break;
            case 5: valor1_carta1 = densidade_populacional1; valor1_carta2 = densidade_populacional2; break;
            }

            // --- Comparação do segundo atributo ---
            switch (atributo2) {
            case 1: valor2_carta1 = populacao1; valor2_carta2 = populacao2; break;
            case 2: valor2_carta1 = area1; valor2_carta2 = area2; break;
            case 3: valor2_carta1 = pib1; valor2_carta2 = pib2; break;
            case 4: valor2_carta1 = pontos_turisticos1; valor2_carta2 = pontos_turisticos2; break;
            case 5: valor2_carta1 = densidade_populacional1; valor2_carta2 = densidade_populacional2; break;
            }

            printf("\nComparação entre %s e %s\n", nome_da_cidade1, nome_da_cidade2);
            printf("%s: Carta1 = %.2f, Carta2 = %.2f\n", nomeAtributo(atributo1), valor1_carta1, valor1_carta2);
            printf("%s: Carta1 = %.2f, Carta2 = %.2f\n", nomeAtributo(atributo2), valor2_carta1, valor2_carta2);

            float pontos1 = 0, pontos2 = 0;

            // Primeiro atributo
            if (atributo1 == 5) { // densidade → menor vence
                if (valor1_carta1 < valor1_carta2) pontos1++;
                else if (valor1_carta2 < valor1_carta1) pontos2++;
            } else {
                if (valor1_carta1 > valor1_carta2) pontos1++;
                else if (valor1_carta2 > valor1_carta1) pontos2++;
            }

            // Segundo atributo
            if (atributo2 == 5) {
                if (valor2_carta1 < valor2_carta2) pontos1++;
                else if (valor2_carta2 < valor2_carta1) pontos2++;
            } else {
                if (valor2_carta1 > valor2_carta2) pontos1++;
                else if (valor2_carta2 > valor2_carta1) pontos2++;
            }

            printf("\nResultado final:\n");
            printf("%s pontos: %.0f\n", nome_da_cidade1, pontos1);
            printf("%s pontos: %.0f\n", nome_da_cidade2, pontos2);

            if (pontos1 > pontos2) {
                printf(">>> Carta 1 (%s) venceu!\n", nome_da_cidade1);
            } else if (pontos2 > pontos1) {
                printf(">>> Carta 2 (%s) venceu!\n", nome_da_cidade2);
            } else {
                printf(">>> Empate!\n");
            }
            break;

        case 0:
            printf("Saindo do jogo...\n");
            break;

        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}
