#include "grader.h"
#include <stdio.h> //402106134 محمدحسن شفاعت
#include <stdlib.h>


int tool_araye(int *X)
{
    long long int majmoo = 0;
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
long long int Min(long long int a, long long int b)
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
int* aggregator(int* a, int* b) {

    int A = tool_araye(a);
    int B = tool_araye(b);

    long long int MIN = Min(A, B);
    int *NEW_ARRAY = (int *)malloc((A + B) * sizeof(int));
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



