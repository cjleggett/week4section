#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

void copy_cap(FILE*, FILE*, FILE*);

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./copy infile copy_outfile capitalized_outfile\n");
        return 1;
    }
    FILE *infile = fopen(argv[1], "r");
    FILE *copy_outfile = fopen(argv[2], "w");
    FILE *capitalized_outfile = fopen(argv[3], "w");

    // Copy file:
    copy_cap(infile, copy_outfile, capitalized_outfile);


    fclose(infile);
    fclose(copy_outfile);
    fclose(capitalized_outfile);
}

void copy_cap(FILE *infile, FILE *copy_outfile, FILE *capitalized_outfile)
{
    while (true)
    {
        char c = fgetc(infile);
        if (c == EOF)
        {
            return;
        }
        fputc(c, copy_outfile);
        fputc(toupper(c), capitalized_outfile);

    }
}
