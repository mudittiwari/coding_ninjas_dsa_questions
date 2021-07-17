#include<bits/stdc++.h>
using namespace std;
vector<int> scanvector(int);
void printvector(vector<int>);
vector<vector<int>> scanmatrix(int,int);
void printmatrix(vector<vector<int>>);


vector<vector<int>> subsets;

void findans(vector<int> arr,int n,int index,vector<int> temp,int sum,int k)
{
	if(index==n)
	{
		// cout<<sum<<endl;
		if(sum==k)
		{	
			subsets.push_back(temp);
		}
		// printvector(temp);
		return ;
	}
	temp.push_back(arr[index]);
	findans(arr,n,index+1,temp,sum+arr[index],k);
	temp.pop_back();
	// printvector(temp);
	findans(arr,n,index+1,temp,sum,k);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
	subsets.clear();
    findans(arr,n,0,{},0,k);
	return subsets;
}



void solve()
{
	int k;
	int n;
	cin>>n;
	vector<int> arr=scanvector(n);
	cin>>k;
	vector<vector<int>> ans=findSubsetsThatSumToK(arr,n,k);
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
		{
			cout<<ans[i][j]<<" ";
		}
		cout<<endl;
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

vector<vector<int>> scanmatrix(int n,int m)
{
	vector<vector<int>> matrix;
	for(int i=0;i<n;i++)
	{
		vector<int> temp;
		for(int j=0;j<m;j++)
		{
			int a;
			cin>>a;
			temp.push_back(a);
		}
		matrix.push_back(temp);
	}
	return matrix;
}

void printmatrix(vector<vector<int>> matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
}
