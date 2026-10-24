/*
LC 389 - Find the Difference
Link: https://leetcode.com/problems/find-the-difference/
Hours Effort: 00:10:08
Solution: Frequency Array (Hash Table simulation with int[26])
Time: O(N + M), Space: O(1)
*/
char findTheDifference(char* s, char* t) {
    int count[26] = {0};
    for(int i = 0; i < strlen(t);i++){
        int x = t[i] - 'a';
        count[x]++;
    }
   for(int i = 0; i < strlen(s);i++){
        int x = s[i] - 'a';
        count[x]--;
   }
   for(int i = 0; i < 26;i++){
        if(count[i] == 1) return i + 'a';
   }
   return ' ';
}