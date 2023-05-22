#include <stdio.h>

#define SIZE 3

char board[SIZE][SIZE];

void initializeBoard() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard() {
    int i;
    printf("\n");
    for (i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != SIZE - 1) {
            printf("\n---|---|---\n");
        }
    }
    printf("\n");
}

int isBoardFull() {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0; // Board is not full
            }
        }
    }
    return 1; // Board is full
}

int isWinner(char symbol) {
    int i;

    // Check rows
    for (i = 0; i < SIZE; i++) {
        if (board[i][0] == symbol && board[i][1] == symbol && board[i][2] == symbol) {
            return 1; // Row match
        }
    }

    // Check columns
    for (i = 0; i < SIZE; i++) {
        if (board[0][i] == symbol && board[1][i] == symbol && board[2][i] == symbol) {
            return 1; // Column match
        }
    }

    // Check diagonals
    if (board[0][0] == symbol && board[1][1] == symbol && board[2][2] == symbol) {
        return 1; // Diagonal match (top-left to bottom-right)
    }

    if (board[0][2] == symbol && board[1][1] == symbol && board[2][0] == symbol) {
        return 1; // Diagonal match (top-right to bottom-left)
    }

    return 0; // No match
}

int isValidMove(int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return 0; // Move is out of bounds
    }

    if (board[row][col] != ' ') {
        return 0; // Cell is already occupied
    }

    return 1; // Valid move
}

void makeMove(char symbol, int row, int col) {
    board[row][col] = symbol;
}

int main() {
    int row, col;
    char currentPlayer = 'X';
    int gameOver = 0;

    initializeBoard();

    printf("Bem-vindo ao Jogo da Velha!\n\n");

    while (!gameOver) {
        displayBoard();

        printf("Jogador %c, faça sua jogada (linha [0-2] coluna [0-2]): ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (isValidMove(row, col)) {
            makeMove(currentPlayer, row, col);

            if (isWinner(currentPlayer)) {
                displayBoard();
                printf("Parabéns! Jogador %c venceu!\n", currentPlayer);
                gameOver = 1;
            } else if (isBoardFull()) {
                displayBoard();
                printf("Empate! O jogo terminou sem vencedores.\n");
                gameOver = 1;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        } else {
            printf("Movimento inválido. Tente novamente.\n");
        }
    }

    return 0;
}
