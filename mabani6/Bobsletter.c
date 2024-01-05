#include <stdio.h> //402106134 محمدحسن شفاعت
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d%*c", &n);

    char save[10000];
    for (int i = 0; i < n; i++)
    {
        fgets(save, sizeof(save), stdin);
        save[strlen(save) - 1] = '\0';
        int j = 0;
        while( j < strlen(save))
        {
            if (save[j] == '#')
            {     
                memmove(&save[j], &save[j + 1], strlen(save) - j);
                if(j >= 1)
                {
                    memmove(&save[j - 1], &save[j], strlen(save) - (j - 1));
                    j -= 2;
                }
                else
                {
                    j-=1;
                }
            }
            else if (save[j] == '*' && j >= 1)
            {
                save[j] = save[j - 1];
            }
            else if (save[j] == '*' && j == 0)
            {
                memmove(&save[j], &save[j + 1], strlen(save) - j);
                j -= 1;
            }
            j++;

        }
        puts(save);
    }
    return 0;
}