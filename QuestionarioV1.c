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
    printf("\n"); // Linha em branco apos mostrar a resposta certa
}

int main() {
    char resposta;
    int pontuacao = 0;
    printf("Bem-vindo ao Quiz! Responda as perguntas a seguir:\n");
    printf("Insira seu codigo para iniciar: ");
    char codigo[100];
    scanf("%s", codigo);

    fazerPergunta("Qual cidade brasileira sediou a Semana de Arte Moderna de 1922?", "Rio de Janeiro", "Belo Horizonte", "Sao Paulo", 'c', &pontuacao);

    fazerPergunta("Quem foi um dos principais organizadores da Semana de Arte Moderna de 1922?", "Vinicius de Moraes", "Tarsila do Amaral", "Mario de Andrade", 'c', &pontuacao);

    fazerPergunta("Qual movimento artistico influenciou fortemente a Semana de Arte Moderna de 1922?", "Renascimento", "Vanguarda Europeia", "Romantismo", 'b', &pontuacao);

    fazerPergunta("Qual e o ano em que a Semana de Arte Moderna de 1922 comemorou seu centenario?", "2022", "2021", "2020", 'a', &pontuacao);

    printf("Pontuacao Final: %d de 4.\n\n", pontuacao);

    printf("Obrigado por participar do questionario. Agora, com base na sua visita, qual o seu nivel de satisfacao?\n");
    printf("A) 10\nB) 5\nC) 0\nD) PREFIRO NAO INFORMAR\n");
    printf("Resposta: ");
    char nivelSatisfacao;
    scanf(" %c", &nivelSatisfacao);

    printf("Esperamos que tenha aproveitado sua visita, volte sempre!!\n");

    return 0;
}
