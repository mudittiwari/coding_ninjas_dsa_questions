#include<bits/stdc++.h>
using namespace std;

bool isPossible(int *arr, int n)
{
    int count=0;
	if(arr[0]>arr[1])
	{
		count=1;
	}
	for(int i=1;i<n-1;i++)
	{
		if(arr[i]>arr[i+1])
		{
			if(count==1)
			{
				return false;
			}
			if(arr[i-1]>arr[i+1])
			{
				arr[i+1]=arr[i];
				count++;
			}
			else
			{
				arr[i]=arr[i-1];
				count++;
			}
		}
	}
	return true;
}

void solve()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	bool ans=isPossible(arr,n);
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
