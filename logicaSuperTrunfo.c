#include <stdio.h>

#include <stdio.h>
#include <string.h>

// Função para limpar ENTER que sobra no buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    // Valor das variáveis da carta 1
    char estado1;
    char codigo_da_carta1[10];
    char nome_da_cidade1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidade_populacional1;
    float pib_per_capita1;
    float super_poder1;

    // valor das variáveis da carta 2
    char estado2;
    char codigo_da_carta2[10];
    char nome_da_cidade2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidade_populacional2;
    float pib_per_capita2;
    float super_poder2;


    // --- Carta 1 ---
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

    densidade_populacional1 = populacao1 / area1 ;

    pib_per_capita1 = pib1 / populacao1 ;


    // --- Carta 2 ---
    printf("\n Insira os dados da carta 2\n");

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

    densidade_populacional2 = populacao2 / area2 ;

    pib_per_capita2 = pib2 / populacao2 ;

    super_poder1 = (float) populacao1 + area1 + pib1 + (float) pontos_turisticos1 + pib_per_capita1 + (1.0 / densidade_populacional1);
    super_poder2 = (float) populacao2 + area2 + pib2 + (float) pontos_turisticos2 + pib_per_capita2 + (1.0 / densidade_populacional2);


    // --- impressão ---
    printf("\n --- Carta 1 ---\n");
    printf("Estado: %c\n Código: %s\n Cidade: %s\n População: %lu\n Área: %.2f km²\n PIB: %.2f bilhões de reais\n Pontos turísticos: %d\n Densidade populacional: %.2f hab/km²\n PIB per Capita: %.2f reais\n",
        estado1, codigo_da_carta1, nome_da_cidade1, populacao1, area1, pib1, pontos_turisticos1, densidade_populacional1, pib_per_capita1);

    printf("\n --- Carta 2 ---\n");
    printf("Estado: %c\n Código: %s\n Cidade: %s\n População: %lu\n Área: %.2f km²\n PIB: %.2f bilhões de reais\n Pontos turísticos: %d\n Densidade populacional: %.2f hab/km²\n PIB per Capita: %.2f reais\n",
        estado2, codigo_da_carta2, nome_da_cidade2, populacao2, area2, pib2, pontos_turisticos2,densidade_populacional2, pib_per_capita2);


    printf("\n--- Comparação das cartas ---\n");

// População

    printf("Carta 1 - %s : %lu\n",nome_da_cidade1,populacao1);
    printf("Carta 2 - %s : %lu\n",nome_da_cidade2,populacao2);
if (populacao1 > populacao2)
    printf("Carta 1 %s venceu \n",nome_da_cidade1);
else if (populacao2 > populacao1)
    printf("Carta 2 %s venceu\n",nome_da_cidade2);


    return 0;
}
