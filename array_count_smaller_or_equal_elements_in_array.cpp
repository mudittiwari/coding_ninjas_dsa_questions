#include<bits/stdc++.h>
using namespace std;


int binarysearchright(int * arr,int x,int m)
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
		return toreturn;
	}
	return right;
}


vector < int > countSmallerOrEqual(int * a, int * b, int n, int m) 
{
	vector<int> ans;
	sort(&b[0],&b[m]);
	for(int i=0;i<n;i++)
	{
		int temp=binarysearchright(b,a[i],m);
		ans.push_back(temp+1);
	}
	return ans;
}


void solve()
{
	int n,m;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>m;
	int *b=new int[m];
	for(int i=0;i<m;i++)
	{
		cin>>b[i];
	}
	vector<int> ans=countSmallerOrEqual(a,b,n,m);
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
	// int arr[]={3,4};
	// int ans=binarysearchright(arr,5,2);
	// cout<<ans;
	return 0;
}
