#include <stdio.h> //402106134 محمدحسن شفاعت
#include <stdlib.h>

int *ravel(int tedad_satr, int tedad_sotun, int a[tedad_satr][tedad_sotun])
{

    int *NEW_MATRIX = (int *)malloc((tedad_satr * tedad_sotun) * sizeof(int));
    int k = 0;
    for (int i = 0; i < tedad_satr; i++)
    {
        for (int j = 0; j < tedad_sotun; j++)
        {
            *(NEW_MATRIX + k) = *(*(a + i) + j);
            k++;
        }
    }
    return NEW_MATRIX;
}
int **reshape(int tedad_satr, int tedad_sotun, int a[tedad_satr][tedad_sotun], int new_tedad_satr, int new_tedad_sotun)
{
    int *ravel_a = ravel(tedad_satr, tedad_sotun, a);

    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc(new_tedad_satr * sizeof(int *));

    for (int i = 0; i < new_tedad_satr; i++)
    {
        NEW_MATRIX[i] = (int *)malloc(new_tedad_sotun * sizeof(int));
    }
    int k = 0;
    for (int i = 0; i < new_tedad_satr; i++)
    {
        for (int j = 0; j < new_tedad_sotun; j++)
        {
            NEW_MATRIX[i][j] = *(ravel_a + k);
            k++;
        }
    }
    return NEW_MATRIX;
}
int **resize(int tedad_satr, int tedad_sotun, int a[tedad_satr][tedad_sotun], int new_tedad_satr, int new_tedad_sotun)
{
    int *ravel_a = ravel(tedad_satr, tedad_sotun, a);

    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc(new_tedad_satr * sizeof(int *));

    for (int i = 0; i < new_tedad_satr; i++)
    {
        NEW_MATRIX[i] = (int *)malloc(new_tedad_sotun * sizeof(int));
    }

    int k = 0;
    for (int i = 0; i < new_tedad_satr; i++)
    {
        for (int j = 0; j < new_tedad_sotun; j++)
        {
            NEW_MATRIX[i][j] = *(ravel_a + k);
            k++;
            if (k == tedad_satr * tedad_sotun)
            {
                k = 0;
            }
        }
    }
    return NEW_MATRIX;
}
int **append_row(int tedad_satr, int tedad_sotun, int a[tedad_satr][tedad_sotun],int b[tedad_sotun])
{

    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc((tedad_satr + 1) * sizeof(int *));

    for (int i = 0; i < tedad_satr + 1; i++)
    {
        NEW_MATRIX[i] = (int *)malloc(tedad_sotun * sizeof(int));
    }

    for (int i = 0; i < tedad_satr + 1; i++)
    {
        if (i == tedad_satr)
        {
            for (int j = 0; j < tedad_sotun; j++)
            {
                NEW_MATRIX[i][j] = b[j];
            }
        }
        else
        {
            for (int j = 0; j < tedad_sotun; j++)
            {
                NEW_MATRIX[i][j] = a[i][j];
            }
        }
    }
    return NEW_MATRIX;
}

int main()
{

    // char input[11];
    // scanf("%[^\n]s", input);
    /*for (int i = 0; i < 11; i++)
    {
        printf("%c\n", input[i]);
    }*/
    int tedad_satr, tedad_sotun;
    scanf("%d %d", &tedad_satr, &tedad_sotun);

    int matris[tedad_satr][tedad_sotun];

    for (int i = 0; i < tedad_satr; i++)
    {
        for (int j = 0; j < tedad_sotun; j++)
        {
            scanf("%d", &matris[i][j]);
        }
    }
    // for (int i = 0; i < tedad_satr * tedad_sotun; i++)
    //{
    //     printf("%d ", *(ravel(tedad_satr, tedad_sotun, matris) + i));
    // }
    //int a, b;
    //scanf("%d %d", &a, &b);
    int abcd[tedad_sotun];
    for (int i = 0; i < tedad_sotun; i++)
    {
        scanf("%d", &abcd[i]);
    }
    
    int **A = append_row(tedad_satr, tedad_sotun, matris, abcd);

    for (int i = 0; i < tedad_satr + 1; i++)
    {
        for (int j = 0; j < tedad_sotun; j++)
        {
            printf("%d " ,A[i][j]);
        }
        printf("\n");
    }

    return 0;
}