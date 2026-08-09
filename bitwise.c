#include <stdio.h>

int is_power_of_two(unsigned x);

int main(void)
{
    unsigned tests[] = {1, 2, 3, 4, 15, 16, 64, 100};
    int i;

    for (i = 0; i < 8; i++)
        printf("%3u -> %s\n", tests[i], is_power_of_two(tests[i]) ? "power of 2" : "not");

    return 0;
}

int is_power_of_two(unsigned x)
{
    return x != 0 && (x & (x - 1)) == 0;
}