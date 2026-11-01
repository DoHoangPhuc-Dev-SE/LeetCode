/*
LC 561 - Array Partition
Link: https://leetcode.com/problems/array-partition/
Hours Effort: 00:32:58
Solution: Quick Sort (Divide and Conquer) + Greedy Pair Sum
Time: O(N log N), Space: O(log N)
*/
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int part(int* nums,int low, int high){
    int pivot = nums[high];
    int i = low - 1;
    for(int j = low;j <= high - 1;j++ ){
        if(nums[j] <= pivot){
            i++;
            swap(&nums[i],&nums[j]);
        }
    }
    swap(&nums[i + 1],&nums[high]);
    return i + 1;
}
void qusort(int* nums,int low, int high){
    if(low < high){
        int p = part(nums,low,high);
        qusort(nums,low,p - 1);
        qusort(nums,p + 1,high);
    }
}
int arrayPairSum(int* nums, int numsSize) {
    int sum = 0;
    qusort(nums,0,numsSize - 1);
    for(int i = 0; i < numsSize;i += 2){
        sum += nums[i];
    }
    return sum;
}