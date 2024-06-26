#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int binarySearch(vector<vector<int>>& matrix, int t, int start, int end){
        int n = matrix.size();
        int m = matrix[0].size();
        if(start>end) return -1;
        if(t<matrix[start/m][start%m]) return -1;
        if(t>matrix[end/m][end%m]) return -1;
        
        if(t==matrix[((start+end)/2)/m][((start+end)/2)%m]) return (start+end)/2;
        else if(t>matrix[((start+end)/2)/m][((start+end)/2)%m]) return binarySearch(matrix,t,(start+end)/2 +1,end);
        return binarySearch(matrix,t,end, (start+end)/2-1);
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(binarySearch(matrix, target, 0, matrix.size()*matrix[0].size()-1) == -1) return false;
        else return true;
    }
};
// the above solution is refined below
using namespace std;
class Solution {
public:
    int binarySearch(vector<vector<int>>& matrix, int t, int start, int end){
        int n = matrix.size();
        int m = matrix[0].size();
        if(start>end) return -1;
        if(t<matrix[start/m][start%m]) return -1;
        if(t>matrix[end/m][end%m]) return -1;
        int mid = start + end;
        mid/=2;
        if(t==matrix[mid/m][mid%m]) return mid;
        else if(t>matrix[mid/m][mid%m]) return binarySearch(matrix,t,mid +1,end);
        return binarySearch(matrix,t,start, mid-1); // pehle yha start ke bdle end daala
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(binarySearch(matrix, target, 0, matrix.size()*matrix[0].size()-1) == -1) return false;
        else return true;
    }
};
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearch(vector<vector<int>>& matrix, int t, int start, int end) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (start > end) return -1; // base case: search range is invalid
        int mid = start + (end - start) / 2; // i did not know the reason  now I know
        int midValue = matrix[mid / m][mid % m];
        
        if (t == midValue) return mid;  // target found
        else if (t > midValue) return binarySearch(matrix, t, mid + 1, end); // search right half
        else return binarySearch(matrix, t, start, mid - 1); // search left half
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(binarySearch(matrix, target, 0, matrix.size()*matrix[0].size()-1) == -1) return false;
        else return true;
    }
    
    
}; 

// the best solution would be which does not call any function but does binary search in place using while loops

using namespace std;
class Solution {
public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i=0,j=m*n-1;
        while(i<=j){
            // int mid = i- (i-j)/2; // i did in place of (i+j)/2 so that the index is not getting out of rsnge and then rounded
            // the above line caused errors 
            int mid = i+ (j-i)/2;
            
            // one other change store the value at mid index as the program would not have to access it again
            int midvalue =matrix[mid/n][mid%n] // matrix[mid/m][mid%m]; -- the mistake was dividing by m not n
            if(midvalue == target) return true;
            //if(matrix[mid/m][mid%m] == target) return true;
            else if(midvalue > target) j = mid - 1;
            else i = mid+1; // yha j ko mid ya upar i ko mid krne par jyada useless loop
        }
        return false;
    }
};
