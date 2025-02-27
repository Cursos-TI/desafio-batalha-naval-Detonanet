/*
O que você vai fazer

1. Represente o Tabuleiro: Utilize uma matriz (array bidimensional) para representar o tabuleiro do Batalha Naval.
Neste nível novato, o tabuleiro terá um tamanho fixo 10x10. Inicialize todas as posições do tabuleiro com o valor 0, representando água.

2. Posicione os Navios: Declare e inicialize dois vetores (arrays unidimensionais) para representar os navios.
Cada navio ocupará um número fixo de posições no tabuleiro (defina esse tamanho, por exemplo, 3 posições).
Um navio será posicionado horizontalmente e o outro verticalmente.
Represente as posições ocupadas pelos navios na matriz do tabuleiro com o valor 3.
Você deverá escolher as coordenadas iniciais de cada navio e garantir que eles estejam completamente dentro dos limites do tabuleiro e não se sobreponham.
Dica: O posicionamento do navio pode ser feito copiando o valor 3 de cada posição do vetor do navio para as posições correspondentes na matriz do tabuleiro,
de acordo com a orientação (horizontal ou vertical) do navio.

3. Exiba o Tabuleiro: Utilize loops aninhados e o comando printf para exibir o tabuleiro no console.
Mostre a matriz completa, com 0s representando água e 3s representando as partes dos navios.
A saída deve ser clara e organizada, permitindo visualizar facilmente a posição dos navios.
Dica: Imprima um espaço ou outro caractere separador entre os elementos da matriz para facilitar a visualização.

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
*/

#include <stdio.h>

// Vamos criar as variaveis do agua e do navil
int agua = 0;
int navio = 3;
int tabuleiro = 10;

// Criando o tabuleiro para saber aonde iremos colocar os navios
void inicializarTabuleiro(int grid[tabuleiro][tabuleiro])
{
    for (int i = 0; i < tabuleiro; i++)
    {
        for (int j = 0; j < tabuleiro; j++)
        {
            grid[i][j] = 0; // Criando o tabuleiro sera um array grid, foi melhor para manipular ele depois 
                            // printf("(%d,%d) ", i, j); // Paara mostrar os indices da matriz
                            // printf("%d ",0);// Inicializa todas as posições como água (0), não funfionou direito
        }
       // printf("\n"); // Coloquei para pular linha mais pulou muitas linhasa por causa do loop
    }
}

// Aqui crio os navios no grid que ja tinha criado acima 
void localDoNavio(int grid[tabuleiro][tabuleiro])
{

    int linhaHorizontal = 6, colunaHorizontal = 0; // Estou definindo aonde irei ninicializar a contrução do navio horizontal

    int linhaVertical = 2, colunaVertical = 8; // Estou definindo aonde irei ninicializar a contrução do navio vertical

    // Posição do navio na horizontal
    for (int i = 0; i < navio; i++)
    {
        grid[linhaHorizontal][colunaHorizontal + i] = navio; // coloquei o  + i para ele acrecentar o numero 3 nos tres indice que eu quero
    }

    // Posição do navio na vertical
    for (int i = 0; i < navio; i++)
    {
        grid[linhaVertical + i][colunaVertical] = navio; // coloquei o  + i para ele acrecentar o numero 3 nos tres indice que eu quero
    }
}

// Aqui mostra tudo, o tabuleiro com a agua e os navios 
void exibirTabuleiro(int grid[tabuleiro][tabuleiro])
{
    printf("Tabuleiro de Batalha Naval:\n\n");// so para ficar mais bonito, coloquei o titulo 
    
    // loop aninhado
    for (int i = 0; i < tabuleiro; i++)
    {
        for (int j = 0; j < tabuleiro; j++)
        {
            printf("%d ", grid[i][j]); // exibe cada posição do tabuleiro
        }
        printf("\n"); // a cada array finalizada pula uma linha
    }
}

int main()
{

    int tabuleiro[tabuleiro][tabuleiro]; // Array com o tabuleiro do tabuleiro

    inicializarTabuleiro(tabuleiro); // Inicializa o tabuleiro

    localDoNavio(tabuleiro);

    exibirTabuleiro(tabuleiro);

    return 0;
}

// Bom acho que e isto 
// Github:  https://github.com/Cursos-TI/desafio-batalha-naval-Detonanet
