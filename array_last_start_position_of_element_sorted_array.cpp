#include<bits/stdc++.h>
using namespace std;

int binarysearchleft(vector<int> arr,int x)
{
	int left=0;
	int right=arr.size()-1;
	int middle;
	int toreturn=-1;
	while(left<=right)
	{
		// cout<<middle;
		middle=(left+right)/2;
		if(arr[middle]==x)
		{
			toreturn=middle;
		}
		if(arr[middle]>=x)
		{
			right=middle-1;
		}
		else
		{
			left=middle+1;
		}
	}
	return toreturn;
}

int binarysearchright(vector<int> arr,int x)
{
	int left=0;
	int right=arr.size()-1;
	int middle;
	int toreturn=-1;
	while(left<=right)
	{
		// cout<<middle;
		middle=(left+right)/2;
		if(arr[middle]==x)
		{
			toreturn=middle;
		}
		if(arr[middle]>x)
		{
			right=middle-1;
		}
		else
		{
			left=middle+1;
		}
	}
	return toreturn;
}


pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
	int left=binarysearchleft(arr,x);
	int right=binarysearchright(arr,x);
	return make_pair(left,right);
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
	int x;
	cin>>x;
	pair<int,int> ans=findFirstLastPosition(arr,n,x);
	cout<<ans.first<<" "<<ans.second<<endl;
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
