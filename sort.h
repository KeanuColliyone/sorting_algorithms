#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Structure for doubly linked list */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);

/* Function prototypes for print_array and print_list */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif /* SORT_H */

