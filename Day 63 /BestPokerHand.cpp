#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
      

       vector<int> frequency;
       int count=0;
	   

        for(int i=0;i<suits.size();++i)
        {
            if(suits[i]==suits[i+1]) count++;
        }

        if(count+1==suits.size()) 
            return "Flush";
		
        else
        {
            unordered_map<int,int> mp;
            for(int i=0;i<ranks.size();++i)
            {
                mp[ranks[i]]++;
            }

            for(auto i:mp)
            {
                frequency.push_back(i.second);
            }
        
            sort(frequency.begin(),frequency.end());
            

            int largest =  frequency[frequency.size()-1];
            
            if(largest>=3) 
                return "Three of a Kind";
            
            else if(largest==2) 
                return "Pair";
		
        }
        return "High Card";
    }
};