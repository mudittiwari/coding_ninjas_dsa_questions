#include<bits/stdc++.h>
using namespace std;

vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k)
{
	if(k==1)
	{
		return {0,0};
	}
	int finalstart=-1;
	int finalend=-1;
	int len=INT_MAX;
	vector<int> ans;
	int n=arr.size();
	int start=0;
	int end=0;
	unordered_map<int,int> mp;
	// mp[arr[0]]++;
	for(int i=0;i<n;i++)
	{
		mp[arr[i]]++;
		end=i;
		while(start<end && mp.size()>k)
		{
			mp[arr[start]]--;
			if(mp[arr[start]]==0)
			{
				mp.erase(arr[start]);
			}
			start++;
		}
		if(mp.size()==k)
		{
			while(start<end && mp[arr[start]]!=1)
			{
				mp[arr[start]]--;
				start++;
			}
			int temp=end-start+1;
			if(temp<len)
			{
				len=temp;
				finalstart=start;
				finalend=end;
			}
		}
	}
	if(finalstart==-1)
	{
		return {-1};
	}
	return {finalstart,finalend};
}

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	vector<int> ans=smallestSubarrayWithKDistinct(arr,k);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
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
