#include<bits/stdc++.h>
using namespace std;
vector<int> scanvector(int);
void printvector(vector<int>);
vector<vector<int>> scanmatrix(int,int);
void printmatrix(vector<vector<int>>);


vector<int> findSubmatrixSum(vector<vector<int>> &matrix, vector<vector<int>> &queries) 
{
	vector<int> ans;
	int q=queries.size();
	int n=matrix.size();
	int m=matrix[0].size();
    vector<vector<int>> prefix_sum(n+1,vector<int>(m+1,0));
	for(int i=1;i<=n;i++)
	{
		int temp=0;
		for(int j=1;j<=m;j++)
		{
			prefix_sum[i][j]=temp+matrix[i-1][j-1]+prefix_sum[i-1][j];
			temp+=matrix[i-1][j-1];
		}
	}
	// printmatrix(prefix_sum);
	for(int i=0;i<q;i++)
	{
		int startn=queries[i][0];
		int startm=queries[i][1];
		int endn=queries[i][2];
		int endm=queries[i][3];
		int temp=prefix_sum[endn+1][endm+1]-prefix_sum[startn][endm+1]-prefix_sum[endn+1][startm]+prefix_sum[startn][startm];
		ans.push_back(temp);
	}
	return ans;
}



void solve()
{
	int n,m,q;
	cin>>n>>m>>q;
	vector<vector<int>> matrix=scanmatrix(n,m);
	vector<vector<int>> queries=scanmatrix(q,4);
	vector<int> ans=findSubmatrixSum(matrix,queries);
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
