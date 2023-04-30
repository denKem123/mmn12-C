#include <stdio.h>
#include <stdlib.h>

#define RESIZE_BY 1
#define SIZE_ENLARGE(length) ((length) + RESIZE_BY)

struct List
{
    int *numbers;
    int length;
};

void get_set(struct List *all_nums, struct List *set);
void print_set(struct List set);
void print_list(struct List set);
void resize_list(struct List *set);
struct List initialize_list();

int main()
{
    struct List all_nums = initialize_list();
    struct List set = initialize_list();

    get_set(&all_nums, &set);
    printf("all numbers:\n");
    print_list(all_nums);

    printf("set's numbers:\n");
    print_set(set);

    free(set.numbers);
    free(all_nums.numbers);
    return 0;
}

/*
    get_set: get all numbers input and save them in a all_num and
    params:
     all_nums:List - a struct to save all numbers received as an input(doesn't act like a set).
*/
void get_set(struct List *all_nums, struct List *set)
{
    int num, isNumExist = 0;
    int *p;
    printf("%s", "Enter numbers to create a set out of them,\nto stop please enter EOF:\n");

    while (scanf("%d", &num) != EOF)
    {
        resize_list(all_nums);
        all_nums->numbers[all_nums->length - 1] = num;

        isNumExist = 0;

        /*check if the current num already exist in the set array*/
        for (p = set->numbers; p < set->numbers + set->length; p++)
            isNumExist = isNumExist || *p == num ? 1 : 0;

        /*if the current num doesn't already exist in the set array - resize the set and add the number*/
        if (!isNumExist)
        {
            resize_list(set);
            set->numbers[set->length - 1] = num;
        }
    }
}

/*
    print_set: call the print_list function
    params:
     set:List - target List;
*/
void print_set(struct List set)
{
    print_list(set);
}

/*
    print_list: print all the numbers in the received arr. and separate them with comma
    params:
     arr:List - target List;
*/
void print_list(struct List arr)
{

    int *p;
    for (p = arr.numbers; p < arr.numbers + arr.length; p++)
    {
        if (p != arr.numbers)
            printf(",");
        printf("%d", *p);
    }
    printf("\n");
}

/*resize List by SIZE_ENLARGE macro*/
void resize_list(struct List *list)
{
    int *numbersHolder;
    int size = SIZE_ENLARGE(list->length);
    numbersHolder = (int *)realloc(list->numbers, size * sizeof(int));
    if (numbersHolder)
    {
        list->numbers = numbersHolder;
        list->length = size;
    }
}

/*initialize List*/
struct List initialize_list()
{
    struct List list;
    list.length = 0;
    list.numbers = (int *)malloc(0);
    return list;
}
