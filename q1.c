#include <stdio.h>
#define MAXSIZE 80

int my_strcmp(char[], char[]);
int my_strncmp(char[], char[], int);
int my_strchr(char[], char);

int main()
{
    char str1[MAXSIZE];
    char str2[MAXSIZE];
    int n;
    int w;

    /* test my_strcmp*/
    char msg1[] = "\nEnter 2 strings to test the 'my_strcmp' function: \n";
    do
    {
        printf("%s",msg1);
        w = scanf("%s%s", str1, str2);
        if (w == EOF)
            return -1;
    } while (w != 2);
    printf("\nstr 1:%s \nstr 2:%s \nyour compare result is :%d \n", str1, str2, my_strcmp(str1, str2));

    /* test my_strncmp*/
    char msg2[] = "\nEnter 2 strings and 1 positive number to test the 'my_strncmp' function: \n";
    do
    {
        printf("%s",msg2);
        w = scanf("%s%s%d", str1, str2, &n);
        if (w == EOF)
            return -1;
    } while (w != 3);
    printf("\nstr 1:%s \nstr 2:%s \nyour compare result is :%d \n", str1, str2, my_strncmp(str1, str2, n));


    /* test my_strchr*/
    char c;
    char msg3[] = "\nEnter 1 string and 1 character to test the 'my_strchr' function: \n";
    do
    {
        printf("%s",msg3);
        w = scanf("%s %c", str1, &c);
        if (w == EOF)
            return -1;
    } while (w != 2);
    printf("\nstr :%s \nindex of first instance of %c is :%d \n", str1, c, my_strchr(str1, c));

    return 0;
}

/*
    my_strcmp: compare string cs to string ct;
    params:
     cs - target string;
     ct - comparable string

    return: the returned value from my_strncmp without max char condition (-1)
*/
int my_strcmp(char cs[], char ct[])
{
    return my_strncmp(cs, ct, -1);
}

/*
    my_strncmp: compare at most n characters of string cs to string ct;
    params:
     n - max characters to compare;
     cs - target string;
     ct - comparable string

    * in case n is a negative number it will compare  cs to ct without max characters condition
    return: <0 if cs<ct,  0 if cs==ct, >0 if cs>ct
*/
int my_strncmp(char cs[], char ct[], int n)
{
    int i;
    for (i = 0; (cs[i] || ct[i]) && n != i; i++)
    {
        if (cs[i] != ct[i])
            return cs[i] - ct[i];
    }
    return n == i ? 0 : cs[i] - ct[i];
}

/*
    my_strncmp: find the first instance of a character in a cs
    params:
     c - max characters to compare;
     cs - target string;

    return: index of the first char found or -1 if non has found
*/
int my_strchr(char cs[], char c)
{
    int i;
    for (i = 0; cs[i]; i++)
    {
        if (cs[i] == c)
            return i;
    }
    return -1;
}
