#include<bits/stdc++.h>
using namespace std;


vector<int> scanvector(int n)
{
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	return arr;
}
void printvector(vector<int> arr)
{
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}



int switchingSubarray(vector<int> &arr, int n) 
{
	if(n==1)
		return 1;
	int maxlen=INT_MIN;
	int start=0;
	int len=2;
	int i=2;
	while(i<(n-1))
	{
		if(arr[i]==arr[start] && arr[i+1]==arr[start+1])
		{
			len+=2;
			i+=2;
			// cout<<len<<endl;
		}
		else
		{
			if(arr[i]==arr[start])
			{
				len++;
			}
			start=i-1;
			i+=1;
			maxlen=max(len,maxlen);
			len=2;
		}
	}
	if(arr[i]==arr[start])
	{
		len++;
	}
	maxlen=max(len,maxlen);
	return maxlen;
}

void solve()
{
	int n;
	cin>>n;
	vector<int> arr=scanvector(n);
	int ans=switchingSubarray(arr,n);
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
	return 0;
}
