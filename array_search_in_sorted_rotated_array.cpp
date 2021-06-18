#include<bits/stdc++.h>
using namespace std;

int search(int* arr, int n, int key)
{
    int left=0;
	int right=n-1;
	int middle;
	while(left<=right)
	{
		middle=(left+right)/2;
		if(arr[middle]==key)
		{
			return middle;
		}
		else
		{
			if(arr[left]<=arr[middle])
			{
				// first half is sorted
				if(key>=arr[left] && key<arr[middle])
				{
					right=middle-1;
				}
				else
				{
					left=middle+1;
				}
			}
			else
			{
				if(key<=arr[right] && key>arr[middle])
				{
					left=middle+1;
				}
				else
				{
					right=middle-1;
				}
			}
		}
	}
	return -1;
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
	int queries;
	cin>>queries;
	while(queries--)
	{
		int key;
		cin>>key;
		int ans=search(arr,n,key);
		cout<<ans<<endl;
	}
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
