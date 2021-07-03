#include<bits/stdc++.h>
using namespace std;

int longestMountain(int *arr, int n)
{
    int i=0;
	int ans=0;
	while(i<n-1)
	{
		// cout<<i<<endl;
		if(arr[i]>=arr[i+1])
		{
			i++;
		}
		else
		{
			int start=i;
			int peak=-1;
			int end=-1;
			while(i<(n-1) && arr[i]<arr[i+1])
			{
				i++;
			}
			peak=i;
			while(i<(n-1) && arr[i]>arr[i+1])
			{
				i++;
				end=i;
			}
			if(end!=-1)
			{
				ans=max(ans,end-start+1);
			}
		}
	}
	return ans;
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
	cout<<longestMountain(arr,n)<<endl;
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
