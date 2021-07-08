#include<bits/stdc++.h>
using namespace std;


vector<int> scanvector(int n)
{
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	return arr;
}
void printvector(vector<int> arr)
{
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int findMaxFruits(string &str, int n) 
{
	unordered_map<char,int> mp;
	int start=0;
	int maxlen=INT_MIN;
	for(int i=0;i<str.length();i++)
	{
		mp[str[i]]++;
		while(mp.size()>2)
		{
			mp[str[start]]--;
			if(mp[str[start]]==0)
			{
				mp.erase(str[start]);
			}
			start++;
		}
		maxlen=max(maxlen,i-start+1);
	}
	return maxlen;
}

void solve()
{
	int n;
	string str;
	cin>>n>>str;
	cout<<findMaxFruits(str,n)<<endl;
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
