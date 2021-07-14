#include<bits/stdc++.h>
vector<vector<int>> findGoodMatrix(vector<vector<int>> &matrix) 
{
	vector<vector<int>> ans;
	int n=matrix.size();
	int m=matrix[0].size();
    unordered_set<int> cols;
	for(int i=0;i<n;i++)
	{
		int j;
		bool flag=false;
		for(j=0;j<m;j++)
		{
			if(matrix[i][j]==0)
			{
				flag=true;
				cols.insert(j);
			}
		}
		if(flag)
		{
			vector<int> temp(m);
			ans.push_back(temp);
		}
		else
		{
			vector<int> temp(m);
			fill(temp.begin(),temp.end(),1);
			ans.push_back(temp);
		}
	}
	for(auto itr=cols.begin();itr!=cols.end();itr++)
	{
		for(int i=0;i<n;i++)
		{
			ans[i][*itr]=0;
		}
	}
	return ans;
}
