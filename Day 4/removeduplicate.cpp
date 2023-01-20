#include<iostream>
#include<vector>
using namespace std;

int removeDuplicates(vector<int>& v) {
        for(int i=0;i<v.size()-1;i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                if(v[i]==v[j])
                {
                    v.erase(v.begin()+j);
                    j--;
                }
            }
        }
        return v.size();
    
    }