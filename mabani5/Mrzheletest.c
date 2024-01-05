#include <stdio.h> //402106134  محمدحسن شفاعت
#include <stdlib.h>

void swap(double *row1, double *row2, int n)
{
    double temp;
    for (int i = 0; i < n; i++)
    {
        temp = *(row1 + i);
        *(row1 + i) = *(row2 + i);
        *(row2 + i) = temp;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    double **MATRIX = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++)
    {
        *(MATRIX + i) = (double *)malloc(n * sizeof(double));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%lf", *(MATRIX + i) + j);
        }
    }
    

    for (int x = 0; x < n; x++)
    {
        if (*(*(MATRIX + x) + x) != 0)
        {
            for (int i = x + 1; i < n; i++)
            {
                double CONSTANT = *(*(MATRIX + i) + x);
                for (int j = x; j < n; j++)
                {

                    *(*(MATRIX + i) + j) -= ((CONSTANT) / (*(*(MATRIX + x) + x))) * (*(*(MATRIX + x) + j));
                }
            }
        }
        int flag = 0;
        if (*(*(MATRIX + x) + x) == 0)
        {
            for (int i = x + 1; i < n; i++)
            {
                if (*(*(MATRIX + i) + x) != 0)
                {
                    swap(*(MATRIX + i), *(MATRIX + x), n);
                    flag = 1;

                    break;
                }
            }
            if (flag == 0)
            {
                continue;
            }

            for (int i = x + 1; i < n; i++)
            {
                double CONSTANT = *(*(MATRIX + i) + x);
                for (int j = x; j < n; j++)
                {

                    *(*(MATRIX + i) + j) -= ((CONSTANT) / *(*(MATRIX + x) + x)) * (*(*(MATRIX + x) + j));
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.2lf ", *(*(MATRIX + i) + j));
        }
        printf("\n");
    }

    return 0;
}
