/*
LC 225 - Implement Stack using Queues
Link: https://leetcode.com/problems/implement-stack-using-queues/
Hours Effort: 00:25:45
Solution: Queue Simulation (Single Queue Rotation Strategy)
Time: O(n) for push, O(1) for pop/top/empty, Space: O(n)
*/



typedef struct {
    int data[100];
    int front;
    int rear;
    int size;
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->front = 0;
    obj->rear = -1;
    obj->size = 0;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    obj->rear = (obj->rear + 1) % 100;
    obj->data[obj->rear] = x;
    obj->size++;
    int count = obj->size - 1;
    while(count > 0) {
        int temp = obj->data[obj->front];
        obj->front = (obj->front + 1) % 100;
        obj->rear = (obj->rear + 1) % 100;
        obj->data[obj->rear] = temp;
        count--;
    }
}

int myStackPop(MyStack* obj) {
    if(obj->size == 0) return -1;
    int val = obj->data[obj->front];
    obj->front = (obj->front + 1) % 100;
    obj->size--;
    return val;
}

int myStackTop(MyStack* obj) {
    if(obj->size == 0) return -1;
    return obj->data[obj->front];
}

bool myStackEmpty(MyStack* obj) {
    return obj->size == 0;
}

void myStackFree(MyStack* obj) {
    free(obj);
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