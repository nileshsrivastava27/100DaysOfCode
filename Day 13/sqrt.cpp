#include<iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int s = 0, e = x;
        while(s < e){
            long long mid = s + ((long long)e - s + 1) / 2;
            if(mid * mid <= (long long)x)
                s = mid;
            else
                e = mid - 1;
        }
        return s;
    }
};