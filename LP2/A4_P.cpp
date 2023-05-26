#include <bits/stdc++.h>
using namespace std;

bool isSafePos(vector<vector<int>> &board, int row, int col, int n){
    //check row
    for(int i=0; i< col; i++){
        if(board[row][i]==1) return false;
    }
    for(int i=row,  j=col; i>=0 && j>=0; i--, j-- ){
        if(board[i][j]==1) return false;
    }
    for(int i=row,  j=col; i<n && j>=0; i++, j-- ){
        if(board[i][j]==1) return false;
    }
    return true;
}

bool solveQueenUtil(vector<vector<int>> &board, int col, int n){
    if(col==n){
        return true;
    }
    for(int row=0; row<n; row++){
        if(isSafePos(board, row, col, n)){
            board[row][col]=1;
            if(solveQueenUtil(board, col+1, n)){
                return true;
            }
            board[row][col]=0;
        }
        
    }
    return false;
}

void solve(int n){
    vector<vector<int>>board(n, vector<int>(n, 0));
    if(solveQueenUtil(board, 0 ,n)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
    }else {
        cout<<"No Soln!!";
    }

}

int main(){
    int n;
    // cout<<"Enter the Number : ";
    cin>>n;
    solve(n);
    return 0;
}