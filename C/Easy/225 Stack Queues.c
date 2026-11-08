/*
LC 225 - Implement Stack using Queues
Link: https://leetcode.com/problems/implement-stack-using-queues/
Hours Effort: 00:04:33
Solution: Queue-based Stack Simulation (Draft Skeleton)
Time: O(1) / O(n), Space: O(n)
*/



typedef struct {
    int data[100];
    int top;
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->top = -1;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    
}

int myStackPop(MyStack* obj) {
    
}

int myStackTop(MyStack* obj) {
    
}

bool myStackEmpty(MyStack* obj) {
    
}

void myStackFree(MyStack* obj) {
    
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/