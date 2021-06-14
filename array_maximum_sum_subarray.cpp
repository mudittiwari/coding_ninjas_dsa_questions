#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
	long long int sum=0;
	long long int maxsum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+arr[i];
		maxsum=max(sum,maxsum);
		if(sum<0)
		{
			sum=0;
		}
	}
    return maxsum;
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
		long long int ans=maxSubarraySum(arr,n);
		cout<<ans<<endl;
	}
	return 0;
}
