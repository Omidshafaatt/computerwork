#include <stdio.h> //402106134 محمدحسن شفاعت
#include <stdlib.h>
int tool_araye(int *X)
{
    int majmoo = 0;
    int i = 0;
    if (*X == 0)
    {
        return 1;
    }
    else
    {
        do
        {
            majmoo += *(X + i);
            i++;
        } while (majmoo != *(X + i));
        i++;
    }

    return i;
}
int Min(int a, int b)
{
    if (a >= b)
    {
        return b;
    }
    else
    {
        return a;
    }
}

int *aggregator(int *a, int *b)
{
    int A = tool_araye(a);
    int B = tool_araye(b);

    int MIN = Min(A, B);
    int *NEW_ARRAY = malloc((A + B) * sizeof(int));
    int j = 0;
    int k = 0;
    for (int i = 0; i < 2 * MIN; i++)
    {
        if (i % 2 == 0)
        {
            *(NEW_ARRAY + i) = *(a + j);
            j++;
        }
        else
        {
            *(NEW_ARRAY + i) = *(b + k);
            k++;
        }
    }
    if (MIN == A)
    {
        for (int i = 2 * MIN; i < A + B; i++)
        {
            *(NEW_ARRAY + i) = *(b + k);
            k++;
        }
    }
    if (MIN == B)
    {
        for (int i = 2 * MIN; i < A + B; i++)
        {
            *(NEW_ARRAY + i) = *(a + j);
            j++;
        }
    }
    return NEW_ARRAY;
}
int main()
{

    int c[] = {7, 0, 4, 0, 7, 8, 4, 5, 6, 2, 10, 53};
    int d[] = {6, 7, 1, 4, 0, 10, 6, 2, 7, 43};

    // int *ptr = &c[0];
    // printf("%d", x);
    int *ptr = aggregator(c, d);

    for (int i = 0; i < 25; i++)
    {
        printf("%d\n", *(ptr + i));
    }

    return 0;
}
