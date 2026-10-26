/*
LC 2409 - Count Days Spent Together
Link: https://leetcode.com/problems/count-days-spent-together/
Hours Effort: 00:36:21
Solution: Date to Day Conversion & Interval Overlap (Math / String Processing)
Time: O(1), Space: O(1)
*/
int dateToDay(char* date){
    int days[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month = (date[0] - '0') * 10 + (date[1] - '0');
    int day = (date[3] - '0') * 10 + (date[4] - '0');
    int totalDays = 0;
    for(int i = 0; i < 12;i++){
        if(i < month - 1)
        totalDays += days[i];
    }
    totalDays += day;
    return totalDays;
}

int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob, char* leaveBob) {
    int aA = dateToDay(arriveAlice);
    int lA = dateToDay(leaveAlice);
    int aB = dateToDay(arriveBob);
    int lB = dateToDay(leaveBob);
    int startOverlap = (aA > aB) ? aA : aB;
    int endOverlap = (lA < lB) ? lA : lB;
    if(startOverlap <= endOverlap) return endOverlap - startOverlap + 1;
    else return 0;
}