#include <stdio.h>

// Função para fazer uma pergunta e verificar a resposta
void fazerPergunta(char* pergunta, char* opcaoA, char* opcaoB, char* opcaoC, char resposta, int* pontuacao) {
    printf("%s\n", pergunta);
    printf("a) %s\nb) %s\nc) %s\n", opcaoA, opcaoB, opcaoC);
    printf("Resposta: ");
    char escolha;
    scanf(" %c", &escolha);
    if (escolha == resposta || escolha == toupper(resposta)) {
        (*pontuacao)++;
        printf("Parabéns, você acertou!\n");
    } else {
        printf("Que pena, você errou.\n");
    }
    printf("\n"); // Linha em branco após mostrar a resposta certa
}

int main() {
    char resposta;
    int pontuacao = 0;
    printf("Bem-vindo ao Quiz! Responda as perguntas a seguir:\n");
    printf("Insira seu código para iniciar: ");
    char codigo[50];
    scanf("%s", codigo);

    // Perguntas sobre "JOGOS OLIMPICOS PARIS 2024"
    fazerPergunta("Qual é o local planejado para a cerimônia de abertura dos Jogos Olímpicos de Paris 2024?", "Estádio Parc des Princes", "Torre Eiffel", "Palácio de Versalhes", 'b', &pontuacao);

    // Perguntas sobre "JOGOS OLIMPICOS PARIS 2024"
    fazerPergunta("Em que ano os Jogos Olímpicos de Paris 2024 foram anunciados como cidade-sede?", "2017", "2016", "2018", 'a', &pontuacao);

    // Perguntas sobre "JOGOS OLIMPICOS PARIS 2024"
    fazerPergunta("Qual esporte retornará ao programa olímpico em Paris 2024, depois de ter sido retirado por alguns anos?", "Beisebol/Softbol", "Golfe", "Luta Greco-Romana", 'a', &pontuacao);

    // Perguntas sobre "JOGOS OLIMPICOS PARIS 2024"
    fazerPergunta("Qual é o mascote oficial dos Jogos Olímpicos de Paris 2024?", "Gaston o Gato", "Mirabelle a Abelha", "Pierre o Galo", 'c', &pontuacao);

    // Exibir pontuação final
    printf("Pontuação Final: %d de 4.\n\n", pontuacao);

    // Pesquisa de satisfação
    printf("Obrigado por participar do questionário. Agora, com base na sua visita, qual o seu nível de satisfação?\n");
    printf("A) 10\nB) 5\nC) 0\nD) Prefiro não informar\n");
    printf("Resposta: ");
    char nivelSatisfacao;
    scanf(" %c", &nivelSatisfacao);

    // Mensagem de encerramento
    printf("Esperamos que tenha aproveitado sua visita, volte sempre!!\n");

    return 0;
}