#include <bits/stdc++.h>
using namespace std;

#define N 8
#define total 100
int boardassign;


void print(vector<int>& board)
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(board[i]==j)
				cout<<"Q";
			else cout<<".";
		}cout<<endl;
	}
}

int calconflict(vector<int>& board)
{
	int cnt=0;
	for(int i=0;i<N;i++)
	{
		for(int j=i+1;j<N;j++)
		{
			if(board[i]==board[j]||abs(i-j)==abs(board[i]-board[j]))
				cnt++;
		}
	}
	return cnt;
}

void queen()
{
	srand(time(nullptr));

	vector<int>board(N),temp(N);
	for(int i=0;i<N;i++)
		board[i]=rand()%N; 
	int conflicts = calconflict(board); 
	while(conflicts>0&&boardassign<total)
	{
		int curconflicts=conflicts;
		vector<vector<int>>states;
		for(int i=0;i<N;i++)
		{
			temp=board;
			for(int j=0;j<N;j++)
			{
				temp[i]=j;
				int tempconflict=calconflict(temp);
				if(tempconflict<curconflicts)
				{
					curconflicts=tempconflict;
					states.clear();
					states.push_back(temp);
				}
				else if(tempconflict==curconflicts)
					states.push_back(temp);
			}
		}
		if(curconflicts==conflicts)
		{
			boardassign++;
			for(int i=0;i<N;i++)
				board[i]=rand()%N; 
			conflicts=calconflict(board);
		}
		else
		{
			int randindex=rand()%states.size();
			board=states[randindex];
			conflicts=curconflicts;
		}
	}
	if(conflicts==0)
	{
		print(board);
		return;
	}
	cout<<"No solution found\n";
}


int main()
{
	queen();
	return 0;
}
