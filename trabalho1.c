#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int total_ingressos_vendidos = 0;

void museu() {
    int escolha;
    puts("EXIBICAO DO MUSEU");
    printf("APERTE 0 E DEPOIS ENTER PARA VOLTA AO MENU: ");
    scanf("%d", &escolha);
    if (escolha == 0) {
        system("cls"); // Limpa a tela
        return; // Volta ao menu principal
    }
}

void comprar_ingresso() {
    int tipoIngresso;

    puts("***CATEGORIAS DE INGRESSOS:\n");
    printf("1 - INGRESSOS PARA JOVENS\n");
    printf("2 - INGRESSOS PARA ADULTOS\n");
    printf("3 - INGRESSOS PARA IDOSOS\n");
    printf("4 - INGRESSOS PARA CRIANCAS\n");

    printf("\n **ESCOLHA UM TIPO DE INGRESSO PARA A SUA ENTRADA AO MUSEU:\n");

    scanf("%d", &tipoIngresso);

    if (tipoIngresso >= 1 && tipoIngresso <= 4) {
        system("cls"); // Limpa a tela
        char tipo[20];
        switch (tipoIngresso) {
            case 1:
                strcpy(tipo, "JOVEM");
                break;
            case 2:
                strcpy(tipo, "ADULTO");
                break;
            case 3:
                strcpy(tipo, "IDOSO");
                break;
            case 4:
                strcpy(tipo, "CRIANCA");
                break;
            default:
                strcpy(tipo, "SELECIONE OUTRO NUMERO :( ");
                break;
        }
        printf(" **VOCE ESCOLHEU INGRESSO DO TIPO %s **.\n", tipo);
        total_ingressos_vendidos++;
        printf("PRESSIONE 0 E ENTER PARA VOLTAR AO MENU PRINCIPAL: ");
        scanf("%d", &tipoIngresso);
        if (tipoIngresso == 0) {
            system("cls"); // Limpa a tela
            return; // Volta ao menu principal
        }
    } else {
        getchar(); // Aguarda a entrada do Enter
        system("cls"); // Limpa a tela
        puts("OPCAO INVALIDA. POR FAVOR, ESCOLHA UM NUMERO DE 1, 2, 3 ou 4.");
        printf("APERTE ENTER PARA VOLTAR AO MENU PRINCIPAL: ");
        getchar(); // Aguarda a entrada do Enter novamente
    }
}

void exibir_creditos() {
    int escolha;
    puts("CREDITOS\n");
    puts("ESTE PROGRAMA FOI FEITO POR USUARIOS.");
    printf("APERTE 0 E ENTER PARA VOLTA  AO MENU: ");
    scanf("%d", &escolha);
    if (escolha == 0) {
        system("cls"); // Limpa a tela
        return; // Volta ao menu principal
    }
}

int main() {
    int escolha;

    puts("** BEM VINDO AO MUSEU MILTITEMATICO **\n");

    while (1) {
        puts("\n **ESCOLHA UMA OPCAO ABAIXO:**\n");
        puts("1 - VER UM POUCO SOBRE A EXPOSICAO\n");
        puts("2 - COMPRA DE INGRESSOS\n");
        puts("3 - VERIFICAR TOTAL DE INGRESSOS VENDIDOS\n");
        puts("4 - SAIR DO PROGRAMA\n");
        puts("5 - EXIBIR CREDITOS\n");

        printf("ESOLHA UMA OPCAO ACIMA PARA CONTINUAR: ");
        scanf("%d", &escolha);

        system("cls");

        switch (escolha) {
            case 1:
                museu();
                break;
            case 2:
                comprar_ingresso();
                break;
            case 3:
                system("cls"); // Limpa a tela
                break;
            case 4:
                puts("OBRIGADO POR ESCOLHER NOSSO MUSEU ");
                exit(0);
            case 5:
                exibir_creditos();
                break;
            default:
                getchar(); // Aguarda a entrada do Enter
                system("cls"); // Limpa a tela
                puts("OPCAO INVALIDA POR FAVOR SELECIONE UM NUMERO DA LISTA.");
                printf("APERTE ENTER PARA VOLTA AO MENU: ");
                getchar(); // Aguarda a entrada do Enter novamente
                break;
        }
    }

    return 0;
}
