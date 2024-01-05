#include <stdio.h> //402106134   محمدحسن شفاعت
#include <stdlib.h>

int main()
{

    int first_n;
    scanf("%d%*c", &first_n);

    int *save_first_type = (int *)malloc(first_n * sizeof(int));

    for (int i = 0; i < first_n; i++)
    {
        scanf("%d%*c", save_first_type + i);
    }

    unsigned char *save_address = (unsigned char *)malloc(1000 * sizeof(unsigned char));
    char *INPUT;
    int INT_1;
    unsigned int UNSIGNED_INT_1;
    short SHORT_1;
    unsigned short UNSIGNED_SHORT_1;
    char CHAR_1;
    long long LONGLONG_1;

    int INDEX_1 = 0;

    for (int i = 0; i < first_n; i++)
    {
        switch (*(save_first_type + i))
        {
        case 0:
            scanf("%d%*c", &INT_1);
            INPUT = (char *)&INT_1;
            for (int j = INDEX_1; j < INDEX_1 + 4; j++)
            {
                *(save_address + j) = *(INPUT + (-j + INDEX_1 + 3));
            }
            INDEX_1 += 4;
            break;
        case 1:
            scanf("%u%*c", &UNSIGNED_INT_1);
            INPUT = (char *)&UNSIGNED_INT_1;
            for (int j = INDEX_1; j < INDEX_1 + 4; j++)
            {
                *(save_address + j) = *(INPUT + (-j + INDEX_1 + 3));
            }
            INDEX_1 += 4;
            break;
        case 2:
            scanf("%hd%*c", &SHORT_1);
            INPUT = (char *)&SHORT_1;
            for (int j = INDEX_1; j < INDEX_1 + 2; j++)
            {
                *(save_address + j) = *(INPUT + (-j + INDEX_1 + 1));
            }
            INDEX_1 += 2;
            break;
        case 3:
            scanf("%hu%*c", &UNSIGNED_SHORT_1);
            INPUT = (char *)&UNSIGNED_SHORT_1;
            for (int j = INDEX_1; j < INDEX_1 + 2; j++)
            {
                *(save_address + j) = *(INPUT + (-j + INDEX_1 + 1));
            }
            INDEX_1 += 2;
            break;
        case 4:
            scanf("%c%*c", &CHAR_1);
            INPUT = (char *)&CHAR_1;
            for (int j = INDEX_1; j < INDEX_1 + 1; j++)
            {
                *(save_address + j) = *(INPUT + (-j + INDEX_1));
            }
            INDEX_1 += 1;
            break;
        case 5:
            scanf("%lld%*c", &LONGLONG_1);
            INPUT = (char *)&LONGLONG_1;
            for (int j = INDEX_1; j < INDEX_1 + 8; j++)
            {
                *(save_address + j) = *(INPUT + (-j + INDEX_1 + 7));
            }
            INDEX_1 += 8;
            break;
        }
    }
    int second_n;
    scanf("%d", &second_n);

    int *save_second_type = (int *)malloc(second_n * sizeof(int));

    for (int i = 0; i < second_n; i++)
    {
        scanf("%d", save_second_type + i);
    }

    int INDEX_2 = 0;
    for (int i = 0; i < second_n; i++)
    {
        switch (*(save_second_type + i))
        {
        case 0:
            printf("%d\n", *(int *)(save_address + INDEX_2));
            INDEX_2 += 4;
            break;
        case 1:
            printf("%u\n", *(unsigned int *)(save_address + INDEX_2));
            INDEX_2 += 4;
            break;
        case 2:
            printf("%hd\n", *(short *)(save_address + INDEX_2));
            INDEX_2 += 2;
            break;
        case 3:
            printf("%hu\n", *(unsigned short *)(save_address + INDEX_2));
            INDEX_2 += 2;
            break;
        case 4:
            printf("%c\n", *(char *)(save_address + INDEX_2));
            INDEX_2 += 1;
            break;
        case 5:
            printf("%lld\n", *(long long int *)(save_address + INDEX_2));
            INDEX_2 += 8;
            break;
        case 6:
            printf("%.2e\n", *(float *)(save_address + INDEX_2));
            INDEX_2 += 4;
            break;
        case 7:
            printf("%.4e\n", *(double *)(save_address + INDEX_2));
            INDEX_2 += 8;
            break;
        }
    }
}