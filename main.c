#include <stdio.h>
#define ARRAYLENGTH 4000
#define MAXFILESIZE 4000


void pause(void);
void interpret(FILE *file);



int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *fptr = fopen(argv[1], "r");
        if (fptr == NULL)
        {
            printf("File does not exist.");
        } else
        {
            interpret(fptr);
        }
        fclose(fptr);

    } else
    {
        printf("please enter a valid filename.");
    }

    return 0;
}



void pause(void)
{
    printf("Press enter to continue. . .");
    getchar();
}



void interpret(FILE *file)
{
    char memory[ARRAYLENGTH];
    for (int i = 0; i < ARRAYLENGTH; ++i)
    {
        memory[i] = 0;
    }

    char character;
    char fileArray[MAXFILESIZE];
    for (int i = 0; (character = fgetc(file)) != EOF; ++i)
    {
        fileArray[i] = character;
    }


    char *ptr = memory;

    for (int i = 0; (character = fileArray[i]) != EOF; ++i)
    {
        switch (character)
        {
        case '+':
            ++(*ptr);
            break;
        case '-':
            --(*ptr);
            break;
        case '>':
            ++ptr;
            break;
        case '<':
            --ptr;
            break;

        case ',':
            *ptr = getchar();
            break;
        case '.':
            putchar(*ptr);
            break;

        case '[':
            break;
        case ']':
            break;
        }
    }
}