#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n, int k) 
{
	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)
	{
		int sum=k-arr[i];
		int start=i+1;
		int end=n-1;
		while(start<end)
		{
			int temp=arr[start]+arr[end];
			if(temp<sum)
			{
				start++;
			}
			else if(temp>sum)
			{
				end--;
			}
			else
			{
				ans.push_back({arr[i],arr[start],arr[end]});
				int temp=arr[start];
				while(start<end && arr[start]==temp)
				{
					start++;
				}
				temp=arr[end];
				while(start<end && arr[end]==temp)
				{
					temp--;
				}
			}
		}
		int temp=arr[i];
		while(arr[i]==temp)
		{
			i++;
		}
		i--;
	}
	return ans;
}

void solve()
{
	int n,k;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>k;
	vector<vector<int>> ans=findTriplets(arr,n,k);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
	}
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
