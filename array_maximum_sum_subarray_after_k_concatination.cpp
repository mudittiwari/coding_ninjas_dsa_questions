#include<bits/stdc++.h>
using namespace std;


long long maxSubSumKConcat(vector<int> &arr, int n, int k)
{
	if(k==1)
	{
		long long ans=INT_MIN;
		long long temp=0;
		for(int i=0;i<n;i++)
		{
			temp+=arr[i];
			ans=max(temp,ans);
			if(temp<0)
			{
				temp=0;
			}
		}
		return ans;
	}
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
	}
	vector<int> arrtwo;
	arrtwo.insert(arrtwo.end(),arr.begin(),arr.end());
	arrtwo.insert(arrtwo.end(),arr.begin(),arr.end());
	long long ans=INT_MIN;
	long long temp=0;
	for(int i=0;i<arrtwo.size();i++)
	{
		temp+=arrtwo[i];
		ans=max(ans,temp);
		if(temp<0)
		{
			temp=0;
		}
	}
	if(sum<=0)
	{
		return ans;
	}
	ans+=(k-2)*sum;
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}
		long long ans=maxSubSumKConcat(arr,n,k);
		cout<<ans<<endl;
	}
	return 0;
}
