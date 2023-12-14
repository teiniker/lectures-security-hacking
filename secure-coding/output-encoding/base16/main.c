#include <stdio.h>
#include <string.h>
#include "base16.h"

int main(void)
{
	// setup binary data
 	uint8_t bytes[] = {0x12, 0xAB, 0x34, 0xCD};

	// convert binary data to hex
	char *hex = byte_array_to_hex_string(bytes, 4);
	printf("hex string: %s\n", hex);

	// convert hex back to binary data
	size_t binlen;
	unsigned char *bin = hex_string_to_byte_array(hex, &binlen);
	printf("bytes[%ld]: ", binlen);
	for(uint8_t i = 0; i < binlen; i++)
		printf("%02x ", bin[i]);	
	printf("\n");

	// cleanup
	free(bin);
	free(hex);
	
	return 0;
}
