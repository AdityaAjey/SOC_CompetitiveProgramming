#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        if(s[0]==')' ) return false;
    //     int l,r,p;
    //     l=r=p=0;
    //     for(char x:s){
    //         if(x=='(') l++;
    //         if(x=='*') p++;
    //         if(x==')') r++;
    //         if(l+p<r) return false;
            
    //     }
    //     return l-p-r<=0 && l+p-r>=0;
    // } can't find error
        int min = 0,max=0;
        for(char x:s){
            if(x=='(') {
                min++;
                max++;
            }
            if(x=='*'){
                min--;
                max++;
            }
            if(x==')') {
                min--;
                max--;
            }
            if(max<0) return false;
            if(min<0) min=0;
        }
        return min==0;
    }


};