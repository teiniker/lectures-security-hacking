#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "base64.h"

int main(void) 
{
  // Encode to Base64
  char *base64EncodeOutput;
  char *text="Hello World";
  encode_base64(text, strlen(text), &base64EncodeOutput);
  printf("base64: %s\n", base64EncodeOutput);

  // Decode from Base64
  char* base64DecodeOutput;
  size_t test;
  decode_base64("SGVsbG8gV29ybGQ=", &base64DecodeOutput, &test);
  printf("text: %s %lu\n", base64DecodeOutput, test);
  
  return(0);
}
