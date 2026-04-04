#include <iostream>

using namespace std;

int main() {
    // Target sum
    int k;
    cout << "Enter target sum k: ";
    cin >> k;
    
    // Array of 4 elements matching our example
    int n = 4;
    int a[] = {1, 2, 5, 9};

    int res = 0;
    // Iterate through all 2^n possible subsets
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            // If the i-th bit is set, include a[i] in the sum
            if ((mask >> i) & 1) {
                sum += a[i];
            }
        }
        if (sum == k) ++res;
    }
    cout << "Number of subsequences with sum " << k << " is: " << res << endl;
    return 0;
}
