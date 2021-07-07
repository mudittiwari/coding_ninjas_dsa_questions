#include<bits/stdc++.h>
using namespace std;

vector<int> findans(vector<int> arr,int sum)
{
	int temp=arr[0];
	int start=0;
	int end=0;
	for(int i=1;i<arr.size();i++)
	{
		// cout<<temp<<endl;
		while(start<=end && temp>sum)
		{
			// cout<<"mudtitiwar";
			temp-=arr[start];
			start++;
		}
		if(temp==sum)
		{
			cout<<start<<" "<<end;
			return {};
		}
		temp+=arr[i];
		end=i;
	}
	if(temp==sum)
	{
		cout<<start<<" "<<end;
		return {};
	}
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
	int target;
	cin>>target;
	vector<int> ans=findans(arr,target);
	// for(int i=0;i<ans.size();i++)
	// {
	// cout<<ans[i]<<" ";
	// }
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
