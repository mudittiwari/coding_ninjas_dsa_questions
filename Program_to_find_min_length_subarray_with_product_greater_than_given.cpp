#include<bits/stdc++.h>
using namespace std;

int findans(vector<int> arr,int prod)
{
	int len=INT_MAX;
	int n=arr.size();
	int start=0;
	int product=arr[0];
	for(int i=1;i<n;i++)
	{
		product*=arr[i];
		while(product>=prod && start<=i)
		{
			len=min(len,i-start+1);
			product=product/arr[start];
			start++;
		}
	}
	return len;
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
	int product;
	cin>>product;
	int ans=findans(arr,product);
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
	// cout<<int('k');
	return 0;
}
