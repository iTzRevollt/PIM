#include <stdio.h>

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
    char codigo[50];
    scanf("%s", codigo);

    // Perguntas sobre "IMPACTOS DAS MUDANCAS CLIMATICAS."
    fazerPergunta("Qual dos seguintes impactos das mudancas climaticas e uma ameaca direta aos recifes de coral?", "Acidificacao dos oceanos", "Aumento da produtividade agricola", "Expansao das florestas tropicais", 'a', &pontuacao);

    // Perguntas sobre "IMPACTOS DAS MUDANCAS CLIMATICAS."
    fazerPergunta("Quais sao algumas das consequencias das mudancas climaticas para a saude humana?", "Aumento da biodiversidade", "Proliferacao de doencas transmitidas por vetores", "Diminuicao da poluicao do ar", 'b', &pontuacao);

    // Perguntas sobre "IMPACTOS DAS MUDANCAS CLIMATICAS."
    fazerPergunta("O derretimento acelerado das calotas de gelo contribui para o aumento do nivel do mar. Qual e o principal impacto disso?", "Maior acesso a rotas de navegacao no Artico", "Inundacoes costeiras e perda de terras baixas", "Maior disponibilidade de agua doce potavel", 'b', &pontuacao);

    // Perguntas sobre "IMPACTOS DAS MUDANCAS CLIMATICAS."
    fazerPergunta("Que setor da economia e particularmente vulneravel as mudancas climaticas devido a eventos climaticos extremos?", "Setor de tecnologia da informacao", "Industria automobilistica", "Agricultura", 'c', &pontuacao);

    // Exibir pontuacao final
    printf("Pontuacao Final: %d de 4.\n\n", pontuacao);

    // Pesquisa de satisfacao
    printf("Obrigado por participar do questionario. Agora, com base na sua visita, qual o seu nivel de satisfacao?\n");
    printf("A) 10\nB) 5\nC) 0\nD) Prefiro nao informar\n");
    printf("Resposta: ");
    char nivelSatisfacao;
    scanf(" %c", &nivelSatisfacao);

    // Mensagem de encerramento
    printf("Esperamos que tenha aproveitado sua visita, volte sempre!!\n");

    return 0;
}
