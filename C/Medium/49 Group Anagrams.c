/*
LC 49 - Group Anagrams
Link: https://leetcode.com/problems/group-anagrams/
Hours Effort: 00:38:49
Solution: Sorting individual string keys (In Progress)
Time: O(N * K log K), Space: O(1)
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    for(int i = 0; i < strsSize;i++){
        char key[10000];
        int len = 0;
        while(strs[i][len] != '\0'){
            key[len] = strs[i][len];
            len++;
        }
        key[len] = '\0';
        for(int a = 0; a < len - 1;a++){
            for(int b = a + 1;b < len; b++){
                if(key[i][a] > key[i][b]) {
                    char temp = key[i][a];
                    key[i][a] = key[i][b];
                    key[i][b] = temp;
                }
            }
        }
    *returnSize = 0;
    return NULL;
    } 
}