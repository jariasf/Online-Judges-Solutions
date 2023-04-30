#include<bits/stdc++.h>
using namespace std;
#define n 33130
#define INF 9999999
int r,c;
vector<pair<int,int>> v;

void BITMAP()
{
    int dist[r+5][c+5];
    for(int i=0;i<r+5;i++)
        for(int j=0;j<c+5;j++)
            dist[i][j]=INF;
	for(auto it: v)
	{
		queue<pair<int,int>> q;
		q.push(it);
		dist[it.first][it.second]=0;
		while(!q.empty())
		{
			pair<int,int> p=q.front();
			q.pop();
			int x=p.first;
			int y=p.second;
			if(x>=2)
			{
				if(dist[x-1][y]>1+dist[x][y])
				{
					q.push(make_pair(x-1,y));
					dist[x-1][y]=1+dist[x][y];
				}
			}
			if(x<=r-1)
			{
				if(dist[x+1][y]>1+dist[x][y])
				{
					q.push(make_pair(x+1,y));
					dist[x+1][y]=1+dist[x][y];
				}
			}
			if(y>=2)
			{
				if(dist[x][y-1]>1+dist[x][y])
				{
					q.push(make_pair(x,y-1));
					dist[x][y-1]=1+dist[x][y];
				}
			}
			if(y<=c-1)
			{
				if(dist[x][y+1]>1+dist[x][y])
				{
					q.push(make_pair(x,y+1));
					dist[x][y+1]=1+dist[x][y];
				}
			}
		}
	}
	for(int i=1;i<=r;i++)
	{
		for(int j=1;j<=c;j++)
		{
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,x;
	char str[190];
	cin>>t;
	while(t--)
	{
		v.clear();
		cin>>r>>c;
		for(int i=1;i<=r;i++)
		{
		    cin>>str;
		    for(int j=1;j<=c;j++)
		        if(str[j-1]=='1')
		            v.push_back(pair<int,int>(i,j));
		}
		BITMAP();
	}
	return 0;
}
