// Exercise 2-5. Write the function any(s1,s2), which returns the first
// location in a string s1 where any character from the string s2 occurs, or -1 if
// s1 contains no characters from s2. (The standard library function strpbrk
// does the same job but returns a pointer to the location.
// #include <stdio.h>

// int any(char s1[], char s2[]);

// int main(void)
// {
//     char str1[] = "hello world";
//     char str2[] = "aeiou";
//     int result = any(str1, str2);
//     if (result != -1) {
//         printf("First occurrence of any character from '%s' in '%s' is at index: %d\n", str2, str1, result);
//     } else {
//         printf("No characters from '%s' found in '%s'\n", str2, str1);
//     }
//     return 0;
// }

// int any(char s1[], char s2[]) {
//     for (int i = 0; s1[i] != '\0'; i++) {
//         for (int j = 0; s2[j] != '\0'; j++) {
//             if (s1[i] == s2[j]) {
//                 return i;
//             }
//         }
//     }
//     return -1;
// }
// Exercise 2-6. Write a function setbits(x,p,n,y) that returns x with the n
// bits that begin at position p set to the rightmost n bits of y, leaving the other
// bits unchanged.
#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);
void print_bits(unsigned v);

void main(){
    unsigned result1 = getbits(0b10110110, 4, 3);
    printf("Result: %u\n", result1);
    unsigned x = 0xAA; /* 1010 1010 */
    unsigned y = 0x07; /* 0000 0111 */
    int p = 4;
    int n = 3;

    unsigned result2 = setbits(x, p, n, y);

    printf("x      = "); print_bits(x);      printf(" (0x%02X)\n", x);
    printf("y      = "); print_bits(y);      printf(" (0x%02X)\n", y);
    printf("Result = "); print_bits(result2); printf(" (0x%02X)\n", result2);

}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask = ~(~0u << n);           /* n ones at the bottom */
    return (x & ~(mask << (p + 1 - n)))    /* clear the target field in x */
           | ((y & mask) << (p + 1 - n));  /* insert y's bottom n bits there */
}
void print_bits(unsigned v)
{
    for (int i = 7; i >= 0; i--) {
        printf("%u", (v >> i) & 1);
        if (i == 4) printf(" "); /* space for readability */
    }
}

// 2.7 Write a function invert(x,p,n) that returns x with the n bits
// that begin at position p inverted (i.e., 1 changed into 0 and vice versa),
// leaving the others unchanged.
#include <stdio.h>

/*
 * Inverts n bits of x starting at position p (0-indexed from right to left).
 * Other bits remain unchanged.
 */
unsigned int invert(unsigned int x, int p, int n) {
    // Create a mask with n ones in the least significant bit positions
    unsigned int mask = ~(~0u << n);
    
    // Shift those n ones into position p
    mask = mask << (p + 1 - n);
    
    // XOR x with the mask to invert those specific bits
    return x ^ mask;
}

// Helper function to print an unsigned int in binary format for verification
void print_binary(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        unsigned int bit = (num >> i) & 1;
        printf("%u", bit);
        if (i % 4 == 0) printf(" "); // Group bits by nibble for readability
    }
    printf("\n");
}

int main(void) {
    // Example test case:
    // x = 170 (1010 1010 in binary)
    // p = 4, n = 3  -> invert 3 bits starting at position 4 (bits 4, 3, 2)
    unsigned int x = 170;
    int p = 4;
    int n = 3;

    printf("Original x (%u): \t\t", x);
    print_binary(x);

    unsigned int result = invert(x, p, n);

    printf("Inverted x (%u): \t\t", result);
    print_binary(result);

    return 0;
}
// 2-8 Write a function rightrot(x,n) that returns the value of the
// integer x rotated to the right by n positions.

#include <stdio.h>

/* Computes total bits in an unsigned integer on the host machine */
int wordsize(void) {
    unsigned int v = (unsigned int)~0;
    int i = 1;
    while ((v = v >> 1) > 0) {
        i++;
    }
    return i;
}

