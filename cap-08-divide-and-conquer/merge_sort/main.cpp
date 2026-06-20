#include <iostream>

using namespace std;

// The combine operation (Merge) using a single for loop without sentinels
void merge(int A[], int ini, int med, int fin) {
    int n1 = med - ini + 1;
    int n2 = fin - med;

    // Temporary stack-allocated arrays of exact sizes
    int L[n1];
    int R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++) {
        L[i] = A[ini + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[med + 1 + j];
    }

    // Merge the temporary arrays back into A[ini..fin] in a single loop
    int i = 0;
    int j = 0;
    for (int k = ini; k <= fin; k++) {
        // If L is not exhausted AND (R is exhausted OR L[i] <= R[j])
        if (i < n1 && (j >= n2 || L[i] <= R[j])) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
    }
}


void mergeSort(int A[], int ini, int fin) {
    if (ini < fin) {
        int med = ini + (fin - ini) / 2;
        mergeSort(A, ini, med);
        mergeSort(A, med + 1, fin);
        merge(A, ini, med, fin);
    }
}

int main() {
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int N = sizeof(A) / sizeof(A[0]);

    cout << "Original Array: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    mergeSort(A, 0, N - 1);

    cout << "Sorted Array:   ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    return 0;
}
