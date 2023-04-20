#include<iostream>
#include<vector>
using namespace std;

class BrowserHistory {
public:
    vector<string>v;
    int curr, cnt = 0;
    
    BrowserHistory(string homepage) {
     
        v.push_back(homepage);
        curr = 0;
    }
    
    void visit(string url) {
     
      curr++;
      v.resize(curr);
      v.push_back(url); 
    }
    
    string back(int steps) {
     
     curr = max(0, curr - steps);
     return v[curr];
    }
    
    string forward(int steps) {
     int n = v.size();
     curr = min(n-1, curr+steps);

     return v[curr];
    }
};
