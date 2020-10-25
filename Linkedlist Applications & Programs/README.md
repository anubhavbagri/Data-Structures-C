# LinkedList Applications and Its Programs :computer:

> Manipal university Jaipur Data Structures and Algorithms ASSIGNMENT- 2 :  October 2020

**Q1(i)** Given a list, split it into two sublists — one for the front half, and one for the
back half. If the number of elements is odd, the extra element should go in the
front list. Getting this right for all the cases is harder than it looks. You should
check your solution against a few cases (length = 2, length = 3, length=4) to make
sure that the list gets split correctly near the short-list boundary conditions. If it
works right for length=4, it probably works right for length=1000. You will probably
need special case code to deal with the (length<2) cases.
```
Input: 2-> 3-> 5-> 7-> 11 -> NULL
```
```
Output: 2 -> 3 -> 5 -> NULL
        7 -> 11 -> NULL
```
Solution :  [split.c](split.c)

**Q1.(ii)** Given a list, divide its nodes to make two smaller lists. The sublists should be
made from alternating elements in the original list. The elements in the new lists
may be in any order (for some implementations, it turns out to be convenient if they are in the reverse order from the original list.)
```
Input : a -> b -> a -> b -> a -> NULL
```
```
Output :  a -> a -> a -> NULL
          b -> b -> NULL
```
Solution :  [AlternativeSplit.c](AlternativeSplit.c)

**Q2.(i)** For a given singly linked list insert a node:
* at the beginning
* at the end
* at a given position k
```
Input : value=8, k=4
        1 -> 2 -> 5 -> 7-> 4 -> NULL
```
```
Output :
 8 -> 1 -> 2 -> 5 -> 7 -> 4 -> NULL
 1 -> 2 -> 5 -> 7 -> 4 -> 8 -> NULL
 1 -> 2 -> 5 -> 8 -> 7 -> 4 -> NULL
```
Solution :  [MenuDrivenOperation.c]()

**Q2.(ii)** For a given singly linked list delete a node:
* at the beginning
* at the end
* at a given position k
```
Input : k=3
        1 -> 2 -> 5 -> 7 -> 4 -> NULL
```
```
Output :
2 -> 5 -> 7 -> 4 -> NULL
1 -> 2 -> 5 -> 7 -> NULL
1 -> 2 -> 7 -> 4 -> NULL
```
Solution :  [MenuDrivenOperation.c]()

**Q3.(i)** Print all the elements at the index of multiples of k with the first element assumed to have an index of 0. Do this for a single pass of the linked list.
```
Input : k=3
        12 -> 15 -> 18 -> 17 -> 19 -> 20 -> 22 -> NULL
```
```
Output : 12 -> 17 -> 22 -> NULL
```
Solution :  [printMultiple.c]()

**Q3.(ii)** Extend the above solution assuming that the list is circular and the N-th index is the same as 0-th index. You may need multiple passes. However, every number should be printed only once during its first selection.

Input :
k=3

12 -> 15 -> 18 -> 17 -> 19 -> 20 -> 22 -> NULL

Output :

12 -> 17 -> 22 -> 18 -> 20 -> 15 -> 19 -> NULL

Solution :  [circularMultiple.c]()

**Q4.(i)** Remove in a linked list all the nodes that have a greater value to their right.

Input :
* 10 -> 12 -> 15 -> 20 -> 5 -> 16 -> 25 -> 8 -> NULL
* 10 -> 12 -> 15 -> 20 -> 25 -> 26 -> 30 -> 40 -> NULL
* 20 -> 18 -> 15 -> 10 -> 8 -> 6 -> 5 -> 3 -> NULL


Output :

* 20 -> 25 -> 8 -> NULL
* 40 -> NULL
* 20 -> 18 -> 15 -> 10 -> 8 -> 6 -> 5 -> 3 -> NULL

Solution :  [removeGreater.c]()

**Q4.(ii)** Perform pair-wise swapping of nodes of a given linked list.

Input :
20 -> 18 -> 15 -> 10 -> 8 -> 6 -> 5 -> 3 -> 7 -> NULL


Output :
18 -> 20 -> 10 -> 15 -> 6 -> 8 -> 3 -> 5 -> 7 -> NULL

Solution :  [pairWiseSwap.c]()

**Q5.** Given a singly linked list L0 -> L1 -> … -> Ln-1 -> Ln. Write an algorithm to rearrange the nodes in the list so that the new formed list is: L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 …

Solution :  [Rearrange Algorithm](https://gist.github.com/anubhavbagri/b450b4c3ba12927dd56e3133c31c2aa7/f690d90f6f8d4177e05f6dac7c300c5d3176a89b)