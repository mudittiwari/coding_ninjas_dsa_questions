#include<bits/stdc++.h>
using namespace std;

char findNonRepeating(string str) 
{
	vector<pair<int,int>> arr(26);
	for(int i=0;i<str.length();i++)
	{
		// arr[str[i]-97]++;
		arr[str[i]-97]=make_pair(arr[str[i]-97].first+1,i);
	}
	// sort(arr.begin(),arr.end());
	// for(int i=0;i<26;i++)
	// {
		// cout<<arr[i].first<<" "<<arr[i].second<<endl;
	// }
	// cout<<endl;
	char ans='#';
	int index=INT_MAX;
	for(int i=0;i<26;i++)
	{
		if(arr[i].first==1)
		{
			if(arr[i].second<index)
			{
				index=arr[i].second;
				ans=i+97;
			}
		}
	}
	return ans;
}

void solve()
{
	string s;
	cin>>s;
	char ans=findNonRepeating(s);
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