/* Rotates unsigned int x to the right by n positions */
// unsigned int rightrot(unsigned int x, int n) {
//     int w = wordsize();
    
    /* Handle n values larger than wordsize or negative */
    // n = n % w;
    // if (n == 0) {
    //     return x;
    // }

    /* * 1. (x >> n) shifts x right by n bits.
     * 2. (x << (w - n)) takes the rightmost n bits and shifts them to the far left.
     * 3. Combining with '|' merges the two parts.
     */
    // return (x >> n) | (x << (w - n));
// }

// int main(void) {
//     unsigned int x = 0b10100111; /* Example value */
//     int n = 3;

//     printf("Original: 0x%X\n", x);
//     printf("Rotated : 0x%X\n", rightrot(x, n));

//     return 0;
// }
// 2-9In a two's complement number system, x &= (x-1) deletes
// the rightmost 1-bit in x. Explain why. Use this observation to write a faster
// version of bitcount.
// #include <stdio.h>

// /* Faster bitcount using Brian Kernighan's trick */
// int bitcount(unsigned x) {
//     int b;

//     for (b = 0; x != 0; x &= (x - 1)) {
//         b++;
//     }

//     return b;
// }

// int main(void) {
//     unsigned int num = 0b10110100; /* Has 4 set bits */

//     printf("Number of 1-bits in %u: %d\n", num, bitcount(num));

//     return 0;
// }
// #include <stdio.h>

// unsigned rightrot(unsigned x, int n);

// int main(void)
// {
//     unsigned x = 0xB6;   /* 10110110 */
//     printf("before: %u (0x%X)\n", x, x);
//     printf("after:  %u (0x%X)\n", rightrot(x, 3), rightrot(x, 3));
//     return 0;
// }

// unsigned rightrot(unsigned x, int n)
// {
//     int bits = sizeof(x) * 8;
//     return (x >> n) | (x << (bits - n));
// }

// #include <stdio.h>

// int countbits(unsigned x);

// int main(void)
// {
//     unsigned x = 0xB6;   /* 10110110 -> five 1-bits */
//     printf("x = %u (0x%X)\n", x, x);
//     printf("set bits: %d\n", countbits(x));
//     return 0;
// }

// int countbits(unsigned x)
// {
//     int count = 0;
//     while (x != 0) {
//         count += x & 1;   /* check the lowest bit */
//         x >>= 1;          /* shift everything right by 1 */
//     }
//     return count;
// }

// #include <stdio.h>
// #include <string.h>

// int atoi(char s[]);

// int main(void)
// {
//     char str[] = "123";
//     printf("before: %s\n", str);
//     int result = atoi(str);
//     printf("after:  %d\n", result);
//     return 0;
// }

// int atoi(char s[])
// {
//     int i, n;

//     n = 0;
//     for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
//         n = n*10 + (s[i] -'0');
//     }
//     return n;
// }


//stack 
// C Program to demonstrate how to Implement a Stack
#include <stdio.h>
#include <stdbool.h>

// Define the maximim capacity of the stack
#define MAX_SIZE 100

// Define a structure for the stack
typedef struct {
    int arr[MAX_SIZE];  
    int top;        
} Stack;

// Function to initialize the stack
void initialize(Stack *stack) {
    stack->top = -1;  
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;  
}

// Function to check if the stack is full
bool isFull(Stack *stack) {
    return stack->top >= MAX_SIZE - 1;  
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed %d onto the stack\n", value);
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }

    int popped = stack->arr[stack->top];
    stack->top--;
    printf("Popped %d from the stack\n", popped);
    return popped;
}

// Function to peek the top element of the stack
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main() {
    Stack stack;
    initialize(&stack);  

    push(&stack, 3);
    printf("Top element: %d\n", peek(&stack));

    push(&stack, 5);
    printf("Top element: %d\n", peek(&stack));

    push(&stack, 2);
    printf("Top element: %d\n", peek(&stack));

    push(&stack, 8);
    printf("Top element: %d\n", peek(&stack));

    while (!isEmpty(&stack)) {
        printf("Top element: %d\n", peek(&stack));
        printf("Popped element: %d\n", pop(&stack));
    }

    return 0;
}
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



 