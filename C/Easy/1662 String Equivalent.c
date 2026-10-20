/*
LC 1662 - Check If Two String Arrays are Equivalent
Link: https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/
Hours Effort: 00:17:00
Solution: String Concatenation & Comparison
Time: O(N), Space: O(N)
*/
bool arrayStringsAreEqual(char** word1, int word1Size, char** word2, int word2Size) {
    char w1[10000] = "";
    char w2[10000] = "";
    for(int i = 0; i < word1Size;i++ ) {
        strcat(w1,word1[i]);
    } 
    for(int i = 0; i < word2Size;i++ ) {
        strcat(w2,word2[i]);
    }
    if(strcmp(w1,w2) == 0) return true;
    return false;
}