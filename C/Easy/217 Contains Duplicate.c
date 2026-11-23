/*
LC 217 - Contains Duplicate
Link: https://leetcode.com/problems/contains-duplicate/
Hours Effort: 00:31:14
Solution: QuickSort (Lomuto Partition with Mid Pivot) & Adjacent Duplicate Scan
Time: O(n log n) average, Space: O(log n) recursion stack
*/
void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}
int part(int a[], int low, int high){
    int mid = low + (high - low) /2;
    swap(&a[mid],&a[high]);
    int pivot = a[high];
    int i = low - 1;
    for(int j = low; j < high;j++){
        if(a[j] <= pivot){
            i++;
            if(i != j) swap(&a[i],&a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return i + 1;
}
void qs(int a[], int low, int high){
    if(low < high){
        int p = part(a,low,high);
        qs(a, low, p - 1);
        qs(a, p + 1, high);
    }
}
bool containsDuplicate(int* nums, int numsSize) {
    qs(nums,0,numsSize - 1);
    for(int i = 0; i < numsSize - 1; i++){
        if(nums[i] == nums[i +1]) return true;
    }
    return false;
}