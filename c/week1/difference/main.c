// https://leetcode.com/problem-list/w5s9pzgi/
// 389. Find the Difference

#include<stdio.h>
#include<string.h>

char findTheDifference(char* s, char* t);

int main()
{
    char *s = "abcd";
    char *t = "abcde";

    printf("%c", findTheDifference(s, t));

    return 0;
}

char findTheDifference(char* s, char* t) {
    short countChar[26], index;
    memset(countChar, 0x00, sizeof(countChar));

    while(*s != '\0'){
        ++countChar[(short)(*s)-97];
        ++s;
    }

    while(*t != '\0'){
        index = (short)(*t) - 97;
        if(countChar[index] <= 0x00)
            return *t;
        else
            --countChar[index];
        ++t;
    }

    return ' ';
}