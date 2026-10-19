#include <iostream>

using namespace std;

int count_occurrences(int A[], int ini, int fin, int k) {
    if (ini < fin) {
        int med = ini + (fin - ini) / 2;
        int result = 0;
        result += count_occurrences(A, ini, med, k);
        result += count_occurrences(A, med + 1, fin, k);
        return result;
    } else if (ini == fin && A[ini] == k) {
        return 1;
    }
    return 0;
}

int main() {
    int A[] = {38, 3, 43, 3, 9, 82, 10};
    int N = sizeof(A) / sizeof(A[0]);
    int k = 3;
    int occurrences = count_occurrences(A, 0, N, k);
    cout << occurrences << endl;
    return 0;
}