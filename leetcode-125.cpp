#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i=0,j=n-1;
        while(i<j){
            int a= s[i]-'a';
            int b= s[i]-'A';
            int c=s[j]-'a';
            int d= s[j]-'A';
            if(((a>-1 && a<26) ||(b>-1 && b<26)) && ((c>-1 && c<26) || (d>-1 && d<26))){
                if(!(s[i]-s[j]==0 || s[i]-s[j]==32 || s[i]-s[j]==-32)){
                    return false;
                }
                i++;
                j--;
            }
            else if((a>-1 && a<26) || (b>-1 && b<26)) j--;
            else i++;
        }
        return true;
    }
};
// my solution fails for numbers as it did not check for numbers



class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n - 1;
        
        while (i < j) {
            // Move i to the right if s[i] is not alphanumeric
            while (i < j && !isalnum(s[i])) {
                i++;
            }
            
            // Move j to the left if s[j] is not alphanumeric
            while (i < j && !isalnum(s[j])) {
                j--;
            }
            
            // Convert both characters to lowercase to handle case insensitivity
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            
            i++;
            j--;
        }
        
        return true;
    }
};
