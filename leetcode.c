//problem 58 length of last string
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char* s) {
    int length = 0;
    for (int i = strlen(s) - 1; i >=0; i--){
        if(s[i] == ' ' && length == 0){
            continue;
        } else if (s[i] == ' ' && length > 0) {
            return length;
        } else {
            length++;
        }
    }
    return length;
}

int main(void) {
    char stringg[] = "Hello World  ";
    int size = lengthOfLastWord(stringg);
    printf("%d", size);
    
    return 0;
}