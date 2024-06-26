#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0, n=s.length(), l=0;
        if(n==0 || n==1) return n;
        unordered_set<char> a;
        unordered_map<char, int> m;
        while(j<n){
            if(!a.count(s[j])){
                m[s[j]] = j;
                a.insert(s[j]);
                j++;
                l = max(l,j-i+1);
                
            }
            else{
                if(m[s[j]]>=i){
                    l = max(l,j-i);
                    i = m[s[j]] + 1;
                    m[s[j]] = j;
                    j++;
                }
                else{
                    m[s[j]] = j;
                    l = max(l,j-i);
                    j++;
                }
            }
        }
        return l;

    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0, n=s.length(), l=0;
        if(n==0 || n==1) return n;
        unordered_set<char> a;
        unordered_map<char, int> m;
        while(j<n){
            if(!a.count(s[j])){
                m[s[j]] = j;
                a.insert(s[j]);
                l = max(l,j-i+1);
                j++;
               
                
            }
            else{
                if(m[s[j]]>=i){
                    l = max(l,j-i);
                    i = m[s[j]] + 1;
                    m[s[j]] = j;
                    j++;
                }
                else{
                    m[s[j]] = j;
                    l = max(l,j-i+1); //+1 was not there
                    j++;
                }
            }
        }
        return l;

    }
};