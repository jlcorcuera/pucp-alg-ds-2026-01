# Chapter 6: Stacks

This chapter provides an overview of **Stacks** (Pilas), a fundamental abstract data type within the Algorithms and Data Structures curriculum. It outlines the core principles of stack operations, their relationship with recursive programming, and their practical applications in computational problem-solving.

## 📌 Core Concepts
* **The LIFO Algorithm:** A stack is a linear data collection that operates strictly on the **Last-In, First-Out (LIFO)** principle. This means that the most recently added element is always the first one to be removed. This concept can be understood using intuitive real-world analogies, such as a stack of plates or cafeteria trays, emphasizing that one cannot easily extract items from the bottom without first removing the items resting on top.
* **Specialization:** Because of this strict access pattern, stacks are highly specialized. If an algorithm requires access to elements located in the middle or at the bottom of a collection, a stack is not the appropriate data structure to use.

## ⚙️ Essential Components of a Stack
The implementation and dynamic management of a stack rely on a standard set of operations:
1. **Apilar (Push):** Adds a new data element to the very top of the stack.
2. **Desapilar (Pop):** Extracts and removes the element currently situated at the top of the stack.
3. **Cima (Top/Peek):** Examines the value of the top element without removing it from the data structure.
4. **EsPilaVacia (IsEmpty):** A boolean function to determine if the stack currently holds zero elements.
5. **Tamaño (Size):** Calculates the total count of elements currently stored in the stack.

## 💡 Best Practices and Considerations
* **Relationship with Recursion:** There is a critical architectural relationship between stacks and recursion. Because standard recursive function calls are naturally managed by a computer's system execution stack, any recursive algorithm can be mathematically and logically translated into a non-recursive (iterative) program. Instead of relying on the system's memory to track recursive layers, the programmer can explicitly create a custom stack to store relevant data states and manually handle the control flow.

## 📚 Practical Applications and Examples
To demonstrate the algorithmic utility of stacks, here are two extensive practical examples:

### 1. Evaluating Postfix (Reverse Polish) Expressions
*   **Scenario:** Calculating arithmetic expressions where operators appear after their operands (e.g., evaluating `AB* CD/-`). This notation is advantageous because it entirely avoids the need for parentheses to dictate order of operations.
*   **Stack Implementation:** The algorithm reads the expression character by character. If it reads an operand (a number), it pushes it onto the stack. When it reads an operator (like `+` or `*`), it pops the necessary operands from the top of the stack, performs the calculation, and immediately pushes the resulting value back onto the stack. This cycle continues until the expression ends, at which point the final remaining value is popped as the total result.

### 2. Maze Traversal and Backtracking
*   **Scenario:** Finding a valid path through a two-dimensional grid from the top-left to the bottom-right corner. In this matrix, a '1' represents a free space and a '0' represents an impassable wall.
*   **Stack Implementation:** The algorithm explores the grid by identifying all valid adjacent moves (spaces marked '1') and pushing those coordinates onto the stack. It then pops the top move to physically advance to that cell, marking the traversed path. 
*   **Handling Dead Ends:** If the algorithm hits a dead end where there are no valid forward moves, the stack proves its worth. Because unexplored valid moves were saved on the stack earlier, the algorithm can pop the most recent alternative move, effectively "backtracking" to a previous fork in the road to try a different route until the maze is solved.