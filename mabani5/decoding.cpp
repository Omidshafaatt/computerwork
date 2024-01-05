#include<stdio.h>
#include<stdlib.h>
//#include "grader.h"

void function(unsigned long long address, int pointerscount,  int bytes) {
    char* address1 = (char *) address;
    for ( int i=0; i < pointerscount-1; i++) {
        address1 = *((char **) address1);
    } 

    unsigned long long value =0; 
    for(int i = (bytes-1);i>=0 ; i--) {
        value = value << 8;
        value += (unsigned char) *(address1 + i);
    }
    printf("%llu\n", value);
}

void decryption(char *input) {
    int tempNum=0;    
    int tempBase=0;
    int tempBytes=0;
    int tempPointers=0;
    int numLines =0;
    long long int tempaddress = 0;
    int status= 0;
    int j =0;
    int i =0;
    while(status==0) {
        numLines *= 10;
        numLines += input[i] - 48;
        i++;
        if( *(input+i) == '\n') status=1;
    }
    i++;
    while(numLines>0) {
        switch (*(input + i)) {
            case '\0':
            case '\n':
                function(tempaddress, tempPointers, tempBytes);
                tempBase = 0;
                tempBytes = 0;
                tempPointers = 0;
                tempaddress = 0;
                tempNum = 0;
                numLines--;
                j++;
                break; 
            case '.': 
                if(j%4==0) {
                    tempBase = tempNum;
                    tempNum = 0;
                    j++;
                }
                else if (j%4==1) {
                    tempBytes = tempNum;
                    tempNum = 0;
                    j++;
                }
                else if(j%4==2) {
                    tempPointers = tempNum;
                    tempNum = 0;
                    j++;
                }
                break; 
            default : 
                if(j%4==3) {
                        tempaddress *= tempBase;
                        switch(*(input+i)) {
                            case 'A':
                            tempaddress += 10;
                            break;
                            case 'B':
                            tempaddress += 11;
                            break;
                            case 'C':
                            tempaddress += 12;
                            break;
                            case 'D':
                            tempaddress += 13;
                            break;
                            case 'E':
                            tempaddress += 14;
                            break;
                            case 'F':
                            tempaddress += 15;
                            break;
                            case 'G':
                            tempaddress += 16;
                            break;
                            case 'H':
                            tempaddress += 17;
                            break;
                            case 'I':
                            tempaddress += 18;
                            break;
                            case 'J':
                            tempaddress += 19;
                            break;
                            case 'K':
                            tempaddress += 20;
                            break;
                            case 'L':
                            tempaddress += 21;
                            break;
                            case 'M':
                            tempaddress += 22;
                            break;
                            case 'N':
                            tempaddress += 23;
                            break;
                            case 'O':
                            tempaddress += 24;
                            break;
                            case 'P':
                            tempaddress += 25;
                            break;
                            case 'Q':
                            tempaddress += 26;
                            break;
                            case 'R':
                            tempaddress += 27;
                            break;
                            case 'S':
                            tempaddress += 28;
                            break;
                            case 'T':
                            tempaddress += 29;
                            break;
                            case 'U':
                            tempaddress += 30;
                            break;
                            case 'V':
                            tempaddress += 31;
                            break;
                            case 'W':
                            tempaddress += 32;
                            break;
                            case 'X':
                            tempaddress += 33;
                            break;
                            case 'Y':
                            tempaddress += 34;
                            break;
                            case 'Z':
                            tempaddress += 35;
                            break;
                            default:
                            tempaddress += (*(input+i)-48);
                            break;
                        }
                }
                
                else {
                    tempNum *=10;
                    tempNum += (*(input + i)-48);
                }      
        }

        i++;
    }
}