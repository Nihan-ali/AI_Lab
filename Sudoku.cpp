#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 9


void print(int board[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<board[i][j]<<' ';
		}cout<<endl;
	}
}

bool safe(int board[N][N],int row,int col,int val)
{
	for(int i=0;i<N;i++)
	{
		if(board[row][i]==val||board[i][col]==val) {
			//cout<<"row or col "<<row<<col<<val<<endl;
			return false;
		}
	}
	int startrow=row-row%3,startcol=col-col%3; 
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(board[startrow+i][startcol+j]==val)
				return false;
		}
	}
	return true;
}

bool solve(int board[N][N],int row,int col)
{
	if(row==N-1&&col==N) return true;
	if(col==N)
	{
		row++;
		col=0; 
	}
	if(board[row][col])
		return solve(board,row,col+1);
	for(int i=1;i<=N;i++)
	{
		if(safe(board,row,col,i))
		{
			board[row][col]=i; 
			if(solve(board,row,col+1)) return true;
			board[row][col]=0;
		}
	}
	return false;
}


int main()
{
	int board[N][N]={
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
	};

	if(solve(board,0,0))
	{
		cout<<"Solved Solution \n";
		print(board);
	}
	else
		cout<<"No solution found\n";

	return 0;
}
