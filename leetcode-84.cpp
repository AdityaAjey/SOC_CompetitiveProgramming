#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int area = 0;
        stack<int> s;
        stack<int> t;
        for(int i=0;i<n;i++){
            // int j;
           // int start;
           int start = i; // start ko initialise krna =i importanmt tha  jonhi kiya pehle bas 
            while(!s.empty()&& s.top()>heights[i]){
                int h = s.top();
                int j= t.top();
                start = j;
                s.pop(); t.pop();
                area = max(area, h*(i-j));
                
            }
            s.push(heights[i]);
            t.push(start);
        }
        // ab bhi stack ko empty krna hai uss case ke liye jb heights inc ordere mein ho
        while(!s.empty()){
            int h = s.top();
            int j = t.top();
            s.pop(); t.pop();
            area = max(area, h*(n-j));
        }
        return area;
    }
};