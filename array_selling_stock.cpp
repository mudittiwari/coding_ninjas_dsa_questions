#include<bits/stdc++.h>
using namespace std;


long getMaximumProfit(long *arr, int n)
{
    long profit=0;
	long buying_price=arr[0];
	long selling_price=arr[0];
	for(int i=1;i<n;i++)
	{
		if(arr[i]>=selling_price)
		{
			selling_price=arr[i];
		}
		else
		{
			profit+=selling_price-buying_price;
			buying_price=selling_price=arr[i];
		}
	}
	profit+=selling_price-buying_price;
	return profit;
}
void solve()
{
	int n;
	cin>>n;
	long arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	long ans=getMaximumProfit(arr,n);
	cout<<ans<<endl;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	// long long int product=100000000;
	// product=product*200;
	// cout<<product;
	return 0;
}
