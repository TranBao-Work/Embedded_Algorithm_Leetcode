// https://leetcode.com/problem-list/w5s9pzgi/
//  1662. Check If Two String Arrays are Equivalent
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size);

int main()
{
    char* word1[] = {"ab", "c"};
    char* word2[] = {"a", "bc"};

    int word1Size = 2, word2Size = 2;

    if (arrayStringsAreEqual(word1, word1Size, word2, word2Size))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
}

bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    int i = 0, j = 0, it1 = 0, it2 = 0;
    while(it1 < word1Size && it2 < word2Size){
        if(word1[it1][i] != word2[it2][j]){
            return false;
        }
        ++i;
        ++j;

        if(word1[it1][i] == '\0'){
            i = 0;
            ++it1;
        }

        if(word2[it2][j] == '\0'){
            j = 0;
            ++it2;
        }
    }

    if(it1 == word1Size && it2 == word2Size)
        return true;

    return false;
}