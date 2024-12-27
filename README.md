# 42-push_swap

This project aims to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions<br />

## Description
We start with two stacks: stack `a` contains a list of integers and stack `b` is empty. <br />
The goal is to sort in ascending order numbers into stack `a` using only the following operations:
* `sa` (swap a): swap the first 2 elements at the top of stack a - do nothing if there is only one or no elements
* `sb` (swap b): swap the first 2 elements at the top of stack b - do nothing if there is only one or no elements
* `ss` : `sa` and `sb` at the same time
* `pa` (push a): take the first element at the top of b and put it at the top of a - do nothing if b is empty
* `pb` (push b): take the first element at the top of a and put it at the top of b - do nothing if a is empty
* `ra` (rotate a): shift up all elements of stack a by 1 - the first element becomes the last one
* `rb` (rotate b): shift up all elements of stack b by 1 - the first element becomes the last one
* `rr` : `ra` and `rb` at the same time
* `rra` (reverse rotate a): shift down all elements of stack a by 1 - the last element becomes the first one
* `rrb` (reverse rotate b): shift down all elements of stack b by 1 - the last element becomes the first one
* `rrr` : `rra` and `rrb` at the same time

## Sorting algorithm
To solve the problem minimizing the number of movements, I based my solution on the [Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97).

1. Push all numbers onto stack b until there are only 3 elements left on stack a
2. At each iteration, calculate the cost (number of moves) of pushing numbers onto stack b so that they are sorted in **descending** order. Find the cheapest operation and execute it
3. Sort the remaining 3 elements on stack a, if it is not sorted
4. Push all numbers back onto stack a until stack b is empty
5. At each iteration, calculate the cost of pushing numbers onto stack a so that they are sorted in **ascending** order. Find the cheapest operation and execute it
6. If the smallest number is not on top, rotate stack a until the smallest number reaches the top

The [visualizer](https://github.com/o-reo/push_swap_visualizer) helps illustrate how the algorithm works: <br />

<p align="center">
  <img src="gif/push_swap_visualizer.gif"><br />
  <small>Sorting 500 numbers</small>
</p>

## Usage
* Compile the `push_swap` program
  ```sh
  make
  ```

* Run the program providing a series of integers as arguments
  ```sh
  ./push_swap <integers>
  ```

* The program will output a list of operations to sort the input number into stack a
  ```sh
  $>./push_swap 222 -11 42 88 0
  pb
  pb
  rra
  pa
  pa
  ra
  
  $>ARG="222 -11 42 88 0"; ./push_swap $ARG | wc -l
  6
  ```

To achieve full score, we need to perform the sorting with a limited number of operations
* For 3 numbers: 3 moves
* For 5 numbers: 12 moves
* For 100 numbers: 700 moves
* For 500 numbers: 5500 moves

## Bonus
For the bons part, the `checker` program receives a list of integers as argument and reads the instructions on the standard input.<br />
Once all the instructions have been read, the program checks if the **stack a is sorted** and if **stack b is empty**.<br />

* Compile the `checker` program
  ```sh
  make bonus
  ```

* Run the program
  ```sh
  $>./checker 3 1 2
  ra
  [ctrl + d]
  OK

  $>./checker 3 1 2
  sa
  [ctrl + d]
  KO

  $>ARG="222 -11 42 88 0"; ./push_swap $ARG | ./checker $ARG
  OK
  ```
