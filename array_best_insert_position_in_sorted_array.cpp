#include<bits/stdc++.h>
using namespace std;


int binarysearchright(vector<int> arr,int x,int m)
{
	int left=0;
	int right=m-1;
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
	if(toreturn!=-1)
	{
		return toreturn-1;
	}
	return right;
}


int bestInsertPos(vector<int> arr, int n, int m)
{
    int ans=binarysearchright(arr,m,n);
	return ans+1;
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
	int ans=bestInsertPos(arr,n,x);
	cout<<ans;
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
	// int arr[]={3,4};
	// int ans=binarysearchright(arr,5,2);
	// cout<<ans;
	return 0;
}
