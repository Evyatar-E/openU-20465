/** ========================================================================================= **\
 * ?                                          ABOUT
 * @course      -  openU-20465 2023A
 * @task        -  MMN-23
 *	*question   -  2
 * @submitter   -  
 * @repo        -  https://www.github.com/Evyatar-E/openU-20465/tree/main/MMN-23/permut/permut.c
 * @created_on  -  January 2023
 *
 * ?	description
 * @purpose:
 *	*Find all the permutations (combinations where order is significant) of a phrase inside a input file.
 * @assumptions:
 *	*There are no overlapping permutations in the file.
 *	*Max word length in the file: 20 + 3 * length of the phrase.
 * @method:
 *	*Paying attention not to change the equivalence classes of the permutations, unless it is a temporary refinement of a partition (Like the hash:).
 *	*Hash precondition for performance, idea from Rabin–Karp algorithm.
 *	*Comparison of the phrase and the buffer in their sorted state - for each string-permutations equivalence class there is sorted state which can be matched one-to-one to its class.
 *		@see_also: http://amsdottorato.unibo.it/6032/1/ferrari_luca_tesi.pdf
 *		^@archived_in: https://web.archive.org/web/20230122130307/http://amsdottorato.unibo.it/6032/1/ferrari_luca_tesi.pdf
 *		In this case, it's much simpler.
\** ========================================================================================= **/

#include "permutations.h"

int main(int argc, char const *argv[])
{
	char *filePath = NULL, *phrase = NULL;
	FILE *inpFile;
	uint phraseLen = 0;
	char *buff = NULL;

	if (3 != argc) /*  $> prog filePath phrase  */
		exitErr((3 < argc ? "Too many terminal arguments" : "Too few terminal arguments"));
	myCalloc((void *)&filePath, strlen(argv[1]) + 1, sizeof(char));
	myCalloc((void *)&phrase, strlen(argv[2]) + 1, sizeof(char));
	strcpy(filePath, argv[1]);
	strcpy(phrase, argv[2]);

	phraseLen = strlen(phrase);
	if (0 == phraseLen)
		exitErr("Empty phrase. Next, please supply it");
	myCalloc((void *)&buff, phraseLen + 1, sizeof(char));

	if (0 == strlen(filePath))
		exitErr("Empty path. Next, please supply it");
	inpFile = fopen(filePath, "r");
	if (NULL == inpFile || ferror(inpFile))
		exitErr("The file can't be opened or read, please check the path you provided and its status");
	if (feof(inpFile))
		exitErr("Empty file, please write into it");

	printf("#\tPermutations of \"%s\" from \"%s\":\n\t---\t\n", phrase, filePath);
	permutations(&inpFile, buff, phrase, phraseLen);

	free(filePath);
	free(phrase);
	free(buff);

	fclose(inpFile);
	return 0;
}