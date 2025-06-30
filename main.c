#include <stdio.h>
#define ARRAYLENGTH 4000


void pause(void);
void interpret(FILE *file);



int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        FILE *fptr = fopen(argv[1], "r");
        interpret(fptr);
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



    char *i = memory;
    char character;


    while ((character = fgetc(file)) != EOF)
    {
        switch (character)
        {
        case '+':
            ++(*i);
            break;
        case '-':
            --(*i);
            break;
        case '>':
            ++i;
            break;
        case '<':
            --i;
            break;

        case ',':
            *i = getchar();
            break;
        case '.':
            putchar(*i);
            break;

        case '[':
            break;
        case ']':
            break;
        }
    }
}