# Chapter 2: Brute Force

Brute force is the strategy by default, a direct and intuitive problem-solving method requiring minimal reasoning by relying strictly on basic definitions. Its advantages include universal applicability across sorting, searching, string matching, and matrices, alongside a simplicity that facilitates rapid understanding, coding, and debugging. Crucially, these algorithms provide the fundamental baseline for verifying the correctness and efficiency gains of advanced techniques. Despite these merits, brute force is inherently limited by its lack of time and space efficiency; execution time becomes polynomially or exponentially prohibitive as the input size (n) increases. Consequently, while ideal for small datasets, the design of more complex alternatives is only worth the effort when the data scale renders the brute-force approach untenable.

## 🛠️ Prerequisites

Before proceeding with combinatorial exhaustive search problems in this chapter, it is highly recommended to review the following topics:

- **[Bitmasking Tutorial](../rel-top-bit-masking/README.md)**: Essential pre-requisite knowledge for generating and iterating through subsets using bit operations.

---

## 📋 Table of Problems

*Note: The problem statements for these exercises can be found on Paideia under **2026-1 ALGORITMIA Y ESTRUCTURA DE DATOS (1INF27) > Capítulo 1: Fuerza Bruta > Ejercicios**.*

| Problem Name | Source |
|---|---|
| [Security checks in a Bank entity problem](#1-security-checks-in-a-bank-entity-problem) | Question 1, Lab 01, 2025-2 |
| [DB Table assignment problem](#2-db-table-assignment-problem) | Question 1, Lab 01, 2025-1 |
| [The cookie grouping problem](#3-the-cookie-grouping-problem) | Question 1, Lab 01, 2024-2 |
| [The 8-queens problem](#4-the-8-queens-problem) | Classic Problem |

---

## 📝 Problem Descriptions and Algorithms

### 1. Security checks in a Bank entity problem
* **Algorithm Logic:** This approach uses bitmasking to generate all $2^N$ possible subsets of the security checks. The $i$-th bit of the loop integer dictates whether the $i$-th security check is selected ($1$) or excluded ($0$). The subset algorithm individually tallies and filters combinations, only printing subsets that align with the specific budget limits, minimum benefit constraints, and false negative thresholds.

**[Source Code](./security_control_checks)**

### 2. DB Table assignment problem
* **Algorithm Logic:** Because each of the $N$ tables operates by getting assigned to one of $K$ separate disjoint disks, there are exactly $K^N$ possible allocations. The algorithm iterates an integer up to $K^N-1$, extracting its base-$K$ digits (via consecutive modulus and integer division operations) to uniquely map each table to a specific disk. For every valid arrangement that respects capacity conditions, it tracks and returns the combination containing the most optimal leftover IOPS.

**[Source Code](./dba_problem)**

### 3. The cookie grouping problem
*To be develop during the lecture*

### 4. The 8-queens problem
*This is a classical problem; it consists of placing 8 queens on an 8x8 chess board without them attacking each other.*

* **Algorithm Logic:** The implemented unstructured brute-force baseline treats the entire matrix configuration as a flattened array space. It loops a bitmask integer covering all $2^{N \times N}$ board possibilities. Any subset featuring exactly $N$ bits set (precisely $N$ deployed queens) constructs a board representation and runs a validity sweep ensuring no queens threaten each other vertically, horizontally, or diagonally.

**[Source Code](./n_queens)**

