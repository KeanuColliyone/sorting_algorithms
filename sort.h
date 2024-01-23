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

/* Function prototypes for print_array and print_list */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

#endif /* SORT_H */

