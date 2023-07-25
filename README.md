# sorting_algorithms

## Objectives

    . What is the Big O notation, and how to evaluate the time complexity of an algorithm
    . How to select the best sorting algorithm for a given input
    . What is a stable sorting algorithm

## Requirements

### C

	. Editors: `vi, vim, emacs`
	. Ubuntu 20.04 LTS and gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
    . A `README.md` file, at the root of the folder of the project is mandatory
	. `Betty` style compliant code. It will be checked using `betty-style.pl` and `betty-doc.pl`
	. No global variables
	. No more than 5 functions per file
    . Not allowed to use the standard library. Any use of functions like `printf`, `puts`, etc… is forbidden
    . Allowed to use `_putchar`
    . The prototypes of all functions and the prototype of the function `_putchar` should be included in header file called `main.h`
	. All your header files should be include guarded

### Data structures

    /**
     * struct listint_s - Doubly linked list node
     *
     * @n: Integer stored in the node
     * @prev: Pointer to the previous element of the list
     * @next: Pointer to the next element of the list
     */
    typedef struct listint_s
    {
        const int n;
        struct listint_s *prev;
        struct listint_s *next;
    } listint_t;

## Description of files in the repository

    . 0-bubble_sort.c - function that sorts an array of integers in ascending order using the Bubble sort algorithm
    . 0-O - the big O notations of the time complexity of the Bubble sort algorithm
    . 1-insertion_sort_list.c - function that sorts a doubly linked list of integers in ascending order using the Insertion sort algorithm
    . 1-O - the big O notations of the time complexity of the Insertion sort algorithm
    . 2-selection_sort.c - function that sorts an array of integers in ascending order using the Selection sort algorithm
    . 2-O - the big O notations of the time complexity of the Selection sort algorithm
    . 3-quick_sort.c - function that sorts an array of integers in ascending order using the Quick sort algorithm
    . 3-O - the big O notations of the time complexity of the Quick sort algorithm
    . 100-shell_sort.c - function that sorts an array of integers in ascending order using the Shell sort algorithm
    . 101-cocktail_sort_list.c - function that sorts a doubly linked list of integers in ascending order using the Cocktail shaker sort algorithm
    . 101-O - he big O notations of the time complexity of the Cocktail shaker sort algorithm
    . 102-counting_sort.c - function that sorts an array of integers in ascending order using the Counting sort algorithm
    . 102-O - the big O notations of the time complexity of the Counting sort algorithm
    . 103-merge_sort.c - function that sorts an array of integers in ascending order using the Merge sort algorithm
    . 103-O - the big O notations of the time complexity of the Merge sort algorithm
    . 104-heap_sort.c - function that sorts an array of integers in ascending order using the Heap sort algorithm
    . 104-O - the big O notations of the time complexity of the Heap sort algorithm
    . 105-radix_sort.c - function that sorts an array of integers in ascending order using the Radix sort algorithm

## Authors

    . Eric Ubaga
    . Richard Muchira
