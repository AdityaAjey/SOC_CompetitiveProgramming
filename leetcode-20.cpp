class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        if(s.empty()) return true;
        int n= s.length();
        int j=0;
        while(j<n){
            if(s[j] == '{' || s[j]=='[' || s[j]=='(') a.push(s[j]);
            else if(!a.empty() && (s[j]-a.top()==2 || s[j]-a.top()==1)) a.pop(); // first major isue was that I did not check at this stage if s.empty or not
            else return false;
            j++;
        }
        return a.empty();
    }
};