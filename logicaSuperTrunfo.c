#include <stdio.h>
#include <string.h>

// Função para limpar ENTER que sobra no buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
     int opcao;
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
    printf(" Escolha um atributo para comparaçao\n");
    printf("1. Populaçao \n");
    printf("2 Area \n");
    printf("3. PIB \n");
    printf("4. Numeros de pontos turisticos \n");
    printf("5. Densidade populacional \n");
    scanf("%d" , &opcao);

    switch (opcao)
    {
    case 1:
    printf("Nome da cidade da carta 1: %s - Nome da cidade da carta 2: %s\n", 
           nome_da_cidade1, nome_da_cidade2);

    printf("Comparação do Atributo População\n");
    printf("População da carta 1: %lu - População da carta 2: %lu\n", 
           populacao1, populacao2);

    if (populacao1 > populacao2) {
        printf("Carta 1 venceu\n");
    } else if (populacao1 < populacao2) {
        printf("Carta 2 venceu\n");
    } else {  
        printf("EMPATE\n");
    }
    break;

    case 2:
    printf("Nome da cidade da carta 1: %s - Nome da cidade da carta 2: %s\n", 
           nome_da_cidade1, nome_da_cidade2);

    printf("Comparação do Atributo Area\n");
    printf("Area da carta 1: %2.f - Area da carta 2: %2.f\n", 
           area1, area2);

    if (area1 > area2) {
        printf("Carta 1 venceu\n");
    } else if (area1 < area2) {
        printf("Carta 2 venceu\n");
    } else {  
        printf("EMPATE\n");
    }
    break;

    case 3:
    printf("Nome da cidade da carta 1: %s - Nome da cidade da carta 2: %s\n", 
           nome_da_cidade1, nome_da_cidade2);

    printf("Comparação do Atributo PIB\n");
    printf("PIB da carta 1: %2.f - PIB da carta 2: %2.f\n", 
           pib1, pib2);

    if (pib1 > pib2) {
        printf("Carta 1 venceu\n");
    } else if (pib1 < pib2) {
        printf("Carta 2 venceu\n");
    } else {  
        printf("EMPATE\n");
    }
    break;

    case 4:
    printf("Nome da cidade da carta 1: %s - Nome da cidade da carta 2: %s\n", 
           nome_da_cidade1, nome_da_cidade2);

    printf("Comparação do Atributo Pontos turisticos\n");
    printf("Pontos turisticos da carta 1: %d - Pontos Turisticos da carta 2: %d\n", 
           pontos_turisticos1, pontos_turisticos2);

    if (pontos_turisticos1 > pontos_turisticos2) {
        printf("Carta 1 venceu\n");
    } else if (pontos_turisticos1 < pontos_turisticos2) {
        printf("Carta 2 venceu\n");
    } else {  
        printf("EMPATE\n");
    }
    break;

    case 5:
    printf("Nome da cidade da carta 1: %s - Nome da cidade da carta 2: %s\n", 
           nome_da_cidade1, nome_da_cidade2);

    printf("Comparação do Atributo Densidade Populacional\n");
    printf("Densidade Populacional da carta 1: %2.f - Densidade Populacional da carta 2: %2.f\n", 
           densidade_populacional1, densidade_populacional2);

    if (densidade_populacional1 < densidade_populacional2) {
        printf("Carta 1 venceu\n");
    } else if (densidade_populacional1 > densidade_populacional2) {
        printf("Carta 2 venceu\n");
    } else {  
        printf("EMPATE\n");
    }
    break;
    
    }



    return 0;
}
