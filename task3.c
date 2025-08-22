#include <stdio.h>
#include <stdbool.h>

#define N 6


void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}


bool isSafe(int grid[N][N], int row, int col, int num) {
   
    for (int x = 0; x < N; x++)
        if (grid[row][x] == num)
            return false;

    
    for (int x = 0; x < N; x++)
        if (grid[x][col] == num)
            return false;

   
    int startRow = row - row % 2;
    int startCol = col - col % 3;

    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}


bool solveSudoku(int grid[N][N], int row, int col) {
    if (row == N - 1 && col == N)
        return true;

    if (col == N) {
        row++;
        col = 0;
    }

    if (grid[row][col] != 0)
        return solveSudoku(grid, row, col + 1);

    for (int num = 1; num <= N; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1))
                return true;

            grid[row][col] = 0; 
        }
    }

    return false;
}

int main() {
    int grid[N][N];

    printf("Enter the 6x6 Sudoku puzzle (use 0 for empty cells):\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    printf("\nInput Sudoku:\n");
    printGrid(grid);

    if (solveSudoku(grid, 0, 0)) {
        printf("\nSolved Sudoku:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists!\n");
    }

    return 0;
}

