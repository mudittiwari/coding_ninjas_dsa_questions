#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& arr) 
{
	int ans=INT_MIN;
	int start=0;
	int end=arr.size()-1;
	int width;
	while(start<end)
	{
		// cout<<start<<" "<<end<<endl;
		int area=(end-start)*min(arr[start],arr[end]);
		ans=max(ans,area);
		if(arr[start]<arr[end])
		{
			int elem=arr[start];
			while(start<end && arr[start]==elem)
			{
				start++;
			}
		}
		else if(arr[start]>arr[end])
		{
			int elem=arr[end];
			while(start<end && arr[end]==elem)
			{
				end--;
			}
		}
		else
		{
			int elem=arr[start];
			while(start<end && arr[start]==elem)
			{
				start++;
			}
			elem=arr[end];
			while(start<end && arr[end]==elem)
			{
				end--;
			}
		}
	}
	return ans;
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
	cout<<maxArea(arr)<<endl;
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
