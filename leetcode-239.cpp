#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void clean(vector<int> nums, deque<int> &q, int a){
        if(q.empty()) return;
        while(nums[q.back()]<a){
            q.pop_back();
            if(q.empty()) return;
        }
        return ;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> max;
        if(k>n) return max;
        deque<int> q;
        for(int i=0;i<k;i++){
            clean(nums,q, nums[i]);
            q.push_back(i);
        }
        max.push_back(nums[q.front()]);
        for(int i=k;i<n;i++){
            if(q.front()==i-k) q.pop_front();
            clean(nums,q, nums[i]); // pehle yha i daala nums[i] ke badle
            q.push_back(i);
            max.push_back(nums[q.front()]);
        }
        return max;
    }
};

The second solution is much faster.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void clean(vector<int> &nums, deque<int> &q, int i, int k) {
        // Remove elements not within the sliding window
        if (!q.empty() && q.front() == i - k) {
            q.pop_front();
        }
        // Remove elements from the back if they are smaller than the current element
        while (!q.empty() && nums[q.back()] < nums[i]) {
            q.pop_back();
        }
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        if (k > n) return result;

        deque<int> q;
        for (int i = 0; i < n; ++i) {
            clean(nums, q, i, k);
            q.push_back(i);
            // Start to add results to the output vector when we have the first valid window
            if (i >= k - 1) {
                result.push_back(nums[q.front()]);
            }
        }
        return result;
    }
};

