#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_set<int> s;
        // for(auto x:nums){
        //     s.insert(x);
        // }
        unordered_set<int> s(nums.begin(), nums.end()); //same as above
        int seq = 0;
        for(auto x:nums){
            if(!s.count(x-1)){
                
                // while(s.count(x+seq)){
                //     seq++;
                // } 
                // the problem with tha above is that it does not check if the numbers x+1 x+2 etc are present. it takes a leap pf faith and checks directly if x+seq is present and assumes the elements bw x and x+seq are there
            int currseq=1;
            // int temp=x;
            // while(!s.count(temp+1)){
            //     currseq++;
            //     temp++;
            // }
            // seq = max(seq, currseq);
            while (s.count(x + currseq)) {  // Check for consecutive elements
                    currseq++;
                }
                seq = max(currseq, seq);
            }

        }
        return seq;
    }
};

// Example usage
 int main() {
    Solution solution;
     vector<int> nums = {9,1,4,7,3,-1,0,5,8,-1,6}; //3456789
     int result = solution.longestConsecutive(nums);
     cout << "Longest consecutive sequence length: " << result << endl;
     return 0;
 }
