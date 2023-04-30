#include <stdio.h>
#include <ctype.h> /*isspace*/
#include "my_bcmp.h"

unsigned int get_unsigned(int *validity_flag)
{
	unsigned int num = 0;
	char c;

	/* Clear prefix white chars*/
	do
	{
		c = getchar();
	} while (isspace(c));

	/*Now we have a non-white char, let's get the number */
	do
	{
		if ('0' <= c && c <= '9')
			num = num * 10 + (c - '0');
		else if (!isspace(c)) /*white chars including EOF, so also if it isn't it*/
		{
			printf("\n!\tERROR: The input isn`t non-negative integer, followed by white char.\n");
			*validity_flag = -1;
			return 0;
		}
		c = getchar();
	} while (!isspace(c));

	*validity_flag = 1;
	return num;
}

unsigned int get_line(char *line_inp)
{
	if (fgets(line_inp, MAX_STR, stdin) == NULL)
	{
		printf("\n!\tERROR: The input failed in fgets.\n");
		return 0;
	}

	return 1;
}

int my_bcmp(const void *b1, const void *b2, int len)
{
	int i;
	for (i = 0; i < len; ++i)
	{
		/*Casting to <char*> for 1 byte jumping, so <i> will count single bytes*/
		if (*((const char *)b1 + i) != *((const char *)b2 + i))
			return i + 1;
	}
	return 0;
}