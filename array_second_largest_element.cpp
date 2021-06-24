#include<bits/stdc++.h>
using namespace std;

int findSecondLargest(int n, vector<int> &arr)
{
	int largest=INT_MIN;
	int secondlargest=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>largest)
		{
			secondlargest=largest;
			largest=arr[i];
		}
		else if(arr[i]>secondlargest && arr[i]<largest)
		{
			secondlargest=arr[i];
		}
	}
	if(secondlargest==INT_MIN)
		return -1;
	// cout<<largest;
	return secondlargest;
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
	int ans=findSecondLargest(n,arr);
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
