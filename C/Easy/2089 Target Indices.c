/*
LC 2089 - Find Target Indices After Sorting Array
Link: https://leetcode.com/problems/find-target-indices-after-sorting-array/
Hours Effort: 00:29:00
Solution: Bubble Sort & Linear Scan
Time: O(N^2), Space: O(N)
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    int *p = (int*)malloc(numsSize * sizeof(int));
    int count = 0;
    for(int i = 0; i < numsSize - 1 ;i++){
        for(int j = 0; j < numsSize - i - 1;j++){
            if(nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
    for(int i = 0;i < numsSize;i++){
        if(target == nums[i]) {
            p[count++] = i;
        }
    }
    *returnSize = count;
    return p;
}