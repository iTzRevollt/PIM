#include <stdio.h>
#include <ctype.h>

void fazerPergunta(char* pergunta, char* opcaoA, char* opcaoB, char* opcaoC, char resposta, int* pontuacao) {
    printf("%s\n", pergunta);
    printf("a) %s\nb) %s\nc) %s\n", opcaoA, opcaoB, opcaoC);
    printf("Resposta: ");
    char escolha;
    scanf(" %c", &escolha);
    if (escolha == resposta || escolha == toupper(resposta)) {
        (*pontuacao)++;
        printf("Parabens, voce acertou!\n");
    } else {
        printf("Que pena, voce errou.\n");
    }
    printf("\n"); // Linha em branco após mostrar a resposta certa
}

int main() {
    char resposta;
    int pontuacao = 0;
    printf("Bem-vindo ao Quiz! Responda as perguntas a seguir:\n");
    printf("Insira seu codigo para iniciar: ");
    char codigo[100];
    scanf("%s", codigo);

    // Perguntas sobre "150 ANOS DE SANTOS DUMONT"
    fazerPergunta("Qual e o nome completo do famoso aviador conhecido como Santos Dumont?", "Alberto Rodrigues Dumont", "Alberto Santos Dumont", "Alberto da Silva Dumont", 'b', &pontuacao);
    fazerPergunta("Em que ano Santos Dumont nasceu?", "1872", "1873", "1874", 'a', &pontuacao);
    fazerPergunta("Qual foi a principal invencao de Santos Dumont que o tornou famoso mundialmente?", "O aviao 14-bis", "O dirigivel Zeppelin", "O submarino", 'a', &pontuacao);
    fazerPergunta("Em que cidade brasileira Santos Dumont nasceu?", "Belo Horizonte", "Sao Paulo", "Petropolis", 'c', &pontuacao);

    printf("Pontuacao Final: %d de 4.\n\n", pontuacao);

    printf("Obrigado por participar do questionario. Agora, com base na sua visita, qual o seu nivel de satisfacao?\n");
    printf("A)10\nB)5\nC)0\nD)PREFIRO NAO INFORMAR\n");
    printf("Resposta: ");
    char nivelSatisfacao;
    scanf(" %c", &nivelSatisfacao);

    // Agora, vamos criar o arquivo CSV
    FILE* arquivoCSV = fopen("quiz 150 anos santos dumond.csv", "a");
    if (arquivoCSV == NULL) {
        printf("Erro ao criar o arquivo CSV de avaliações.\n");
        return 1;
    }

    fprintf(arquivoCSV, "Codigo, Pontuacao, Satisfacao\n");
    fprintf(arquivoCSV, "%s, %d, %c\n", codigo, pontuacao, nivelSatisfacao);
    
    fclose(arquivoCSV);

    printf("Esperamos que tenha aproveitado sua visita, volte sempre!!\n");

    return 0;
}