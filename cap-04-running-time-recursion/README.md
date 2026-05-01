# Chapter 4: Running Time of Recursion

This document outlines the principles for calculating the computational complexity of recursive algorithms. It provides a formal framework for understanding how recursive functions consume computational time as the input size grows, specifically by analyzing recurrence equations.

## 📌 Core Concepts
* **Recursive Algorithms (Rule 7):** A recursive algorithm solves a problem by breaking it down into simpler instances of the exact same problem. The function continuously calls itself with a reduced case until it reaches a **base case**, which is simple enough to be solved by definition without further recursion. 
* **Recurrence Equations:** To analyze the execution time of such algorithms, computer scientists use **recurrence equations**, typically denoted as `T(n)`. These equations separate the execution time into two parts:
    1. **The Base Case:** Takes a constant time, represented as $k_1$.
    2. **The Recursive Step:** Represented by the time taken by the recursive call plus any additional operations performed during that step (e.g., $T(n-1) + k_2$).

## ⚙️ The Replacement Technique
To find the asymptotic upper bound (Big O notation) of a recurrence equation, the text demonstrates the **replacement technique**. This involves iteratively substituting the recursive term with its own definition to discover a recognizable mathematical pattern or series. By evaluating the pattern until reaching the base case, the total computational complexity can be deduced.

## 📚 Complexity Classes and Examples
The material provides three distinct algorithmic examples to demonstrate how different recursive structures lead to different time complexities:

### 1. Linear Complexity: $O(n)$
* **Example Scenario:** Calculating the factorial of a number recursively.
* **Mechanism:** The algorithm reduces the input `n` by 1 in each recursive step (e.g., calling `factorial(n-1)`).
* **Recurrence Equation:** $T(n) = T(n-1) + k_2$
* **Analysis:** By iteratively expanding the equation and summing both sides, the terms cancel out to reveal a linear relationship directly proportional to $n$. Adding the base case $k_1$ to $n \times k_2$ results in an $O(n)$ complexity.

### 2. Logarithmic Complexity: $O(\log n)$
* **Example Scenario:** A recursive function where the input size is halved with every call.
* **Mechanism:** The algorithm calls itself with half the input size (e.g., calling `Recursiva1(n/2)`).
* **Recurrence Equation:** $T(n) = T(n/2) + 1$
* **Analysis:** Using the replacement technique, the substitutions form a pattern corresponding to $i$ iterations. By setting $n/2^i = 1$ to reach the base case, we find that $n = 2^i$. Solving for $i$ yields $\log_2(n)$, proving that the algorithm executes in $O(\log n)$ time.

### 3. Exponential Complexity: $O(2^n)$
* **Example Scenario:** A function making two identical recursive calls for every step.
* **Mechanism:** The algorithm splits into two branches that both reduce `n` by 1 (e.g., calling `Rec3(n-1) + Rec3(n-1)`).
* **Recurrence Equation:** $T(n) = 2T(n-1) + 1$
* **Analysis:** Multiplying out and expanding this equation generates a geometric progression. Summing this progression proves that the execution time doubles with each addition to $n$ (yielding a total time of $2^n - 2$), making it an exponential upper bound of $O(2^n)$.