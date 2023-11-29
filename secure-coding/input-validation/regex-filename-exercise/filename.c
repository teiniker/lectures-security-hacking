#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <regex.h>

// TODO: Define regular expression

bool is_valid_filename(char *filename);

int main() 
{
//    char *filename = "shadow";
    char *filename = "filename.c";
//    char *filename = "../filename.c";

    if(!is_valid_filename(filename)) 
    {
        printf("Invalid filename\n");
        return 1;
    }

    printf("Load file from: %s\n", filename);

    return 0;
}

// TODO: Implement function