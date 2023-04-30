#include <stdio.h>
#include <stdlib.h>

#define RESIZE_BY 1
#define SIZE_ENLARGE(length) ((length) + RESIZE_BY)

void get_set(struct List *all_nums, struct List *set);
void print_set(struct List set);
void print_list(struct List set);
void resize_list(struct List *set);
struct List initialize_list();