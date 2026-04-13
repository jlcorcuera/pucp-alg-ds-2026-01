#include <iostream>
#include <strings.h>

using namespace std;

const int N = 2;
const int M = 10;

int find_max_value(int numbers[N][M], int row, int col) {
    if (row == N - 1 && col == M - 1) {
        return numbers[row][col];
    } else if (col == M - 1) {
        return max(numbers[row][col], find_max_value(numbers, row + 1, 0));
    }
    return max(numbers[row][col], find_max_value(numbers, row, col + 1));
}


int main() {
    int numbers[N][M] = {
        {4, 8, -15, 15, 4, 26, 6, 8, 10, 5},
        {40, -4, 5487, 15, 4, 222, 87, 8, 10, 5},
    };
    int max_number = find_max_value(numbers, 0, 0);
    cout << "Maximum in an array " << max_number << endl;
    return 0;
}