int main(){
    printf("Desafio Batalha Naval!\n");
    #include <stdio.h>
#define N 10       // Tamanho do tabuleiro (10×10)
#define SHIP 3     // Tamanho de cada navio
#define WATER 0
#define BOAT 3

int main(void) {
    int board[N][N];
    int i, j;

    // 1. Inicializar o tabuleiro com água (0)
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            board[i][j] = WATER;
        }
    }

    // 2. Definir posições iniciais dos navios
    //    Navio horizontal: linha 2, coluna 4
    int startRowH = 2, startColH = 4;
    //    Navio vertical: linha 5, coluna 7
    int startRowV = 5, startColV = 7;

    // 3. Validar limites e sobreposição (mensagens simples)
    // Verificar se navio horizontal cabe
    if (startColH + SHIP > N) {
        printf("Erro: navio horizontal ultrapassa borda!\n");
        return 1;
    }
    // Verificar se navio vertical cabe
    if (startRowV + SHIP > N) {
        printf("Erro: navio vertical ultrapassa borda!\n");
        return 1;
    }

    // 4. Posicionar o navio horizontal
    for (i = 0; i < SHIP; i++) {
        if (board[startRowH][startColH + i] != WATER) {
            printf("Erro: sobreposição detectada (horizontal)!\n");
            return 1;
        }
        board[startRowH][startColH + i] = BOAT;
    }

    // 5. Posicionar o navio vertical
    for (i = 0; i < SHIP; i++) {
        if (board[startRowV + i][startColV] != WATER) {
            printf("Erro: sobreposição detectada (vertical)!\n");
            return 1;
        }
        board[startRowV + i][startColV] = BOAT;
    }

    // 6. Exibir o tabuleiro
    printf("  ");  // Espaço para cabeçalho de colunas
    for (j = 0; j < N; j++) {
        printf("%2d", j);
    }
    printf("\n");

    for (i = 0; i < N; i++) {
        printf("%2d", i);  // Índice de linha
        for (j = 0; j < N; j++) {
            printf(" %d", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}

