#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:

    bool match(char close, char open){

        if(close == ']' && open == '[')
            return true;
        if(close == '}' && open == '{')
            return true;
        if(close == ')' && open == '(')
            return true;

        return false;
    }


    bool isValid(string s) {

        stack<int> st;

        int len = s.length();
        if(len&1){
            return false;
        }


        for(int i=0;i< len;i++){
            char ch = s[i];

            if(ch=='[' || ch=='(' || ch == '{'){
                st.push(ch);
            }

            else{

                if(!st.empty() && match(ch, st.top())){
                    st.pop();
                }

                else{
                    return false;
                }
            }

        }

        if(st.empty()){
            return true;
        }

        else{
            return false;
        }



    }
};