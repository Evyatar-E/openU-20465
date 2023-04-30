/**================================================================================================
 * ?										ABOUT
 * @course     -  openU-20465 2023C
 * @task       -  MMN-11
 *	*question  -  2
 * @submitter  -   | 
 * @repo       -  https://www.github.com/Evyatar-E/openU-20465/tree/main/MMN-11/my_rottate
 * @createdOn  -  October 2022
 *
 * ?	description
 * @purpose:
 *	*Bitwise Rotation
 * @assumption:
 *	*Input can be adjusted into unsigned int & int (will not be larger than capacity)
 * @method:
 *	*Input handling in the main program, output via "print_bases" and the bitwise rotation process occurs in the "my_rottate" function; More info there.
 *================================================================================================**/

#include <stdio.h>

/* From: bitwise rotation.c */
unsigned int my_rottate(unsigned int a, int b);
void print_bases(unsigned int num);

int main()
{
    unsigned int num, rottated;
    int shift;

    /*I/O handling */
    printf("\n%s\n⇱\t", "Please enter natural number:");
    scanf("%u", &num);
    printf("\n%s\n⇱\t", "What shift needed to its bitwise rotation?");
    scanf("%d", &shift);

    printf("\n\n%s\n%s", "Thanks, got it\t✓", "The input received:");
    print_bases(num);

    printf("\n%s", "Working...");
    rottated = my_rottate(num, shift);
    printf("\nOK, the %d shift bitwise rotation of %u is:", shift, num);
    print_bases(rottated);

    return 0;
}