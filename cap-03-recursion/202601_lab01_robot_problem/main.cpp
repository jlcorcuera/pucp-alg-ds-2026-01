#include <iostream>

using namespace std;

const int N = 10;
const int M = 10;
const int coverage = 3;

void print_matrix(char matrix[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matrix[i][j];
        }
        cout << endl;
    }
}

int solve(int x, int y, int coverage, int direction, char matrix[N][M]) {
    if (coverage == 0) {
        return 0;
    }
    int counter = matrix[x][y] == 'A' ? 1 : 0;
    matrix[x][y] = '*';
    if (direction >= 0) {
        counter = counter +
                    solve(x + 1, y, coverage - 1, 1, matrix) +
                    solve(x + 1, y-1, coverage - 1, 1, matrix)+
                    solve(x + 1, y+1, coverage - 1, 1, matrix);
    }
    if (direction <= 0) {
        counter = counter +
                solve(x - 1, y, coverage - 1, -1, matrix) +
                solve(x - 1, y - 1, coverage - 1, -1, matrix)+
                solve(x - 1, y + 1, coverage - 1, -1, matrix);
    }
    return counter;
}

int main() {
    char matrix [N][M] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'A', 'A', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', 'A', ' ', ' ', 'A', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    int x = 5, y = 5;
    solve(x, y, coverage, 0, matrix);
    print_matrix(matrix);
    return 0;
}