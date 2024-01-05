#include <stdio.h> //402106134 محمدحسن شفاعت
#include <string.h>
#include <stdlib.h>
int does_this_string_have_space(char *input)
{
    int flag = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            return 1;
        }
        else
        {
            flag++;
        }
    }
    if (flag == strlen(input))
    {
        return 0;
    }
}
int find_number(char *input)
{
    int result = 0;
    int b = 1;
    for (int i = strlen(input) - 2; i > 0; i--)
    {
        result += b * (input[i] - '0');
        b = 10 * b;
    }
    return result;
}
void delete(int first_index, int number, char scw, char *input)
{
    if (scw == 's')
    {
        int X = 0;
        for (int i = first_index; i < strlen(input); i++)
        {
            if (input[i] == '.' || input[i] == '?' || input[i] == '!')
            {
                X++;
            }
            if (X == number) /////////////// compare with w!
            {
                memmove(&input[first_index], &input[i + 1], strlen(input) - first_index); ////// firts index + i - 1
                break;
            }
        }
        if (X < number)
        {
            printf("out of bounds\n");
        }
    }
    if (scw == 'c')
    {
        if (first_index + number >= strlen(input))
        {
            printf("out of bounds\n");
        }
        else
        {
            memmove(&input[first_index], &input[first_index + number], strlen(input) - first_index);
        }
    }
    if (scw == 'w')
    {
        int X = 0;
        for (int i = first_index; i < strlen(input); i++)
        {
            if (input[i] == ' ')
            {
                X++;
            }
            if (X == number) ///////////////////  +1 ?
            {
                memmove(&input[first_index], &input[i + 1], strlen(input) - first_index); ///// i - 2? ////// firts index + i - 2
                break;
            }
        }
        if (X < number)
        {
            printf("out of bounds\n");
        }
    }
}

void insert(int first_index, char *sentence, char *input)
{
    char *save = (char *)malloc(strlen(input) * sizeof(char));
    strcpy(save, input);
    for (int i = first_index; i < first_index + strlen(sentence); i++)
    {
        input[i] = sentence[i - first_index];
    }
    for (int i = first_index + strlen(sentence); i < strlen(sentence) + strlen(input); i++)
    {
        input[i] = save[i - strlen(sentence)];
    }
}

