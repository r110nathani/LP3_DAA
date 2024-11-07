#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row , int col, vector<string> board , int n)
{
    int dupRow = row;
    int dupCol= col;

    while(row>=0 && col>=0)
    {
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    row = dupRow;
    col = dupCol;

    while(col>=0)
    {
        if(board[row][col] == 'Q') return false;
        col--;
    }

    row = dupRow;
    col = dupCol;

    while(row<n && col>=0)
    {
        if(board[row][col] == 'Q') return false;
        row++;
        col--;
    }

    return true;
}


void solve(int col , vector<string> &board , vector<vector<string>> &ans , int n)
{
    if(col == n)
    {
        ans.push_back(board);
        return;
    }

    for(int row = 0 ; row<n ; row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col] = 'Q';
            solve(col+1,board,ans,n);
            board[row][col] = '.';
        }
    }
}

int main()
{
    cout<<"Enter number"<<endl;
    int n ; cin>>n;
    vector<vector<string>> ans;
    vector<string> board(n);
    string temp(n,'.');
    for(int i = 0 ; i<n ; i++)
    {
        board[i] = temp;
    }

    solve(0,board,ans,n);

    for(auto it : ans)
    {
        for(auto j : it)
        {
            for(auto k : j)
            {
                cout<<k<<" ";
            }
            cout<<endl;
        }

        cout<<endl;
    }
}