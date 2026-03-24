// https://leetcode.com/problem-list/w5s9pzgi/
// 1431. Kids With the Greatest Number of Candies

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize);

int main()
{
    int cadies[] = {2, 5, 3, 1, 3};

    int extraCandies = 3, candiesSize = 5, returnSize = 0;
    bool* result = kidsWithCandies(cadies, candiesSize, extraCandies, &returnSize);

    for (int i = 0 ; i < returnSize ; ++i)
    {
        printf("%d\n", result[i]);
    }

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool* result = (bool*)malloc(candiesSize*sizeof(bool));

    *returnSize = candiesSize;

    short maxCandies = 0, tmp, i;
    for(i = 0 ; i < candiesSize ; ++i){
        tmp = candies[i];
        maxCandies = (tmp > maxCandies) ? tmp : maxCandies;
    }

    for(i = 0 ; i < candiesSize ; ++i){
        tmp = candies[i];
        result[i] = ((tmp + (short)(extraCandies)) >= maxCandies) ? true : false;
    }
    return result;
}