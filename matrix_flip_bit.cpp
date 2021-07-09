#include<bits/stdc++.h>
using namespace std;
vector<int> scanvector(int);
void printvector(vector<int>);
vector<vector<int>> scanmatrix(int,int);
void printmatrix(vector<vector<int>>);


int countFlip(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int rows=0;
	int total=0;
	for(int i=0;i<n;i++)
	{
		int temp=0;
		for(int j=0;j<n;j++)
		{
			if(matrix[i][j]==1)
			{
				temp++;
			}
		}
		if(temp==n)
		{
			rows++;
		}
		else
		{
			total+=temp;
		}
	}
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<n;i++)
		{
			if(matrix[i][j]==0)
			{
				total+=rows;
				break;
			}
		}
	}
	return total;
}


void solve()
{
	int n;
	cin>>n;
	vector<vector<int>> matrix=scanmatrix(n,n);
	cout<<countFlip(matrix)<<endl;
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
