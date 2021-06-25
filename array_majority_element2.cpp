#include<bits/stdc++.h>
using namespace std;


vector<int> majorityElementII(vector<int> &arr)
{
	vector<int> ans;
	int firstelement=0;
	int secondelement=0;
	int firstcount=0;
	int secondcount=0;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]==firstelement)
		{
			firstcount++;
		}
		else if(arr[i]==secondelement)
		{
			secondcount++;
		}
		else if(firstcount==0)
		{
			firstelement=arr[i];
			firstcount=1;
		}
		else if(secondcount==0)
		{
			secondelement=arr[i];
			secondcount=1;
		}
		else
		{
			firstcount--;
			secondcount--;
		}
	}
	firstcount=0;
	secondcount=0;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i]==firstelement)
		{
			firstcount++;
		}
		else if(arr[i]==secondelement)
		{
			secondcount++;
		}
	}
	if(firstcount>(arr.size()/3))
	{
		ans.push_back(firstelement);
	}
	if(secondcount>(arr.size()/3))
	{
		ans.push_back(secondelement);
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
	vector<int> ans=majorityElementII(arr);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
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
