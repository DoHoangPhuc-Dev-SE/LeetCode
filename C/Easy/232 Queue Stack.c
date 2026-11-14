/*
LC 232 - Implement Queue using Stacks
Link: https://leetcode.com/problems/implement-queue-using-stacks/
Hours Effort: 00:41:25
Solution: Two-Stack Queue Simulation (s1 for push, s2 for pop/peek transfer)
Time: O(1) amortized, Space: O(n)
*/



typedef struct {
    int s1[100];
    int top1;
    int s2[100];
    int top2;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->top1 = -1;
    obj->top2 = -1;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->top1++;
    obj->s1[obj->top1] = x;
}

int myQueuePop(MyQueue* obj) {
    if(obj->top1 == -1 && obj->top2 == -1) return -1;
    if(obj->top2 == -1) {
        while(obj->top1 != -1) {
            obj->top2++;
            obj->s2[obj->top2] = obj->s1[obj->top1];
            obj->top1--;
        }
    }
   return obj->s2[obj->top2--];
}

int myQueuePeek(MyQueue* obj) {
    if(obj->top1 == -1 && obj->top2 == -1) return -1;
    if(obj->top2 == -1) {
        while(obj->top1 != -1){
            obj->top2++;
            obj->s2[obj->top2] = obj->s1[obj->top1];
            obj->top1--;
        } 
    }
    return obj->s2[obj->top2];
}

bool myQueueEmpty(MyQueue* obj) {
    return (obj->top1 == -1 && obj->top2 == -1);
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/