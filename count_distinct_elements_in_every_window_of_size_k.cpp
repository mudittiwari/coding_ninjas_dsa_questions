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


vector<int> countDistinctElements(vector<int> &arr, int k) 
{
	int n=arr.size();
	int start=0;
	vector<int> ans;
    unordered_map<int,int> mp;
	int i=0;
	while(i<k)
	{
		mp[arr[i]]++;
		i++;
	}
	ans.push_back(mp.size());
	while(i<n)
	{
		mp[arr[start]]--;
		if(mp[arr[start]]==0)
		{
			mp.erase(arr[start]);
		}
		start++;
		mp[arr[i]]++;
		ans.push_back(mp.size());
		i++;
	}
	return ans;
}

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> arr=scanvector(n);
	vector<int> ans=countDistinctElements(arr,k);
	printvector(ans);
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
