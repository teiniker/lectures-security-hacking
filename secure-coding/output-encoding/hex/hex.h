#ifndef _HEX_H_
#define _HEX_H_

#include <stdlib.h>

extern char *bin2hex(const unsigned char *bin, size_t len);
extern size_t hexs2bin(const char *hex, unsigned char **out);

#endif // _HEX_H_