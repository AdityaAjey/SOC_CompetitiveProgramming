#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int m=INT_MAX;
        for(int x:nums){
            m= min(x,m);
        }
        return m;
    }
}; // naive till now
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,n=nums.size(), j=n-1 ;
        if(n==1) return nums[0];
        if(n==2) return min(nums[0], nums[1]);
        while(i<j){
            int mid = i +(j-i)/2;
            if(nums[mid]<nums[(mid+1)%n] && nums[mid]<nums[(mid-1)%n]){
                
                return nums[mid];
            }
            if(nums[mid]>nums[i] && nums[mid]<nums[j]) return nums[0];
            else if(nums[mid]<nums[i] && nums[mid]<nums[j]) {
                j = mid-1;
            }
            else if(nums[mid]>nums[i] && nums[mid]>nums[j]){\
                i = mid+1;
            }
            else if(nums[mid]<nums[i] && nums[mid]>nums[j]){
                return nums[0];
            }
        }
        return nums[i];
    }
};


// final code where I not only use the i and j but also mid-1 and mid +1. Based on mid+1 or mid - 1 which is greater I can decide

class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0,n=nums.size(), j=n-1 ;
        if(n==1) return nums[0];
        if(n==2) return min(nums[0], nums[1]); // the cases which need to be done for faster --also I did not want mid-1 to be -ve as mid-1%n would give -ve index
        while(i<=j){
            int mid = i +(j-i)/2;
            if(mid>0 && nums[mid]<=nums[(mid+1)%n] && nums[mid]<=nums[(mid-1)%n]){
                return nums[mid]; // if both sides are greater than mid then we got ans 
            }
            if(mid>0 && nums[mid]>=nums[(mid+1)%n] && nums[mid]>=nums[(mid-1)%n]){
                return nums[(mid+1)%n]; // itmeans mid has the greatest element
            }
            else if(mid>0 && nums[mid]<=nums[(mid+1)%n] && nums[mid]>=nums[(mid-1)%n]){
                if(nums[j]>nums[mid]){
                    j = mid-1;
                }
                else i = mid+1;
            }

        }
        return -1;
    }
};