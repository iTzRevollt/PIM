#include <stdio.h>
#include <ctype.h>

// Funcao para fazer uma pergunta e verificar a resposta
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
    printf("\n"); // Linha em branco apos mostrar a resposta certa
}

int main() {
    char resposta;
    int pontuacao = 0;
    printf("Bem-vindo ao Quiz! Responda as perguntas a seguir:\n");
    printf("Insira seu codigo para iniciar: ");
    char codigo[100];
    scanf("%s", codigo);

    // Perguntas sobre "100 ANOS DA SEMANA MODERNA"
    fazerPergunta("Qual cidade brasileira sediou a Semana de Arte Moderna de 1922?", "Rio de Janeiro", "Belo Horizonte", "Sao Paulo", 'c', &pontuacao);

    // Perguntas sobre "100 ANOS DA SEMANA MODERNA"
    fazerPergunta("Quem foi um dos principais organizadores da Semana de Arte Moderna de 1922?", "Vinicius de Moraes", "Tarsila do Amaral", "Mario de Andrade", 'c', &pontuacao);

    // Perguntas sobre "100 ANOS DA SEMANA MODERNA"
    fazerPergunta("Qual movimento artistico influenciou fortemente a Semana de Arte Moderna de 1922?", "Renascimento", "Vanguarda Europeia", "Romantismo", 'b', &pontuacao);

    // Perguntas sobre "100 ANOS DA SEMANA MODERNA"
    fazerPergunta("Qual e o ano em que a Semana de Arte Moderna de 1922 comemorou seu centenario?", "2022", "2021", "2020", 'a', &pontuacao);

    // Exibir pontuacao final
    printf("Pontuacao Final: %d de 4.\n\n", pontuacao);

    // Pesquisa de satisfacao
    printf("Obrigado por participar do questionario. Agora, com base na sua visita, qual o seu nivel de satisfacao?\n");
    printf("A) 10\nB) 5\nC) 0\nD) PREFIRO NAO INFORMAR\n");
    printf("Resposta: ");
    char nivelSatisfacao;
    scanf(" %c", &nivelSatisfacao);

    // Mensagem de encerramento
    printf("Esperamos que tenha aproveitado sua visita, volte sempre!!\n");

    return 0;
}

// Agora, vamos criar o arquivo CSV
    FILE* arquivoCSV = fopen("quiz sobre a semana de arte moderna.csv", "a");
    if (arquivoCSV == NULL) {
        printf("Erro ao criar o arquivo CSV de avaliacoes.\n");
        return 1;
    }
{
    fprintf(arquivoCSV, "Codigo, Pontuacao, Satisfacao\n");
    fprintf(arquivoCSV, "%s, %d, %c\n", codigo, pontuacao, nivelSatisfacao);

    fclose(arquivoCSV);

    printf("Esperamos que tenha aproveitado sua visita, volte sempre!!\n");

    return 0;

}