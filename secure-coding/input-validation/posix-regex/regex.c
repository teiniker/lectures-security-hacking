#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main() 
{
    char *input = "example@example.com";
    char *pattern = "^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$";

    // Compile the regular expression
    regex_t regex;
    int ret = regcomp(&regex, pattern, REG_EXTENDED);
    if(ret) 
    {
        fprintf(stderr, "Could not compile regex\n");
        exit(1);
    }

    // Execute the regular expression
    ret = regexec(&regex, input, 0, NULL, 0);
    if(ret) 
    {
        char error_message[100];
        regerror(ret, &regex, error_message, sizeof(error_message));
        fprintf(stderr, "Regex match failed: %s\n", error_message);
        return 1;
    } 
    
    printf("Valid mail address: %s\n", input);

    // Free the compiled regular expression
    regfree(&regex);

    return 0;
}
