// https://leetcode.com/problem-list/w5s9pzgi/
// 657. Robot Return to Origin

#include<stdio.h>
#include<stdbool.h>

bool judgeCircle(char* moves);

int main()
{
    char* moves = "UD";

    if (judgeCircle(moves))
    {
        printf("True\n");
    } else
    {
        printf("False\n");
    }

    return 0;
}

bool judgeCircle(char* moves) {
    int x = 0, y = 0;
    for (; *moves != '\0'; ++moves) {
        switch (*moves) {
        case 'U':
            ++y;
            break;
        case 'D':
            --y;
            break;
        case 'R':
            ++x;
            break;
        case 'L':
            --x;
            break;
        }
    }
    return (x == y && x == 0);
}