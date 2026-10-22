/*
LC 383 - Ransom Note
Link: https://leetcode.com/problems/ransom-note/
Hours Effort: 00:38:25
Solution: Frequency Array (Hash Table simulation with int[26])
Time: O(N + M), Space: O(1)
*/
bool canConstruct(char* ransomNote, char* magazine) {
    int count[26] = {0};
    for(int i = 0; i < strlen(magazine);i++){
        int x = magazine[i] - 'a';
        count[x]++;
    }
    for(int i = 0; i < strlen(ransomNote);i++){
        int x = ransomNote[i] - 'a';
        count[x]--;
        if(count[x] < 0) return false;
    }
    return true;
}