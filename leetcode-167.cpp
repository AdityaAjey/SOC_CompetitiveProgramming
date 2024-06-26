#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> a(2);
        int i=0,j=numbers.size()-1;
        if(numbers[i]+numbers[j]==target){
            a[0] = i;
            a[1] = j;
            return a;
        }
        while(numbers[i]+numbers[j]!=target){
            if(numbers[i]+numbers[j]<target) i++;
            else j--;
        }
        a[0] = min(i,j)+1;
        a[1] = max(i,j)+1;
        return a;
    }
}; // we use the last and first pointer in start because we know for each case there is only 1 direction to move in
