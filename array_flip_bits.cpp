#include<bits/stdc++.h>
using namespace std;

// max_difference=0;
// difference=0;
int flipBits(int* arr, int n) 
{
    int difference=0;
	int max_difference=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			difference++;
		}
		else
		{
			difference--;
		}
		max_difference=max(difference,max_difference);
		if(difference<0)
		{
			difference=0;
		}
	}
	return max_difference;
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
		int ans=flipBits(arr,n);
		for(int i=0;i<n;i++)
		{
			if(arr[i]==1)
			{
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
