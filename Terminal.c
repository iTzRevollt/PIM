#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Definir o tamanho máximo para exposições e visitantes
#define MAX_EXPOSICOES 4
#define MAX_VISITANTES 100

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

int main() {
    srand((unsigned int)time(NULL));

    struct Visitante visitantes[MAX_VISITANTES];
    struct Exposicao exposicoes[MAX_EXPOSICOES];

    struct Visitante novoVisitante;
    novoVisitante.nome[0] = '\0';
    novoVisitante.idade = 0;
    novoVisitante.codigo[0] = '\0';

    strcpy(exposicoes[0].nome, "100 anos da semana moderna");
    exposicoes[0].preco = 25.0;
    exposicoes[0].descontoEstudante = 1;
    exposicoes[0].descontoCrianca = 0;
    exposicoes[0].descontoIdoso = 1;

    strcpy(exposicoes[1].nome, "150 anos de Santos Dumond");
    exposicoes[1].preco = 25.0;
    exposicoes[1].descontoEstudante = 1;
    exposicoes[1].descontoCrianca = 0;
    exposicoes[1].descontoIdoso = 0;

    strcpy(exposicoes[2].nome, "Jogos Olímpicos de Paris 2024");
    exposicoes[2].preco = 25.0;
    exposicoes[2].descontoEstudante = 1;
    exposicoes[2].descontoCrianca = 1;
    exposicoes[2].descontoIdoso = 1;

    strcpy(exposicoes[3].nome, "Impactos das Mudanças Climáticas");
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
        printf("Escolha uma opção:\n");
        printf("1. Comprar ingresso\n");
        printf("2. Registrar visitante\n");
        printf("3. Finalizar compra\n");
        //printf("4. Sair\n");
        printf("\n");

        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Escolha uma exposição para comprar ingressos:\n");
                for (int i = 0; i < MAX_EXPOSICOES; i++) {
                    printf("%d. %s - Preço: %.2f reais\n", i + 1, exposicoes[i].nome, exposicoes[i].preco);
                }
                printf("\n");

                int escolhaExposicao;
                scanf("%d", &escolhaExposicao);

                if (escolhaExposicao >= 1 && escolhaExposicao <= MAX_EXPOSICOES) {
                    struct Exposicao exposicaoEscolhida = exposicoes[escolhaExposicao - 1];
                    printf("Ingresso para %s selecionado.\n", exposicaoEscolhida.nome);
                    printf("Preço do ingresso: %.2f reais\n", exposicaoEscolhida.preco);
                    printf("Escolha o tipo de ingresso:\n");
                    printf("1. Inteiro\n");
                    printf("2. Meia\n");
                    printf("\n");

                    int escolhaTipoIngresso;
                    scanf("%d", &escolhaTipoIngresso);

                    printf("Ingresso selecionado com sucesso.\n");
                } else {
                    printf("Escolha inválida de exposição. Tente novamente.\n");
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
                printf("Visitante registrado com sucesso. Código gerado: %s\n", codigo);
                break;

            case 3:
                printf("Finalizando compra...\n");
                break;

            case 4:
                printf("Encerrando o programa.\n");
                break;
        }
    }

    return 0;
}
