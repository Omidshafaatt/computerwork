#include <stdio.h> //402106134   محمدحسن شفاعت
#include <stdlib.h>
#include <string.h>

union IntByte
{
    int intValue;
    unsigned char bytes[4];
};
int main() {
    union IntByte fb;
    
    // دریافت یک عدد اعشاری از کاربر
    printf("Enter a floating-point number: ");
    scanf("%f", &fb.intValue);

    int A[4];

    for (int i = 0; i < 4; i++)
    {
        A[i] = fb.bytes[i];
    }
    for (int i = 0; i < 4; i++)
    {
        printf("%x\n",A[i]);
    }
    
    

    return 0;
}