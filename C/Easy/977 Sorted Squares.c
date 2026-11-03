C
/*
LC 977 - Squares of a Sorted Array
Link: https://leetcode.com/problems/squares-of-a-sorted-array/
Hours Effort: 00:16:26
Solution: In-place Squaring + Quick Sort (Divide and Conquer)
Time: O(N log N), Space: O(log N)
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
 }
 int part(int a[],int low,int high){
    int pivot = a[high];
    int i = low - 1;
    for(int j = low;j < high;j++){
        if(a[j] < pivot){
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i + 1;
 }
 void qusort(int a[],int low,int high){
    if(low < high){
        int p = part(a,low,high);
        qusort(a,low,p - 1);
        qusort(a, p + 1, high);
    }
 }
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    for(int i = 0;i < numsSize;i++){
        nums[i] *= nums[i];
    }
    qusort(nums,0,numsSize - 1);
    *returnSize = numsSize;
    return nums;
}