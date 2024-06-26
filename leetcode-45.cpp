#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        int steps = 0;
        int maxReachable = 0;
        int lastJump = 0;

        for (int i = 0; i < n - 1; ++i) {
            maxReachable = std::max(maxReachable, i + nums[i]);
            if (i == lastJump) {
                lastJump = maxReachable;
                ++steps;
            }
        }

        return steps;
    }
};

class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        int steps = 0;
        int maxi = 0;
        int last = 0;
        for(int i=0;i<n-1;i++){ // mistake was i put n insted of n-1
            maxi = max(maxi, nums[i]+i);
            if(last == i){
                last = maxi;
                steps++;
            }
        }

        return steps;
    }
};