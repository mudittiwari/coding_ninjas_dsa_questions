#include<bits/stdc++.h>
using namespace std;
vector<int> scanvector(int);
void printvector(vector<int>);
vector<vector<int>> scanmatrix(int,int);
void printmatrix(vector<vector<int>>);


vector<int> ans;

void findansone(int n,int k)
{
	if(n<=0)
	{
		return ;
	}
	ans.push_back(n-k);
	findansone(n-k,k);
	return ;
	
}
void findanstwo(int n,int k)
{
	if(n==*ans.begin())
	{
		return ;
	}
	ans.push_back(n+k);
	findanstwo(n+k,k);
}

vector<int> printSeries(int n, int k)
{
	ans.clear();
    ans.push_back(n);
	findansone(n,k);
	findanstwo(*ans.rbegin(),k);
	return ans;
}


void solve()
{
	long long int k;
	int n;
	cin>>n;
	cin>>k;
	vector<int> ans=printSeries(n,k);
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
