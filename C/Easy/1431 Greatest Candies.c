/*
LC 1431 - Kids With the Greatest Number of Candies
Link: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/
Hours Effort: 00:15:00
Solution: Iterative (Array Scan)
Time: O(N), Space: O(N)
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    bool* res = (bool*)malloc(candiesSize * sizeof(bool));
    int max = candies[0];
    for(int i = 0; i < candiesSize; i++){
        if(candies[i] > max) max = candies[i];
    }
    for(int i = 0; i < candiesSize;i++){
        if(candies[i] + extraCandies >= max)  res[i] = true;
        else res[i] =false;
    }
    *returnSize = candiesSize;
    return res;
}