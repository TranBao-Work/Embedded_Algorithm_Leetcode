// https://leetcode.com/problem-list/w5s9pzgi/
// 383. Ransom Note

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool canConstruct(char* ransomNote, char* magazine);

int main(void)
{
    char *a = "aa";
    char *b = "aab";

    if (canConstruct(a, b))
    {
        printf("True!\n");
    } else
    {
        printf("False!\n");
    }

    return 0;
}

bool canConstruct(char* ransomNote, char* magazine) {
    short countChar[26];
    short index;

    memset(countChar, 0x00, 26*sizeof(short));

    while(*magazine != '\0'){
        ++countChar[(short)*magazine - 97];
        ++magazine;
    }

    while(*ransomNote != '\0'){
        index = (short)*ransomNote;
        if(countChar[index-97] == 0)
            return false;
        --countChar[index-97];
        ++ransomNote;
    }

    return true;
}