#include <stdio.h> //402106134 محمدحسن شفاعت
#include <stdlib.h>
#include <string.h>

int **ravel(int tedad_satr, int tedad_sotun, int a[tedad_satr][tedad_sotun])
{
    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc(1 * sizeof(int *));

    for (int i = 0; i < 1; i++)
    {
        *(NEW_MATRIX + i) = (int *)malloc((tedad_satr + tedad_sotun) * sizeof(int));
    }

    int k = 0;
    for (int i = 0; i < tedad_satr; i++)
    {
        for (int j = 0; j < tedad_sotun; j++)
        {
            *(*(NEW_MATRIX) + k) = *(*(a + i) + j);
            k++;
        }
    }
    return NEW_MATRIX;
}
int **reshape(int tedad_satr, int tedad_sotun, int a[tedad_satr][tedad_sotun], int new_tedad_satr, int new_tedad_sotun)
{
    int **ravel_a = ravel(tedad_satr, tedad_sotun, a);

    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc(new_tedad_satr * sizeof(int *));

    for (int i = 0; i < new_tedad_satr; i++)
    {
        *(NEW_MATRIX + i) = (int *)malloc(new_tedad_sotun * sizeof(int));
    }
    int k = 0;
    for (int i = 0; i < new_tedad_satr; i++)
    {
        for (int j = 0; j < new_tedad_sotun; j++)
        {
            *(*(NEW_MATRIX + i) + j) = *(*(ravel_a) + k);
            k++;
        }
    }
    return NEW_MATRIX;
}
int **resize(int tedad_satr, int tedad_sotun, int a[tedad_satr][tedad_sotun], int new_tedad_satr, int new_tedad_sotun)
{
    int **ravel_a = ravel(tedad_satr, tedad_sotun, a);

    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc(new_tedad_satr * sizeof(int *));

    for (int i = 0; i < new_tedad_satr; i++)
    {
        *(NEW_MATRIX + i) = (int *)malloc(new_tedad_sotun * sizeof(int));
    }

    int k = 0;
    for (int i = 0; i < new_tedad_satr; i++)
    {
        for (int j = 0; j < new_tedad_sotun; j++)
        {
            *(*(NEW_MATRIX + i) + j) = *(*(ravel_a ) + k);
            k++;
            if (k == tedad_satr * tedad_sotun)
            {
                k = 0;
            }
        }
    }
    return NEW_MATRIX;
}
int **append_row(int tedad_satr, int tedad_sotun, int a[tedad_satr][tedad_sotun], int b[tedad_sotun])
{

    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc((tedad_satr + 1) * sizeof(int *));

    for (int i = 0; i < tedad_satr + 1; i++)
    {
        *(NEW_MATRIX + i) = (int *)malloc(tedad_sotun * sizeof(int));
    }

    for (int i = 0; i < tedad_satr + 1; i++)
    {
        if (i == tedad_satr)
        {
            for (int j = 0; j < tedad_sotun; j++)
            {
                *(*(NEW_MATRIX + i) + j) = *(b + j); // BUG?!!!!
            }
        }
        else
        {
            for (int j = 0; j < tedad_sotun; j++)
            {
                *(*(NEW_MATRIX + i) + j) = *(*(a + i) + j); // BUG?!!!!
            }
        }
    }
    return NEW_MATRIX;
}
int **insert_row(int tedad_satr, int tedad_sotun, int new_satr, int a[tedad_satr][tedad_sotun], int b[tedad_sotun])
{
    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc((tedad_satr + 1) * sizeof(int *));

    for (int i = 0; i < tedad_satr + 1; i++)
    {
        *(NEW_MATRIX + i) = (int *)malloc(tedad_sotun * sizeof(int));
    }
    for (int i = 0; i < tedad_satr + 1; i++)
    {

        for (int j = 0; j < tedad_sotun; j++)
        {
            if (i == new_satr)
            {
                *(*(NEW_MATRIX + i) + j) = *(b + j);
            }
            if (i < new_satr)
            {
                *(*(NEW_MATRIX + i) + j) = *(*(a + i) + j);
            }
            if (i > new_satr)
            {
                *(*(NEW_MATRIX + i) + j) = *(*(a + i - 1) + j);
            }
        }
    }
    return NEW_MATRIX;
}
int **append_column(int tedad_satr, int tedad_sotun, int a[tedad_satr][tedad_sotun], int b[tedad_satr])
{

    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc((tedad_satr) * sizeof(int *));

    for (int i = 0; i < tedad_satr; i++)
    {
        *(NEW_MATRIX + i) = (int *)malloc((tedad_sotun + 1) * sizeof(int));
    }

    for (int i = 0; i < tedad_satr; i++)
    {
        for (int j = 0; j < tedad_sotun; j++)
        {
            *(*(NEW_MATRIX + i) + j) = *(*(a + i) + j);
        }
    }
    for (int i = 0; i < tedad_satr; i++)
    {
        *(*(NEW_MATRIX + i) + tedad_sotun) = *(b + i);
    }

    return NEW_MATRIX;
}
int **insert_column(int tedad_satr, int tedad_sotun, int new_sotun, int a[tedad_satr][tedad_sotun], int b[tedad_satr])
{
    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc((tedad_satr) * sizeof(int *));

    for (int i = 0; i < tedad_satr; i++)
    {
        *(NEW_MATRIX + i) = (int *)malloc((tedad_sotun + 1) * sizeof(int));
    }
    for (int j = 0; j < tedad_sotun + 1; j++)
    {

        for (int i = 0; i < tedad_satr; i++)
        {
            if (j == new_sotun)
            {
                *(*(NEW_MATRIX + i) + j) = *(b + i);
            }
            if (j < new_sotun)
            {
                *(*(NEW_MATRIX + i) + j) = *(*(a + i) + j);
            }
            if (j > new_sotun)
            {
                *(*(NEW_MATRIX + i) + j) = *(*(a + i) + j - 1);
            }
        }
    }
    return NEW_MATRIX;
}
int **delete_row(int tedad_satr, int tedad_sotun, int delete, int a[tedad_satr][tedad_sotun])
{
    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc((tedad_satr - 1) * sizeof(int *));

    for (int i = 0; i < tedad_satr - 1; i++)
    {
        *(NEW_MATRIX + i) = (int *)malloc((tedad_sotun) * sizeof(int));
    }
    for (int i = 0; i < tedad_satr; i++)
    {
        if (i < delete)
        {
            for (int j = 0; j < tedad_sotun; j++)
            {
                *(*(NEW_MATRIX + i) + j) = *(*(a + i) + j);
            }
        }
        if (i > delete)
        {
            for (int j = 0; j < tedad_sotun; j++)
            {
                *(*(NEW_MATRIX + i - 1) + j) = *(*(a + i) + j);
            }
        }
    }

    return NEW_MATRIX;
}
int **delete_column(int tedad_satr, int tedad_sotun, int delete, int a[tedad_satr][tedad_sotun])
{
    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc((tedad_satr) * sizeof(int *));

    for (int i = 0; i < tedad_satr; i++)
    {
        *(NEW_MATRIX + i) = (int *)malloc((tedad_sotun - 1) * sizeof(int));
    }
    for (int j = 0; j < tedad_sotun; j++)
    {
        if (j < delete)
        {
            for (int i = 0; i < tedad_satr; i++)
            {
                *(*(NEW_MATRIX + i) + j) = *(*(a + i) + j);
            }
        }
        if (j > delete)
        {
            for (int i = 0; i < tedad_satr; i++)
            {
                *(*(NEW_MATRIX + i) + j - 1) = *(*(a + i) + j);
            }
        }
    }

    return NEW_MATRIX;
}
int **tile(int tedad_satr, int tedad_sotun, int tile_sotun, int tile_satr, int a[tedad_satr][tedad_sotun])
{
    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc((tedad_satr * tile_satr) * sizeof(int *));

    for (int i = 0; i < tedad_satr * tile_satr; i++)
    {
        *(NEW_MATRIX + i) = (int *)malloc((tedad_sotun * tile_sotun) * sizeof(int));
    }
    for (int i = 0; i < tedad_satr * tile_satr; i++)
    {
        for (int j = 0; j < tedad_sotun * tile_sotun; j++)
        {
            *(*(NEW_MATRIX + i) + j) = *(*(a + (i % tedad_satr)) + (j % tedad_sotun));
        }
    }
    return NEW_MATRIX;
}
int **transpose(int tedad_satr, int tedad_sotun, int a[tedad_satr][tedad_sotun])
{
    int **NEW_MATRIX;

    NEW_MATRIX = (int **)malloc(tedad_sotun * sizeof(int *));

    for (int i = 0; i < tedad_sotun; i++)
    {
        *(NEW_MATRIX + i) = (int *)malloc(tedad_satr * sizeof(int));
    }
    for (int i = 0; i < tedad_sotun; i++)
    {
        for (int j = 0; j < tedad_satr; j++)
        {
            *(*(NEW_MATRIX + i) + j) = *(*(a + j) + i);
        }
    }
    return NEW_MATRIX;
}

