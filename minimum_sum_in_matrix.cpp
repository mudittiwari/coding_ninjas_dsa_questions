#include<bits/stdc++.h>
using namespace std;
vector<int> scanvector(int);
void printvector(vector<int>);
vector<vector<int>> scanmatrix(int,int);
void printmatrix(vector<vector<int>>);



int minSum(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	for(int i=1;i<n;i++)
	{
		matrix[i][0]=min(matrix[i-1][1]+matrix[i][0],matrix[i-1][2]+matrix[i][0]);
		matrix[i][1]=min(matrix[i-1][0]+matrix[i][1],matrix[i-1][2]+matrix[i][1]);
		matrix[i][2]=min(matrix[i-1][0]+matrix[i][2],matrix[i-1][1]+matrix[i][2]);
	}
	return min(matrix[n-1][0],min(matrix[n-1][1],matrix[n-1][2]));
}

void solve()
{
	int n;
	cin>>n;
	vector<vector<int>> matrix=scanmatrix(n,3);
	cout<<minSum(matrix)<<endl;
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
