#include <iostream>

using namespace std;

const int N = 10;

int find_max_value(int numbers[N], int index) {
    if (index == N - 1) {
        return numbers[index];
    }
    return max(numbers[index], find_max_value(numbers, index + 1));
}


int main() {
    int numbers[N] = {4, 8, -15, 15, 4, 26, 6, 8, 10, 5};
    int max_number = find_max_value(numbers, 0);
    cout << "Maximum in an array " << max_number << endl;
    return 0;
}