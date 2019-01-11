/*Author: Omar Misael Chiara Gutiérrez : Electronics & Communication Engineer          */
/*                                                                                     */
/*                                                                                     */
/*                                                                                     */
/* This code generates 255 pseudo-random numbers based on a LFSR                       */
/* The polynomial used was x^8 + x^6 + x^5 + x^4 (8 bit)                               */
/* The seed is modifiable, but with this polynomial we get the max value               */
/* With any of the 255 seeds                                                           */
/* mask bit , bitn and bit_xorn variables must be changed if you change the polynomial */

#include <stdio.h>



#define MASK_BIT_3      0x08
#define MASK_BIT_4      0x10
#define MASK_BIT_5      0x20
#define MASK_BIT_7      0x80


void fsrl();


static int seednumber=1;
static int i;
int main()
{
    for(i=1;i<256;i++ )
    {


        fsrl(seednumber);


    }
        return 0;


}

/*This fuction makes de LSFR with 8 bits and one seed*/

void fsrl(int seed_st)

{
    unsigned char bit7, bit5, bit4, bit3, bit_xor1,bit_xor2, bit_xor3,seed ;


    seed = seed_st;

    bit7= (seed & MASK_BIT_7 )>>7;
    bit5 = (seed & MASK_BIT_5)>>5;
    bit_xor1 = bit7 ^ bit5;
    bit4 = (seed & MASK_BIT_4)>>4;
    bit_xor2 = bit4 ^ bit_xor1;
    bit3= (seed & MASK_BIT_3) >>3;
    bit_xor3 = bit3 ^ bit_xor2;
    seed = seed << 1;


    seed = seed|bit_xor3;
    seednumber =seed;

    printf("| Seed #%d  - Value %d |\n",i,seed);



}
