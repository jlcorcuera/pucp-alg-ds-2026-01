#include <iostream>

using namespace std;

int binarySearch(int A[], int ini, int fin, int key) {
    if (ini > fin) {
        return -1;
    }

    int med = ini + (fin - ini) / 2;

    if (A[med] == key) {
        return med;
    }

    if (A[med] < key) {
        return binarySearch(A, med + 1, fin, key);
    }

    return binarySearch(A, ini, med - 1, key);
}

int main() {
    int A[] = {3, 9, 10, 27, 38, 43, 82};
    int N = sizeof(A) / sizeof(A[0]);

    cout << "Array: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    int key = 10;
    int index = binarySearch(A, 0, N - 1, key);

    if (index != -1) {
        cout << "Key " << key << " found at index " << index << endl;
    } else {
        cout << "Key " << key << " not found" << endl;
    }

    return 0;
}
