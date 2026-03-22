// https://leetcode.com/problem-list/w5s9pzgi/
//20. Valid Parentheses
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

bool isValid(char* s);

int main()
{
    char* s = "{}";

    if (isValid(s))
        printf("true");
    else
        printf("false");

    return 0;
}

bool isValid(char* s) {
    size_t s_len = strlen(s);

    if (s_len % 2 != 0) {
        return false;
    }

    char* arr = (char*)malloc(s_len*sizeof(char));
    short i = 0;

    for(short j = 0 ; j < s_len ; ++j){
        switch(s[j]){
        case '(':{
                arr[i++] = ')';
                break;
        }

        case '{':{
                arr[i++] = '}';
                break;
        }

        case '[':{
                arr[i++] = ']';
                break;
        }

        default:{
                if(i <= 0){
                    free(arr);
                    return false;
                } else if(s[j] != arr[i-1]){
                    free(arr);
                    return false;
                } else {
                    --i;
                }
        }
        }
    }

    free(arr);
    if(i == 0)
        return true;

    return false;
}