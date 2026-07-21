# C Cheat Sheet

A general-purpose reference for working through K&R / a C course, with extra
weight on the topics you'll lean on for the HTTP server (pointers, memory,
structs, file descriptors).

---

## 1. Program Skeleton

```c
#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
    return 0;
}
```

- `int main(void)` — prefer `void` over empty `()` in modern C (empty parens
  in C mean "unspecified arguments", not "no arguments").
- `return 0;` — success. Non-zero signals an error to the OS/shell.

Compile with gcc (MSYS2 terminal):
```
gcc -Wall -Wextra -std=c11 -o program program.c
./program
```
`-Wall -Wextra` turns on warnings you actually want to see. Always compile
with these on.

---

## 2. Types & Sizes

| Type            | Typical size | Notes |
|-----------------|-------------|-------|
| `char`          | 8 bits      | signedness is implementation-defined |
| `short`         | 16 bits     | |
| `int`           | 32 bits     | |
| `long`          | 32 or 64 bits | 64-bit on Linux/macOS, 32-bit on Windows (LLP64) |
| `long long`     | 64 bits     | |
| `float`         | 32 bits     | ~6-7 sig figs |
| `double`        | 64 bits     | ~15-16 sig figs |
| pointer (`T*`)  | 64 bits on 64-bit systems | |

Use `sizeof(x)` instead of memorizing — it's always correct on your platform.
For guaranteed sizes, use `<stdint.h>`: `int32_t`, `uint32_t`, `int64_t`,
`uint64_t`, etc. `size_t` is the unsigned type returned by `sizeof` and used
for array indexing / lengths — you'll see it constantly in socket code
(`recv`, `send`, `read`, `write` all use it).

**Overflow:** signed overflow is undefined behavior; unsigned overflow wraps
(mod 2^n) and is well-defined.

---

## 3. printf / scanf Format Specifiers

```
%d   int              %u    unsigned int
%ld  long             %lu   unsigned long
%lld long long        %llu  unsigned long long
%c   char             %s    string (char*)
%f   float/double     %lf   double (scanf only)
%x / %X  hex          %o    octal
%p   pointer          %zu   size_t
%%   literal %
```

---

## 4. Operators & Precedence (high to low, common ones)

```
()  []  ->  .              grouping/access
!  ~  ++  --  (type) *  &  unary
*  /  %                    multiplicative
+  -                       additive
<<  >>                     shift
<  <=  >  >=                relational
==  !=                     equality
&                           bitwise AND
^                           bitwise XOR
|                           bitwise OR
&&                          logical AND
||                          logical OR
?:                          ternary
=  +=  -=  *=  /=  etc.    assignment
,                           comma
```
When unsure, just use parentheses — free clarity, no runtime cost.

---

## 5. Control Flow

```c
if (cond) { } else if (cond2) { } else { }

for (int i = 0; i < n; i++) { }

while (cond) { }

do { } while (cond);   // runs body at least once

switch (x) {
    case 1: ...; break;
    case 2: ...; break;
    default: ...;
}
```

---

## 6. Arrays & Strings

```c
int a[5] = {1, 2, 3, 4, 5};
int a2[5] = {0};          // rest zero-initialized
int len = sizeof(a) / sizeof(a[0]);   // element count (only works on real arrays, not decayed pointers)

char s[] = "hello";       // array of 6 chars, includes '\0'
char *p = "hello";        // pointer to string literal — READ ONLY, don't modify
```

C strings are just `char` arrays terminated by `'\0'`. Nothing tracks length
for you — that's on you (this bites people constantly when parsing HTTP
requests byte-by-byte).

Common `<string.h>` functions:
```
strlen(s)             length, excluding '\0'
strcpy(dst, src)       copy (unsafe — no bounds check)
strncpy(dst, src, n)   safer, but doesn't guarantee null-termination
strcat(dst, src)       append (unsafe)
strcmp(a, b)           0 if equal
strchr(s, c)           find first occurrence of char
strstr(a, b)           find substring
memcpy(dst, src, n)    raw byte copy
memset(p, val, n)      fill bytes
```

---

## 7. Pointers

```c
int x = 5;
int *p = &x;     // p holds the address of x
*p = 10;         // dereference: x is now 10
int **pp = &p;   // pointer to pointer

int arr[3] = {1,2,3};
int *pa = arr;   // array decays to pointer to first element
pa[1];           // same as *(pa + 1)
```

- `&` = address-of, `*` = dereference (or "pointer to" in a declaration).
- A pointer with no valid target should be `NULL`, and you should check
  before dereferencing.
- Function pointers: `int (*fp)(int, int) = add;` — you'll see these in
  callback-style networking code.
- `void *` is a generic pointer — used a lot in socket APIs (e.g. the buffer
  argument to `read`/`write`/`recv`/`send`).

