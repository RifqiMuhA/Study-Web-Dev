#include <stdio.h>
#include <stdlib.h>
#include <conio.h>  // For _getch() to capture user input
#include <time.h>   // For clock and clock_t

#define WIDTH 10
#define HEIGHT 10

// Define structures for the game
typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position pos;
    char symbol;
} PacMan;

typedef struct {
    Position pos;
    char symbol;
} Ghost;

// Initialize the game board with walls, empty spaces, and a dot
void initializeBoard(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == 0 || i == HEIGHT - 1 || j == 0 || j == WIDTH - 1) {
                board[i][j] = '#'; // Wall
            } else {
                board[i][j] = '.'; // Dots
            }
        }
    }
}

// Display the current game board
void displayBoard(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Move Pac-Man based on user input
void movePacMan(PacMan *pacman, char board[HEIGHT][WIDTH], char direction) {
    Position newPos = pacman->pos;

    if (direction == 'w') newPos.y--;
    if (direction == 's') newPos.y++;
    if (direction == 'a') newPos.x--;
    if (direction == 'd') newPos.x++;

    if (board[newPos.y][newPos.x] != '#') {
        board[pacman->pos.y][pacman->pos.x] = ' ';
        pacman->pos = newPos;
        board[pacman->pos.y][pacman->pos.x] = pacman->symbol;
    }
}

// Move Ghost randomly
void moveGhost(Ghost *ghost, char board[HEIGHT][WIDTH]) {
    int direction = rand() % 4;
    Position newPos = ghost->pos;

    if (direction == 0) newPos.y--;
    if (direction == 1) newPos.y++;
    if (direction == 2) newPos.x--;
    if (direction == 3) newPos.x++;

    if (board[newPos.y][newPos.x] != '#') {
        board[ghost->pos.y][ghost->pos.x] = ' ';
        ghost->pos = newPos;
        board[ghost->pos.y][ghost->pos.x] = ghost->symbol;
    }
}

// Check for collision with the ghost
int checkCollision(PacMan *pacman, Ghost *ghost) {
    return (pacman->pos.x == ghost->pos.x && pacman->pos.y == ghost->pos.y);
}

int main() {
    char board[HEIGHT][WIDTH];
    int gameOver = 0;

    PacMan pacman = {{1, 1}, 'P'};
    Ghost ghost = {{WIDTH - 2, HEIGHT - 2}, 'G'};

    initializeBoard(board);
    board[pacman.pos.y][pacman.pos.x] = pacman.symbol;
    board[ghost.pos.y][ghost.pos.x] = ghost.symbol;

    srand(time(NULL)); // Seed for random number generation

    clock_t lastMoveTime = clock();

    while (!gameOver) {
        system("cls");
        displayBoard(board);

        if (_kbhit()) {
            char input = _getch(); // Capture user input
            movePacMan(&pacman, board, input);
        }

        // Move ghost every 2 seconds
        if ((clock() - lastMoveTime) / CLOCKS_PER_SEC >= 2) {
            moveGhost(&ghost, board);
            lastMoveTime = clock();
        }

        if (checkCollision(&pacman, &ghost)) {
            printf("Game Over! Pac-Man collided with the ghost!\n");
            gameOver = 1;
        }
    }

    return 0;
}
