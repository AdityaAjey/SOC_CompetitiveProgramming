class Solution {
public:

    bool isPerm(string s1, string s2, int i, int j){
        vector<int> a(26,0);
        for(char x:s1){
            a[x-'a']++;

        } //s2 mein bas i se j tk
        for(int k=i;k<=j;k++){
            char x = s2[k];
            a[x-'a']--;
            if(a[x-'a']<0) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int m=s1.length(),n=s2.length();
        if(m>n) return false;
        int i=0,j=m-1;
        while(j<n){
            if(isPerm(s1,s2,i,j)) return true;
            i++;
            j++;
        }
        return false;
    }
};
/*
    Given 2 strings, return true if s2 contains permutation of s1
    Ex. s1 = "ab", s2 = "eidbaooo" -> true, s2 contains "ba"

    Sliding window, expand + count down char, contract + count up char

    Time: O(n)
    Space: O(1)
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if (m > n) {
            return false;
        }
        
        vector<int> count(26);
        for (int i = 0; i < m; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        if (isPermutation(count)) {
            return true;
        }
        
        for (int i = m; i < n; i++) {
            count[s2[i] - 'a']--;
            count[s2[i - m] - 'a']++;
            if (isPermutation(count)) {
                return true;
            }
        }
        
        return false;
    }
private:
    bool isPermutation(vector<int>& count) {
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
 // my implementation had a problem that i was calculating the frequency again of each element jb i aur j  change hue tb bas 
// ek char ki freq inc. hogi aur ek ki dec. yhi bas update krna hai. fir count ko check krna hai.
