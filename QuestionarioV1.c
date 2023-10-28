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

     // Perguntas sobre "JOGOS OLIMPICOS PARIS 2024"
    fazerPergunta("Qual e o local planejado para a cerimonia de abertura dos Jogos Olimpicos de Paris 2024?", "Estadio Parc des Princes", "Torre Eiffel", "Palacio de Versalhes", 'b', &pontuacao);
    fazerPergunta("Em que ano os Jogos Olimpicos de Paris 2024 foram anunciados como cidade-sede?", "2017", "2016", "2018", 'a', &pontuacao);
    fazerPergunta("Qual esporte retornara ao programa olimpico em Paris 2024, depois de ter sido retirado por alguns anos?", "Beisebol/Softbol", "Golfe", "Luta Greco-Romana", 'a', &pontuacao);
    fazerPergunta("Qual e o mascote oficial dos Jogos Olimpicos de Paris 2024?", "Gaston o Gato", "Mirabelle a Abelha", "Pierre o Galo", 'c', &pontuacao);


    printf("Obrigado por participar do questionario. Agora, com base na sua visita, qual o seu nivel de satisfacao?\n");
    printf("A)10\nB)5\nC)0\nD)PREFIRO NAO INFORMAR\n");
    printf("Resposta: ");
    char nivelSatisfacao;
    scanf(" %c", &nivelSatisfacao);

     // Agora, vamos criar o arquivo CSV
    FILE* arquivoCSV = fopen("quiz JOGOS OLIMPICOS PARIS 2024.csv", "a");
    if (arquivoCSV == NULL) {
        printf("Erro ao criar o arquivo CSV de avaliações.\n");
        return 1;
    }

    fprintf(arquivoCSV, "Codigo, Pontuacao, Satisfacao\n");
    fprintf(arquivoCSV, "%s, %d, %c\n", codigo, pontuacao, nivelSatisfacao);
    
    fclose(arquivoCSV);

    printf("Esperamos que tenha aproveitado sua visita, volte sempre!!\n");

    return 0;