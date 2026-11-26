/*
LC 3360 - Stone Removal Game
Link: https://leetcode.com/problems/stone-removal-game/
Hours Effort: 00:22:31
Solution: Recursive Turn Simulation
Time: O(1), Space: O(1) (at most 10 turns for n <= 50)
*/
bool turn(int remain, int take, bool isAlice) {
    if(remain < take)
    return isAlice == false;
    else if( isAlice == true) return turn(remain - take, take - 1, false);
    else return turn(remain - take, take - 1, true);
}
bool canAliceWin(int n) {
    if(n < 10) return false;
    bool isAlice = true;
    int take = 10;
    bool win = turn (n,take, isAlice);
    return win;
}