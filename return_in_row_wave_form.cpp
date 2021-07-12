vector<int> rowWaveForm(vector<vector<int>> &matrix) 
{
	vector<int> ans;
	int n=matrix.size();
	int m=matrix[0].size();
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			ans.insert(ans.end(),matrix[i].begin(),matrix[i].end());
		}
		else
		{
			vector<int> temp=matrix[i];
			reverse(temp.begin(),temp.end());
			ans.insert(ans.end(),temp.begin(),temp.end());
		}
	}
	return ans;
}
