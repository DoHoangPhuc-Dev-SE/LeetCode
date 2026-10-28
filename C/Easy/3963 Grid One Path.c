/*
LC 3963 - Create Grid With Exactly One Path
Link: https://leetcode.com/problems/create-grid-with-exactly-one-path/
Hours Effort: 00:20:08
Solution: L-shape Path Construction (2D Memory Allocation & Grid Filling)
Time: O(m * n), Space: O(m * n)
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** createGrid(int m, int n, int* returnSize) {
    char ** grid = (char**)malloc(m * sizeof(char*));
    for(int i = 0; i < m;i++){
        grid[i] = (char*)malloc((n + 1) * sizeof(char));
        for(int j = 0; j < n;j++) {
            grid[i][j] = '#';
        }
        grid[i][n] = '\0';
    }
    for(int i = 0; i < n;i++){
        grid[0][i] = '.';
        for(int j = 0; j < m;j++){
            grid[j][n - 1] = '.';
        }
    }
    *returnSize = m;
    return grid;
}