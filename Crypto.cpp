#include <bits/stdc++.h>
using namespace std;

vector<char>letters;
string s1,s2,ans;
int ok,vis[15];
map<char,int>mp;

int value(string s)
{
	int sum=0;
	for(auto x:s)
	{
		sum*=10;
		if(x!='*') sum+=mp[x];
	}
	return sum;
}

void check()
{
	ok = (value(s1)+value(s2))==value(ans);
}

void assignValue(int index)
{
	if(index==letters.size())
	{
		check();
		return;
	}
	for(int i=0;i<10;i++)
	{
		if(vis[i]) continue;
		mp[letters[index]]=i;
		vis[i]=1;
		assignValue(index+1);
		if(ok) return;
		vis[i]=0;
	}
}


int main()
{
	cin>>s1>>s2>>ans;
	string total=s1+s2+ans;
	int mxlength=max({s1.size(),s2.size(),ans.size()});
	while(s1.size()<mxlength) s1='*'+s1;
	while(s2.size()<mxlength) s2='*'+s2;
	while(ans.size()<mxlength) ans='*'+ans;
	set<char>letterset;
	for(auto ch:total) letterset.insert(ch);
	for(auto ch:letterset) letters.push_back(ch);
	
	assignValue(0);
	if(!ok)
	{
        cout << "impossible" << endl;
        return 0;
    }
	for(auto c : s1)if(c != '*') cout << mp[c];else cout << ' '; cout << endl;
    for(auto c : s2)if(c != '*') cout << mp[c];else cout << ' '; cout << endl;
    for(auto c : ans)if(c != '*') cout << mp[c];else cout << ' '; cout << endl;

}
