#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        bool a,b,c;
        a=b=c=false;
        for(int i=0;i<n;i++){
            if(triplets[i][0]<=target[0] && triplets[i][1]<=target[1] && triplets[i][2]<=target[2]) {
                if(!(triplets[i][0]<target[0] && triplets[i][1]<target[1] && triplets[i][2]<target[2])){
                    if(!a) a = (triplets[i][0]==target[0]);
                   if(!b) b = (triplets[i][1]==target[1]);
                    if(!c) c = (triplets[i][2]==target[2]);
                }
            }
            if (a && b && c) {
                return true; // left this part but it makes it faster
            }
        }
        return a&&b&&c;
    }
};