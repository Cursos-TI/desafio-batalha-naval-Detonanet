/*
O que você vai fazer

1.	Criar um Tabuleiro 10x10: Declare uma matriz (array bidimensional) de tamanho 10x10 para representar o tabuleiro do Batalha Naval.
Inicialize todas as posições com o valor 0, representando água.

2.	Posicionar Quatro Navios: Posicione quatro navios no tabuleiro.

1.	Dois navios devem estar posicionados horizontalmente ou verticalmente (como no nível anterior).

2.	Os outros dois navios devem ser posicionados na diagonal.
Considere que um navio diagonal ocupa posições onde a linha e a coluna aumentam ou diminuem simultaneamente
(ex: tabuleiro[i][i] ou tabuleiro[i][9-i] para um tabuleiro 10x10).

3.	Represente as posições ocupadas pelos navios com o valor 3.

4.	Escolha as coordenadas iniciais.

5.	Valide que as posições dos navios estejam dentro dos limites do tabuleiro e que eles não se sobreponham.

3.	Exibir o Tabuleiro: Utilize loops aninhados e o comando printf para exibir o tabuleiro completo no console.
A saída deve mostrar a matriz 10x10, com 0s representando água e 3s representando as partes dos navios.
Utilize espaços para alinhar a saída e facilitar a visualização do tabuleiro.
*/

/*
A saida do inicializarTabuleiro foi esta
(0,0) (0,1) (0,2) (0,3) (0,4) (0,5) (0,6) (0,7) (0,8) (0,9)
(1,0) (1,1) (1,2) (1,3) (1,4) (1,5) (1,6) (1,7) (1,8) (1,9)
(2,0) (2,1) (2,2) (2,3) (2,4) (2,5) (2,6) (2,7) (2,8) (2,9)
(3,0) (3,1) (3,2) (3,3) (3,4) (3,5) (3,6) (3,7) (3,8) (3,9)
(4,0) (4,1) (4,2) (4,3) (4,4) (4,5) (4,6) (4,7) (4,8) (4,9)
(5,0) (5,1) (5,2) (5,3) (5,4) (5,5) (5,6) (5,7) (5,8) (5,9)
(6,0) (6,1) (6,2) (6,3) (6,4) (6,5) (6,6) (6,7) (6,8) (6,9)
(7,0) (7,1) (7,2) (7,3) (7,4) (7,5) (7,6) (7,7) (7,8) (7,9)
(8,0) (8,1) (8,2) (8,3) (8,4) (8,5) (8,6) (8,7) (8,8) (8,9)
(9,0) (9,1) (9,2) (9,3) (9,4) (9,5) (9,6) (9,7) (9,8) (9,9)
Para o navil horizontal irei usar o indice 6,0 6,1 6,2
Para o navil horizontal irei usar o indice 2,8 3,8 4,8
Para o navil diagonal subindo irei usar o indice 4,1 3,2 2,3
Para o navil diagonal descendo irei usar o indice 6,6 7,5 8,4
*/

#include <stdio.h>

// Vamos criar as variaveis do AGUA e do navil
#define AGUA 0
#define NAVIO 3
#define TABULEIRO 10

// Criando o tabuleiro para saber aonde iremos colocar os NAVIOs
void inicializartabuleiro(int grid[TABULEIRO][TABULEIRO])
{
    for (int i = 0; i < TABULEIRO; i++)
    {
        for (int j = 0; j < TABULEIRO; j++)
        {
            grid[i][j] = AGUA; // Criando o TABULEIRO sera um array grid, foi melhor para manipular ele depois
                               // printf("(%d,%d) ", i, j); // Paara mostrar os indices da matriz
                               // printf("%d ",0);// Inicializa todas as posições como água (0), não funfionou direito
        }
        // printf("\n"); // Coloquei para pular linha mais pulou muitas linhasa por causa do loop
    }
}

// Aqui crio os NAVIOs no grid que ja tinha criado acima
void localDoNavio(int grid[TABULEIRO][TABULEIRO])
{

    int linhaHorizontal = 6, colunaHorizontal = 0; // Estou definindo aonde irei ninicializar a contrução do NAVIO horizontal

    int linhaVertical = 2, colunaVertical = 8; // Estou definindo aonde irei ninicializar a contrução do NAVIO vertical

    int linhaDiagonalAumenta = 4, colunaDiagonalAumenta = 1; // Estou definindo aonde irei inicializar a contrução do navio diagonal aumenta

    int linhaDiagonalDiminui = 6, colunaDiagonalDiminui = 6; // Estou definindo aonde irei inicializar a contrução do navio diagonal diminui

    // Navio na horizontal (6,0) → (6,1) → (6,2)
    for (int i = 0; i < NAVIO; i++)
    {
        grid[linhaHorizontal][colunaHorizontal + i] = NAVIO; // coloquei o  + i para ele acrecentar o numero 3 nos tres indice que eu quero
    }

    // Navio na vertical (2,8) → (3,8) → (4,8)
    for (int i = 0; i < NAVIO; i++)
    {
        grid[linhaVertical + i][colunaVertical] = NAVIO; // coloquei o  + i para ele acrecentar o numero 3 nos tres indice que eu quero
    }

    // Navio na diagonal subindo (4,1) → (3,2) → (2,3)
    for (int i = 0; i < NAVIO; i++)
    {
        grid[linhaVertical + i][colunaVertical] = NAVIO; // coloquei o  + i para ele acrecentar o numero 3 nos tres indice que eu quero
    }

    // Navio na diagonal subindo (4,1) → (3,2) → (2,3)
    for (int i = 0; i < NAVIO; i++) 
    {
        // grid[linhaVertical + i][colunaVertical] = NAVIO; // coloquei o  + i para ele acrecentar o numero 3 nos tres indice que eu quero
        grid[linhaDiagonalAumenta - i][colunaDiagonalAumenta + i] = NAVIO;
    }

    // Navio na diagonal descendo (6,6) → (7,5) → (8,4)
    for (int i = 0; i < NAVIO; i++)
    {
        // grid[linhaVertical + i][colunaVertical] = NAVIO; // coloquei o  + i para ele acrecentar o numero 3 nos tres indice que eu quero
        grid[linhaDiagonalDiminui + i][colunaDiagonalDiminui - i] = NAVIO;
    }
}

// Aqui mostra tudo, o TABULEIRO com a AGUA e os NAVIOs
void exibirTabuleiro(int grid[TABULEIRO][TABULEIRO])
{
    printf("TABULEIRO de Batalha Naval:\n\n"); // so para ficar mais bonito, coloquei o titulo

    // loop aninhado
    for (int i = 0; i < TABULEIRO; i++)
    {
        for (int j = 0; j < TABULEIRO; j++)
        {
            printf("%d ", grid[i][j]); // exibe cada posição do TABULEIRO
        }
        printf("\n"); // a cada array finalizada pula uma linha
    }
}

int main()
{

    int tabuleiro[TABULEIRO][TABULEIRO]; // Array com o TABULEIRO

    inicializartabuleiro(tabuleiro); // Inicializa o TABULEIRO

    localDoNavio(tabuleiro); // Gera os NAVIOs

    exibirTabuleiro(tabuleiro); // Mostra o TABULEIRO pronto

    return 0;
}

// Bom acho que e isto
// Github:  https://github.com/Cursos-TI/desafio-batalha-naval-Detonanet
