#include<bits/stdc++.h>
using namespace std;
vector<int> scanvector(int);
void printvector(vector<int>);
vector<vector<int>> scanmatrix(int,int);
void printmatrix(vector<vector<int>>);


vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 
{
	vector<int> ans;
	int startrow=0;
	int startcol=0;
	int endrow=n-1;
	int endcol=m-1;
	while(true)
	{
		if(startrow<=endrow && startcol<=endcol)
		{
			for(int i=startcol;i<=endcol;i++)
			{
				ans.push_back(matrix[startrow][i]);
			}
			startrow++;
		}
		else
		{
			break;
		}
		if(startrow<=endrow && startcol<=endcol)
		{
			for(int i=startrow;i<=endrow;i++)
			{
				ans.push_back(matrix[i][endcol]);
			}
			endcol--;
		}
		else
		{
			break;
		}
		if(startrow<=endrow && startcol<=endcol)
		{
			for(int i=endcol;i>=startcol;i--)
			{
				ans.push_back(matrix[endrow][i]);
			}
			endrow--;
		}
		else
		{
			break;
		}
		if(startrow<=endrow && startcol<=endcol)
		{
			for(int i=endrow;i>=startrow;i--)
			{
				ans.push_back(matrix[i][startcol]);
			}
			startcol++;
		}
		else
		{
			break;
		}
	}
	return ans;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> matrix=scanmatrix(n,m);
	vector<int> ans=spiralPathMatrix(matrix,n,m);
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
