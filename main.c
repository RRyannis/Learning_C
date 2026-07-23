#include <stdio.h>
#include <string.h>


int power(int m, int n);

int main() {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d %d %d\n", i,power(2,i), power(-3,i));
    }
    return 0;
}

int power(int base, int n) {
    int i, p;
    p = 1;
    for (i = 1; i <= n; i++) {
        p = p * base;
    }
    return p;
}

// int main() {
    
//     char item[50] = "";
//     float price = 0.0f;
//     int quantity = 0;
//     char currency = '$';
//     float total = 0.0f;
    
//     printf("What would you like to buy: ");
//     fgets(item, sizeof(item), stdin);
//     item[strlen(item) - 1] = 0;
//     printf("What is the price of the item: ");
//     scanf("%f", &price);
//     printf("How many would you like to buy: ");
//     scanf("%d", &quantity);

//     total = price * quantity;

//     printf("You have purchased %d %s for a total of %c%.2f\n", quantity, item, currency, total);


//     return 0;
// }



/* ============================================================
 * C TYPES CHEAT SHEET
 * ============================================================
 *
 * TYPE            SIZE (typical, 64-bit)   RANGE (signed unless noted)
 * --------------------------------------------------------------
 * char            8 bits   (1 byte)        -128 to 127
 * unsigned char   8 bits                   0 to 255
 * short           16 bits  (2 bytes)       -32,768 to 32,767
 * unsigned short  16 bits                  0 to 65,535
 * int             32 bits  (4 bytes)       -2,147,483,648 to 2,147,483,647
 * unsigned int    32 bits                  0 to 4,294,967,295
 * long            64 bits* (8 bytes)       -9.2e18 to 9.2e18 (see note)
 * unsigned long   64 bits*                 0 to 1.8e19
 * long long       64 bits  (8 bytes)       -9.2e18 to 9.2e18
 * float           32 bits  (4 bytes)       ~6-7 significant decimal digits
 * double          64 bits  (8 bytes)       ~15-16 significant decimal digits
 * pointer (T*)    64 bits* (8 bytes)       depends on architecture
 *
 * *long and pointers are 32 bits on some platforms (e.g. Windows/LLP64).
 *  ALWAYS use sizeof(type) if you need to know for sure.
 *
 * ------------------------------------------------------------
 * PRINTF / SCANF FORMAT SPECIFIERS
 * ------------------------------------------------------------
 * %d   int (signed)              %u    unsigned int
 * %ld  long                      %lu   unsigned long
 * %lld long long                 %llu  unsigned long long
 * %c   char                      %s    string (char*)
 * %f   float/double (printf)     %lf   double (scanf only)
 * %e   scientific notation       %g    shortest of %f/%e
 * %x   hex (lowercase)           %X    hex (uppercase)
 * %o   octal                     %p    pointer address
 * %%   literal percent sign
 *
 * ------------------------------------------------------------
 * LIMITS.H / FLOAT.H CONSTANTS
 * ------------------------------------------------------------
 * CHAR_MIN / CHAR_MAX       INT_MIN / INT_MAX
 * SHRT_MIN / SHRT_MAX       LONG_MIN / LONG_MAX
 * UCHAR_MAX                 UINT_MAX
 * USHRT_MAX                 ULONG_MAX
 * FLT_MIN / FLT_MAX (float.h)   DBL_MIN / DBL_MAX (float.h)
 *
 * ------------------------------------------------------------
 * STDINT.H FIXED-WIDTH TYPES (use these when size MUST be exact)
 * ------------------------------------------------------------
 * int8_t   uint8_t     -128 to 127        / 0 to 255
 * int16_t  uint16_t    -32,768 to 32,767  / 0 to 65,535
 * int32_t  uint32_t    ~-2.1e9 to 2.1e9   / 0 to ~4.3e9
 * int64_t  uint64_t    ~-9.2e18 to 9.2e18 / 0 to ~1.8e19
 * size_t   — unsigned, used for sizeof() results and array indexing
 *
 * ------------------------------------------------------------
 * QUICK RULES
 * ------------------------------------------------------------
 * - Signed overflow  -> undefined behavior (avoid relying on it)
 * - Unsigned overflow -> defined, wraps modulo 2^n
 * - Integer division truncates toward zero (7/2 == 3, -7/2 == -3)
 * - char may be signed or unsigned depending on platform
 * - Always use sizeof(x) instead of hardcoding byte/bit counts
 * ============================================================
 */