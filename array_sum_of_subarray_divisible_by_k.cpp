#include<bits/stdc++.h>
using namespace std;


int subArrayCount(vector<long long int> &arr, int k) 
{
	int ans=0;
	vector<int> rem_frequency(k);
	int sum=0;
	rem_frequency[0]=1;
	for(int i=0;i<arr.size();i++)
	{
		sum+=arr[i];
		ans+=rem_frequency[sum%k];
		rem_frequency[sum%k]++;
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
		int k;
		cin>>k;
		vector<long long int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		int ans=subArrayCount(arr,k);
		cout<<ans<<endl;
	}
	return 0;
}
