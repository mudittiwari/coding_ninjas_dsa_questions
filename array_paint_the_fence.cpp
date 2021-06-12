#include<bits/stdc++.h>
using namespace std;

int paintTheFence(vector<vector<int>>& queries, int n, int q)
{
	vector<int> single_painter(n);
	vector<int> double_painter(n);
	int total;
	vector<int> section_array(n);
	for(int i=0;i<q;i++)
	{
		if((queries[i][1])==n)
		{
			section_array[queries[i][0]-1]+=1;
		}
		else
		{
			section_array[queries[i][0]-1]+=1;
			section_array[queries[i][1]]-=1;
		}
	}
	for(int i=1;i<n;i++)
	{
		section_array[i]=section_array[i]+section_array[i-1];
	}
	// for(int i=0;i<n;i++)
	// {
		// cout<<section_array[i]<<" ";
	// }
	total=n;
	for(int i=0;i<n;i++)
	{
		if(section_array[i]==0)
		{
			total--;
		}
		else if(section_array[i]==1)
		{
			single_painter[i]+=1;
		}
		else if(section_array[i]==2)
		{
			double_painter[i]+=1;
		}
	}
	for(int i=1;i<n;i++)
	{
		single_painter[i]=single_painter[i]+single_painter[i-1];
		double_painter[i]=double_painter[i]+double_painter[i-1];
	}
	// for(int i=0;i<n;i++)
	// {
		// cout<<single_painter[i]<<" ";
	// }
	// cout<<endl;
	// for(int i=0;i<n;i++)
	// {
		// cout<<double_painter[i]<<" ";
	// }
	// cout<<endl;
	int ans=0;
	for(int i=0;i<q;i++)
	{
		for(int j=i+1;j<q;j++)
		{
			// cout<<i<<j<<endl;
			int temp=total;
			if(queries[i][0]==1)
			{
				temp-=single_painter[queries[i][1]-1];
			}
			else
			{
				temp-=single_painter[queries[i][1]-1]-single_painter[queries[i][0]-2];
			}
			if(queries[j][0]==1)
			{
				temp-=single_painter[queries[j][1]-1];
			}
			else
			{
				temp-=single_painter[queries[j][1]-1]-single_painter[queries[j][0]-2];
			}
			int l,r;
			l=max(queries[i][0],queries[j][0]);
			r=min(queries[i][1],queries[j][1]);
			// cout<<queries[i][0]<<" "<<queries[i][1]<<endl;
			// cout<<queries[j][0]<<" "<<queries[j][1]<<endl;
			// cout<<r<<l<<endl;
			if(r>=l)
			{
				if(l==1)
				{
					temp+=single_painter[r-1];
					temp-=double_painter[r-1];
				}
				else
				{
					temp+=single_painter[r-1]-single_painter[l-2];
					temp-=double_painter[r-1]-double_painter[l-2];
				}
			}
			if(temp>ans)
			{
				ans=temp;
			}
		}
	}
	return ans;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int q;
		cin>>q;
		vector<vector<int>> queries;
		for(int i=0;i<q;i++)
		{
			vector<int> query(2);
			cin>>query[0]>>query[1];
			query[0];
			query[1];
			queries.push_back(query);
		}
		int ans=paintTheFence(queries,n,q);
		cout<<ans<<endl;
	}
	return 0;
}
