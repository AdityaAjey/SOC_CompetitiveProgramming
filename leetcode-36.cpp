#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(vector<int> &groupofnine){
       // bitset a[9];
        std::bitset<9> bits(0);
        for(auto x:groupofnine){
            if(x>0){
                if(bits[x-1]==1) return false;
                bits[x-1] = 1;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        // pehle row ko validate
        for(int i=0;i<9;i++){
            vector<int> a(9); // int a[9] se issue tha kyoki function ko vector pass kr rhe
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') a[j]=0;
                else a[j] = board[i][j] - '0';
            }
            if(!isValid(a)){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            vector<int> a(9);
            for(int j=0;j<9;j++){
                if(board[j][i]=='.') a[j]=0;
                else a[j] = board[j][i] - '0';
            }
            if(!isValid(a)){
                return false;
            }
        }
        for(int i=0;i<9;i++){
            vector<int> a(9);
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){ //pehle k++ ki jagah j++
                    if(board[j+3*(i/3)][k+3*(i%3)]=='.') a[j*3+k]=0;
                    else a[j*3+k] = board[j+3*(i/3)][k+3*(i%3)] - '0';
                }
            }
            if(!isValid(a)){
                return false;
            }

        }
        return true;

    }
};