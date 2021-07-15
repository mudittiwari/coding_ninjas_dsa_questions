vector<vector<int>> ans;
void towerofhanoi(int n,int source,int destination,int aux)
{
	if(n==2)
	{
		// cout<<source<<" "<<aux<<endl;
		ans.push_back({source,aux});
		// cout<<source<<" "<<destination<<endl;
		ans.push_back({source,destination});
		// cout<<aux<<" "<<destination<<endl;
		ans.push_back({aux,destination});
		return;
	}
	towerofhanoi(n-1,source,aux,destination);
	// cout<<source<<" "<<destination<<endl;
	ans.push_back({source,destination});
	towerofhanoi(n-1,aux,destination,source);
}
vector<vector<int>> towerOfHanoi(int n)
{
    ans.clear();
    if(n==1)
    {
        ans.push_back({1,3});
        return ans;
    }
    towerofhanoi(n,1,3,2);
	return ans;
}
