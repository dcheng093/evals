*This project has been created as part of the 42 curriculum by mbiusing.*

# push_swap

## Description

`push_swap` is a sorting algorithm project that sorts a stack of integers (using a limited set of operations).

The goal of this project is to optimize the number of operations required to sort the numbers.

This project introduces concepts such as:

- stacks
- sorting algorithms (such as radix, turk sort and so on)

## Instructions
### Compilation

Compile the project using make:

```
make
```
which will create:

```
./push_swap
```
that is executable

### Execution

Run the program with a list of integers as arguments to get the list of operations needed to sort it:

```
./push_swap 3 2 1
```
Run the program with the checker from the resources of the Push_swap project page.

```
./push_swap 3 2 1 | ./checker_linux 3 2 1
```
### Allowed Operations
`pa`, `pb` — push the top element from one stack to the other

`ra`, `rb`, `rr` — rotate a stack upward

`rra`, `rrb`, `rrr` — rotate a stack downward

## Things To Figure Out Throughout This Project

1. What sorting algorithm to do?
2. What's better to do, Doubly Circular or just Doubly Linked list?
3. How should I handle different types of input?
4. How should I structure my code?

## Algorithm Chosen : Radix Sort

### What is Radix Sort?

It is a linear sorting algorithm (for fixed length digit counts) that sorts elements by processing them digit by digit.

It is an efficient non-comparison sorting algorithm for sorting integers or strings with fixed-length keys as it compares digit by digit (or character by character).
It repeatedly distributes the elements into buckets based on each digit's value. 

By repeatedly sorting the elements by their significant digits, from the least significant to the most significant, it achieves the final sorted order.

Basic steps to perform radix sort on the array [170, 45, 75, 90, 802, 24, 2, 66]:

**Step 1**: Find the largest element, which is 802. It has three digits, so we will iterate three times.

**Step 2**: Sort the elements based on the first place digit (X=0).

| Unsorted | Sorted by first place digit |
| --- | --- |
| 17**0**, 4**5**, 7**5**, 9**0**, 80**2**, 2**4**, **2**, 6**6** | 170, 90, 802, 2, 24, 45, 75, 66 |

**Step 3**: Sort the elements based on the tens/second place digit.

| Unsorted | Sorted by tens/second place digit |
| --- | --- |
| 1**7**0, **9**0, 8**0**2, [**0**]2, **2**4, **4**5, **7**5, **6**6 | 802, 2, 24, 45, 66, 170, 75, 90|

**Step 4**: Sort the elements based on the hundreds/third place digit.

| Unsorted | Sorted by hundreds/third place digit |
| --- | --- |
| **8**02, [**0**][**0**]2, [**0**]24, [**0**]45, [**0**]66, 170, [**0**]75, [**0**]90 | 2, 24, 45, 66, 75, 90, 170, 802|

**Step 5**: It is now sorted in ascending order.

**2, 24, 45, 66, 75, 90, 170, 802** !!!

## How did I implement Radix Sort into push_swap?

Since we can only use two stacks that is **a** and **b**, I used `&` (which is a Bitwise Operator) and `>>` (Right Shift Operator) to compare the digits in binary form.

But before doing that, I had to take negative numbers and huge numbers into consideration as well. So I "normalised" the input numbers, aka assign them/ turn them into index numbers.

Example:

Before Normalisation: 67, -67, 0, 100, 2, -3

After Normalisation: 4, 0, 2, 5, 3, 1

So just like the original version of radix sort, we have to find the maximum digits of the biggest number, to figure out how many iterations of digit places do we have to go through.

When sorting, we are grouping the stacks with;

**a** holding the *1*s ( which is `ra` -ed)

**b** holding the *0*s ( which is `pb` -ed)

After each iteration, everything from stack **b** is `pa` -ed back to stack **a**

Then this is repeated until the last digit place is iterated.

## RESOURCES

### Things I Searched For:
1. [push_swap Tutorial using Radix](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
2. [What is & (Bitwise AND) and >> or << (Right/Left Shift Operators)](https://stackoverflow.com/questions/3427585/understanding-the-bitwise-and-operator)
3. [patsubst](https://www.gnu.org/software/make/manual/html_node/Text-Functions.html) -> learnt this from gracious' push_swap when i evalled her
4. [abbastoof's push_swap github](https://github.com/abbastoof/Push_Swap) -> got stumped on how to simplify the numbers to get the sorted index
5. [push_swap tester](https://github.com/gemartin99/Push-Swap-Tester) -> basic checker
6. [circular doubly linked list](https://www.geeksforgeeks.org/dsa/introduction-to-circular-doubly-linked-list/)
7. [how to read valgrind output](https://stackoverflow.com/questions/2479684/understanding-the-valgrind-output)
8. [stacks in c](https://www.geeksforgeeks.org/c/implement-stack-in-c/)
9. [push swap visualiser](https://push-swap-visualizer.vercel.app/)
10. [radix sort](https://www.geeksforgeeks.org/dsa/radix-sort/)
11. [bit left and right shift](https://www.geeksforgeeks.org/cpp/left-shift-right-shift-operators-c-cpp/)

### Resources Peers Suggested:

1. [guide on valgrind usage -> suggested by Erica Chin](https://www.cs.swarthmore.edu/~newhall/unixhelp/valgrind.php)

### AI Usage:
- Explain pros & cons of the type of data structure to implement (also asked some peers why they picked certain data structures)
- Explain certain parts that i just cant with bro (like understanding what the valgrind output means)
- Help with debugging