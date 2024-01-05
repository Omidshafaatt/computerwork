#include <stdio.h>
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

int main()
{
    /*char mainString[100]; 
    char subString[20];   

    // دریافت رشته اصلی
    printf("Enter the main string: ");
    fgets(mainString, sizeof(mainString), stdin);

    // حذف کاراکتر newline که توسط fgets افزوده شده است
    mainString[strcspn(mainString, "\n")] = 0;

    // دریافت زیررشته برای حذف
    printf("Enter the substring to remove: ");
    fgets(subString, sizeof(subString), stdin);
    subString[strcspn(subString, "\n")] = 0;
    // حذف زیررشته
    removeSubstring(mainString, subString);

    // چاپ رشته حاصل
    printf("Result: %s\n", mainString);*/
    /*char save[100];
    
        fgets(save, sizeof(save), stdin);
        save[strcspn(save, "\n")] = '\0';
        
        printf("%s",save);*/
    char *A = (char *)malloc(100 * sizeof(char));
    A[0] = '9';
    A[1] = 'c';
    int x = strlen(A);
    printf("%d",x);
    return 0;
}
