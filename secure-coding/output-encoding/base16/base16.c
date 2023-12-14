#include <string.h>
#include "base16.h"

char hex_char(uint8_t nibble) 
{
    if (nibble < 10) return '0' + nibble;
    return 'a' + (nibble - 10);
}

char* byte_array_to_hex_string(const uint8_t* bytes, size_t size) 
{
    char* hex_string = malloc(size * 2 + 1);
    for (size_t i = 0; i < size; i++) {
        hex_string[i * 2] = hex_char((bytes[i] >> 4) & 0x0F);
        hex_string[i * 2 + 1] = hex_char(bytes[i] & 0x0F);
    }
    hex_string[size * 2] = '\0';
    return hex_string;
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
