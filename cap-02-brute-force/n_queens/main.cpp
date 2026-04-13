#include <iostream>
#include <cmath>

using namespace std;

const int N = 5;

void init_board(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[i][j] = '.';
        }
    }
}

void print_board(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
}

int count_bits(long long num) {
    int counter = 0;
    while (num > 0) {
        if (num % 2 == 1) {
            counter = counter + 1;
        }
        num = num / 2;
    }
    return counter;
}

void populate_board(char board[N][N], long long solution) {
    int index = 0;
    while (solution > 0) {
        if (solution % 2 == 1) {
            int row = index / N;
            int column = index % N;
            board[row][column] = 'Q';
        }
        solution = solution / 2;
        index++;
    }
}

bool valid(char board[N][N], int row, int col) {
    for (int j = 0; j < N; j++) {
        if (j != col and board[row][j] == 'Q') {
            return false;
        }
    }
    for (int i = 0; i < N; i++) {
        if (i != row and board[i][col] == 'Q') {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    for (int i = row + 1, j = col - 1; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    for (int i = row + 1, j = col + 1; i < N && j < N; i++, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }
    return true;
}

bool is_valid(char board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 'Q' && !valid(board, i, j)) {
                return false;
            }
        }
    }
    return true;
}

void solve() {
    long long num_solutions = 1 << (N * N);
    //it is up to you choose how to compute the total number of combitations
    //num_solutions = pow(2, N * N);
    for (long long solution = 0; solution < num_solutions; solution++) {
        //at this point we have generated a candidate solution
        //we must verify whether there are N queens
        if (count_bits(solution) == N) {
            char board[N][N];
            init_board(board);
            populate_board(board, solution);
            if (is_valid(board)) {
                cout << "Solution found: " << endl;
                print_board(board);
            }
        }
    }

}

int main() {
    solve();
    return 0;
}