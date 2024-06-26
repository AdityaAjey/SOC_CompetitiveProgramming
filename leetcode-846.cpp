#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        int g=groupSize;
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        unordered_map<int,int> m;
        for(int x:hand){
            m[x]++; //if m[x] dne it will be 0
            minHeap.push(x);
        }
        int count = n; // number of remaining elements
        while(count>0){
             // int start = minHeap.top();
            
            // if(m[start]<=0) minHeap.pop(); after this line start should have been updated with the new vakue at top after popping
            // m[start]--;
            // the above part was faulty
            int start;
            while(m[minHeap.top()]<=0){
                minHeap.pop();
            }
            start = minHeap.top();
            m[start]--;
            for(int i=1;i<=g-1;i++){
                if(m[start+i]<=0) return false;
                m[start+i] --; // left this step
            }
            count-=g;
        }
        return true;
    }
}; // using priority queue for minheap