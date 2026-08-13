/* ============================================================
 * BITWISE OPERATORS CHEAT SHEET
 * ============================================================
 *
 * OPERATORS
 * --------------------------------------------------------------
 * &   AND   1 only if BOTH bits are 1
 * |   OR    1 if EITHER bit is 1
 * ^   XOR   1 if bits DIFFER
 * ~   NOT   flips every bit (unary, one operand)
 * <<  left shift   slide bits left, fill with 0 on the right
 * >>  right shift  slide bits right, fill with 0 on the left
 *                  (unsigned: always 0-fill. signed negative:
 *                  fill behavior is platform-dependent)
 *
 * NOT the same as && || (logical, true/false, short-circuit).
 * x=1,y=2: x & y == 0, but x && y == 1.
 *
 * --------------------------------------------------------------
 * CORE PATTERNS
 * --------------------------------------------------------------
 * Turn bit N on:        x = x | (1 << N);
 * Turn bit N off:       x = x & ~(1 << N);
 * Toggle bit N:         x = x ^ (1 << N);
 * Check if bit N is on: (x & (1 << N)) != 0
 * Clear low n bits:     x = x & ~0 << n;
 * Keep only low n bits: x = x & ~(~0 << n);   (an n-bit mask of 1s)
 * Multiply by 2^n:      x << n
 * Divide by 2^n:        x >> n   (unsigned only — truncates)
 *
 * --------------------------------------------------------------
 * BUILDING AN N-BIT MASK (n ones at the bottom)
 * --------------------------------------------------------------
 * ~0            all bits set to 1
 * ~0 << n       n zeros at the bottom, 1s above
 * ~(~0 << n)    n ones at the bottom, 0s above   <- the mask
 *
 * Width-independent: works for char/int/long without hardcoding
 * bit count. Prefer this over hand-picking a literal like 0xFF.
 *
 * --------------------------------------------------------------
 * GETBITS / SETBITS PATTERN (extract or replace an n-bit field
 * starting at position p, counting from 0 at the right)
 * --------------------------------------------------------------
 * getbits(x,p,n):
 *   (x >> (p + 1 - n)) & ~(~0 << n)
 *   1. shift the field down to the bottom
 *   2. mask off everything except the n bits you want
 *
 * setbits(x,p,n,y):
 *   mask = ~(~0 << n);
 *   (x & ~(mask << (p+1-n))) | ((y & mask) << (p+1-n))
 *   1. clear the target field in x
 *   2. isolate y's bottom n bits, shift into position
 *   3. OR the two together
 *
 * --------------------------------------------------------------
 * ROTATE (bits wrap around instead of disappearing)
 * --------------------------------------------------------------
 * rightrot(x,n): (x >> n) | (x << (bits_in_x - n))
 * leftrot(x,n):  (x << n) | (x >> (bits_in_x - n))
 * bits_in_x = sizeof(x) * 8
 *
 * --------------------------------------------------------------
 * HANDY ONE-LINERS
 * --------------------------------------------------------------
 * Count set bits:     while (x) { count += x & 1; x >>= 1; }
 * Check power of 2:   x != 0 && (x & (x - 1)) == 0
 * Check even/odd:     x & 1   (0 = even, 1 = odd)
 * Clear lowest 1-bit: x & (x - 1)
 * Isolate lowest 1-bit: x & (-x)
 * Swap without temp:  a ^= b; b ^= a; a ^= b;
 *
 * --------------------------------------------------------------
 * OCTAL / HEX QUICK NOTES (common in bit-mask literals)
 * --------------------------------------------------------------
 * 0177   leading 0  -> octal (base 8), = 127 decimal = 01111111
 * 0x7F   leading 0x -> hex   (base 16), = 127 decimal = 01111111
 * Octal digit -> 3 bits exactly. Hex digit -> 4 bits exactly.
 * Watch out: an accidental leading zero on a decimal literal
 * (042) silently becomes octal (34), not 42.
 *
 * --------------------------------------------------------------
 * REMINDERS
 * --------------------------------------------------------------
 * - Bitwise ops act on every bit of the operand's real storage
 *   size (8/16/32/64), not a fixed 8 — small numbers just have
 *   lots of leading zeros that don't visibly matter.
 * - char/short get promoted to int before bitwise ops apply.
 * - Prefer ~0 / sizeof(x)*8 over hardcoded widths — portable
 *   across char/int/long and across platforms.
 * ============================================================
 */


//  #include <stdio.h>

//  int getbits(int x, int p, int n);

//  int main(void){
//    int result = getbits(0xB6, 4, 3);
//    printf("result: %d", result);
//  }

//  int getbits(int x, int p, int n){
//     x = (x >> (p + 1 - n) & ~(~0u << n));
//     return x;
//  }

//  #include <stdio.h>

//  int invert(int x, int p, int n);

//  int main(void){
//   int result = invert(10, 1, 2);
//   printf("result: %d", result);
//  }

//  int invert(int x, int p, int n){
//   x = x^(~(~0u << n) << (p + 1 - n));
//   return x;
//  }



 #include <stdio.h>

unsigned char swap_nibbles(unsigned char x);

int main(void)
{
    unsigned char x = 0xA5;   /* 10100101 */
    printf("before: 0x%02X\n", x);
    printf("after:  0x%02X\n", swap_nibbles(x));
    return 0;
}

unsigned char swap_nibbles(unsigned char x)
{
    unsigned char high = (x >> 4) & 0x0F;   
    unsigned char low  = (x << 4) & 0xF0;   
    return low | high;                       
}


#include <stdio.stdio.h>

/* bitcount: count 1 bits in x (unsigned to avoid sign-extension issues) */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x - 1)) {
        b++;
    }

    return b;
}

int main(void)
{
    unsigned test_val1 = 0;       /* 0 set bits */
    unsigned test_val2 = 12;      /* 0000 1100 -> 2 set bits */
    unsigned test_val3 = 0x8001;  /* 1000 0000 0000 0001 -> 2 set bits */
    unsigned test_val4 = 255;     /* 1111 1111 -> 8 set bits */

    printf("bitcount(%u) = %d\n", test_val1, bitcount(test_val1));
    printf("bitcount(%u) = %d\n", test_val2, bitcount(test_val2));
    printf("bitcount(%u) = %d\n", test_val3, bitcount(test_val3));
    printf("bitcount(%u) = %d\n", test_val4, bitcount(test_val4));

    return 0;
}