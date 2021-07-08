vector<int> findAnagramsIndices(string str, string ptr, int n, int m)
{
	vector<int> ans;
	vector<int> temptwo(26);
	int start=0;
	vector<int> temp(26);
	for(int i=0;i<m;i++)
	{
		temp[str[i]-65]++;
		temptwo[ptr[i]-65]++;
	}
	int j;
	for(j=0;j<26;j++)
	{
		if(temptwo[j]!=temp[j])
		{
			break;
		}
	}
	if(j==26)
	{
		ans.push_back(start);
	}
	for(int i=m;i<n;i++)
	{
		temp[str[start]-65]--;
		start++;
		temp[str[i]-65]++;
		// printvector(temp);
		int j;
		for(j=0;j<26;j++)
		{
			if(temptwo[j]!=temp[j])
			{
				break;
			}
		}
		if(j==26)
		{
			ans.push_back(start);
		}
	}
	return ans;
}
