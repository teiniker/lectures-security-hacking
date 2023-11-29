#ifndef _BASE64_H_
#define _BASE64_H_

#include <stdlib.h>

extern int encode_base64(char *buffer, size_t length, char** b64text);
extern int decode_base64(char *b64message, char** buffer, size_t* length);

#endif // _BASE64_H_