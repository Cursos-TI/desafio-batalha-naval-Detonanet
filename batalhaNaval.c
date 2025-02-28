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

// Definições para os tipos de células do tabuleiro
#define AGUA 0
#define NAVIO 3
#define TABULEIRO 10 // Tamanho padrão do tabuleiro principal

// Definições para o tabuleiro de habilidades
#define TABULEIRO_LINHAS 3
#define TABULEIRO_COLUNAS 5

// Função para inicializar qualquer tabuleiro com água
void inicializarTabuleiro(int linhas, int colunas, int grid[linhas][colunas])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            grid[i][j] = AGUA; // Preenche o tabuleiro com água (0)
        }
    }
}

// Função para posicionar navios em um tabuleiro 10x10
void localDoNavio(int grid[TABULEIRO][TABULEIRO])
{
    // Definição das posições iniciais dos navios
    int linhaHorizontal = 6, colunaHorizontal = 0;           // Navio na horizontal
    int linhaVertical = 2, colunaVertical = 8;               // Navio na vertical
    int linhaDiagonalAumenta = 4, colunaDiagonalAumenta = 1; // Diagonal subindo
    int linhaDiagonalDiminui = 6, colunaDiagonalDiminui = 6; // Diagonal descendo

    // Navio na horizontal (6,0) → (6,1) → (6,2)
    for (int i = 0; i < NAVIO; i++)
    {
        grid[linhaHorizontal][colunaHorizontal + i] = NAVIO;
    }

    // Navio na vertical (2,8) → (3,8) → (4,8)
    for (int i = 0; i < NAVIO; i++)
    {
        grid[linhaVertical + i][colunaVertical] = NAVIO;
    }

    // Navio na diagonal subindo (4,1) → (3,2) → (2,3)
    for (int i = 0; i < NAVIO; i++)
    {
        grid[linhaDiagonalAumenta - i][colunaDiagonalAumenta + i] = NAVIO;
    }

    // Navio na diagonal descendo (6,6) → (7,5) → (8,4)
    for (int i = 0; i < NAVIO; i++)
    {
        grid[linhaDiagonalDiminui + i][colunaDiagonalDiminui - i] = NAVIO;
    }
}

// Função para criar um tabuleiro de habilidades em formato cone
void habilidadeCone(int grid[TABULEIRO_LINHAS][TABULEIRO_COLUNAS])
{
    grid[0][2] = NAVIO; 
    grid[1][1] = NAVIO;
    grid[1][2] = NAVIO;
    grid[1][3] = NAVIO; 
    grid[3][1] = NAVIO;
    grid[3][2] = NAVIO;
    grid[3][3] = NAVIO; 
    grid[2][0] = NAVIO;
    grid[2][1] = NAVIO;
    grid[2][2] = NAVIO;
    grid[2][3] = NAVIO;
    grid[2][4] = NAVIO; 
}

// Função para criar um tabuleiro de habilidades em formato cruz
void habilidadeCruz(int grid[TABULEIRO_LINHAS][TABULEIRO_COLUNAS])
{
    grid[1][2] = NAVIO; 
    grid[0][2] = NAVIO;
    grid[2][2] = NAVIO;
    grid[1][0] = NAVIO;
    grid[1][1] = NAVIO;
    grid[2][3] = NAVIO;
    grid[2][4] = NAVIO;
}

// Função para criar um tabuleiro de habilidades em formato octaedro
void habilidadeOctaedro(int grid[TABULEIRO_LINHAS][TABULEIRO_COLUNAS])
{
    grid[0][2] = NAVIO;
    grid[1][2] = NAVIO;
    grid[2][2] = NAVIO; 
    grid[1][1] = NAVIO;
    grid[1][3] = NAVIO; 
    
}

// Função para exibir qualquer tabuleiro na tela
void exibirTabuleiro(int linhas, int colunas, int grid[linhas][colunas])
{
   
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n"); // Pula linha ao terminar cada linha do tabuleiro
    }
    printf("\n");
}

int main()
{
    // Criando o tabuleiro principal (10x10)
    printf("Tabuleiro\n");
    int tabuleiro[TABULEIRO][TABULEIRO];
    inicializarTabuleiro(TABULEIRO, TABULEIRO, tabuleiro); // Inicializa com água
    localDoNavio(tabuleiro);                               // Gera os NAVIOs
    exibirTabuleiro(TABULEIRO, TABULEIRO, tabuleiro);      // Exibe o tabuleiro principal

    // Criando o tabuleiro de habilidades (5x5)
    int tabuleiroHabilidades[TABULEIRO_LINHAS][TABULEIRO_COLUNAS];

    inicializarTabuleiro(TABULEIRO_LINHAS, TABULEIRO_COLUNAS, tabuleiroHabilidades); // Inicializa com água

    // Habilidade em cone
    printf("Habilidade em Cone:\n");
    habilidadeCone(tabuleiroHabilidades);                                       // Aplica habilidade em cone
    exibirTabuleiro(TABULEIRO_LINHAS, TABULEIRO_COLUNAS, tabuleiroHabilidades); // Exibe o tabuleiro de cone

    // Habilidade em cruz
    printf("Habilidade em Cruz:\n");
    inicializarTabuleiro(TABULEIRO_LINHAS, TABULEIRO_COLUNAS, tabuleiroHabilidades); // Re-inicializa o tabuleiro
    habilidadeCruz(tabuleiroHabilidades);                                            // Aplica habilidade em cruz
    exibirTabuleiro(TABULEIRO_LINHAS, TABULEIRO_COLUNAS, tabuleiroHabilidades);      // Exibe o tabuleiro de cruz

    // Habilidade em octaedro
    printf("Habilidade em Octaedro:\n");
    inicializarTabuleiro(TABULEIRO_LINHAS, TABULEIRO_COLUNAS, tabuleiroHabilidades); // Re-inicializa o tabuleiro
    habilidadeOctaedro(tabuleiroHabilidades);                                        // Aplica habilidade em octaedro
    exibirTabuleiro(TABULEIRO_LINHAS, TABULEIRO_COLUNAS, tabuleiroHabilidades);      // Exibe o tabuleiro de octaedro

    return 0;
}


// Bom acho que e isto
// Github:  https://github.com/Cursos-TI/desafio-batalha-naval-Detonanet
