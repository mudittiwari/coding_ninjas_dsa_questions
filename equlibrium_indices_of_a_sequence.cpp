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


vector<int> findEquilibriumIndices(vector<int> &arr) 
{
	int n=arr.size();
	vector<int> ans;
    vector<long long> prefix_sum(arr.size());
	prefix_sum[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		prefix_sum[i]=prefix_sum[i-1]+arr[i];
	}
	for(int i=1;i<n-1;i++)
	{
		if(prefix_sum[i-1]==(prefix_sum[n-1]-prefix_sum[i]))
		{
			ans.push_back(i);
		}
	}
	if(prefix_sum[n-1]-prefix_sum[0]==0)
	{
		ans.insert(ans.begin(),0);
	}
	if(prefix_sum[n-2]==0)
	{
		ans.push_back(n-1);
	}
	return ans;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr=scanvector(n);
	vector<int> ans=findEquilibriumIndices(arr);
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
