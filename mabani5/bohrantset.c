#include <stdio.h> //402106134   محمدحسن شفاعت
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);

    int *input_adad = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", input_adad + i);
    }
    scanf("\n");

    char *input_char = malloc(4 * n * sizeof(char));
    for (int i = 0; i < 4 * n; i++)
    {
        scanf("%c", input_char + i);
    }

    int *input_adad_dodoi = malloc(4 * n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        *(input_adad_dodoi + 4 * i) = *(input_adad + i) % 256;
        *(input_adad_dodoi + 4 * i + 1) = (*(input_adad + i) >> 8) % 256;
        *(input_adad_dodoi + 4 * i + 2) = (*(input_adad + i) >> 16) % 256;
        *(input_adad_dodoi + 4 * i + 3) = (*(input_adad + i) >> 24) % 256;
    }

    int flag = 0;
    for (int i = 0; i < 4 * n; i++)
    {

        if (*(input_char + i) != *(input_adad_dodoi + i))
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    free(input_adad);
    free(input_char);
    free(input_adad_dodoi);

    return 0;
}
