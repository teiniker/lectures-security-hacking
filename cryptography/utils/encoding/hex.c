#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "hex.h"

char* to_hex_string(uint8_t *bytes, size_t len)
{
    char *hex_str = malloc(2 * len + 1);
    char *ptr = hex_str;
    for (size_t i = 0; i < len; i++) 
    {
        sprintf(ptr, "%02x", bytes[i]);
        ptr += 2; 
    }
    return hex_str;
}

uint8_t hex_value(char hex_digit) 
{
    if (hex_digit >= '0' && hex_digit <= '9') 
		return hex_digit - '0';
    if (hex_digit >= 'a' && hex_digit <= 'f') 
		return 10 + hex_digit - 'a';
    return 10 + hex_digit - 'A'; // assuming valid input
}

uint8_t* hex_string_to_byte_array(const char* hex_string, size_t *size) 
{
    size_t len = strlen(hex_string);
    *size = len / 2;
    uint8_t* byte_array = malloc(*size);
    
    for (size_t i = 0; i < *size; i++) 
	{
        byte_array[i] = (hex_value(hex_string[i * 2]) << 4) | hex_value(hex_string[i * 2 + 1]);
    }

    return byte_array;
}
