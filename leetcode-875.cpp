#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int speed = 1, hour=0;
        for(int x:piles){
            hour+=ceil(x/speed);
        }
        if(hour==h) return speed;
        while(hour>h){
            speed = speed *2;
            hour = 0;
            for(int x:piles){
                hour+=ceil(x/speed);
            }
        }
        int max = speed, min = speed/2,mid;
        if(hour==h) return min;
        while(hour!=h){
            int mid = min + (max-min)/2;
            hour = 0;
            for(int x:piles){
                hour+=ceil(x/mid);
            }
            if(hour>h){
                min = mid+1;
            }
            if(hour==h){
                return mid;
            }
            else max = mid-1;
        }

        return mid;
    }
};  
 
// O(nlogn) becuase for each speed I am doing calculation
// better will be keep the min at 1 and max at maximum in array
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int min = 1, maxi=0, hour=0;
        for(int x:piles){
            hour+=ceil(x/min);
            maxi = max(maxi,x);
        }
        if(hour==h) return min;
        for(int x:piles){
                hour+=ceil(x/maxi);
        }
        if(hour==h) return maxi;
        int mid;
        
        while(hour!=h){
            mid = min + (maxi-min)/2;
            hour = 0;
            for(int x:piles){
                hour+=ceil(x/mid);
            }
            if(hour>h){
                min = mid+1;
            }
            if(hour==h){
                return mid;
            }
            else maxi = mid-1;
        }

        return mid;
    }
};

/*
    Given array of banana piles, guards are gone for h hours
    Return min int k such that can eat all banans within h
    Ex. piles = [3,6,7,11] h = 8 -> 4 (1@3, 2@6, 2@7, 3@11)

    Binary search, for each k count hours needed, store min

    Time: O(n x log m) -> n = # of piles, m = max # in a pile
    Space: O(1)
*/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        
        int low = 1;
        int high = 0;
        for (int i = 0; i < n; i++) {
            high = max(high, piles[i]);
        }
        
        int result = high;
        
        while (low <= high) {
            int k = low + (high - low) / 2;
            long int hours = 0;
            for (int i = 0; i < n; i++) {
                hours += ceil((double) piles[i] / k);
            }
            if (hours <= h) {
                result = min(result, k);
                high = k - 1;
            } else {
                low = k + 1;
            }
        }
        
        return result;
    }
};


// complexity same hone se time same nhi hoga let's refine
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini = 1, maxi=0, hour=0;
        for(int x:piles){
            hour+=ceil((double)x/mini);
            maxi = max(maxi,x);
        }
        if(hour==h) return mini;
        hour = 0; // ye line chhoda
        for(int x:piles){
            hour+=ceil((double)x/maxi);
        }
        if(hour==h) return maxi;
        int mid, result = maxi;
        
        while(mini<=maxi){
            mid = mini + (maxi-mini)/2;
            hour = 0;
            for(int x:piles){
                hour+=ceil((double)x/mid);
            }
            if(hour==h){
                result = min(result,mid);
                maxi = mid-1;
            }
            else if(hour>h){
                mini = mid+1;
            }
            
            else maxi = mid-1;
        }

        //return (mini + maxi)/2;
        return result;
    }
};


