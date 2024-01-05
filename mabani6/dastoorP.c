#include <stdio.h> //402106134 محمدحسن شفاعت
#include <string.h>
#include <stdlib.h>

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
    //tedad_kalame--;
    //new_save[tedad_kalame][0] = '\0';
    new_save[tedad_kalame - 1][strlen(new_save[tedad_kalame - 1])] = '\0';

    // printf("%s",new_save[1]);
    // char new_new_save[1000][1000];
    for (int i = 0; i < tedad_kalame; i++)
    {
        for (int j = 0; j < tedad_kalame - 1; j++)
        {
            int result = strcmp(new_save[j], new_save[j + 1]);
            if (result > 0)
            {
                char temp[strlen(new_save[j])];
                strcpy(temp, new_save[j]);
                strcpy(new_save[j], new_save[j + 1]);
                strcpy(new_save[j + 1], temp);
            }
        }
    }
    for (int x = 0; x < tedad_kalame; x++)
    {
        int tedad_harf = strlen(new_save[x]);

        for (int i = 0; i < tedad_harf; i++)
        {
            for (int j = 0; j < tedad_harf - 1; j++)
            {
                if (new_save[x][j] < new_save[x][j + 1])
                {
                    char temp;
                    temp = new_save[x][j];
                    new_save[x][j] = new_save[x][j + 1];
                    new_save[x][j + 1] = temp;
                }
            }
        }
        printf("%s ", new_save[x]);
    }
    return 0;
}