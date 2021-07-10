#include<bits/stdc++.h>
using namespace std;
vector<int> scanvector(int);
void printvector(vector<int>);
vector<vector<int>> scanmatrix(int,int);
void printmatrix(vector<vector<int>>);


vector<int> rotateMatRight(vector<vector<int>> matrix, int n, int m, int k) 
{
	vector<int> ans;
	vector<vector<int>> cols;
	k=k%m;
	for(int i=0,j=(m-k)%m;i<m;i++)
	{
		// cout<<"mudtitiwr";
		// printmatrix(cols);
		vector<int> temp;
		for(int k=0;k<n;k++)
		{
			temp.push_back(matrix[k][j]);
		}
		cols.push_back(temp);
		j++;
		if(j==m)
		{
			j=0;
		}
	}
	// printmatrix(cols);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			ans.push_back(cols[j][i]);
		}
	}
	return ans;
}
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<vector<int>> matrix=scanmatrix(n,m);
	vector<int> ans=rotateMatRight(matrix,n,m,k);
	printvector(ans);
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