int main()
{

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
    int ***SAVE;
    SAVE = (int ***)malloc(1000 * (sizeof(int **)));
    *SAVE = matris;

    for (int i = 1; i < 1000; i++)
    {
        char input[11];
        scanf("%[^\n]s", input);
        if (strcmp(input,ravel) == 0)
        {
            *(SAVE + i) = ravel(tedad_satr, tedad_sotun, *(SAVE + i - 1));
            tedad_sotun = tedad_satr + tedad_sotun;
            tedad_satr = 1;
        }
        if (strcmp(input,reshape) == 0)
        {
            int new_tedad_satr, new_tedad_sotun;
            scanf("%d %d", &new_tedad_satr, &new_tedad_sotun);
            *(SAVE + i) = reshape(tedad_satr, tedad_sotun, *(SAVE + i - 1), new_tedad_satr, new_tedad_sotun);
            tedad_satr = new_tedad_satr;
            tedad_sotun = new_tedad_sotun;
        }
        if (strcmp(input, resize) == 0)
        {
            int new_tedad_satr, new_tedad_sotun;
            scanf("%d %d", &new_tedad_satr, &new_tedad_sotun);
            *(SAVE + i) = resize(tedad_satr, tedad_sotun, *(SAVE + i - 1), new_tedad_satr, new_tedad_sotun);
            tedad_satr = new_tedad_satr;
            tedad_sotun = new_tedad_sotun;
        }
        if (strcmp(input, append_row) == 0)
        {
            int b[tedad_sotun];
            for (int q = 0; q < tedad_sotun; q++)
            {
                scanf("%d ", &b);
            }
            *(SAVE + i) = append_row(tedad_satr, tedad_sotun, *(SAVE + i - 1), b);
            tedad_satr += 1;
        }
        if (strcmp(input, insert_row) == 0)
        {
            int new_satr;
            scanf("%d", &new_satr);
            int b[tedad_sotun];
            for (int q = 0; q < tedad_sotun; q++)
            {
                scanf("%d ", &b);
            }
            *(SAVE + i) = insert_row(tedad_satr, tedad_sotun, new_satr, *(SAVE + i - 1), b);
            tedad_satr += 1;
        }
        if (strcmp(input, append_column) == 0)
        {
            int b[tedad_satr];
            for (int q = 0; q < tedad_satr; q++)
            {
                scanf("%d ", &b);
            }
            *(SAVE + i) = append_column(tedad_satr, tedad_sotun, *(SAVE + i - 1), b);
            tedad_sotun += 1;
        }
        if (strcmp(input, insert_column) == 0)
        {
            int new_sotun;
            scanf("%d", &new_sotun);
            int b[tedad_satr];
            for (int q = 0; q < tedad_satr; q++)
            {
                scanf("%d ", &b);
            }
            *(SAVE + i) = insert_column(tedad_satr, tedad_sotun, new_sotun, *(SAVE + i - 1), b);
            tedad_sotun += 1;
        }
        if (strcmp(input, delete_row) == 0)
        {
            int delete;
            scanf("%d", &delete);
            *(SAVE + i) = delete_row(tedad_satr, tedad_sotun, delete, *(SAVE + i - 1));
            tedad_satr -= 1;
        }
        if (strcmp(input, delete_column) == 0)
        {
            int delete;
            scanf("%d", &delete);
            *(SAVE + i) = delete_column(tedad_satr, tedad_sotun, delete, *(SAVE + i - 1));
            tedad_sotun -= 1;
        }
        if (strcmp(input, tile) == 0)
        {
            int tile_sotun, tile_satr;
            scanf("%d %d", &tile_sotun, &tedad_satr);
            *(SAVE + i) = tile(tedad_satr, tedad_sotun, tile_sotun, tile_satr, *(SAVE + i - 1));
            tedad_satr *= tile_satr;
            tedad_sotun *= tile_sotun;
        }
        if (strcmp(input, transpose) == 0)
        {
            *(SAVE + i) = transpose(tedad_satr, tedad_sotun, *(SAVE + i - 1));
            int temp = tedad_satr;
            tedad_satr = tedad_sotun;
            tedad_sotun = temp;
        }
        if (strcmp(input,exit) == 0)
        {
            break;
        }
    }

    /*int **A = transpose(tedad_satr, tedad_sotun, matris);

    for (int i = 0; i < tedad_sotun; i++)
    {
        for (int j = 0; j < tedad_satr; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }*/

    return 0;
}