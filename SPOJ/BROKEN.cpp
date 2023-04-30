#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);	cin.tie(NULL);	cout.tie(NULL);
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define mod 1000000007

int main()
{
	fast;
	int ans,pos,k,minn;
	while(1)
	{
    unordered_map<int,pii> mp;
		cin>>k;
		if(!k)
			break;
		string str;
    getline(cin,str);
    getline(cin,str);
		ans=0;
		for(int i=0;i<(int)str.size();i++)
		{
			if((!mp.count(str[i])) && (int)mp.size()==k)
			{
				minn=INF;
        int local_ans=0;
				for(auto it: mp)
        {
             minn=min(minn,it.second.first);
             local_ans+=it.second.second;
        }
				i=minn;
        ans=max(ans,local_ans);
				mp.clear();
			}
			else
      {
            pii p=mp[str[i]];
            mp[str[i]]=pii(i,p.second+1);
       }
      }
      if(!ans)
        ans=(int)str.size();
      cout<<ans<<"\n";   
	}	
	return 0;
}
