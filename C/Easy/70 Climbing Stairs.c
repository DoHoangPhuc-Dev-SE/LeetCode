/*
LC 70 - Climbing Stairs
Link: https://leetcode.com/problems/climbing-stairs/
Hours Effort: 00:08:27
Solution: Space-Optimized Bottom-Up DP (Fibonacci Rolling Variables)
Time: O(n), Space: O(1)
*/
int climbStairs(int n) {
    if(n < 2) return n;
    int a = 1;
    int b = 2;
    for(int i = 2; i < n; i++){
        int c = a + b;
        a = b;
        b = c;
    }
    return b;
}