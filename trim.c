//to run on linux
#include <stdio.h>
#include <ctype.h>

char *trim_in_place(char *s);

int main(void) {
    char buf1[] = "hello   ";
    char buf2[] = "world";
    char buf3[] = "   ";
    char buf4[] = "";

    printf("[%s]\n", trim_in_place(buf1));
    printf("[%s]\n", trim_in_place(buf2));
    printf("[%s]\n", trim_in_place(buf3));
    printf("[%s]\n", trim_in_place(buf4));
    return 0;
}

char *trim_in_place(char *s) {
    char *p = s;
    while (*p) {
        p++;
    }
    p--;
    while (p > s && isspace(*p)) {
        p--;
    }
    if (isspace(*p)) {
        *p = '\0';
    } else {
        p++;
        *p = '\0';
    }
    return s;
}