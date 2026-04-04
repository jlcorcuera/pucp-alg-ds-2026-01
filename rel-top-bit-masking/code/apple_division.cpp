#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

int main() {
    int n = 5;
    // Example apple weights
    int a[] = {3, 2, 7, 4, 1}; 

    long long min_diff = LLONG_MAX;
    // Try every possible division using a bitmask
    for (int mask = 0; mask < (1 << n); ++mask) {
        long long group1_sum = 0, group2_sum = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                group1_sum += a[i];
            } else {
                group2_sum += a[i];
            }
        }
        min_diff = min(min_diff, abs(group1_sum - group2_sum));
    }
    cout << "Minimum weight difference between the two apple groups is: " << min_diff << endl;
    return 0;
}
