#include <openssl/bio.h>
#include <openssl/evp.h>
#include <openssl/buffer.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


int Base64Encode(char *buffer, size_t length, char** b64text) 
{ 
	BIO *bio, *b64;
	BUF_MEM *bufferPtr;

	b64 = BIO_new(BIO_f_base64());
	bio = BIO_new(BIO_s_mem());
	bio = BIO_push(b64, bio);

	BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Ignore newlines - write everything in one line
	BIO_write(bio, (uint8_t *)buffer, length);
	BIO_flush(bio);
	BIO_get_mem_ptr(bio, &bufferPtr);
	BIO_set_close(bio, BIO_NOCLOSE);
	BIO_free_all(bio);

	*b64text=(*bufferPtr).data;

	return 0; //success
}

size_t calcDecodeLength(const char* b64input) 
{ 
	size_t len = strlen(b64input),
	padding = 0;

	if (b64input[len-1] == '=' && b64input[len-2] == '=') //last two chars are =
		padding = 2;
	else if (b64input[len-1] == '=') //last char is =
		padding = 1;

	return (len*3)/4 - padding;
}

int Base64Decode(char *b64message, char** buffer, size_t* length) 
{ 
	BIO *bio, *b64;

	int decodeLen = calcDecodeLength(b64message);
	*buffer = (char *)malloc(decodeLen + 1);
	(*buffer)[decodeLen] = '\0';

	bio = BIO_new_mem_buf((uint8_t *)b64message, -1);
	b64 = BIO_new(BIO_f_base64());
	bio = BIO_push(b64, bio);

	BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL); //Do not use newlines to flush buffer
	*length = BIO_read(bio, *buffer, strlen(b64message));
	assert(*length == decodeLen); //length should equal decodeLen, else something went horribly wrong
	BIO_free_all(bio);

	return (0); //success
}


int main() 
{
  //Encode To Base64
  char* base64EncodeOutput, *text="Hello World";

  Base64Encode(text, strlen(text), &base64EncodeOutput);
  printf("Output (base64): %s\n", base64EncodeOutput);

  //Decode From Base64
  char* base64DecodeOutput;
  size_t test;
  Base64Decode("SGVsbG8gV29ybGQ=", &base64DecodeOutput, &test);
  printf("Output: %s %lu\n", base64DecodeOutput, test);
  
  return(0);
}
