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


bool checkDuplicate(vector<int> &arr, int n, int k) 
{
	unordered_map<int,int> mp;
	int windowsize;
	if(k>=n)
	{
		windowsize=n;
	}
	else
	{
		windowsize=k+1;
	}
	int start=0;
	int i;
	for(i=0;i<windowsize;i++)
	{
		mp[arr[i]]++;
	}
	if(mp.size()!=windowsize)
	{
		return true;
	}
	for(int j=i;j<n;j++)
	{
		mp[arr[start]]--;
		if(mp[arr[start]]==0)
		{
			mp.erase(arr[start]);
		}
		start++;
		mp[arr[j]]++;
		if(mp.size()!=windowsize)
		{
			return true;
		}
	}
	return false;
	
}



void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> arr=scanvector(n);
	bool ans=checkDuplicate(arr,n,k);
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
