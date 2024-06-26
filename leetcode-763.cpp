#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> p;
        vector<int> ind(26,0);
        int n = s.size();
        for(int i=0;i<n;i++){
            ind[s[i]-'a'] = i;
        }
        int start = 0, end;
        while(start<n){
            end = ind[s[start]-'a'];
            int temp = start;
            while(start<end && end<n){
                start++;
                end = max(end,ind[s[start]-'a']);
            }
            p.push_back(end-temp+1);
            start =end+1;
        }
        return p;

    }
};