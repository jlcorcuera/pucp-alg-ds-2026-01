# Chapter 7: Queues

This chapter provides an overview of **Queues** (Colas), a fundamental abstract data type within the Algorithms and Data Structures curriculum. It outlines the core principles of queue operations and their practical applications in computational problem-solving, such as simulations and repeating sequences.

## 📌 Core Concepts
* **The FIFO Algorithm:** A queue is a linear data collection that operates strictly on the **First-In, First-Out (FIFO)** principle. This means that the first element added to the queue will be the first one to be removed. Elements enter through one end and exit through the other.
* **Real-world Analogy:** The concept is identical to waiting in a physical line, such as customers at a supermarket checkout or cars waiting at a traffic light. The first person to arrive in the line is the first to leave.
* **Strict Access:** Similar to stacks, there are no operations that allow the user to "manipulate" the middle of the queue to reorganize or remove elements from anywhere other than the front. If such access is required, a different data structure like a List should be used.

## ⚙️ Essential Components of a Queue
The implementation and dynamic management of a queue rely on a standard set of operations:
1. **Encolar (Enqueue):** Adds a new data element to the very end of the queue.
2. **Desencolar (Dequeue):** Extracts and removes the element currently situated at the front (beginning) of the queue.
3. **Primero (Front/Peek):** Examines the value of the element at the front of the queue without removing it.
4. **EsColaVacia (IsEmpty):** A boolean function to determine if the queue currently holds zero elements.
5. **Tamaño (Size):** Calculates the total count of elements currently stored in the queue.

## 💡 Best Practices and Considerations
* **Usage Constraints:** Queues are designed for scenarios where elements must be processed in the exact order they arrive. They lack mechanisms to access or modify intermediate elements. If an algorithm requires mid-collection insertions or deletions, a list is the appropriate alternative.
* **Modeling Sequences:** Queues are perfectly suited for storing sequences that need to be processed continuously and cyclically (e.g., a repeating encryption key).
* **Simulations:** In computational simulations, queues are naturally used to represent physical waiting lines and evaluate system efficiency.

## 📚 Practical Applications and Examples
To demonstrate the algorithmic utility of queues, here are two extensive practical examples:

### 1. Queues for Encryption (Repeating Keys)
*   **Scenario:** Encoding and decoding a message using a repetitive numerical key. Each number in the key dictates how many positions a character in the message should be shifted.
*   **Queue Implementation:** The key values are stored in a queue. To process each character of the message, a key value is dequeued from the front, used to shift the character, and then immediately enqueued at the back of the queue. This ensures that the key sequence repeats continuously, handling messages of any length effectively.

### 2. Ticket Sales Simulation
*   **Scenario:** A movie theater owner wants to optimize the number of cashiers to ensure that customers spend an average of less than 7 minutes waiting in line to purchase tickets.
*   **Queue Implementation:** A queue is used to represent the single line of arriving customers. The simulation models customer arrivals (e.g., every 15 seconds) and the processing time for each cashier (e.g., 120 seconds). By simulating the queue dynamics with varying numbers of cashiers, the owner can determine the exact number of cashiers needed to meet the wait time goal without over-hiring.
