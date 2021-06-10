#include<bits/stdc++.h>
using namespace std;

long long int mod=1000000007;

int * getProductArrayExceptSelf(int *arr, int n)
{
	if(n==0)
	return arr;
	long long int mod=1000000007;
	int *ans;
	ans=new int[n];
	long long int product=1;
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			count++;
		}
		else
		{
			product=(product*arr[i])%mod;
		}
	}
	if(count>1)
	{
		for(int i=0;i<n;i++)
		{
			ans[i]=0;
		}
	}
	else if(count==1)
	{
		// cout<<product<<endl;
		for(int i=0;i<n;i++)
		{
			if(arr[i]==0)
			{
				ans[i]=product;
			}
			else
			{
				ans[i]=0;
			}
		}
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			if(arr[i]==0)
			{
				ans[i]=0;
			}
			else
			{
				ans[i]=product/arr[i];
			}
		}
	}
	return ans;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int *ans=getProductArrayExceptSelf(arr,n);
		// cout<<"Mudittiwari"<<endl;
		for(int i=0;i<n;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
