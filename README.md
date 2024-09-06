# Standard Template Library in c

This library provides a collection of common data structures and algorithms implemented in C, allowing you to easily integrate them into your projects. With a focus on flexibility, you can use these data structures with any data type. Whether you're building complex systems or working on small projects, the library includes efficient implementations for stacks, queues, priority queues, linked lists, binary search trees, unordered maps, and key algorithms like sorting and searching.
<br/>
<br/>

## Table Of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Data Structures](#data-structures)
  - [Stack](#stack)
  - [Queue](#queue)
  - [Priority Queue](#priority-queue)
  - [Linked List](#linked-list)
  - [Binary Search Tree](#binary-search-tree)
  - [Unordered Map](#unordered-map)
- [Algorithms](#algorithms)
  - [Searching](#searching)
  - [Sorting](#sorting)
- [Contributing](#contributing)
<br/>

## Introduction

This C library offers a collection of foundational data structures and algorithms commonly used in software development. It is designed to be flexible and efficient, allowing you to work with generic data types. The library includes essential data structures like stacks, queues, priority queues (heaps), linked lists, and unordered maps (hash maps). Additionally, it provides a wide range of algorithms, including various sorting techniques and search methods.

By focusing on modularity and performance, the library enables developers to implement efficient solutions to complex problems. Whether you're handling dynamic collections of data, searching through data sets, or performing complex sorting operations, this library provides well-tested and optimized implementations to help streamline development. The library is well-suited for students, hobbyists, and professionals working on systems-level programming or other C-based applications.
<br/>
<br/>

## Features

- ***Comprehensive Data Structures:*** The library includes generic implementations of common data structures like stack, queue, priority queue (heap), linked list, and unordered map (hash map). Each data structure provides essential operations for inserting, deleting, searching, and retrieving data.

- ***Efficient Algorithms:*** The library offers a variety of sorting algorithms, such as bubble sort, quick sort, merge sort, and insertion sort, along with searching algorithms like linear search and binary search. These algorithms are optimized for performance and designed to handle different types of data.

- ***Dynamic Memory Management:*** The data structures dynamically resize based on the number of elements stored. Whether it's a stack, queue, or priority queue, the library efficiently manages memory by expanding or shrinking the internal storage as required.

- ***Function Pointers for Customization:*** Sorting algorithms and priority queues allow users to pass custom comparison functions, making it easy to switch between different criteria (e.g., ascending vs. descending order) without changing the underlying logic.

- ***Modular and Easy to Integrate:*** The library is modular, with each data structure and algorithm implemented in a separate file. This makes it simple to include only the components you need for your project while maintaining clean and organized code.
<br/>

## Getting Started

  ### Prerequisites

  Before using this library, you'll need to have a C development environment set up on your       system.

  ### Installation

  1. **Clone the repository:**
     
     ```
     https://github.com/dharuv26/STL_Library.git
     cd STL_Library
     ```
  2. **Use in Your Project:<br/>**
     
     Link the library to your project by including the header files and linking to the static ``lib_stl.a`` library file. Make sure to include the relevant headers for the data structures and algorithms or include ``stl.h`` for your use.

3. **Compile Code**
    
   Compile the code using the following command:
   ```
    gcc your_program.c -L. -lib_stl.a -o your_program
   ```
<br/>

## Usage

1. Initialize the Data Structure:

   - For a stack: `stack* s = createStack();`
   - For a queue: `queue* q = createQueue();`
   - For a priority queue: `priority_queue* pq = createPriorityQueue(10, maxCmp);`
   - For a Binary Search Tree: `BST* bst = createBST(10);`
   - For a linked list: `linked_list* list = createLinkedList();`
   - For an unordered map: `unordered_map* map = createMap();`
  
2. Use the Data Structures:
   
   - Insert elements, retrieve top values, remove values, and perform various operations as documented in the respective header files.

3. Clean up:

   - When done, make sure to free the dynamically allocated memory, e.g., mpdeleteStack(s);, deleteQueue(q);, deletePriorityQueue(pq);, etc.

<br/>

## Data Structures

  ### Stack
  A stack is a LIFO (Last In First Out) data structure. This implementation includes the following main operations:

  - `spush(stack* s, void* data)`: Pushes data onto the stack.
  - `spop(stack* s)`: Pops the top element from the stack.
  - `stop(stack* s)`: Returns the top element without removing it.
  - `sisEmpty(stack* s)`: Checks if the stack is empty.

  ### Queue
  A queue is a FIFO (First In First Out) data structure. The implementation includes:

  - `qpush(queue* q, void* data)`: Adds an element to the back of the queue.
  - `qpop(queue* q)`: Removes an element from the front of the queue.
  - `qfront(queue* q)`: Returns the front element without removing it.
  - `qisEmpty(queue* q)`: Checks if the queue is empty.

  ### Priority Queue 
  A priority queue is implemented using a heap and allows for custom comparison functions. Main operations include:

  - `pqpush(priority_queue* pq, int data)`: Adds an element based on priority.
  - `pqpop(priority_queue* pq)`: Removes the highest/lowest priority element.
  - `pqtop(priority_queue* pq)`: Returns the highest/lowest priority element.
  - `pqisEmpty(priority_queue* pq)`: Checks if the priority queue is empty.

  ### Linked List
  A singly linked list implementation with basic operations:

  - `push_back(linked_list* list, void* data)`: Adds a new node to the end of the list.
  - `pop_back(linked_list* list, void* data)`: Removes last node from the list.
  - `getElement(linked_list* list, void* data)`: Retrieves the node at ith index.
  - `isEmpty(linked_list* list)`: Checks if the list is empty.

  ### Binary Search Tree
  A binary search tree implementation with basic operations:

  - `BST* tinsert(BST* root, int data)`: Inserts a new node with the specified data while maintaining the BST's sorted property.
  - `BST* tsearch(BST* root, int key)`: Searches the BST for a node containing the specified key.
  - `BST* tdeleteNode(BST* root, int key)`: Deletes a node with the specified key and restructures the tree to preserve its properties.
  - `void tinorderTraversal(BST* root)`: Performs an in-order traversal of the BST, visiting nodes in ascending order of their keys.

  ### Unordered Map
  An unordered map (hash map) allows for efficient key-value pair storage with average O(1) time complexity. Main operations include:

  - `mpinsert(unordered_map* map, void* key, void* value)`: Inserts a key-value pair.
  - `mpfind(unordered_map* map, void* key)`: Finds the value associated with a key.
  - `mperase(unordered_map* map, void* key)`: Removes a key-value pair.
  - `mpgetMap(unordered_map* map)`: Returns a 2D array of all key-value pairs. 
<br/>
<br/>
<br/>

## Algorithms

  ### Searching 
  - ***Linear Search:*** Find an element in an array using a linear search algorithm
  - ***Binary Search:*** Find an element in a sorted array using a binary search algorithm

  ### Sorting
  - ***Bubble Sort:*** Sort an array using the bubble sort algorithm.
  - ***Insertion Sort:*** Sort an array using the insertion sort algorithm.
  - ***Quick Sort:*** Sort an array using the quick sort algorithm.
  - ***Merge Sort:*** Sort an array using the merge sort algorithm.
<br/>

## Contributing

  Contributions are welcome! If you'd like to contribute to this project, please follow these     guidelines:

  1. Fork the repository.
  2. Create a new branch: ```git checkout -b feature/your-feature-name```.
  3. Make your changes and commit them: ```git commit -m 'New:Add some feature'```.
  4. Push to the branch: ```git push origin feature/your-feature-name```.
  5. Open a pull request to the `main` branch of this repository.
<br/>
