#include <stdlib.h> /*EXIT_, calloc, free*/
#include <stdio.h>  /*printf, perror*/
#include <string.h> /*strlen, strcpy*/
#include <stdarg.h> /*va_list, va_start*/

#define uint unsigned int
#define ERR_FORMAT "\n!\tERROR:\t%s.\n"
#define WRN_FORMAT "\n*\tWARNING:\t%s.\n"
#define BUFF_UPSIZE 100
#define RTRN_IF_NULL(ptr) \
  if ((ptr) == NULL)      \
    return NULL;

void exitErr(const char *errMessage);
void myCalloc(void **ptr, size_t _Count, size_t _Size);

void permutations(FILE **input, char *buff, const char *phrase, size_t len);
int myBitHash(const char *str);
char *strSort(char *str);
/* ^ Supported by:*/ int charCmpFunc(const void *a, const void *b);