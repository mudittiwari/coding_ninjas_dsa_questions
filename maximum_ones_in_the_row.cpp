bool condition(int x,int y)
{
	return x<=y;
}

int maxOne(vector<vector<int>> &matrix)
{
	int n=matrix.size();
	int m=matrix[0].size();
	int maxone=INT_MIN;
	int row;
	for(int i=0;i<n;i++)
	{
		auto itr=upper_bound(matrix[i].begin(),matrix[i].end(),1,condition);
		int ind=itr-matrix[i].begin();
		int total=m-ind;
		if(total>maxone)
		{
			maxone=total;
			row=i;
		}
	}
	return row;
}
