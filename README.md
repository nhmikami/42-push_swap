# 42-push_swap

This project aims to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions.<br />

## Description
The goal is to sort in ascending order numbers into stack a. To do so you have the following operations:
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


