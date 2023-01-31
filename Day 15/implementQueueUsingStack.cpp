#include<iostream>
#include<stack>
#include<queue>
using namespace std;


class MyQueue {
public:

    stack<int> s;
    MyQueue() {
        
    }
    
    void push(int x) {
        pushfunc(x);
    }

    void pushfunc(int x){
        if(s.empty()){
            s.push(x);
            return;
        }
        int data=s.top();
        s.pop();
        pushfunc(x);
        s.push(data);
    }
    
    int pop() {
        int x = s.top();
        s.pop();
        return x;
    }
    
    int peek() {
        return s.top();
    }
    
    bool empty() {
        return s.empty();
    }
};