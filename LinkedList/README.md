# Types of Linkedlist

> A linked list is a linear collection of data elements called nodes in which linear representation is given by links from one node to the next node. It can can be perceived as a train or a sequence of nodes in which each node contains one or more data fields and a pointer to the next node.

* [**Singly Linkedlist**](#singly-linkedlist)
* [**Circular Singly Linkedlist**](#circular-singly-linkedlist)
* [**Doubly Linkedlist**](#doubly-linkedlist)

## Singly Linkedlist

A singly linked list is a type of linked list that is unidirectional, that is, it can be traversed in only one direction from head to the last node (tail).

Each element in a linked list is called a node. A single node contains data and a pointer to the next node which helps in maintaining the structure of the list.

Node is represented as :
```
struct node {
    int data;
    struct node *next;
}
```
## Circular Singly Linkedlist

A circular linked list is a variation of a normal linked list. In a circular linked list, as the name suggests, the list does not end; instead, it loops around. The last element of a circular linked list points to the head instead of pointing to null. A circular linked list can be implemented as a singly linked list or a doubly linked list.

In this repository, I have added the code for circular linked list which is implemented using _singly linked list_.