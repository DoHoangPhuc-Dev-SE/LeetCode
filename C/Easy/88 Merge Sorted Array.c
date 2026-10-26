/*
LC 88 - Merge Sorted Array
Link: https://leetcode.com/problems/merge-sorted-array/
Hours Effort: 00:20:12
Solution: Copy & Bubble Sort (In-place Array Merging)
Time: O((m + n)^2), Space: O(1)
*/
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    for(int i = 0; i < n ;i++){
        nums1[m + i] = nums2[i];
        }
    for(int i = 0; i < m + n - 1; i++){
        for(int j = 0; j < m + n - 1 - i; j++){
            if(nums1[j] > nums1[j + 1]){
                int temp = nums1[j];
                nums1[j] = nums1[j + 1];
                nums1[j + 1] = temp;
            }
        }
    }
}