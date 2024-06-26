#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int curr = 0, n=temperatures.size();
        vector<int> daily(n,0) ;
        
        for(int i=1;i<n;i++){
            if(temperatures[i]>temperatures[0]) {
                curr=i;
                
                break;
            }
        }
        daily[0]=(curr);
        for(int i=1;i<n;i++){
            if(temperatures[i]==temperatures[i-1]){
                daily[i]=max(daily[i-1]-1,0);
            }
            else if(temperatures[i]<temperatures[i-1]){
                for(int j=i+1;j<n;j++){
                    if(temperatures[j]>temperatures[i]){
                        daily[i] = j-i;
                        break;
                    }
                }
            }
            else {
                for(int j=i+1;j<n;j++){
                    if(temperatures[j]>temperatures[i]){
                        daily[i] = j-i;
                        break;
                    }
                }
            }
        }

        return daily;
    }
}; // brue till now

/*
    Given array of temps, return an array w/ # of days until warmer
    Ex. temperature = [73,74,75,71,69,72,76,73] -> [1,1,4,2,1,1,0,0]

    Monotonic decr stack, at each day, compare incr from prev days

    Time: O(n)
    Space: O(n)
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        
        // pair: [index, temp]
        stack<pair<int, int>> stk;
        vector<int> result(n);
        
        for (int i = 0; i < n; i++) {
            int currDay = i;
            int currTemp = temperatures[i];
            
            while (!stk.empty() && stk.top().second < currTemp) {
                int prevDay = stk.top().first;
                int prevTemp = stk.top().second;
                stk.pop();
                
                result[prevDay] = currDay - prevDay;
            }
            
            stk.push({currDay, currTemp});
        }
        
        return result;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        int n = temperatures.size();
        vector<int> daily(n,0);
        for(int i=0;i<temperatures.size();i++){ //index is important
            
                // while(temperatures[s.top()]<temperatures[i] && !s.empty()){ // didn't check if s is empty before using top
                   while(!s.empty()&& temperatures[s.top()]<temperatures[i] ){ // tnis line checks if tsack is empty before checking the top the above line firt used top then checked if empty or not
                    daily[s.top()] = i-s.top();
                    s.pop();
                }
                s.push(i);
            
        }
        return daily;
    }
};