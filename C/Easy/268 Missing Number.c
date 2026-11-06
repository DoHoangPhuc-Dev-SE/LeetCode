/*
LC 268 - Missing Number
Link: https://leetcode.com/problems/missing-number/
Hours Effort: 00:11:51
Solution: Summation Method (Expected Sum vs Actual Sum)
Time: O(n), Space: O(1)
*/
int missingNumber(int* nums, int numsSize) {
    int sum = 0;
    int sumReal = 0;
    for(int i = 0; i < numsSize;i++){
        sum += nums[i];
    }
    for(int i = 0; i <= numsSize;i++){
        sumReal += i;
    }
    return sumReal - sum;
}