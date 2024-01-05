#include <stdio.h> //402106134 محمدحسن شفاعت
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
void removeCharsFromLeft(char str[], int n) {
    int len = strlen(str);
    if (n >= len) {
        // اگر تعداد حروف حذفی بیشتر یا مساوی طول رشته باشد، رشته خالی می‌شود
        str[0] = '\0';
    } else {
        // انتقال باقیمانده حروف به سمت چپ
        memmove(str, str + n, len - n + 1);
    }
}
char *remove_http(char A[])
{
    if (A[0] == 'h' && A[1] == 't' && A[2] == 't' && A[3] == 'p' && A[4] == ':' && A[5] == '/' && A[6] == '/')
    {
        removeCharsFromLeft(A , 7);
    }
}
char *remove_https(char A[])
{
    if (A[0] == 'h' && A[1] == 't' && A[2] == 't' && A[3] == 'p' && A[4] == 's' && A[5] == ':' && A[6] == '/' && A[7] == '/')
    {
        removeCharsFromLeft(A , 8);
    }
}
char *remove_www(char A[])
{
    if (A[0] == 'w' && A[1] == 'w' && A[2] == 'w' && A[3] == '.')
    {
        removeCharsFromLeft(A , 4);
    }
}
char *strlwr(char *str)
{
    if (str == NULL)
    {
        return NULL; // Handle NULL pointer
    }

    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower((unsigned char)str[i]);
    }

    return str;
}
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
    if (ABCD[4] == 's')
    {
        remove_https(ABCD);
    }
    else
    {
        remove_http(ABCD);
    }
    //remove_http(ABCD);
    //remove_https(ABCD);
    remove_www(ABCD);
    //removeSubstring(ABCD, "https://");
    //removeSubstring(ABCD, "http://");
    //removeSubstring(ABCD, "www.");
    strcpy(ABCD, remove_after_forward_slash(ABCD));
    char *ABCDEFG = (char *)malloc(strlen(ABCD) * sizeof(char));
    strcpy(ABCDEFG, ABCD);
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

    for (int i = 0; i < n; i++)
    {
        fgets(save[i], sizeof(save), stdin);
        save[i][strcspn(save[i], "\n")] = '\0';

        if (add_or_lookup(save[i]))
        {
            strcpy(save_URL[HOW_MANY_SAVE], CHECK_URL(save[i]));
            strcpy(save_IP[HOW_MANY_SAVE], find_IP(save[i]));
            HOW_MANY_SAVE++;
        }
        else
        {
            int flag = 0;
            for (int j = HOW_MANY_SAVE - 1; j >= 0; j--) // BUG?!
            {
                if (!strcmp(CHECK_URL(save[i]), save_URL[j]))
                {
                    printf("%s\n", save_IP[j]);
                    break;
                }
                else
                {
                    flag++;
                }
            }
            if (flag == HOW_MANY_SAVE)
            {
                printf("URL not found\n");
            }
        }
    }
    return 0;
}