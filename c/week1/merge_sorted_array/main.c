//https://leetcode.com/problem-list/w5s9pzgi/
// 88. Merge Sorted Array
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

int main()
{
    //test case
    int nums1Size = 6, nums2Size = 3, m = 3, n = 3;
    int nums1[6] = {1, 2, 3, 0, 0, 0};
    int nums2[3] = {2, 5, 6};
    merge(nums1, nums1Size, m, nums2, nums2Size, n);
}

void print_array(int *array, int size)
{
    if (size == 0)
        return;
    for(int i = 0; i < size-1; ++i)
    {
        printf("%d,", array[i]);
    }
    printf("%d", array[size-1]);
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    if(m == 0){
        for(int i = 0 ; i < n ; ++i)
            nums1[i] = nums2[i];
        return;
    } else if(n == 0){
        return;
    }

    int i, j, o, totalSize = m + n;
    int* res = (int*)malloc(totalSize * sizeof(int));
    i = j = o = 0;
    while(o < (m + n)){
        if(i < m && j < n){
            int *temp1 = &nums1[i], *temp2 = &nums2[j];
            if(*temp1 <= *temp2)
                res[o++] = nums1[i++];
            else
                res[o++] = nums2[j++];
        }
        else if(i < m && j >= n){
            res[o++] = nums1[i++];
        }
        else{
            res[o++] = nums2[j++];
        }
    }

    for(int i = 0 ; i < totalSize ; ++i)
        nums1[i] = res[i];

    print_array(res, totalSize);

    free(res);
}