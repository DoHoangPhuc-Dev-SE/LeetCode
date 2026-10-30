/*
LC 20 - Valid Parentheses
Link: https://leetcode.com/problems/valid-parentheses/
Hours Effort: 00:14:28
Solution: Stack (LIFO Data Structure with Array Implementation)
Time: O(n), Space: O(n)
*/
bool isValid(char* s) {
    char stack[10000];
    int top = -1;
    for(int i = 0; s[i] != '\0';i++){
        char c = s[i];
        if(c == '(' || c == '[' || c == '{') stack[++top] = c;
        else{ if(top == -1) return false;
        char topChar = stack[top--];
        if(c == ')' && topChar != '(') return false;
        if(c == ']' && topChar != '[') return false;
        if(c == '}' && topChar != '{') return false;
    }
    }
    return top == -1;
}