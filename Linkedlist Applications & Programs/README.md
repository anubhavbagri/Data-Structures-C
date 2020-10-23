# LinkedList Applications and Its Programs :computer:

> Manipal university Jaipur Data Structures and Algorithms ASSIGNMENT- 2 :  October 2020

**Q1(i)** Given a list, split it into two sublists — one for the front half, and one for the
back half. If the number of elements is odd, the extra element should go in the
front list. Getting this right for all the cases is harder than it looks. You should
check your solution against a few cases (length = 2, length = 3, length=4) to make
sure that the list gets split correctly near the short-list boundary conditions. If it
works right for length=4, it probably works right for length=1000. You will probably
need special case code to deal with the (length<2) cases.

_Input:_
2-> 3-> 5-> 7-> 11 -> NULL

_Output:_
2 -> 3 -> 5 -> NULL

7 -> 11 -> NULL

_Solution_ :  [split.c](split.c)

**Q1.(ii)** Given a list, divide its nodes to make two smaller lists. The sublists should be
made from alternating elements in the original list. The elements in the new lists
may be in any order (for some implementations, it turns out to be convenient if they are in the reverse order from the original list.)

_Input :_
a -> b -> a -> b -> a -> NULL

_Output :_
a -> a -> a -> NULL

b -> b -> NULL

_Solution_ :  **AlternativeSplit.c**

**Q2.(i)** For a given singly linked list insert a node:
* at the beginning
* at the end
* at a given position k

_Input :_
value=8, k=4

1 -> 2 -> 5 -> 7-> 4 -> NULL

_Output :_

* 8 -> 1 -> 2 -> 5 -> 7 -> 4 -> NULL
* 1 -> 2 -> 5 -> 7 -> 4 -> 8 -> NULL
* 1 -> 2 -> 5 -> 8 -> 7 -> 4 -> NULL

_Solution_ :  **MenuDrivenOperation.c**

**Q2.(ii)** For a given singly linked list delete a node:
* at the beginning
* at the end
* at a given position k

_Input :_
k=3

1 -> 2 -> 5 -> 7 -> 4 -> NULL

_Output :_

* 2 -> 5 -> 7 -> 4 -> NULL
* 1 -> 2 -> 5 -> 7 -> NULL
* 1 -> 2 -> 7 -> 4 -> NULL

_Solution_ :  **MenuDrivenOperation.c**

**Q3.(i)** Print all the elements at the index of multiples of k with the first element assumed to have an index of 0. Do this for a single pass of the linked list.

_Input :_
k=3

12 -> 15 -> 18 -> 17 -> 19 -> 20 -> 22 -> NULL

_Output :_

12 -> 17 -> 22 -> NULL

_Solution_ :  **printMultiple.c**

**Q3.(ii)** Extend the above solution assuming that the list is circular and the N-th index is the same as 0-th index. You may need multiple passes. However, every number should be printed only once during its first selection.

_Input :_
k=3

12 -> 15 -> 18 -> 17 -> 19 -> 20 -> 22 -> NULL

_Output :_

12 -> 17 -> 22 -> 18 -> 20 -> 15 -> 19 -> NULL

_Solution_ :  **printMultiple.c**

**Q4.(ii)** For a given singly linked list delete a node:
* at the beginning
* at the end
* at a given position k

_Input :_
k=3

1 -> 2 -> 5 -> 7 -> 4 -> NULL

_Output :_

* 2 -> 5 -> 7 -> 4 -> NULL
* 1 -> 2 -> 5 -> 7 -> NULL
* 1 -> 2 -> 7 -> 4 -> NULL

_Solution_ :  **MenuDrivenOperation.c**