void show(int first_index, int number, char scw, char *input)
{
    if (scw == 's')
    {
        int X = 0;
        for (int i = first_index; i < strlen(input); i++)
        {
            if (input[i] == '.' || input[i] == '?' || input[i] == '!')
            {
                X++;
            }
            if (X == number)
            {
                for (int j = first_index; j <= i; j++) ////// firts index + i - 1
                {
                    printf("%c", input[j]);
                }
                printf("\n");
                break;
            }
        }
        if (X < number)
        {
            printf("out of bounds\n");
        }
    }
    if (scw == 'c')
    {
        if (first_index + number >= strlen(input))
        {
            printf("out of bounds\n");
        }
        else
        {
            for (int i = first_index; i < first_index + number; i++)
            {
                printf("%c", input[i]);
            }
            printf("\n");
        }
    }
    if (scw == 'w')
    {
        int X = 0;
        for (int i = first_index; i < strlen(input); i++)
        {
            if (input[i] == ' ')
            {
                X++;
            }
            if (X == number)
            {
                for (int j = first_index; j < i; j++) ////// i - 2 ?
                {
                    if (input[j] != '\n')
                    {
                        printf("%c", input[j]);
                    }
                }
                printf("\n");
                break;
            }
        }
        if (X < number)
        {
            printf("out of bounds\n");
        }
    }
}
void jump(int *first_index, int number, char scw, char *input)
{
    if (scw == 's')
    {
        int X = 0;
        for (int i = *first_index; i < strlen(input); i++)
        {
            if (input[i] == '.' || input[i] == '?' || input[i] == '!')
            {
                X++;
            }
            if (X == number)
            {
                *first_index = i + 1; ///////MOHEM  i + 1
                break;
            }
        }
        if (X < number)
        {
            printf("out of bounds\n");
        }
    }
    if (scw == 'c')
    {
        if (*first_index + number >= strlen(input))
        {
            printf("out of bounds\n");
        }
        else
        {
            *first_index = *first_index + number;
        }
    }
    if (scw == 'w')
    {
        int X = 0;
        for (int i = *first_index; i < strlen(input); i++)
        {
            if (input[i] == ' ')
            {
                X++;
            }
            if (X == number)
            {
                *first_index = i;
                break;
            }
        }
        if (X < number)
        {
            printf("out of bounds\n");
        }
    }
}
void copy(int first_index, int number, char scw, char *input, char *clip_board)
{
    if (scw == 's')
    {
        int X = 0;
        for (int i = first_index; i < strlen(input); i++)
        {
            if (input[i] == '.' || input[i] == '?' || input[i] == '!')
            {
                X++;
            }
            if (X == number)
            {
                for (int j = first_index; j < first_index + i - 1; j++)
                {
                    clip_board[j - first_index] = input[j];
                }
                clip_board[i - 1] = '\0';
                break;
            }
        }
        if (X < number)
        {
            printf("out of bounds\n");
        }
    }
    if (scw == 'c')
    {
        if (first_index + number >= strlen(input))
        {
            printf("out of bounds\n");
        }
        else
        {
            for (int i = first_index; i < first_index + number; i++)
            {
                clip_board[i - first_index] = input[i];
            }
            clip_board[number] = '\0';
        }
    }
    if (scw == 'w')
    {
        int X = 0;
        for (int i = first_index; i < strlen(input); i++)
        {
            if (input[i] == ' ')
            {
                X++;
            }
            if (X == number)
            {
                for (int j = first_index; j < first_index + i - 2; j++) ////// i - 2 ?
                {
                    clip_board[j - first_index] = input[j];
                }
                clip_board[i - 2] = '\0';
                break;
            }
        }
        if (X < number)
        {
            printf("out of bounds\n");
        }
    }
}
void find(char sw, char *word, char *input)
{
    if (sw == 's')
    {
        int X = 1;
        int flag;
        for (int i = 0; i < strlen(input) - strlen(word); i++)
        {
            if (input[i] == '.' || input[i] == '?' || input[i] == '!')
            {
                X++;
            }
            flag = 0;
            for (int j = 0; j < strlen(word); j++)
            {
                if (input[i + j] != word[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("%d\n", X);
                break;
            }
        }
        if (flag == 1)
        {
            printf("not found");
        }
    }
    if (sw == 'w')
    {
        int X = 1; ////////////momkene nabashe va sefr bede
        int flag;
        for (int i = 0; i < strlen(input) - strlen(word); i++)
        {
            if (input[i] == ' ')
            {
                X++;
            }
            flag = 0;
            for (int j = 0; j < strlen(word); j++)
            {
                if (input[i + j] != word[j])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                printf("%d\n", X);
                break;
            }
        }
        if (flag == 1)
        {
            printf("not found");
        }
    }
}
int main()
{
    char input;
    char *save = (char *)malloc(1000 * sizeof(char));
    char *dastoorat = (char *)malloc(1000 * sizeof(char));
    char *CLIP_BOARD = (char *)malloc(1000 * sizeof(char));
    CLIP_BOARD[0] = '\0';
    int MODE = 0; ////// 0 == edit
    int esharegar = 0;

    int i = 0;
    while ((input = getchar()) != '#')
    {
        *(save + i) = input;
        i++;
    }
    *(save + i) = '\0';
    // puts(save);
    scanf("\n");
    while (1)
    {
        gets(dastoorat);

        switch (dastoorat[0])
        {
        case 'R':
            MODE = 1; /// READ
            break;

        case 'E':
            MODE = 0; /// EDIT
            break;
        case 'd':
            if (MODE == 0)
            {
                delete (esharegar, find_number(dastoorat), dastoorat[strlen(dastoorat) - 1], save);
            }
            else
            {
                printf("invalid command\n");
            }
            break;
        case 'i':
            if (dastoorat[1] == ' ')
            {
                if (MODE == 0)
                {
                    memmove(&dastoorat[0], &dastoorat[2], strlen(dastoorat));
                    // puts(dastoorat);
                    // printf("%d\n",does_this_string_have_space(dastoorat));
                    if (does_this_string_have_space(dastoorat) == 1 && dastoorat[0] == '"' && dastoorat[strlen(dastoorat) - 1] == '"')
                    {
                        dastoorat[strlen(dastoorat) - 1] = '\0';
                        memmove(&dastoorat[0], &dastoorat[1], strlen(dastoorat));
                        insert(esharegar, dastoorat, save);
                    }
                    else if (does_this_string_have_space(dastoorat) == 0 && dastoorat[0] != '"')
                    {
                        insert(esharegar, dastoorat, save);
                    }
                    else
                    {
                        printf("invalid command\n");
                    }
                }
                else
                {
                    printf("invalid command\n");
                }
            }
            else
            {
                printf("invalid command\n");
            }
            break;
        case 'p':
            if (MODE == 0)
            {
                if (CLIP_BOARD[0] == '\0')
                {
                    printf("clipboard is empty\n");
                }
                else
                {
                    insert(esharegar, CLIP_BOARD, save);
                }
            }
            else
            {
                printf("invalid command\n");
            }
            break;
        case 's':
            if (dastoorat[strlen(dastoorat) - 1] != 's' && dastoorat[strlen(dastoorat) - 1] != 'c' && dastoorat[strlen(dastoorat) - 1] != 'w')
            {
                printf("invalid command\n");
            }
            else
            {
                if (MODE == 1)
                {
                    show(esharegar, find_number(dastoorat), dastoorat[strlen(dastoorat) - 1], save);
                }
                else
                {
                    printf("invalid command\n");
                }
            }
            break;
        case 'j':
            if (MODE == 1)
            {
                jump(&esharegar, find_number(dastoorat), dastoorat[strlen(dastoorat) - 1], save);
                // printf("%d\n",esharegar);
            }
            else
            {
                printf("invalid command\n");
            }
            break;
        case 'c':
            if (MODE == 1)
            {
                copy(esharegar, find_number(dastoorat), dastoorat[strlen(dastoorat) - 1], save, CLIP_BOARD);
            }
            else
            {
                printf("invalid command\n");
            }
            break;
        case 'f':
            if (MODE == 1)
            {
                char temp = dastoorat[strlen(dastoorat) - 1];
                memmove(&dastoorat[0], &dastoorat[2], strlen(dastoorat));
                dastoorat[strlen(dastoorat) - 2] = '\0';
                find(temp, dastoorat, save);
            }
            else
            {
                printf("invalid command\n");
            }
            break;
        case '<':
            if (MODE == 1)
            {
                esharegar = 0;
            }
            else
            {
                printf("invalid command\n");
            }
            break;
        case '#':
            if (dastoorat[1] == '\0') ////////////////
            {
                return 0;
            }
        default:
            printf("invalid command\n"); ////// \n?
        }
    }
    // gets(dastoorat);
    //  gets(A);
    //   delete(2,4,'c',A);
    //   delete(2,4,'w',A);
    //   delete(2,4,'s',A);
    // show(5, 2, 's', save);
    //   insert(2,"are you ok",A);
    //   int k = 3;
    //   int *x = &k;
    //   jump(x,1,'s',A);
    //   printf("%d",k);;
    //   copy(2,3,'s',A,CLIP_BOARD);
    //  find('w',"hi",A);
    //  puts(A);

    return 0;
}