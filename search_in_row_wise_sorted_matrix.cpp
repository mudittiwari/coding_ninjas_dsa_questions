#include<bits/stdc++.h>
using namespace std;
vector<int> scanvector(int);
void printvector(vector<int>);
vector<vector<int>> scanmatrix(int,int);
void printmatrix(vector<vector<int>>);


bool findnum(int x,int y)
{
	return x<=y;
}

pair<int, int> search(vector<vector<int>> matrix, int x)
{
	int n=matrix.size();
    for(int i=0;i<n;i++)
	{
		if(matrix[i][0]>x)
		{
			return make_pair(-1,-1);
		}
		auto itr=upper_bound(matrix[i].begin(),matrix[i].end(),x,findnum);
		if(*itr==x)
		{
			return make_pair(i,itr-matrix[i].begin());
		}
	}
	return make_pair(-1,-1);
}


void solve()
{
	int n,x;
	cin>>n>>x;
	vector<vector<int>> matrix=scanmatrix(n,n);
	pair<int,int> ans=search(matrix,x);
	cout<<ans.first<<" "<<ans.second<<endl;
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
