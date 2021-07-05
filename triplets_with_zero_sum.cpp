#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int>arr, int n) 
{
	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++)
	{
		int sum=-arr[i];
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
				int elemone=arr[start];
				int elemtwo=arr[end];
				ans.push_back({arr[i],arr[start],arr[end]});
				while(start<end && arr[start]==elemone)
				{
					start++;
				}
				while(start<end && arr[end]==elemtwo)
				{
					end--;
				}
			}
		}
		// while(i<(n-1) && arr[i]!=arr[i+1])
		// {
			// i++;
		// }
		int tosearch=arr[i];
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]==tosearch)
			{
				i++;
				continue;
			}
			break;
		}
	}
	return ans;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	vector<vector<int>> ans=findTriplets(arr,n);
	if(ans.size()==0)
	{
		cout<<"-1"<<endl;
	}
	else
	{
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
		}
		// cout<<endl;
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
	// unordered_map<int,unordered_set<int>> mp;
	// mp[1].insert(2);
	// cout<<*mp[1].begin();
	return 0;
}
