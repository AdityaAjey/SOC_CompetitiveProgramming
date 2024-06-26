#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int cum[n];
        cum[0] = nums[0];
        for(int i=1;i<n;i++){
            cum[i] = cum[i-1]+nums[i];
        }
        int minSub = INT64_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i>0){
                    minSub = max(minSub, cum[j]-cum[i-1]);
                }
                else  minSub = max(minSub, cum[j]);
            }
        }
        return minSub;
    }
};

// this is o(n2)
/*
kadane's algorithm- for each index calculate the maximum sybaarraay sum ending there. 
*/

int maxSubArray(int* nums, int numsSize) {
    int curr=0,maxi=INT_MIN;
    for(int i=0;i<numsSize;i++){
        curr = max(curr+nums[i], nums[i]);
        maxi = max(curr, maxi);
    }
    return maxi;
}
// gpt gave below
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int maxi = INT_MIN;

        for (const auto& num : nums) {
            curr = max(curr + num, num);
            maxi = max(curr, maxi);
        }

        return maxi;
    }
};
