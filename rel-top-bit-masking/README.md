# Bitmasking Tutorial: Complete Search with Bits

Bitmasking is one of the most powerful and elegant techniques in competitive programming. It allows us to represent subsets using bits and perform complete search efficiently.

## Difference Between Array Terms
Understanding the distinction between these terms is crucial for choosing the right approach:

| Term | Meaning | Order Matters? |
| :--- | :--- | :---: |
| **Subarray** | A continuous part of an array. | Yes |
| **Subset** | Any combination of elements from a set. | No |
| **Subsequence** | Elements taken from an array in their original order, but not necessarily contiguous. | Yes |

## Complete Search → Iterative Approach
To iterate over all subsets of a set of size $n$, we can use integers from $0$ to $(1 \ll n) - 1$. Each bit in the integer (mask) represents whether we include a specific element or not.

### Example: Binary Representation of Subsets
Suppose we have the array: `[1, 2, 5, 9]` ($n = 4$).
Each bitmask from `0000` to `1111` (binary) represents a unique subset:

| Mask (Binary) | Decimal | Subset Example |
| :--- | :--- | :--- |
| `0000` | 0 | `{}` |
| `0001` | 1 | `{9}` |
| `0010` | 2 | `{5}` |
| `0011` | 3 | `{5, 9}` |
| `0100` | 4 | `{2}` |
| `0101` | 5 | `{2, 9}` |
| `0110` | 6 | `{2, 5}` |
| `0111` | 7 | `{2, 5, 9}` |
| `1000` | 8 | `{1}` |
| `1001` | 9 | `{1, 9}` |
| `1010` | 10 | `{1, 5}` |
| `1011` | 11 | `{1, 5, 9}` |
| `1100` | 12 | `{1, 2}` |
| `1101` | 13 | `{1, 2, 9}` |
| `1110` | 14 | `{1, 2, 5}` |
| `1111` | 15 | `{1, 2, 5, 9}` |

- **Total Subsets:** $2^n$ (represented as `1 << n`).
- **Check if element $i$ is in mask:** `(mask >> i) & 1`.

---

## Example 1: Count Subsequences with Sum = K
**Problem:** Given an array of $n$ integers and a target $K$, count how many subsequences have a sum equal to $K$.

```cpp
#include <iostream>

using namespace std;

int main() {
    // Target sum
    int k;
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
    cout << res << endl;
    return 0;
}
```
**Complexity:** $O(2^n \cdot n)$

---

## Example 2: Apple Division
**Problem:** Given $n$ apples with weights $p_1, p_2, \dots, p_n$, divide them into two groups such that the difference between the total weights of the groups is minimized.

**Algorithm:**
Every possible division of the $n$ apples into two distinct groups can be represented by a binary bitmask from $0$ to $(1 \ll n) - 1$. 
For each apple $i$:
- We look at the $i$-th bit of our current bitmask.
- If the bit is `1`, we assign the $i$-th apple to **Group 1**.
- If the bit is `0`, we assign the $i$-th apple to **Group 2**.

By iterating through all possible bitmasks, we effectively check every single combination of grouping the apples. For each combination, we calculate the absolute difference in weights between Group 1 and Group 2, keeping track of the minimum difference found.

```cpp
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
    cout << min_diff << endl;
    return 0;
}
```
**Complexity:** $O(2^n \cdot n)$

---

## Summary
- **When to use:** Bitmasking is typically feasible when $n \le 20$ or $22$.
- **Time Limits:** For $n=20$, $2^{20} \approx 10^6$ operations, which easily fits within 1 second. For $n=25$, $2^{25} \approx 3.3 \cdot 10^7$ operations, which might be close to the limit depending on the complexity of the inner loop.

---

## Source
- [Codeforces: Bitmask – Complete Search with Bits](https://codeforces.com/blog/entry/147798)
