#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal=nums.size();
        goal--;
        int i=goal-1;
        while(i>=0 && i<goal){
            if(nums[i]>=goal-i){
                goal=i;
                i--;
            }
            else i--;
        }
        if(goal ==0) return true;
        return false;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==0) return true;
        if(nums[0] == 0) return false;
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            if(maxi<i) return false;
            int curr = min(n, nums[i]+i);
            maxi = max(curr,maxi);
            if(maxi>=n-1) return true;
        }
        if(maxi>=n-1) return true;
        return false;
    }
}; // maxi is the maximum index we can reach from the covered indices -- the assumption is that if you can reach x 
// you can reach anywhere from 0 to x