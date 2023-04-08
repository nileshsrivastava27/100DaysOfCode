#include<iostream>
#include<vector>
using namespace std;

    string longestCommonPrefix(vector<string>& str) {
        sort(str.begin(),str.end());

        int a=str.size();

        string n=str[0], m=str[a-1], ans="";

        for(int i=0;i<n.size();i++){

            if(n[i]==m[i])
            {
                ans+=n[i];
            }

            else 
                break;
                
        }
        return ans;
        
    }