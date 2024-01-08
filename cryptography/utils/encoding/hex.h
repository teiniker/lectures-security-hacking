#ifndef _HEX_ENCODING_H_
#define _HEX_ENCODING_H_

char* to_hex_string(uint8_t *bytes, size_t len);
uint8_t hex_value(char hex_digit);
uint8_t* hex_string_to_byte_array(const char* hex_string, size_t *size);

#endif
