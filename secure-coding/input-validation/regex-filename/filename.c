#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <regex.h>

const char *pattern = "^[a-zA-Z0-9_]{1,255}(\\.[a-zA-Z0-9]{1,3})?$";
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

bool is_valid_filename(char *filename)
{
    regex_t regex;
    int ret = regcomp(&regex, pattern, REG_EXTENDED);
    if(ret != 0) 
    {
        fprintf(stderr, "Could not compile regex\n");
        return false;
    }

    ret = regexec(&regex, filename, 0, NULL, 0);
    regfree(&regex);

    if(ret == REG_NOMATCH) 
        return false;
    else 
        return true;
}
