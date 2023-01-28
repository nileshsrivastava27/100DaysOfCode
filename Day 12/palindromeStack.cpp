#include<iostream>
#include<vector>
#include<stack>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        stack<int> st;
        if(x<0)
            return false;
        int y=x;
        while(x)
        {
            st.push(x%10);
            x/=10;
        }
        while(y)
        {
            if(st.top()!=(y%10))
               return false;
             st.pop();
               y/=10;
        }
        return true;
    }
};