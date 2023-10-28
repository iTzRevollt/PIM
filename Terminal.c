#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct Visitante {
    char nome[100];
    int idade;
    char codigo[6];
};

struct Exposicao {
    char nome[100];
    double preco;
    int descontoEstudante;
    int descontoCrianca;
    int descontoIdoso;
};

char* gerarCodigoAleatorio() {
    static char codigo[6];
    srand((unsigned int)time(NULL));
    sprintf(codigo, "%05d", rand() % 10000);
    return codigo;
}

void escreverCSV(struct Visitante visitantes[], int numVisitantes) {
    FILE* arquivoCSV = fopen("vendas.csv", "w");
    if (arquivoCSV == NULL) {
        printf("Erro ao criar o arquivo CSV de vendas.\n");
        return;
    }

    fprintf(arquivoCSV, "Nome,Idade,Codigo\n");
    for (int i = 0; i < numVisitantes; i++) {
        fprintf(arquivoCSV, "%s,%d,%s\n", visitantes[i].nome, visitantes[i].idade, visitantes[i].codigo);
    }

    fclose(arquivoCSV);
}

int main() {
    srand((unsigned int)time(NULL));

    struct Visitante visitantes[100];
    struct Exposicao exposicoes[100];

    int numVisitantes = 0;

    struct Visitante novoVisitante;
    novoVisitante.nome[0] = '\0';
    novoVisitante.idade = 0;
    novoVisitante.codigo[0] = '\0';

    strcpy(exposicoes[0].nome, "Exposicao 1");
    exposicoes[0].preco = 25.0;
    exposicoes[0].descontoEstudante = 1;
    exposicoes[0].descontoCrianca = 0;
    exposicoes[0].descontoIdoso = 1;

    strcpy(exposicoes[1].nome, "Exposicao 2");
    exposicoes[1].preco = 25.0;
    exposicoes[1].descontoEstudante = 1;
    exposicoes[1].descontoCrianca = 0;
    exposicoes[1].descontoIdoso = 0;

    strcpy(exposicoes[2].nome, "Exposicao 3");
    exposicoes[2].preco = 25.0;
    exposicoes[2].descontoEstudante = 1;
    exposicoes[2].descontoCrianca = 1;
    exposicoes[2].descontoIdoso = 1;

    strcpy(exposicoes[3].nome, "Exposicao 4");
    exposicoes[3].preco = 25.0;
    exposicoes[3].descontoEstudante = 0;
    exposicoes[3].descontoCrianca = 1;
    exposicoes[3].descontoIdoso = 1;

    int escolha = 0;
    char nome[100];
    int idade;
    char codigo[6];

    while (escolha != 4) {
        printf("Sistema de Vendas e Registro de Visitantes\n");
        printf("Escolha uma opcao:\n");
        printf("1. Comprar ingresso\n");
        printf("2. Registrar visitante\n");
        printf("3. Finalizar compra\n");
        printf("\n");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Escolha uma exposicao para comprar ingressos:\n");
                for (int i = 0; i < 4; i++) {
                    printf("%d. %s - Preco: %.2f reais\n", i + 1, exposicoes[i].nome, exposicoes[i].preco);
                }
                printf("\n");

                int escolhaExposicao;
                scanf("%d", &escolhaExposicao);

                if (escolhaExposicao >= 1 && escolhaExposicao <= 4) {
                    struct Exposicao exposicaoEscolhida = exposicoes[escolhaExposicao - 1];
                    printf("Ingresso para %s selecionado.\n", exposicaoEscolhida.nome);
                    printf("Preco do ingresso: %.2f reais\n");
                    printf("Escolha o tipo de ingresso:\n");
                    printf("1. Inteiro\n");
                    printf("2. Meia\n");
                    printf("\n");

                    int escolhaTipoIngresso;
                    scanf("%d", &escolhaTipoIngresso);

                    printf("Ingresso selecionado com sucesso.\n");
                } else {
                    printf("Escolha invalida de exposicao. Tente novamente.\n");
                }
                break;

            case 2:
                printf("Digite o nome do visitante: ");
                scanf("%s", nome);
                printf("Digite a idade do visitante: ");
                scanf("%d", &idade);
                printf("\n");
                strcpy(codigo, gerarCodigoAleatorio());
                strcpy(novoVisitante.nome, nome);
                novoVisitante.idade = idade;
                strcpy(novoVisitante.codigo, codigo);
                printf("Visitante registrado com sucesso. Codigo gerado: %s\n");
                visitantes[numVisitantes] = novoVisitante;
                numVisitantes++;
                break;

            case 3:
                printf("Finalizando compra...\n");
                break;

            case 4:
                printf("Encerrando o programa.\n");
                break;
        }
    }

    escreverCSV(visitantes, numVisitantes);

    return 0;
}
