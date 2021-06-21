#include<bits/stdc++.h>
using namespace std;

bool answer(int x,int y)
{
	return x<=y;
}

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
	vector<vector<int>> ans;
	sort(arr.begin(),arr.end());
	for(int i=0;i<arr.size();i++)
	{
		int lowerindex=upper_bound(arr.begin()+i+1,arr.end(),s-arr[i],answer)-arr.begin();
		int upperindex=upper_bound(arr.begin()+i+1,arr.end(),s-arr[i])-arr.begin();
		// cout<<lowerindex<<" "<<upperindex<<endl;
		int elements=upperindex-lowerindex;
		// cout<<elements<<endl;
		for(int j=0;j<elements;j++)
		{
			ans.push_back({arr[i],s-arr[i]});
		}
	}
	return ans;
}

void solve()
{
	int n,x;
	cin>>n>>x;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	vector<vector<int>> ans=pairSum(arr,x);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
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
