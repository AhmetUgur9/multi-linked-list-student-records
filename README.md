# Multi-Linked List Student Records

This is a simple C++ project that manages student records using a multi-linked list structure.  
Each student node is connected in two separate linked lists:
- One sorted by **student ID**
- One sorted by **CGPA**

##  Features
- Add student records
- Delete student records by ID
- Print student records sorted by ID or CGPA

##  Files
- `LinkedList.h`: Abstract base class with insert, delete, and print methods.
- `multiLinkedList.h`: Implements the dual-linked list structure.
- `main.cpp`: Runs the menu-based console application.

##  Example Usage
```txt
Enter 'i' to insert student informations
Enter 's' to delete any student's information
Enter 'c' or 'd' to print all student's informations as sorted (CGPA/id)
Enter 'e' to Exit

