#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int numarr[] = {1, 2, 3, 4};
    int *numarrptr = numarr;
    int fuckaf[] = {2, 3};
    int *returnSize = fuckaf;

    int numsSize = sizeof numarr / sizeof numsSize;
    int *a = twoSum(numarrptr, numsSize, 7, fuckaf);
    int b = *a;
    a++;
    int c = *a;
    printf("%d, %d", b, c);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int size = *returnSize = 2;
    int *arr = malloc(size * sizeof(int));

    for(int i = 0; i < numsSize; i++){
        for(int j = 1 + i; j < numsSize; j++){
            if(nums[i]+nums[j] == target){
                arr[0] = i;
                arr[1] = j;
            };
        }
    }
    return arr;
}