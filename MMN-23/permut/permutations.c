#include "permutations.h"

void exitErr(const char *errMessage)
{
  fprintf(stderr, ERR_FORMAT, errMessage);
  exit(EXIT_FAILURE);
}

void myCalloc(void **ptr, size_t _Count, size_t _Size)
{
  *ptr = calloc(_Count, _Size);
  if (NULL == ptr)
    exitErr("Memory allocation failed, sorry");
}

void permutations(FILE **input, char *buff, const char *phrase, size_t len)
{
  uint phraseHash = myBitHash(phrase), foundFlag = 0;
  char *phraseSort = NULL, *buffSort = NULL;

  myCalloc((void *)&phraseSort, len + 1, sizeof(char));
  myCalloc((void *)&buffSort, len + 1, sizeof(char));

  strcpy(phraseSort, phrase);
  strSort(phraseSort);

  rewind(*input);
  while (1 == fread(buff, len, 1, *input))
  {
    /** ---------------------------------------- **\
     * 1.Hash precondition for performance.		&&
     * 2.Comparing the sorted strings:
     * 	The sorting does not change the
     * 	equivalence classes of the permutations.
    \** ---------------------------------------- **/
    if (myBitHash(buff) == phraseHash &&
        !strcmp(strSort(strcpy(buffSort, buff)), phraseSort))
    {
      printf("\t\"%s\"\n", buff);
      foundFlag |= 1;
    }
    fseek(*input, -(len - 1), SEEK_CUR);
  }

  if (0 == foundFlag)
    printf("*\tNo permutations found.\n");

  free(phraseSort);
  free(buffSort);
}

char *strSort(char *str)
{
  qsort(str, (size_t)strlen(str), (size_t)sizeof(char), charCmpFunc);
  return str;
}

int charCmpFunc(const void *a, const void *b)
{
  return *(char *)a - *(char *)b;
}

int myBitHash(const char *str)
{
  int i;
  uint andS = ~0, or_S = 0, xorS = 0;
  uint prime = 83;

  /** ------------------------------ **\
   * @method: Ensuring commutativity in the loop:
   * Neutralizing the dependence on the position of
   * the characters, so that any permutation with
   * identical components will lead to identical values.
  \** ------------------------------ **/
  for (i = 0; '\0' != *(str + i); ++i)
  {
    andS &= *(str + i);
    or_S |= *(str + i);
    xorS ^= *(str + i);
  }

  andS = (andS << 1) % prime;
  or_S = (or_S << 3) % prime;
  xorS = (xorS << 7) % prime;

  return (((andS & or_S) | xorS) ^ 1 << (prime - 1)) % prime;
}
