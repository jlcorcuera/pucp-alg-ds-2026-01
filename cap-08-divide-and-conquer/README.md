# Chapter 8: Divide and Conquer

This chapter provides a formal analysis of the **Divide and Conquer** (*Divide y Vencerás*) algorithmic paradigm—a foundational design strategy in computer science used to solve complex computational problems by recursively decomposing them into smaller, independent subproblems.

## 📌 Core Concepts
* **Historical Context:** Derived from the Latin maxim *divide et impera* (divide and rule), historically utilized as a political strategy, this approach was adapted into computer science as one of the most powerful design paradigms.
* **Decomposition Methodology:** The paradigm operates by partitioning a given problem into smaller instances of the same problem, solving those instances independently, and subsequently consolidating their individual outputs to solve the original instance.
* **The Three Phases:**
  1. **Dividir (Divide):** Partitioning the problem instance into two or more smaller subproblems of the same type.
  2. **Vencer (Conquer):** Solving the subproblems recursively. If the subproblem size is sufficiently small (the base case), it is solved directly.
  3. **Combinar (Combine):** Merging the subproblem solutions to construct the solution for the original problem.

## ⚙️ Essential Components of Divide and Conquer
To ensure algorithmic correctness and optimal complexity, any Divide and Conquer implementation must explicitly define:
1. **Base Case (Trivial Instance):** The threshold at which the subproblem size is minimal and can be resolved in constant time $O(1)$ without further recursion.
2. **Decomposition Operator:** The mechanism used to partition the input space (e.g., computing a midpoint index).
3. **Recombination Function (Synthesis):** The procedure that aggregates the subproblem solutions. The computational efficiency of this step often determines the overall asymptotic complexity of the algorithm.

## 💡 Analytical Considerations
* **Implementation Paradigms:** While Divide and Conquer algorithms are naturally expressed through recursion, they do not strictly require a recursive runtime environment. They can be formulated iteratively by manually managing a state stack, which eliminates the overhead of call stack frames at the cost of implementation complexity.
* **Asymptotic Efficiency:** Independent subproblem resolution is the key mechanism for reducing asymptotic complexity. For instance, in sorting algorithms, it facilitates the transition from a quadratic running time $O(N^2)$ to a linearized logarithmic running time $O(N \log N)$.
* **Termination Guarantee:** The decomposition step must strictly decrease the size of the input, ensuring that the parameters eventually satisfy the base case condition to prevent infinite recursion and stack overflow.

## 📚 Algorithmic Implementations and Case Studies
The paradigm is illustrated through two fundamental computer science algorithms:

### 1. Binary Search (Búsqueda Binaria)
* **Problem Statement:** Locate a target key $K$ within a monotonically sorted array $A[0..N-1]$.
* **Paradigm Application:**
  * **Divide:** Compute the midpoint index $\text{med} = \lfloor \frac{\text{ini} + \text{fin}}{2} \rfloor$ and compare the value $A[\text{med}]$ against $K$.
  * **Conquer:**
    * If $A[\text{med}] == K$, the target is found, terminating the search.
    * If $A[\text{med}] < K$, recursively restrict the search space to the right partition $A[\text{med}+1..\text{fin}]$.
    * If $A[\text{med}] > K$, recursively restrict the search space to the left partition $A[\text{ini}..\text{med}-1]$.
  * **Combine:** No recombination phase is required, as the result from the active partition is propagated directly.
* **Termination Criteria:**
  * If $K$ is present, the search boundaries converge to its index.
  * If $K$ is absent, the boundary indices cross ($\text{ini} > \text{fin}$), triggering the base case which returns a boolean `False`.

### 2. Merge Sort (Ordenación por Mezcla)
* **Problem Statement:** Sort a sequence of $N$ elements in non-decreasing order.
* **Paradigm Application:**
  * **Divide:** Partition the unsorted array into two halves at the midpoint index $\text{med} = \lfloor \frac{\text{ini} + \text{fin}}{2} \rfloor$.
  * **Conquer:** Recursively sort both sub-arrays. The base case is reached when a sub-array contains a single element ($\text{ini} == \text{fin}$), which is sorted by definition.
  * **Combine:** Recombine the sorted sub-arrays into a single sorted array.
* **The Recombination Phase (`Merge`):**
  * The primary computational complexity of the algorithm resides in the merging phase. It allocates temporary storage for copies of the two sorted sub-arrays, compares their elements sequentially, and writes them back into the main array in sorted order.
  * **Boundary Conditions:** When one sub-array is exhausted, the remaining elements of the other sub-array are copied directly.
  * **Boundary Handling:** To merge the arrays in a single loop without using sentinels, we check if each index has exceeded the boundaries of its respective temporary array inside the merge condition.

---

## 📋 Table of Problems

| Problem Name | Description |
|---|---|
| [1. Merge Sort Algorithm](#1-merge-sort-algorithm) | Implementation of the Merge Sort algorithm with a single-loop combine operation without using sentinels. |
| [2. Binary Search](#2-binary-search) | Implementation of the recursive Binary Search algorithm. |

---

## 📝 Problem Descriptions

### 1. Merge Sort Algorithm
Implement the Merge Sort algorithm in C++ where the combination/merging phase is performed in exactly one single `for` loop.

* **Divide and Conquer Strategy:** The array is partitioned at the midpoint until subproblems consist of a single element (base case). During the combine phase, temporary arrays are allocated to copy both sorted sub-arrays. By incorporating boundary checks directly into the loop condition, the merging step can compare and merge the sub-arrays back into the original array in exactly one single `for` loop, eliminating the need for sentinels, post-loop checks, or multiple loops.

**[Source Code](./merge_sort/main.cpp)**

---

### 2. Binary Search
Implement the Binary Search algorithm in C++ using a recursive divide-and-conquer strategy.

* **Divide and Conquer Strategy:** The array is partitioned at the midpoint. Depending on the comparison with the key, the search recursively proceeds in the left or right partition, or terminates. No combine phase is necessary.

**[Source Code](./binary_search/main.cpp)**
