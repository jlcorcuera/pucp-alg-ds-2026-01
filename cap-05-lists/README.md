# Chapter 5: Lists

Lists are fundamental linear data structures that provide a flexible way to store collections of data. Unlike arrays, which have a fixed size and require contiguous memory allocation, lists—specifically linked lists—are dynamically allocated. They consist of nodes where each node contains data and a reference (or pointer) to the next node in the sequence. This structure allows for efficient insertion and deletion of elements without needing to reorganize the entire data structure, making lists highly versatile for various computational tasks.

> **Note:** The exercises in this chapter will use the `BibliotecaLista` library provided by Prof. A. Roncal for building up the lists.

> [!WARNING]
> In order to modify the content or data element that a node stores, it is required to modify the file [`ElementoLista.h`](./ListaSimplementeEnlazada/BibliotecaLista/ElementoLista.h).

## 📌 Core Concepts
* **Node:** The fundamental building block of a linked list. It contains the actual data element and a pointer/reference to the subsequent node.
* **Head (Inicio):** A pointer to the first node in the list. It is essential for traversing the list. If the head is null, the list is considered empty.
* **Dynamic Memory:** Linked lists grow and shrink dynamically as elements are added or removed, utilizing memory more efficiently than fixed-size arrays.

## ⚙️ Essential Components of a Linked List
To function correctly, a standard linked list implementation typically includes the following core operations:
1. **Construction / Destruction:** Initializing an empty list (`construir`) and properly freeing the memory of all nodes when the list is no longer needed (`destruir`).
2. **Insertion:** Adding new nodes to the list, which can be done at the beginning (`insertarAlInicio`), at the end (`insertarAlFinal`), or in a specific sorted order (`insertarEnOrden`).
3. **Traversal:** Iterating through the nodes, typically starting from the head, to perform operations such as printing (`imprimir`) or searching.
4. **Deletion:** Removing a specific node (`eliminaNodo`) and correctly re-linking the remaining nodes to maintain the list's integrity.

## 💡 Best Practices and Considerations
* **When to use lists:** Linked lists are ideal when the number of elements is unpredictable and frequent insertions or deletions are required. 
* **Lists vs. Arrays:** While linked lists excel at dynamic sizing and fast insertions/deletions (once the position is found), arrays provide faster $O(1)$ random access to elements using indices. Linked lists require sequential traversal $O(N)$ to access an element.
* **Memory Overhead:** Each node in a linked list requires extra memory to store the pointer(s) to the next (and potentially previous) node, which is not required in standard arrays.

## 📚 Classic Operations
The provided implementation demonstrates several classic linked list operations:
* **Insertion:** Examples of inserting data at the beginning, at the end, and maintaining a sorted order upon insertion.
* **Sorting:** Implementing sorting algorithms specifically designed for linked lists, which involves carefully changing pointer references without allocating new nodes or copying data.

---

## 📋 Table of Problems

| Problem Name | Description |
|---|---|
| [1. Singly Linked List Sorting](#1-singly-linked-list-sorting) | An algorithm to sort a singly linked list by changing references in C++. |

---

## 📝 Problem Descriptions

### 1. Singly Linked List Sorting
Implement a sorting algorithm for a Singly Linked List in C++. The sorting must be done by changing the node references, rather than just swapping the values they hold.

* **List Strategy:** The logic implemented in the `sortv2` function operates similarly to Selection Sort, but it re-links the existing nodes to form a sorted sequence rather than creating new ones or swapping their values. The algorithm iterates based on the list's total length. In each pass, it traverses the remaining unsorted nodes to find the node with the minimum `codigo` value, keeping track of both this node (`minPtr`) and its preceding node (`anteriorMin`). Once found, it unlinks this minimum node from the original list structure. It then appends this node to the end of a newly forming sorted list, maintaining a pointer to the head (`nueva`) and the tail (`nuevaFinal`). Finally, the list's main head pointer (`inicio`) is updated to point to this new sorted sequence.

**[Source Code](./ListaSimplementeEnlazada/main.cpp)**
