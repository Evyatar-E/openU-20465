/** ========================================================================================= **\
 * ?                                          ABOUT
 * @course      -  openU-20465 2023A
 * @task        -  MMN-12
 *	*question   -  1
 * @submitter   -  
 * @repo        -  https://www.github.com/Evyatar-E/openU-20465/tree/main/MMN-12/my_bcmp/my_bcmp.c
 * @created_on  -  December 2022
 *
 * ?	description
 * @purpose:
 *	*compare between data blocks
 * @assumptions:
 *	*Max line input = 512
 * @method:
 *	*I/O handling of length, two indexes and a string.
 *	*compare two blocks, byte-after-byte, starting from two addresses simultaneity
\** ========================================================================================= **/

#include <stdio.h>
#include <string.h> /*strlen*/
#include "my_bcmp.h"

int main()
{
	int valid_inp;
	unsigned int len_cmp = 0, len_inp = MAX_STR, i1 = 0, i2 = 0;
	unsigned int *max_i = 0;
	char text[MAX_STR] = "";
	char *c1, *c2;

	/*------- Simple I/O -------*/
	printf("#\tHi, lets compare some bytes!\n\t\tShall we? [-:");
	printf("\n\tPlease enter the length for compering.[1-%u]\n>\t", MAX_STR - 1);
	len_cmp = get_unsigned(&valid_inp);
	if (valid_inp == -1)
		return -1;

	printf("\n\tWhich index will be the 1st? [0-%u]\n>\t", MAX_STR - 2);
	i1 = get_unsigned(&valid_inp);
	if (valid_inp == -1)
		return -1;

	printf("\n\tWhich index will be the 2nd?\n>\t");
	i2 = get_unsigned(&valid_inp);
	if (valid_inp == -1)
		return -1;
	max_i = (i1 > i2 ? &i1 : &i2);

	printf("\n\tPlease enter some string:\n>\t");
	if (get_line(text) == 0)
		return 0;
	len_inp = strlen(text);

	/*------- Complex Validates -------*/
	if (*max_i > len_inp - 1)
	{
		printf("!\tERROR: One (or more) of the indexes is <%u> chars out of the string. [0-%u]\n", *max_i - (len_inp - 1), len_inp - 1);
		return -1 * (*max_i - len_inp);
	}
	if (len_cmp > (len_inp - *max_i)) /*	if the len for compering is out of the len remain in the input after the max index*/
	{
		printf("!\tERROR: The <%u> length for compering from index <%u>, is <%u> bytes too long.\n", len_cmp, *max_i, (len_cmp - (len_inp - *max_i)));
		return -1 * (len_inp - *max_i);
	}

	/*------- Compering -------*/
	c1 = &text[i1];
	c2 = &text[i2];

	printf("\n*\tOK: Compering in \n\t\"%s\"\n\tfrom #%u & #%u for %u bytes...\n", text, i1, i2, len_cmp);

	if (my_bcmp(c1, c2, len_cmp) == 0)
		printf("\nV\tPositive comparison\t\t#");
	else
		printf("\nX\tNegative comparison\t\t#");

	return 0;
}