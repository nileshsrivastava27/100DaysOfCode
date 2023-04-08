#include<iostream>
#include<vector>
using namespace std;

class Trie {
public:
vector<string> ans;
    Trie() {
       
    }
    
    void insert(string word) {

        ans.push_back(word);
    }
    
    bool search(string word) {

        for(int i=0;i<ans.size();i++){
           if(ans[i]==word)
           {
               return true;
           }
        }
        return false;
    }
    
    bool startsWith(string prefix) {


        for(int i = 0; i < ans.size(); i++)
            if(ans[i].substr(0, prefix.size()) == prefix)
                return true;
        return false;
        }
    
};