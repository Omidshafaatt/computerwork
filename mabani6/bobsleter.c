#include <stdio.h> //402106134   محمدحسن شفاعت
#include <string.h>
#include <stdlib.h>
int WHEN_IS_END(char input[])
{

    int TOOLE_STRING = strlen(input);
    for (int i = 0; i < TOOLE_STRING; i++)
    {
        if (input[i] == '#' || input[i] == '*')
        {
            return 0;
        }
        else if (i == TOOLE_STRING - 1)
        {
            return 1;
        }
    }
}
char *DELET_ELEMENT(char input[], int DELET_ANDIS)
{

    int TOOLE_STRING = strlen(input);

    char *NEW_STRING = (char *)malloc((TOOLE_STRING - 1) * sizeof(char));
    for (int i = 0; i < DELET_ANDIS; i++)
    {
        NEW_STRING[i] = input[i];
    }
    for (int i = DELET_ANDIS; i < TOOLE_STRING - 1; i++)
    {
        NEW_STRING[i] = input[i + 1];
    }
    return NEW_STRING;
}
char *RAMZ_GOSHA(char input[])
{

    int TOOLE_STRING = strlen(input);

    if (WHEN_IS_END(input))
    {
        return input;
    }
    else
    {
        for (int i = 0; i < TOOLE_STRING; i++)
        {
            if (input[i] == '*')
            {
                input[i] = input[i - 1]; // i == 0?
                return RAMZ_GOSHA(input);
            }
            else if (input[i] == '#')
            {
                char *NEW_STRING = (char *)malloc((TOOLE_STRING - 1) * sizeof(char));
                NEW_STRING = DELET_ELEMENT(input, i);
                char *NEW_NEW_STRING = (char *)malloc((TOOLE_STRING - 2) * sizeof(char));
                NEW_NEW_STRING = DELET_ELEMENT(NEW_STRING, i - 1);
                return RAMZ_GOSHA(NEW_NEW_STRING);
            }
        }
    }
}
int TOOLE_NAHAYI(char X[])
{
    int result = strlen(X);
    int a = strlen(X);
    for (int i = 0; i < a; i++)
    {
        if (X[i] == '#')
        {
            result -= 2;
        }
    }
    return result;
}
int main()
{
    int n;
    scanf("%d\n", &n);

    char save[1000];
    for (int i = 0; i < n; i++)
    {
        fgets(save, sizeof(save), stdin);
        char *output = RAMZ_GOSHA(save);
        int tool = TOOLE_NAHAYI(save);
        for (int i = 0; i < tool; i++)
        {
            printf("%c", *(output + i));
        }
        printf("\n");
    }

    return 0;
}