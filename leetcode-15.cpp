#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> three;
        unordered_set<int> s;
       // unordered_set<vector<int>> tripletholder;
        for(auto x:nums){
            s.insert(x);
        }
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
            if(s.count(-nums[i]-nums[j])){
                vector<int> a(3);
                a[0]=nums[i];
                a[1]=nums[j];
                a[2]=-nums[i]-nums[j];
                three.push_back(a);
            }
            }
        }
        return three;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> three;
        for(int i=0;i<n-2;i++){ //i <n se error aaya because the last 3rd ke baad triplet nhi bnega
            int j=i+1;
            int k=n-1;
            while(nums[j]+nums[k]!=-1*nums[i] && j<k){
                if(nums[j]+nums[k]<-1*nums[i]) j++;
                else k--;
            }
            if(j<k){
                vector<int> a(3);
                a[0]=nums[i];
                a[1]=nums[j];
                a[2]=-nums[i]-nums[j];
                three.push_back(a);
            }

        }
        return three;
    }
};

// my idea was good to implement first sorting then for each element do two sum for -1*element
