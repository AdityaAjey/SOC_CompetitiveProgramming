#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i=0,j=1, n=prices.size();
        int curr = prices[i];
        int next = prices[j];
        while(j<n && i<j){
            
            if(prices[j+1]>next) next = prices[j+1];
            if(prices[i+1]<curr) curr = prices[i+1];
            i++;
            j++;
        }
        int profit = max(0,next-curr);
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int min=INT_MAX;
        int profit = 0;
        for(auto price:prices){
            if(price<min){
                min = price;
            }
            else if(price-min>profit){
                profit = price-min;
            }
        }
        return profit;
    }

    int maxProfit(vector<int>& prices) {
        int l=0,r=0,p=0;
        while(r<prices.size()){
            if(prices[r]>prices[l]){
                p = max(p, prices[r]-prices[l]);
            }
            else l=r;
            r++;
        }
        return p;
    }
};

int main(){
    Solution s;
    vector<int> a= {7,1,5,3,6,4};
    
    cout<<s.maxProfit(a)<<"\n";
    return 0;
}