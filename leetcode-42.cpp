#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int water(vector<int>& height, int i, int j){
        int water = 0;
        if(height[i]>=height[j]){
            int k=i+1;
            int n= height.size();
            while(!(height[k+1]>=height[j] && height[j]>height[k])){
                k++;
            }
            for(int a=k;a<j && a<n;a++){
                water+=height[a]-height[k];
            }
            return water;
        }
        if(height[i]<height[j]){
            int k=j-1;
            while(!(height[k+1]>=height[i] && height[i]>height[k])){
                k--;
            }
            for(int a=k;a>i && a>0;a--){
                water+=height[a]-height[k];
            }
            return water;

        }
        return water;
    }
    int trap(vector<int>& height) {
        int trap = 0;
        int n=height.size();
        int i=0;
        int j=2;
        while(j<n){
            if(height[i]<height[i+1]){
                i++;
                if(i==j) j++;
                
            }
            if(height[j]<=height[j+1]) j++;
            if(!(height[i]<height[i+1]) || (height[j]<=height[j+1])){
                trap += water(height,i,j);
            }

        }
        return trap;
    }
};

int main() {
    Solution solution;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "Trapped water: " << solution.trap(height) << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int> &height){
        
    }
};