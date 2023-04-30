/**================================================================================================
 * ?										ABOUT
 * @course		–	openU-20465 2023A
 * @task		–	MMN-11
 *	*question	–	1
 * @submitter	–	 | 
 * @repo		–	https://www.github.com/Evyatar-E/openU-20465/tree/main/MMN-11/abc
 * @createdOn	–	October 2022
 *
 * ?	description
 * @purpose:
 *	*Shorten ascending sequences of the English alphabet
 * @assumption:
 *	*Max input = 80
 * @method:
 *	*I/O handling in the main program, the shortening process occurs in the "abcShort" function; More info there.
 *================================================================================================**/

#include <stdio.h>

#define MAXINP 81

void abcShort(char[]); /* From: abcShort.c */

int main()
{
	char text[MAXINP];

	printf("\n%s\n⇱\t", "▢\tPlease enter some text\t¦›)");
	fgets(text, MAXINP, stdin);
	printf("\n%s\n%s\n⇲\t%s\n%s", "▢\tThanks, got it\t✓", "▢\tThe input received:", text, "▢\tWorking...");

	abcShort(text);

	printf("\n%s\n⇲\t%s\n%s\n\n", "▢\tThe short data:", text, "▢\tDone\t\t\t∎");

	return 0;
}