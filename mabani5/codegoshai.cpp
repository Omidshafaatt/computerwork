#include <stdio.h> //402106134 محمدحسن شفاعت
#include <stdlib.h>
//#include "grader.h"
void CODEGOSHA(int Count_Of_Bytes, int Level, unsigned long long Address)
{
    char *A = (char *)Address;
    for (int i = 0; i < Level - 1; i++)
    {
        A = *((char **)A);
    }
    unsigned long long Its_ME = 0;
    for (int i = Count_Of_Bytes - 1; i >= 0; i--)
    {
        Its_ME = (Its_ME * 256) + (unsigned char)*(A + i);
    }
    printf("%llu\n", Its_ME);
}

void decryption(char *input)
{
    int toole_reshte = 0;
    //int n = 1;
    while (*(input + toole_reshte) != '\0')
    {
        /*if (*(input + toole_reshte) == '\n')
        {
            n++;
        }*/
        toole_reshte++;
    }
    toole_reshte++;

    int a = 0;
    int Count_Of_Bytes = 0;
    int Level = 0;
    int Base = 0;
    long long int Address = 0;
    int b = 0;
    //while (n > 0)
    //{
        for (int x = 0; x < toole_reshte; x++)
        {
            switch (*(input + x))
            {
            case '\0':
            case '\n':
                CODEGOSHA(Count_Of_Bytes, Level, Address);
                b = Count_Of_Bytes = Level = Address = 0;
                //n--;
                a++;
                break;
            case '.':
                if (a % 4 == 0)
                    Base = b;
                else if (a % 4 == 1)
                    Count_Of_Bytes = b;
                else if (a % 4 == 2)
                    Level = b;
                b = 0;
                a++;
                break;
            default:
                if (a % 4 == 3)
                {
                    Address *= Base;
                    if (*(input + x) >= 'A' && *(input + x) <= 'Z')
                    {
                        Address += *(input + x) - 'A' + 10;
                    }
                    else
                    {
                        Address += *(input + x) - '0';
                    }
                }
                else
                {
                    b = b * 10 + (*(input + x) - '0');
                }
                break;
            }
        }
    //}
}
