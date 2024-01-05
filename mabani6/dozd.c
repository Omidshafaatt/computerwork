#include <stdio.h> //402106134 محمدحسن شفاعت 
#include <string.h>
#include <stdlib.h>

void removeSubstring(char *mainStr, const char *subStr)
{
    char *ptr = strstr(mainStr, subStr);
    while (ptr != NULL)
    {
        memmove(ptr, ptr + strlen(subStr), strlen(ptr + strlen(subStr)) + 1);
        ptr = strstr(mainStr, subStr);
    }
}
char *remove_after_forward_slash(char A[])
{
    int X = strlen(A);
    int a = 0;
    char *output = (char *)malloc(1100 * sizeof(char));
    for (int i = 0; i < X; i++)
    {
        if (A[i] == '/')
        {
            break;
        }
        a++;
        output[i] = A[i];
    }
    for (int i = a; i < 1100; i++)
    {
        output[i] = '\0';
    }
    return output;
}
char *find_URL(char A[])
{
    int X = strlen(A);
    char *URL = (char *)malloc(1100 * sizeof(char));
    int start = 0;
    int end = 0;
    for (int i = 0; i < X; i++)
    {
        start++;
        end++;
        if (A[i] == ' ')
        {
            break;
        }
    }
    for (int i = start; i < X; i++)
    {
        if (A[i] == ' ')
        {
            break;
        }
        end++;
    }
    for (int i = start; i < end; i++)
    {
        URL[i - start] = A[i];
    }
    for (int i = end - start; i < 1100; i++)
    {
        URL[i] = '\0';
    }
    //printf("%s",URL);
    return URL;
}
char *find_IP(char A[])
{
    int X = strlen(A);
    char *IP = (char *)malloc(30 * sizeof(char));
    int a = 0;
    for (int i = 0; i < X; i++)
    {
        if (A[i] == ' ')
        {
            a++;
        }
        if (a == 2)
        {
            for (int j = i + 1; j < X; j++)
            {
                IP[j - i - 1] = A[j];
            }
            for (int j = X - i - 1; j < 30; j++)
            {
                IP[j] = '\0';
            }
            break;
        }
    }
    return IP;
}
char *CHECK_URL(char input[])
{
    char ABCD[1100];
    strcpy(ABCD, find_URL(input));
    strlwr(ABCD);
    removeSubstring(ABCD, "https://");
    removeSubstring(ABCD, "http://");
    strcpy(ABCD, remove_after_forward_slash(ABCD));
    char *ABCDEFG = (char *)malloc(strlen(ABCD) * sizeof(char));
    strcpy(ABCDEFG, ABCD);
    //printf("%s",ABCDEFG);
    return ABCDEFG;
}
int add_or_lookup(char input[])
{
    if (input[0] == 'a')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    scanf("%d%*c", &n);

    char save[n][1100];
    char save_URL[n][1100];
    char save_IP[n][30];
    int HOW_MANY_SAVE = 0;
    // char wow[1100];
    for (int i = 0; i < n; i++)
    {
        fgets(save[i], sizeof(save), stdin);
        save[i][strcspn(save[i], "\n")] = '\0';

        if (add_or_lookup(save[i]))
        {
            strcpy(save_URL[HOW_MANY_SAVE], CHECK_URL(find_URL(save[i])));
            strcpy(save_IP[HOW_MANY_SAVE], find_IP(save[i]));
            HOW_MANY_SAVE++;
        }
        else
        {
            int flag = 0;
            for (int j = HOW_MANY_SAVE - 1; j >= 0; j--) // BUG?!
            {
                if (!strcmp(CHECK_URL(find_URL(save[i])), save_URL[j]))
                {
                    printf("%s\n", save_IP[j]);
                    break;
                }
                else
                {
                    flag++;
                }
            }
            if (flag == HOW_MANY_SAVE - 1 && flag != 0)
            {
                printf("URL not found\n");
            }
        }

        // strcpy(wow, find_IP(save[i]));
        // printf("%s\n", wow);
    }
    /*char ABCD[1100];
    strcpy(ABCD, find_URL(save[0]));
    strlwr(ABCD);
    removeSubstring(ABCD,"https://");
    removeSubstring(ABCD,"http://");
    strcpy(ABCD, remove_after_forward_slash(ABCD));
    printf("%s", ABCD);*/

    // char HI[] = "HI MY NAMID IS *(HUIL)sdfv&*&@*eru123";
    // strlwr(HI);
    // printf("%s",HI);

    return 0;
}