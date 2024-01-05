#include <stdio.h> //402106134 محمدحسن شفاعت
#include <string.h>
#include <stdlib.h>



int main()
{
    char *A = (char *)malloc(1000 * sizeof(char));
    gets(A);
    printf("%d",A[3]);
    //gets(A);
    //printf("%d",strlen(A));
    /*int i =0;
    while ((input = getchar()) != '#')
    {
        *(A + i) = input;
        i++;
    }
    *(A + i) = '\0';
    puts(A);*/
    //memmove(&A[0],&A[2],strlen(A));
    //printf("%c\n",A[1]);

    //puts(A);
    return 0;
}