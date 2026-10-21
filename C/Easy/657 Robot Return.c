/*
LC 657 - Robot Return to Origin
Link: https://leetcode.com/problems/robot-return-to-origin/
Hours Effort: 00:11:00
Solution: Coordinate Tracking & Linear Scan
Time: O(N), Space: O(1)
*/
bool judgeCircle(char* moves) {
    int x = 0;
    int y = 0;
    for(int i = 0; i < strlen(moves);i++){
        if(moves[i] == 'L') x++;
        else if(moves[i] == 'R') x--;
        if(moves[i] == 'U') y++;
        else if(moves[i] == 'D') y--;
    }
    if(x == 0 && y == 0) return true;
    return false;
}