#include<bits/stdc++.h>
using namespace std;

int getMinimumAnagramDifference(string &str1, string &str2) 
{
	unordered_map<char,int> mp;
	for(int i=0;i<str1.length();i++)
	{
		mp[str1[i]]++;
	}
	// for(auto itr=mp.begin();itr!=mp.end();itr++)
	// {
		// cout<<itr->first<<" "<<itr->second<<endl;
	// }
	for(int i=0;i<str2.length();i++)
	{
		if(mp.find(str2[i])!=mp.end())
		{
			mp[str2[i]]--;
			if(mp[str2[i]]==0)
			{
				mp.erase(str2[i]);
			}
		}
	}
	// for(auto itr=mp.begin();itr!=mp.end();itr++)
	// {
		// cout<<itr->first<<" "<<itr->second<<endl;
	// }
	int ans=0;
	for(auto itr=mp.begin();itr!=mp.end();itr++)
	{
		ans+=itr->second;
	}
	return ans;
}


void solve()
{
	string strone;
	string strtwo;
	cin>>strone>>strtwo;
	int ans=getMinimumAnagramDifference(strone,strtwo);
	cout<<ans<<endl;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
