vector<long> emptyCells(int n, int k, vector<vector<int>> &tasks)
{
	unordered_set<int> stone;//rows
	unordered_set<int> sttwo;//cols
	vector<long> ans;
	long rows=n;
	long cols=n;
	for(int i=0;i<k;i++)
	{
		if(stone.find(tasks[i][0])==stone.end())
		{
			rows--;
			stone.insert(tasks[i][0]);
		}
		if(sttwo.find(tasks[i][1])==sttwo.end())
		{
			cols--;
			sttwo.insert(tasks[i][1]);
		}
		ans.push_back(rows*cols);
	}
	return ans;
}
