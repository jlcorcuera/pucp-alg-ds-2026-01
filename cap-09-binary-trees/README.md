# Chapter 9: Binary Trees

Unlike stacks, queues, and lists, which are linear data structures where elements are arranged sequentially one after another, a **Tree** is a non-linear, dynamic data structure where elements are organized hierarchically. 

A tree is composed of a set of **nodes** that store elements (information) and **edges** (links) that connect these nodes to each other.

### 🌳 Classification: Binary Trees
A **Binary Tree (BT)** is a specific type of tree in which any given node can have **at most two children**.

A binary tree is considered **balanced** if all its leaf nodes are situated at the same level or, at most, with a difference of one level between them.

### 🧩 Tree Terminology
- **Root**: The topmost node in the tree hierarchy.
- **Children**: Nodes located in the lower levels of the tree connected to a node in the previous level.
- **Parent**: The node directly above a given node. (Note: Each node can have only one parent and at most two children).
- **Leaf Nodes**: Nodes at the bottom of the tree that do not have any children.
- **Sub-trees**: A tree structure consisting of a node and all its descendants.
- **Height**: The maximum number of edges required to reach a leaf node from the root.

### 🛠️ Basic Operations
Standard operations for Binary Trees include:
- Create a tree
- Plant a tree (combine trees)
- Check if the tree is empty
- Traverse the tree elements
- Determine the tree's height
- Determine the right child
- Determine the left child
- Destroy/Finalize a tree

*(Note: In general binary trees, specific `insert` or `delete` methods are often not explicitly defined as they lack the ordering criteria found in Binary Search Trees).*

---

## 🚶‍♂️ Traversal Algorithms

Since a tree is not a linear structure, specialized algorithms are required to visit all its nodes. The three primary depth-first traversal methods are:

### 1. Pre-Order Traversal
1. Visit the **root** node.
2. Traverse the **left** sub-tree in pre-order.
3. Traverse the **right** sub-tree in pre-order.

### 2. In-Order Traversal
1. Traverse the **left** sub-tree in in-order.
2. Visit the **root** node.
3. Traverse the **right** sub-tree in in-order.

### 3. Post-Order Traversal
1. Traverse the **left** sub-tree in post-order.
2. Traverse the **right** sub-tree in post-order.
3. Visit the **root** node.

### 4. Breadth-First (Level-Order) Traversal
Recurse through the tree level by level, starting from the root and moving strictly from top to bottom, left to right.

---

## 📋 Table of Problems

*Note: The detailed problem statements for these exercises are available on the course's virtual learning platform.*

| Problem Name | Source |
|---|---|
| *(Problems to be added)* | *TBA* |

---

## 📝 Problem Descriptions and Algorithms

*(To be populated as exercises are developed during the lectures.)*

---

## 📚 Library Reference: `ArbolBinario`

To facilitate the resolution of the exercises, this chapter includes a foundational C++ library implementing the Binary Tree Abstract Data Type (ADT). The library is structured using C-style structs to explicitly manage nodes and memory.

### Structure Definitions

The library abstracts the tree using three main structures:
- `ElementoArbolBinario`: Represents the payload of the tree, encapsulating an integer value (`int numero`).
- `NodoArbolBinario`: Represents an individual node within the tree. It contains an `ElementoArbolBinario` and two pointers (`izquierda` and `derecha`) pointing to its left and right children, respectively.
- `ArbolBinario`: A wrapper structure that holds the `raiz` (root) pointer of the Binary Tree.

### Key Functions

The library provides a comprehensive set of functions defined in `funcionesArbolBinario.h`:
- **Initialization & Destruction**: `construir` initializes an empty tree, and `destruirArbolBinario` safely deallocates all memory used by the nodes.
- **Construction**: `plantarArbolBinario` allows building a new tree by combining a root element with existing left and right subtrees.
- **Traversals**: Functions to visit nodes systematically, including `recorrerPreOrden`, `recorrerEnOrden`, and `recorrerPostOrden`.
- **Utility Functions**: Includes functions to calculate properties of the tree such as `altura` (height), `numeroNodos` (total nodes), `numeroHojas` (number of leaf nodes), and `esEquilibrado` (balance check).

**[Source Code](./ArbolBinario)**