---

## 8. Dynamic Memory (`<stdlib.h>`)

```c
int *p = malloc(n * sizeof(int));   // allocate, uninitialized
if (p == NULL) { /* handle allocation failure */ }

int *p2 = calloc(n, sizeof(int));   // allocate, zeroed

p = realloc(p, new_size * sizeof(int));  // resize (may move the block)

free(p);   // release — always free what you malloc
p = NULL;  // avoid dangling pointer / accidental double free
```

**Rules that will save you hours of debugging:**
- Every `malloc`/`calloc` needs exactly one matching `free`.
- Never use memory after `free`ing it (use-after-free).
- Never `free` the same pointer twice (double free).
- Always check `malloc`'s return for `NULL` before using it.
- Tools: compile with `-fsanitize=address,undefined` while developing, or
  run under `valgrind` (if available in your MSYS2 setup) to catch leaks
  and invalid access.

---

## 9. Structs

```c
struct Point {
    int x;
    int y;
};

struct Point p1 = {1, 2};
struct Point *pp = &p1;

p1.x;        // access via .
pp->x;       // access via -> when you have a pointer (shorthand for (*pp).x)

typedef struct {
    int x;
    int y;
} Point;     // now you can write `Point p1;` without the `struct` keyword
```

You'll use structs constantly for things like representing an HTTP request
(method, path, headers, body) or a `sockaddr_in`.

---

## 10. Functions

```c
int add(int a, int b) {
    return a + b;
}

// Declare (prototype) before use if defined later in the file / in another file:
int add(int a, int b);
```

- Arrays and structs passed to functions: arrays decay to pointers
  (no copy); structs are copied by value unless you pass a pointer.
- Pass a pointer when the function needs to modify the caller's data, or
  when the data is large and copying would be wasteful.

---

## 11. File I/O & File Descriptors

Two APIs you'll meet:

**Buffered, standard C (`<stdio.h>`)** — `FILE *`:
```c
FILE *f = fopen("file.txt", "r");   // "r","w","a","rb","wb", etc.
if (f == NULL) { /* handle error */ }
char buf[256];
fgets(buf, sizeof(buf), f);
fprintf(f, "%d\n", 42);
fclose(f);
```

**Low-level POSIX (`<unistd.h>`, `<fcntl.h>`)** — raw file descriptors
(this is what sockets use too, since a socket *is* a file descriptor on
POSIX systems):
```c
int fd = open("file.txt", O_RDONLY);
ssize_t n = read(fd, buf, sizeof(buf));
write(fd, buf, n);
close(fd);
```
Sockets (`socket()`, `bind()`, `listen()`, `accept()`, `recv()`, `send()`)
return/operate on the same kind of integer file descriptor — that's the
conceptual bridge from "file I/O" to "network I/O" you'll cross when you
start the server.

---

## 12. Preprocessor

```c
#include <stdio.h>      // system header
#include "myheader.h"   // local header

#define MAX_SIZE 100    // simple macro
#define SQUARE(x) ((x) * (x))   // parenthesize everything in macros!

#ifdef DEBUG
    printf("debug info\n");
#endif

#ifndef MYHEADER_H       // classic header guard
#define MYHEADER_H
// ...declarations...
#endif
```

---

## 13. Common Gotchas

- `=` vs `==` — assignment vs comparison; `if (x = 5)` compiles and is
  almost always a bug.
- Forgetting `break` in a `switch` — falls through to the next case.
- Off-by-one errors in loops/array bounds — arrays are 0-indexed, no bounds
  checking.
- Uninitialized local variables contain garbage, not 0.
- Comparing C strings with `==` compares pointers, not contents — use
  `strcmp`.
- Integer division truncates: `7 / 2 == 3`, `-7 / 2 == -3`.
- Returning a pointer to a local (stack) variable from a function —
  the memory is invalid once the function returns.

---

## 14. Quick Reference: Headers You'll Use Most

```
<stdio.h>     printf, fopen, fgets, ...
<stdlib.h>    malloc, free, exit, atoi, ...
<string.h>    strlen, strcmp, memcpy, ...
<unistd.h>    read, write, close, fork (POSIX)
<fcntl.h>     open, file control flags (POSIX)
<sys/socket.h> socket, bind, listen, accept (POSIX, for the server later)
<netinet/in.h> sockaddr_in, htons, etc. (POSIX, for the server later)
<limits.h>    INT_MAX, ULONG_MAX, etc.
<stdint.h>    fixed-width types: int32_t, uint64_t, ...
```

*Note: the socket headers are POSIX, not part of standard C. On MSYS2/Windows
you may need the Winsock API (`<winsock2.h>`) instead, or build/run under
WSL for a POSIX-native environment — worth deciding before you get to the
networking part of the project.*
