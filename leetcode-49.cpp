#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        vector<int> alpha(26,0);
        for(char c:s){
            alpha[c-'a']++; // using ascii 
        }
        for(char c:t){
            if(alpha[c-'a']==0) return false;
            alpha[c-'a']--; 
        }
        return true;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> group;

    }
};