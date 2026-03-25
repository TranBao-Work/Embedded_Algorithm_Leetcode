// https://leetcode.com/problem-list/w5s9pzgi/
// 643. Maximum Average Subarray I

#include<stdio.h>
#include<math.h>

double findMaxAverage(int* nums, int numsSize, int k);

int main()
{
    const int SIZE = 6;
    int k = 4;
    int nums[] = {1, 12, -5, -6, 50, 3};

    printf("%.5f", findMaxAverage(nums, SIZE, k));

    return 0;
}

double findMaxAverage(int* nums, int numsSize, int k) {
    double result = -10000.000;
    int i, tmp = 0;

    for(i = 0 ; i < numsSize ; ++i){
        tmp += nums[i];
        if(i < k-1){
            continue;
        }

        if(i == k - 1){
            result = fmax(result, (double)tmp/(double)k);
            continue;
        }

        tmp -= nums[i - k];
        result = fmax(result, (double)tmp/(double)k);
    }

    return result;
}