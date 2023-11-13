#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

#define N 3

int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};

vector<vector<int>>path;
map<vector<int>,vector<int>>parent;
vector<int>root;



void printState(int state[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<state[i][j]<<' ';
		}cout<<endl;
	}
	cout<<endl;
}

void printvec(vector<int>v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<' ';
		if((i+1)%N==0) cout<<endl;
	}
}


int calculatecost(int state[N][N],int final[N][N])
{
	int count = 0;
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			if(state[i][j]&&state[i][j]!=final[i][j])
				count++;
		}
	}
	return count;
}

void solve(int initial[N][N],int blankx,int blanky,int final[N][N])
{
	priority_queue<pair<int, vector<int>>,vector<pair<int, vector<int>>>,greater<pair<int, vector<int>>>>pq;
	set<vector<int>>vis;
	vector<int>v1d;
	for(int i=0;i<N;i++) 
		for(int j=0;j<N;j++) 
			v1d.push_back(initial[i][j]);
	int cost = calculatecost(initial,final);
	pq.push({cost,v1d});

	while (!pq.empty())
	{
		vector<int>state1d = pq.top().second; 
		int curcost = pq.top().first;
		pq.pop();

		int state2d[N][N]; 
		for(int i=0;i<N*N;i++)
			state2d[i/N][i%N]=state1d[i];
		if(vis.count(state1d)) continue;
		vis.insert(state1d);
		if(curcost==0)
		{
			int cntt=0; 
			while(state1d!=root)
			{
				cntt++;
				path.push_back(state1d);
				state1d=parent[state1d];
			}path.push_back(root);
			reverse(path.begin(),path.end());
			cout<<"total stape needed "<<path.size()-1<<endl;
			for(int i=0;i<path.size();i++)
			{
				printvec(path[i]); 
				cout<<endl;
			}
			cout<<"Reached the goal \n";
			return;
		}
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				if(!state2d[i][j]) blankx=i,blanky=j; 
		for(int i=0;i<4;i++)
		{
			int x=blankx+dx[i];
			int y=blanky+dy[i];
			if(x>=0&&x<N&&y>=0&&y<N)
			{
				swap(state2d[x][y],state2d[blankx][blanky]);
				int curcost2=calculatecost(state2d,final);
				vector<int>child;
				for(int i=0;i<N*N;i++)
					child.push_back(state2d[i/N][i%N]);

				pq.push({curcost2,child});
				if(parent.find(child)==parent.end())
					parent[child]=state1d;
				swap(state2d[x][y],state2d[blankx][blanky]);
			}
		}

	}
	cout<<"No solution found\n";
}

int main()
{

 	int inital[N][N]={
 		{4, 3, 7},
        {6, 8, 5},
        {2, 1, 0}
    };
    for(int i=0;i<N*N;i++) root.push_back(inital[i/N][i%N]);
    int final[N][N]={
    	{0, 1, 2},
        {3, 4, 5},
        {6, 7, 8}
    };
 	
 	solve(inital,2,2,final);

	return 0;
}
