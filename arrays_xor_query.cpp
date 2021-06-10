#include<bits/stdc++.h>
using namespace std;


vector<int> xorQuery(vector<vector<int>> &queries)
{
	vector<int> temp(queries.size());
	vector<int> ans;
	for(int i=0;i<queries.size();i++)
	{
		if(queries[i][0]==1)
		{
			ans.push_back(queries[i][1]);
		}
		else
		{
			temp[0]=temp[0]^queries[i][1];
			temp[ans.size()]=temp[ans.size()]^queries[i][1];
		}
	}
	for(int i=1;i<temp.size();i++)
	{
		temp[i]=temp[i]^temp[i-1];
	}
	for(int i=0;i<ans.size();i++)
	{
		ans[i]=ans[i]^temp[i];
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int q;
		cin>>q;
		vector<vector<int>> queries;
		for(int i=0;i<q;i++)
		{
			vector<int> temp(2);
			cin>>temp[0]>>temp[1];
			queries.push_back(temp);
		}
		vector<int> ans=xorQuery(queries);
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
