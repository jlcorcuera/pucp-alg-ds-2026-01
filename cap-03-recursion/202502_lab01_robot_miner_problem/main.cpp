#include <iomanip>
#include <iostream>

using namespace std;

const int N = 6;
const int M = 11;

void init_board(int board[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[i][j] = -1;
        }
    }
}

void print_board(int board[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(4);
            if (board[i][j] == -1) {
                cout << ".";
            } else if (board[i][j] == 0) {
                cout << "*";
            } else {
                cout << board[i][j];
            }
        }
        cout << endl;
    }
}

bool solve(int board[N][M], int row, int col, int level) {
    if (row < 0 || row >= N || col < 0 || col >= M || board[row][col] != -1) {
        return false;
    }
    board[row][col] = level;

    if (col == M - 1) {
        if (row > 0) {
            solve(board, row - 1, 0, level + 1);
            return true;
        }
    }

    if (solve(board, row + 1, col, level)) {
        return true;
    }
    if (solve(board, row, col + 1, level)) {
        return true;
    }
    if (solve(board, row - 1, col, level)) {
        return true;
    }

    board[row][col] = -1;
    return false;
}

int main() {
    int board[N][M];
    int initial_level = 1;
    init_board(board);
    board[N - 3][10] = 0;
    board[N - 2][10] = 0;
    board[N - 1][10] = 0;
    /*
        board[N - 3][5] = 0;
        board[N - 2][5] = 0;
        board[N - 1][5] = 0;
    */
    cout << "Initial state: " << endl;
    print_board(board);
    solve(board, N - 1, 0, initial_level);
    cout << "Final state: " << endl;
    print_board(board);
    return 0;
}
