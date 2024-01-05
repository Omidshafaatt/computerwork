#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void manipulator(int byteCount, int type, int andStart, unsigned char* charPtr) {
    switch (type) {
        case 0:
        case 1: {
            unsigned int value = 0;
            for (int i = 0; i < byteCount; i++) {
                value |= (charPtr[andStart + i] << (8 * i));
            }
            printf("%u", value);
            break;
        }
        case 2:
        case 3: {
            unsigned short value = (charPtr[andStart + 1] << 8) | charPtr[andStart];
            printf("%hu", value);
            break;
        }
        case 4: {
            char value = charPtr[andStart];
            printf("%c", value);
            break;
        }
        case 5: {
            long long int value = 0;
            for (int i = 0; i < byteCount; i++) {
                value |= ((long long int)charPtr[andStart + i] << (8 * i));
            }
            printf("%lld", value);
            break;
        }
        case 6: {
            uint32_t value = 0;
            for (int i = 0; i < byteCount; i++) {
                value |= (charPtr[andStart + i] << (8 * i));
            }
            float floatValue;
            memcpy(&floatValue, &value, sizeof(float));
            printf("%.2e", floatValue);
            break;
        }
        case 7: {
            uint64_t value = 0;
            for (int i = 0; i < byteCount; i++) {
                value |= ((uint64_t)charPtr[andStart + i] << (8 * i));
            }
            double doubleValue;
            memcpy(&doubleValue, &value, sizeof(double));
            printf("%.4e", doubleValue);
            break;
        }
    }
    printf("\n");
}

int main() {
    int n, byteCount = 0;
    scanf("%d%*c", &n);
    int typeTable[n];

    for (int i = 0; i < n; i++) {
        scanf("%d%*c", &typeTable[i]);
        switch (typeTable[i]) {
            case 0:
            case 1:
            case 3:
            case 5:
            case 7:
                byteCount += 4;
                break;
            case 2:
            case 4:
                byteCount += 2;
                break;
            case 6:
                byteCount += 8;
                break;
        }
    }

    unsigned char charPtr[byteCount];
    int andStart = 0;

    for (int i = 0; i < n; i++) {
        switch (typeTable[i]) {
            case 0:
            case 1:
            case 3:
            case 5:
            case 7: {
                int tempInt;
                scanf("%d%*c", &tempInt);
                unsigned char* tempPtr = (unsigned char*)&tempInt;
                for (int j = 3; j >= 0; j--) {
                    charPtr[andStart++] = tempPtr[j];
                }
                break;
            }
            case 2:
            case 4: {
                short tempValue;
                scanf("%hd%*c", &tempValue);
                unsigned char* tempPtr = (unsigned char*)&tempValue;
                charPtr[andStart++] = tempPtr[1];
                charPtr[andStart++] = tempPtr[0];
                break;
            }
            case 6: {
                float tempFloat;
                scanf("%f%*c", &tempFloat);
                uint32_t tempValue;
                memcpy(&tempValue, &tempFloat, sizeof(float));
                unsigned char* tempPtr = (unsigned char*)&tempValue;
                for (int j = 3; j >= 0; j--) {
                    charPtr[andStart++] = tempPtr[j];
                }
                break;
            }
        }
    }

    int newN;
    scanf("%d%*c", &newN);
    int tempType[newN];

    for (int i = 0; i < newN; i++) {
        scanf("%d%*c", &tempType[i]);
    }

    for (int i = 0; i < newN; i++) {
        manipulator((tempType[i] == 2 || tempType[i] == 3 || tempType[i] == 4) ? 2 : 4,
                     tempType[i], andStart, charPtr);
        andStart += (tempType[i] == 2 || tempType[i] == 3 || tempType[i] == 4) ? 2 : 4;
    }

    return 0;
}
