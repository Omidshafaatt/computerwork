#include <stdio.h>
#include <stdlib.h>

int main() {
    int first_n;
    scanf("%d", &first_n);

    unsigned char *buffer = (unsigned char *)malloc(1000 * sizeof(unsigned char));

    int currentIndex = 0;
    for (int i = 0; i < first_n; ++i) {
        int dataType;
        scanf("%d", &dataType);

        switch (dataType) {
            case 0: {
                int *data = (int *)(buffer + currentIndex);
                scanf("%d", data);
                currentIndex += sizeof(int);
                break;
            }
            case 1: {
                unsigned int *data = (unsigned int *)(buffer + currentIndex);
                scanf("%u", data);
                currentIndex += sizeof(unsigned int);
                break;
            }
            case 2: {
                short *data = (short *)(buffer + currentIndex);
                scanf("%hd", data);
                currentIndex += sizeof(short);
                break;
            }
            case 3: {
                unsigned short *data = (unsigned short *)(buffer + currentIndex);
                scanf("%hu", data);
                currentIndex += sizeof(unsigned short);
                break;
            }
            case 4: {
                char *data = (char *)(buffer + currentIndex);
                scanf("\n%c", data);
                currentIndex += sizeof(char);
                break;
            }
            case 5: {
                long long int *data = (long long int *)(buffer + currentIndex);
                scanf("%lld", data);
                currentIndex += sizeof(long long int);
                break;
            }
            default:
                break;
        }
    }

    int second_n;
    scanf("%d", &second_n);

    for (int j = 0; j < second_n; ++j) {
        int dataType;
        scanf("%d", &dataType);

        switch (dataType) {
            case 0: {
                int *data = (int *)(buffer + currentIndex);
                printf("%d\n", *data);
                currentIndex += sizeof(int);
                break;
            }
            case 1: {
                unsigned int *data = (unsigned int *)(buffer + currentIndex);
                printf("%u\n", *data);
                currentIndex += sizeof(unsigned int);
                break;
            }
            case 2: {
                short *data = (short *)(buffer + currentIndex);
                printf("%hd\n", *data);
                currentIndex += sizeof(short);
                break;
            }
            case 3: {
                unsigned short *data = (unsigned short *)(buffer + currentIndex);
                printf("%hu\n", *data);
                currentIndex += sizeof(unsigned short);
                break;
            }
            case 4: {
                char *data = (char *)(buffer + currentIndex);
                printf("%c\n", *data);
                currentIndex += sizeof(char);
                break;
            }
            case 5: {
                long long int *data = (long long int *)(buffer + currentIndex);
                printf("%lld\n", *data);
                currentIndex += sizeof(long long int);
                break;
            }
            default:
                break;
        }
    }

    free(buffer);

    return 0;
}
