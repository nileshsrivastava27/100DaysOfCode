#include<iostream>
using namespace std;


int strStr(string haystack, string needle)
{
    int ans = -1;
    int n = needle.size();

    for(int i=0;i<haystack.size();i++)
    {
        if(haystack[i] == needle[0])
        {
            int flag = 0;
            int index = 1;

            while(index!=n)
            {
                if((index+i)<haystack.size() && haystack[index+i] == needle[index])
                {
                    index++;
                }
                else{
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){
                ans = i;
                return ans;
            }
        }

    }

    return ans;
}