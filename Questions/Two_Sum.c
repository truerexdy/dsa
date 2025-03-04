#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
}

int main(){
    int* nums = (int*)calloc(5,sizeof(int));
    int numsSize = 5;
    for(int i=0; i<numsSize; i++){
        nums[i] = rand() % 10;
    }
    int target = nums[rand()%5]+nums[rand()%5];
    int returnSize = 2;
    int* out = twoSum(nums, numsSize, target, returnSize);
    for(int i=0; i<returnSize; i++){
        printf("%d ", out[i]);
    }
    free(out);
    return 0;
}