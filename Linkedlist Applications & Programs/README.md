# LinkedList Applications and its programs

> Manipal university Jaipur Data Structures and Algorithms ASSIGNMENT- 2 :  October 2020

Q1(i) Given a list, split it into two sublists — one for the front half, and one for the
back half. If the number of elements is odd, the extra element should go in the
front list. Getting this right for all the cases is harder than it looks. You should
check your solution against a few cases (length = 2, length = 3, length=4) to make
sure that the list gets split correctly near the short-list boundary conditions. If it
works right for length=4, it probably works right for length=1000. You will probably
need special case code to deal with the (length<2) cases.

Input:
2-> 3-> 5-> 7-> 11 -> NULL

Output:
2 -> 3 -> 5 -> NULL

7 -> 11 -> NULL

_Solution_ :  **split.c**

Q1.(ii) Given a list, divide its nodes to make two smaller lists. The sublists should be
made from alternating elements in the original list. The elements in the new lists
may be in any order (for some implementations, it turns out to be convenient if they are in the reverse order from the original list.)

input :

a -> b -> a -> b -> a -> NULL

output :

a -> a -> a -> NULL

b -> b -> NULL

_Solution_ :  **AlternativeSplit.c**