#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> topK;
        unordered_map<int, int> frequency;
        // unordered_map<int, int> elements;
        for(auto i:nums){
            frequency[i] +=1; // for keys not existing the value will be initialised to 0
        }
        for(int i=0;i<k;i++){
            int tempfrequency=0;
            int maximalelement = INT_MIN;//-INFINITY; problem with infintiy
            for(auto x:frequency){
                if(x.second>tempfrequency){
                    tempfrequency = x.second;
                    maximalelement = x.first;
                }
            }
            topK.push_back(maximalelement);
            frequency.erase(maximalelement); // erase function
        }
        return topK;
    }
};