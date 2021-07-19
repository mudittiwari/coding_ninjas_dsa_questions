#include<bits/stdc++.h>
using namespace std;
vector<int> scanvector(int);
void printvector(vector<int>);
vector<vector<int>> scanmatrix(int,int);
void printmatrix(vector<vector<int>>);

vector<string> ans;
void findans(string temp,int i,int j,int n,vector<vector<int>> matrix,vector<vector<int>> arr)
{
	// cout<<i<<j<<endl;
	if(i<0 || j<0 || i==n || j==n)
	{
		return;
	}
	if(matrix[i][j]==0)
	{
		return;
	}
	if(i==(n-1) && j==(n-1))
	{
		ans.push_back(temp);
		return;
	}
	if(arr[i][j]==1)
	{
		return;
	}
	arr[i][j]=1;
	findans(temp+'D',i+1,j,n,matrix,arr);
	findans(temp+'U',i-1,j,n,matrix,arr);
	findans(temp+'L',i,j-1,n,matrix,arr);
	findans(temp+'R',i,j+1,n,matrix,arr);
}


vector<string> findAllPaths( vector<vector<int>> &arr)
{
	if(arr[0][0]==0 || arr[n-1][n-1]==0)
	{
		return {};
	}
	ans.clear();
	vector<vector<int>> temp(arr.size(),vector<int>(arr.size()));
    findans("",0,0,arr.size(),arr,temp);
	return ans;
}



void solve()
{
	int n;
	cin>>n;
	vector<vector<int>> matrix(n,vector<int>(n));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>matrix[i][j];
		}
	}
	vector<string> ans=findAllPaths(matrix);
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
