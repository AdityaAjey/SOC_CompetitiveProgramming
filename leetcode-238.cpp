#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n= nums.size();
        int pref[n]; //product of prefix array 
        int suff[n]; //product of suffix array 
        pref[0] = 1;
        suff[n-1] = 1;
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] * nums[i-1];
            
        }
       // for(int i=0;i<n-1;i++){ // problem here the suff is calculated from back
        for(int i=n-2;i>-1;i--){
            suff[i]=suff[i+1]*nums[i+1];
        }
        vector<int> product(n);
        for(int i=0;i<n;i++){
            product[i] = pref[i]*suff[i];
        }
        return product;


        
    }
};