#include <stdio.h>
#define BYTE_SIZE 8

/**----------------------
 * ?   my_rottate
 * ?description
 * @purpose:
 *	*bitwise rotation, more advance than just shift it
 * @method:
 *	*sizeof*BYTE_SIZE a for bits lenth & b%lenth for efficiency
 *	*<<shift>> everything to the b, and add the falling digits to the empty area

 * ?use
 * @param:
 *	*char a, num to work on.
 *	*char b, bitwise shift amount needed for that num. + to right, - to left.
 * @return unsigned int,
 * @I/O sample: (on machine with BYTE_SIZE*sizeof(unsigned int)==32)
 *	*121454, 321	⇝	60727
 *	*99433711, 1000983	⇝	3665419787
 *	*2, 1	⇝	1
 *	*-1, 10	⇝	20
 *------------------------**/
unsigned int my_rottate(unsigned int a, int b);

/**----------------------
 * ?   print_bases
 * ?description
 * @purpose:
 *	*print DECimal num also in HEX, OCT & BIN
 * @method:
 *	*print conversions argument types for HEX & OCT
 *  *shifting by counting digits for BIN

 * ?use
 * @param char num, num to print.
 * @return void, just print
 * @I/O sample: (on machine with BYTE_SIZE*sizeof(unsigned int)==32)
 *	*10 ⇝
    ⇲	 Number in base...
        DEC-10	10
        HEX-16	A
        OCT-8	12
        BIN-2	00000000 00000000 00000000 00001010
 *	*121454	⇝
    ⇲	 Number in base...
        DEC-10	121454
        HEX-16	1DA6E
        OCT-8	355156
        BIN-2	00000000 00000001 11011010 01101110
 *------------------------**/
void print_bases(unsigned int num);

/*SECTION: functions*/

unsigned int my_rottate(unsigned int a, int b)
{
    unsigned int lenth = sizeof(a) * BYTE_SIZE;
    b %= lenth;

    if (a == 0 || b == 0)
    {
        return a;
    }

    if (b > 0)
    {
        return ((a >> b)               /*shift everything b to the LSB*/
                + (a << (lenth - b))); /*add to MSB the b digits fell from the LSB*/
    }
    else if (b < 0)
    {
        return ((a << (-b))            /*shift everything |b| to the MSB*/
                + (a >> (lenth + b))); /*add to LSB the (lenth - |b|) digits fell from the MSB*/
    }

    return 0; /*not in use anyway*/
}

void print_bases(unsigned int num)
{
    int digit_index = (sizeof(num) * BYTE_SIZE), byte_index = BYTE_SIZE;

    /*HEX & OCT with print conversions argument types*/
    printf("\n⇲\t Number in base...\t");
    printf("\n\tDEC-10\t%u\t\n\tHEX-16\t%X\t\n\tOCT-8\t%o\t\n\tBIN-2\t", num, num, num);

    /*BIN with spaces bitween bytes */
    while (digit_index--)
    {
        putchar('0' + ((num >> digit_index) & 1));
        if (--byte_index == 0)
        {
            printf(" ");
            byte_index = BYTE_SIZE;
        }
    }

    printf("\n");
    return;
}