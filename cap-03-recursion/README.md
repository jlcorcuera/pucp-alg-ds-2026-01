# Chapter 3: Recursion

Recursion is a fundamental algorithmic technique where a function calls itself to solve a smaller instance of the same problem. This approach is highly intuitive for problems that possess a recursive structure, such as traversing trees, generating permutations, or evaluating mathematical recurrence relations. A correct recursive algorithm must always define one or more base cases to terminate the execution and prevent infinite loops. While recursion provides elegant and concise code, it is important to understand its underlying mechanics, including call stack behavior and potential memory overhead, as excessive recursion depth can lead to stack overflow errors.

## 📌 Core Concepts
* **Definition:** An object is considered recursive if it can be defined in terms of itself. In programming, recursion is highly useful when the solution to a problem can be formulated by solving a smaller instance of the exact same problem.
* **Local Scope:** The variables and parameters defined within a recursive function are strictly local. Even if variables share the same name across different recursive calls, they contain distinct values and are not transmitted between calls.

## ⚙️ Essential Components of a Recursive Function
To function correctly and avoid running infinitely, every recursive algorithm must contain a condition that determines whether to continue or stop. This is broken down into two parts:
1. **The Base Case:** The condition that halts the recursion and ensures the program eventually terminates. 
2. **The Recursive Case:** The condition where the function calls itself using a smaller instance of the original problem. 

## 💡 Best Practices and Considerations
* **When to use recursion:** Recursion should primarily be used when the problem itself is defined recursively, as it provides the best option in terms of code clarity.
* **Recursion vs. Iteration:** Any recursive algorithm can theoretically be implemented iteratively, and most iterative algorithms can be made recursive. However, it is important to note that recursive algorithms are generally slower than iterative ones.

## 📚 Classic Examples
The lecture slides demonstrate recursion through several classic computing problems:
* **Factorial Calculation ($n!$):** Defines a base case of $0! = 1$ and a recursive case of $n \times (n-1)!$.
* **Fibonacci Sequence:** Calculates the $n$-th number by adding the two preceding numbers, using base cases for the first and second terms.
* **Towers of Hanoi:** A puzzle that involves moving a stack of differently sized disks across three rods. The recursive solution dictates that you can only move one disk at a time and can never place a larger disk on top of a smaller one. 
* **Other Operations:** Recursion can also be used to find the maximum number in an array, search for a specific number in an array, or convert a base-10 number to base-2.

---

## 📋 Table of Problems

| Problem Name | Description |
|---|---|
| [1. Maximum in Array](#1-maximum-in-array) | Find the maximum number in an array of N integers. |
| [2. Maximum in Matrix](#2-maximum-in-matrix) | Find the maximum number in a matrix of N x M integers. |
| [3. Base 10 to Base 2](#3-base-10-to-base-2) | Print a base-10 number in base-2. |
| [4. Triangle Pattern](#4-triangle-pattern) | Generate an asterisk pattern based on two bounds. |

---

## 📝 Problem Descriptions

### 1. Maximum in Array
Implement a recursive function to find the maximum number in an array of $N$ integers.

* **Recursive Strategy:** The problem can be divided into a smaller subproblem by comparing the current element of the array against the maximum of the rest of the array. The base case is reached when targeting the last remaining element, which is returned as the maximum by default.

**[Source Code](./max_element_in_array)**

### 2. Maximum in Matrix
Implement a recursive function to find the maximum number in a matrix of $N \times M$ integers.

* **Recursive Strategy:** Similar to a 1D array, you can virtually flatten the matrix and use a single index that increments up to $N \times M - 1$. The maximum is found by comparing the current cell's value with the recursively obtained maximum of the remaining cells. The base case occurs when returning the final cell.

**[Source Code](./max_element_in_matrix)**

### 3. Base 10 to Base 2
Implement a recursive function that takes a base-10 number as its only parameter and prints it in base-2.

* **Recursive Strategy:** The base-2 representation involves continuously dividing the number by 2 and extracting the remainders. By making the recursive call with the quotient (`n / 2`) *before* printing the remainder (`n % 2`), the call stack naturally reverses the output, ensuring the binary sequence is printed in the correct, most-significant-bit-first order. The base case is when the number becomes 0.

**[Source Code](./base10_2_base2)**

### 4. Triangle Pattern
Implement a recursive function with the following signature: `triangle(int a, int b)`. This function should generate a pattern like the following:

```text
* * *
* * * *
* * * * *
* * * * *
* * * *
* * *
```

The pattern described above is generated by calling `triangle(3, 5)`.

* **Recursive Strategy:** This algorithm creatively leverages the call stack's LIFO (Last-In-First-Out) behavior. A single recursive function prints a line of `a` asterisks, then recursively calls itself with `a + 1` (stopping when `a > b`), and *after* the recursive call completes, it prints the line of `a` asterisks a second time. The first print executes on the way "down" the recursion tree to build the upper half, while the second print executes on the way "up" (as functions return) to generate the mirrored bottom half, completely eliminating the need for loops or a separate reversal logic.

**[Source Code](./triangle_pattern)**
