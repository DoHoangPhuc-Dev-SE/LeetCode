/*
LC 49 - Group Anagrams
Link: https://leetcode.com/problems/group-anagrams/
Hours Effort: 01:38:14
Solution: Sorting individual string keys (In Progress)
Time: O(N * K log K), Space: O(1)
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 static char** global_keys;
 int compareIndices(const void*a,const void*b){
    int idxA = *(int*)a;
    int idxB = *(int*)b;
    return strcmp(global_keys[idxA],global_keys[idxB]);
 }

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    char** keys = (char**)malloc(100000 * sizeof(char*));
    for(int i = 0; i < strsSize;i++) keys[i] = (char*)malloc(10000 * sizeof(char*));
    int indices[strsSize];
    for(int i = 0; i < strsSize;i++){
        int len = 0;
        while(strs[i][len] != '\0'){
            keys[i][len] = strs[i][len];
            len++;
        }
        keys[i][len] = '\0';
        for(int a = 0; a < len - 1;a++){
            for(int b = a + 1;b < len; b++){
                if(keys[i][a] > keys[i][b]) {
                    char temp = keys[i][a];
                    keys[i][a] = keys[i][b];
                    keys[i][b] = temp;
                }
            }
        }
        indices[i] = i;
    } 
    global_keys = keys;
    qsort(indices,strsSize,sizeof(int),compareIndices);
    int groups = 0;
    for(int i = 0; i < strsSize;i++){
        if(i == 0 || strcmp(keys[indices[i]],keys[indices[i - 1]]) != 0) groups++;
    }
    char*** res = malloc(groups  * sizeof(char**));
    *returnColumnSizes = malloc(groups * sizeof(int));
    *returnSize = groups;
    int g = -1, i = 0;
    while(i < strsSize) {
        int j = i;
        while(j < strsSize && strcmp(keys[indices[j]],keys[indices[i]]) == 0) j++;
        int size = j - i;
        g++;
        res[g] = malloc(size * sizeof(char*));
        (*returnColumnSizes)[g] = size;
        for(int k = 0; k < size;k++){
            res[g][k] = strs[indices[i + k]];
        }
        i = j;
    }
    for(int i = 0; i < strsSize;i++) free(keys[i]);
    free(keys);
    return res;
}