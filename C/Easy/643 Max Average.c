/*
LC 643 - Maximum Average Subarray I
Link: https://leetcode.com/problems/maximum-average-subarray-i/
Hours Effort: 00:16:14
Solution: Sliding Window (O(1) window update)
Time: O(n), Space: O(1)
*/
double findMaxAverage(int* nums, int numsSize, int k) {
    double currentSum = 0;
    for(int i = 0; i < k; i++){
        currentSum += nums[i];
    }
    double maxSum = currentSum;
    for(int i = k; i < numsSize;i++){
        currentSum += nums[i] - nums[i - k];
        if(maxSum < currentSum) maxSum = currentSum;
    }
    return maxSum/k;
}