#include <stdio.h> //402106134   محمدحسن شفاعت
#include <stdlib.h>
#include <string.h>

union IntByte
{
    int intValue;
    unsigned char bytes[4];
};
union UnsignedIntByte
{
    unsigned int UnsignedIntValue;
    unsigned char bytes[4];
};
union ShortByte
{
    short ShortValue;
    unsigned char bytes[2];
};
union UnsignedShortByte
{
    unsigned short UnsignedShortValue;
    unsigned char bytes[2];
};
union CharByte
{
    char CharValue;
    unsigned char bytes[1];
};
union LongLongByte
{
    long long LongLongValue;
    unsigned char bytes[8];
};
union FloatByte
{
    float FloatValue;
    unsigned char bytes[4];
};
union DoubleByte
{
    double DoubleValue;
    unsigned char bytes[8];
};

int main()
{

    int first_n;
    scanf("%d", &first_n);

    int save_first_type[first_n];

    for (int i = 0; i < first_n; i++)
    {
        scanf("%d", &save_first_type[i]);
    }
    scanf("\n");
    int tedad_byte = 0;
    for (int i = 0; i < first_n; i++)
    {
        switch (save_first_type[i])
        {
        case 0:
        case 1:
        case 6:
            tedad_byte = tedad_byte + 4;
            break;
        case 2:
        case 3:
            tedad_byte = tedad_byte + 2;
            break;
        case 4:
            tedad_byte = tedad_byte + 1;
            break;
        case 5:
        case 7:
            tedad_byte = tedad_byte + 8;
            break;
        }
    }

    int BYTEEE[tedad_byte];
    int flag = 0;
    union IntByte fb0;
    union UnsignedIntByte fb1;
    union ShortByte fb2;
    union UnsignedShortByte fb3;
    union CharByte fb4;
    union LongLongByte fb5;
    union FloatByte fb6;
    union DoubleByte fb7;

    for (int i = 0; i < first_n; i++)
    {
        switch (*(save_first_type + i))
        {
        case 0:
            scanf("%d", &fb0.intValue);
            for (int j = flag; j < flag + 4; j++)
            {
                BYTEEE[j] = fb0.bytes[j - flag];
            }

            flag += 4;
            if (flag != tedad_byte)
            {
                scanf("\n");
            }
            break;
        case 1:
            scanf("%u", &fb1.UnsignedIntValue);
            for (int j = flag; j < flag + 4; j++)
            {
                BYTEEE[j] = fb1.bytes[j - flag];
            }

            flag += 4;
            if (flag != tedad_byte)
            {
                scanf("\n");
            }
            break;
        case 6:
            scanf("%f", &fb6.FloatValue);
            for (int j = flag; j < flag + 4; j++)
            {
                BYTEEE[j] = fb6.bytes[j - flag];
            }

            flag += 4;
            if (flag != tedad_byte)
            {
                scanf("\n");
            }
            break;
        case 2:
            scanf("%hd", &fb2.ShortValue);
            for (int j = flag; j < flag + 2; j++)
            {
                BYTEEE[j] = fb2.bytes[j - flag];
            }

            flag += 2;
            if (flag != tedad_byte)
            {
                scanf("\n");
            }
            break;
        case 3:
            scanf("%hu", &fb3.UnsignedShortValue);
            for (int j = flag; j < flag + 2; j++)
            {
                BYTEEE[j] = fb3.bytes[j - flag];
            }

            flag += 2;
            if (flag != tedad_byte)
            {
                scanf("\n");
            }
            break;

        case 4:
            scanf("%c", &fb4.CharValue);
            for (int j = flag; j < flag + 1; j++)
            {
                BYTEEE[j] = fb4.bytes[j - flag];
            }

            flag += 1;
            if (flag != tedad_byte)
            {
                scanf("\n");
            }
            break;
        case 5:
            scanf("%llu", &fb5.LongLongValue);
            for (int j = flag; j < flag + 8; j++)
            {
                BYTEEE[j] = fb5.bytes[j - flag];
            }

            flag += 8;
            if (flag != tedad_byte)
            {
                scanf("\n");
            }
            break;
        case 7:
            scanf("%lf", &fb7.DoubleValue);
            for (int j = flag; j < flag + 8; j++)
            {
                BYTEEE[j] = fb7.bytes[j - flag];
            }

            flag += 8;
            if (flag != tedad_byte)
            {
                scanf("\n");
            }
            break;
        }
    }

    for (int i = 0; i < tedad_byte; i++)
    {
        printf("%x\n", BYTEEE[i]);
    }

    int second_n;
    scanf("%d", &second_n);

    int save_second_type[second_n];

    for (int i = 0; i < second_n; i++)
    {
        scanf("%d", &save_second_type[i]);
    }

    return 0;
}