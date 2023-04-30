#define MAX_STR 513 /*512 + '\0'*/

/** -------------------- **\
 * ?   get_unsigned
 * ?description
 * @purpose:
 *	*get unsigned integer from the user
 * @method:
 *	*getchar(), isspace()
 *	*do{}while(): #1 for clear prefix white spaces, #2 for the num itself;
 * ?use
 * @param validity_flag,   pointer for validation value
 * @return the input, and its validity through validity_flag
 * ?I/O samples:
 *	*input of     ""  ⇝	0; *validity_flag = -1
 *	*input of "   2"	⇝	2;      *validity_flag = 1
 *	*input of "2342"	⇝	2342;   *validity_flag = 1
 *	*input of "23r2 "	⇝	0; *validity_flag = -1
 *	*input of " -2 "	⇝	0; *validity_flag = -1
 *	*input of " 3.1"	⇝	0; *validity_flag = -1
 *	*input of " 3.0 "	⇝	0; *validity_flag = -1
\** -------------------- **/
unsigned int get_unsigned(int *validity_flag);

/** -------------------- **\
 * ?   get_line
 * ?description
 * @purpose:
 *	*get line into string with size of MAX_STR, in a controlled manner.
 * @assumptions:
 *	*Max line input = MAX_STR
 * @method:
 *	*fgets()
 * ?use
 * @param line_inp,   pointer ot the string that will contain the input
 * @return 1 if worked well, else 0
 * ?I/O samples:
 *	*pointer; input of ""	⇝	didn't get it; 0
 *	*pointer; input of "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"	⇝ get it; 1
 *	*pointer; input of bigger than MAX_STR (although it is assumed that it will not happen)	⇝ ;  get the first MAX_STR chars; 1
\** -------------------- **/
unsigned int get_line(char *line_inp);

/** -------------------- **\
 * ?   my_bcmp
 * ?description
 * @purpose:
 *	*compare two blocks of byte given by two addresses and length
 * @method:
 *	*run along the addresses with ascending counter
 *  *compare the values in the address located counter-step from the pointer
 * ?use
 * @param b1,   Pointer to the first block address
 * @param b2,	     "     "  "  second  "      "
 * @param len,  Bytes-length for compering from the pointers
 * @return 0 if equal, and the (index of violation +1) if not
 * ?I/O samples:
 *	*#0 & #1 for 26 bytes in  "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz" ⇝	1
 *  *________for 0  bytes in________ ⇝	0
 *  *#0 & #26 for 26 bytes in "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz" ⇝	0
\** -------------------- **/
int my_bcmp(const void *b1, const void *b2, int len);
