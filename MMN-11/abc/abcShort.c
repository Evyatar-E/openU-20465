#include <ctype.h>

/**----------------------
 * ?   abcShort
 * ?description
 * @purpose:
 *	*Shorten ascending sequences of the English alphabet in the input, uppercase and lowercase letters separately
 * @method:
 *	*"abcShort" works like a caterpillar, whose base is in "first", and whose head checks the "alphaCont" relation between "next" and its predecessor.
 *	*The caterpillar keeps moving its head "next" as long as the "alphaCont" relation is maintained.
 *	*When it is violated, the base "first" and the predecessor to "next" are recorded, and the base is renewed for the next segment.
 * ?use
 * @param char[] text , the input string changes
 * @return void, output through @param text
 * @I/O sample:
 *	*"dabcefLMNOpQrstuv567zyx"	⇝	"da-cefL-OpQr-v567zyx"
 *	*"abcdfSEFGEFg2S123Drsvabcdghijlkmonopno"	⇝	"a-dfSE-GEFg2S123Drsva-dg-jlkmon-pno"
 *	*"cdeffedc87586947ABcD`W@*#3>%!@"	⇝	"c-ffedc87586947ABcD`W@*#3>%!@"
 *------------------------**/
void abcShort(char[]);

/**----------------------
 * ?   alphaCont
 * ?description
 * @purpose:
 *	*Checking the alphabetical continuity between two english characters
 * @method:
 *	*Adjusted comparison
 *	*isalpha() from <ctype.h>
 * ?use
 * @param:
 *	*char a, The left(before) ASCII char.
 *	*char b, The right(after) ASCII char.
 * @return int, 1 if they AC and 0 if they don`t
 * @I/O sample:
 *	*'a', 'b'	⇝	1
 *	*'b', 'b'	⇝	0
 *	*'c', 'b'	⇝	0
 *	*'X', 'Y'	⇝	1
 *	*'1', '2'	⇝	0
 *	*'Z', 'a'	⇝	0 		//'Z'=90 & 'a'=97 -> 'Z'+1 !='a', so there is no interalphabetic continuity problem
 *------------------------**/
int alphaCont(char, char);

/*SECTION: functions*/

void abcShort(char text[])
{
	int first = 0, next = 1, out = 0;

	while (text[next - 1] != '\0')
	{
		if (!alphaCont(text[next - 1], text[next]))
		{
			text[out++] = text[first];
			if ((next - 1) != first)
			{
				if ((next - 1) - first > 1)
				{
					text[out++] = '-';
				}
				text[out++] = text[next - 1];
			}
			first = next;
		}
		++next;
	}
	text[out] = '\0';
	return;
}

int alphaCont(char a, char b)
{
	if (a + 1 == b					   /*	Continuity?		*/
		&& (isalpha(a)) && isalpha(b)) /*	Alphabetical?	*/
	{
		return 1;
	}
	else /*If they aren`t || '\0' case*/
	{
		return 0;
	}
}