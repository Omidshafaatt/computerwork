#include <stdio.h> //402106134 محمدحسن شفاعت
#include <string.h>
#include <stdlib.h>

int CAN_WE_BE_LIKE_EACH_OTHER(char A[], char B[])
{
    /*if (strlen(A) != strlen(B))
    {
        return 0;
    }*/
    if (A[0] != '1')
    {
        int TAFAZOL[strlen(B)];
        for (int i = 0; i < strlen(B); i++)
        {
            TAFAZOL[i] = A[i] - B[i];
            if (TAFAZOL[i] < 0)
            {
                TAFAZOL[i] += 26;
            }
        }
        int flag = 0;
        for (int i = 0; i < strlen(B); i++)
        {
            if (TAFAZOL[i] != TAFAZOL[0])
            {
                flag = 1;
                break;
            }
        }
        if (flag != 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }

    /*int X = 0;
    int TAFAZOL[strlen(B)];
    for (int i = 0; i <= strlen(A) - strlen(B); i++)
    {
        int flag = 0;
        for (int j = i; j < i + strlen(B); j++)
        {
            TAFAZOL[j - i] = A[j] - B[j];
            if (TAFAZOL[j - i] < 0)
            {
                TAFAZOL[j - i] += 26;
            }
            if (TAFAZOL[j - i] != TAFAZOL[0])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            X++;
        }
    }
    return X;*/
}

int main()
{

    char save[1000];
    fgets(save, sizeof(save), stdin);

    char new_save[1000][1000];

    char *token = strtok(save, " ");
    int tedad_kalame = 0;
    while (token != NULL)
    {
        // printf("%s\n", token);
        strcpy(new_save[tedad_kalame], token);
        tedad_kalame++;
        token = strtok(NULL, " "); // harf akhar \n
    }
    new_save[tedad_kalame - 1][strlen(new_save[tedad_kalame - 1]) - 1] = '\0';
    // printf("%s",new_save[1]);
    char point[1000];
    fgets(point, sizeof(save), stdin);
    point[strlen(point) - 1] = '\0';

    for (int i = 0; i < tedad_kalame; i++)
    {
        for (int j = i + 1; j < tedad_kalame; j++)
        {
            int flag = 0;
            if (strlen(new_save[i]) == strlen(new_save[j]))
            {
                for (int k = 0; k < strlen(new_save[i]); k++)
                {
                    if (new_save[i][k] != new_save[j][k])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    for (int k = 0; k < strlen(new_save[i]); k++)
                    {
                        new_save[j][k] = '1';
                    }
                }
            }
        }
    }
    int HOW_MANY_TIMES = 0;

    for (int i = 0; i < tedad_kalame; i++)
    {
        if (CAN_WE_BE_LIKE_EACH_OTHER(new_save[i], point))
        {
            HOW_MANY_TIMES++;
        }
    }
    printf("%d", HOW_MANY_TIMES);

    return 0;
}