# Chapter 10: Binary Search Trees

A Binary Search Tree (BST) is a non-linear, hierarchical data structure that extends the standard binary tree definition. It possesses a fundamental structural property designed to ensure efficient data retrieval and manipulation: for any given node, its left child must contain a value strictly lesser than the parent's value, while its right child must contain a value strictly greater. Consequently, both left and right subtrees must also recursively satisfy these properties.

This intrinsic ordering facilitates the execution of core operations—such as search, insertion, and deletion—by leveraging the binary search method. These operations are structurally designed to maintain the tree's order while achieving an average-case time complexity of $O(\log N)$, where $N$ is the number of elements in the tree. However, it is crucial to note that the efficiency of a BST is heavily dependent on its balance; in a worst-case scenario, the tree can degrade into a linear structure, reducing the performance of these operations to $O(N)$.

### Core Operations

- **Search**: The algorithm compares the target value with the current node's information. If they do not match, the search proceeds recursively down only one of the two subtrees (left if smaller, right if greater) until the value is found or an empty node is reached.
- **Insertion**: The algorithm compares the key to be inserted with the root. If the key is greater, it traverses to the right subtree; otherwise, it traverses to the left. This process is repeated until an empty subtree is found, at which point the new element is inserted. If the key already exists within the tree, it is typically not inserted to prevent duplicates.
- **Deletion**: Removing a node requires careful handling to maintain the BST property. Three distinct cases exist:
  1. **Leaf Node**: If the node has no children, it is simply removed by redefining the parent's pointer to null.
  2. **One Child**: If the node has exactly one child, it must be substituted by its single child subtree.
  3. **Two Children**: If the node possesses both left and right children, it must be substituted by its in-order predecessor (the rightmost node in the left subtree) or its in-order successor (the leftmost node in the right subtree).

## 🛠️ Prerequisites

Before proceeding with the problems in this chapter, it is highly recommended to review the following topics:

- **[Chapter 9: Binary Trees](../cap-09-binary-trees/README.md)**: Essential pre-requisite knowledge regarding standard binary tree structures, recursive algorithms, pointers, and fundamental traversal techniques (In-order, Pre-order, Post-order).

---

## 📋 Table of Problems

*Note: The detailed problem statements for these exercises are available on the course's virtual learning platform.*

| Problem Name | Source |
|---|---|
| [Zig-Zag order traversal](#1-zig-zag-order-traversal) | Question 1, Lab 05, 2026-1 |

---

## 📝 Problem Descriptions and Algorithms

### 1. Zig-Zag order traversal
* **Algorithm Logic:** This algorithm traverses a Binary Search Tree (BST) level by level but alternates the printing direction for each level (left-to-right for the first level, right-to-left for the second, and so on). Based on the provided source code, three different iterative approaches are explored:
  - **Optimal $O(N)$ Solution**: Utilizes two Abstract Data Types (like two Stacks, or a Stack and a Queue) to manage the alternating order. It tracks the current level's nodes in one stack and pushes their children into the second stack in the appropriate direction, achieving the zigzag pattern in a single pass.
  - **$O(N \log N)$ Solution**: An alternative approach that first calculates the height of the tree and then iterates through each level sequentially, printing the nodes from left to right or right to left based on the current level.
  - **Single Queue $O(N \log N)$ Solution**: A variation of the previous approach that minimizes space by utilizing only one single Queue (one TAD) to manage the level-by-level processing.

**[Source Code](./202601_lab05_p01)**

---

## 📚 Library Reference: `ArbolBinarioBusqueda`

To facilitate the resolution of the exercises, this chapter includes a foundational C++ library implementing the Binary Search Tree Abstract Data Type (ADT). The library is structured using C-style structs to explicitly manage nodes and memory.

### Structure Definitions

The library abstracts the tree using three main structures:
- `ElementoArbolBinarioBusqueda`: Represents the payload of the tree, encapsulating an integer value (`int numero`).
- `NodoArbolBinarioBusqueda`: Represents an individual node within the tree. It contains an `ElementoArbolBinarioBusqueda` and two pointers (`izquierda` and `derecha`) pointing to its left and right children, respectively.
- `ArbolBinarioBusqueda`: A wrapper structure that holds the `raiz` (root) pointer of the BST.

### Key Functions

The library provides a comprehensive set of functions defined in `funcionesArbolBinarioBusqueda.h`:
- **Initialization & Destruction**: `construir` initializes an empty tree, while `destruirArbolBinario` safely deallocates all memory used by the nodes.
- **Core Operations**: Standard BST operations are available through `insertar` (inserts an element), `buscar` (verifies the existence of an element), and `eliminar` (removes a node handling all three deletion cases).
- **Traversals**: Functions to visit nodes systematically, including `recorrerPreOrden`, `recorrerEnOrden`, and `recorrerPostOrden`.
- **Utility Functions**: Includes functions to calculate properties of the tree such as `altura` (height), `numeroNodos` (total nodes), `numeroHojas` (number of leaf nodes), and `esEquilibrado` (balance check).

**[Source Code](./ArbolBinarioBusqueda)**
