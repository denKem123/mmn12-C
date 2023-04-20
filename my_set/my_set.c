#include <stdio.h>

#define RESIZE_BY 1
#define SIZE_ENLARGE(length) ((length) + RESIZE_BY)

typedef struct Set
{
    int *numbers;
    int length;
};

struct Set get_set(struct Set all_nums);
void print_set(struct Set set);
void resize_set(struct Set set);

int main()
{
    struct Set all_nums;
    all_nums.length = 0;
    all_nums.numbers = (int *)malloc(0);

    struct Set set = get_set(all_nums);
    printf("all numbers:\n");
    print_set(all_nums);

    printf("set's numbers:\n");
    print_set(set);

    free(set.numbers);
    free(all_nums.numbers);
    return 0;
}

/*

*/
struct Set get_set(struct Set all_nums)
{

    /*initialize the set*/
    struct Set set;
    set.length = 0;
    set.numbers = (int *)malloc(0);

    printf("%s", "Enter as many numbers as you want to create a set out of them,\nto stop please enter EOF:");
    int num;
    do
    {
        scanf("%d", &num);
        int i, isNumFound = 0;

        resize_set(all_nums);
        all_nums.numbers[all_nums.length - 1] = num;

        for (int i = 0; i < set.length; i++)
            isNumFound = isNumFound || set.numbers[i] == num ? 1 : 0;

        if (!isNumFound)
        {
            resize_set(set);
            set.numbers[set.length - 1] = num;
        }
    } while (num != EOF);

    return set;
}

/*

*/
void print_set(struct Set set)
{
    int i = 0;
    for (i; i < set.length; i++)
    {
        if (i)
            printf(",");
        printf("%d", set.numbers[i]);
    }
}

void resize_set(struct Set set)
{
    set.length = SIZE_ENLARGE(set.length);
    int *numbersHolder = (int *)realloc(set.numbers, set.length * sizeof(int));
    if (!numbersHolder)
        set.numbers = numbersHolder;
}