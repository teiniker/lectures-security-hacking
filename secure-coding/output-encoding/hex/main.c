#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include "hex.h"

# define SIZE_OF_BIN_DATA 32

int main(int argc, char **argv)
{
	// setup binary data
	uint8_t bytes[SIZE_OF_BIN_DATA];
	for(uint8_t i = 0; i < SIZE_OF_BIN_DATA; i++)
		bytes[i] = i;

	// convert binary data to hex
	char *hex = bin2hex(bytes, SIZE_OF_BIN_DATA);
	printf("%s\n", hex);

	// convert hex back to binary data
	unsigned char *bin;
	size_t binlen = hexs2bin(hex, &bin);
	for(uint8_t i = 0; i < binlen; i++)
		printf("%02x ", bin[i]);	
	printf("\n");

	// cleanup
	free(bin);
	free(hex);
	
	return 0;
}
