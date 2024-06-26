#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string x:tokens){
            if(x=="+"){
                int a=(s.top());
                s.pop();
                int b=(s.top());
                s.pop();
                s.push(a+b);
                continue;
            }
            if(x=="-"){
                int a=(s.top());
                s.pop();
                int b=(s.top());
                s.pop();
                s.push(-a+b);
                continue;

            }
            if(x=="*"){
                int a=(s.top());
                s.pop();
                int b=(s.top());
                s.pop();
                s.push(a*b);
                continue;

            }
            if(x=="/"){
                int a=(s.top());
                s.pop();
                int b=(s.top());
                s.pop();
                s.push(b/a);
                continue;

            }
            s.push(stoi(x));
        }

        return s.top();
    }
};