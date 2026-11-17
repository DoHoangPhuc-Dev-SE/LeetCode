/*
LC 1544 - Make The String Great
Link: https://leetcode.com/problems/make-the-string-great/
Hours Effort: 00:30:21
Solution: Stack-based string reduction using ASCII difference check
Time: O(n), Space: O(n)
*/
char* makeGood(char* s) {
    char stack[1000];
    int top = -1;
    for(int i = 0;  s[i] != '\0';i++) {
        if(top != -1 && abs(s[i] - stack[top]) == 32) {
            top--;
        }
        else {
            top++;
            stack[top] = s[i];
        }
    }
    stack[top + 1] = '\0';
    char* result = (char*)malloc((top + 2) * sizeof(char));
    strcpy(result,stack);
    return result;
}