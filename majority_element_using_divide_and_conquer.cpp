#include<bits/stdc++.h>
using namespace std;
vector<int> scanvector(int);
void printvector(vector<int>);
vector<vector<int>> scanmatrix(int,int);
void printmatrix(vector<vector<int>>);


pair<int,int> findans(vector<int> arr)
{
	if(arr.size()==1)
	{
		return make_pair(arr[0],1);
	}
	vector<int> arrone(arr.begin(),arr.begin()+arr.size()/2);
	vector<int> arrtwo(arr.begin()+arr.size()/2,arr.end());
	pair<int,int> pone=findans(arrone);
	pair<int,int> ptwo=findans(arrtwo);
	for(int i=0;i<arrtwo.size();i++)
	{
		if(pone.first==arrtwo[i])
		{
			pone.second++;
		}
	}
	for(int i=0;i<arrone.size();i++)
	{
		if(ptwo.first==arrone[i])
		{
			ptwo.second++;
		}
	}
	if(pone.second>ptwo.second)
	{
		return pone;
	}
	return ptwo;
}



void solve()
{
	int n;
	cin>>n;
	vector<int> arr=scanvector(n);
	pair<int,int> ans=findans(arr);
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
