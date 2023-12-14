#ifndef _HEX_H_
#define _HEX_H_

#include <stdlib.h>
#include <stdint.h>

char* byte_array_to_hex_string(const uint8_t* bytes, size_t size); 
uint8_t* hex_string_to_byte_array(const char* hex_string, size_t *size); 

#endif // _HEX_H_