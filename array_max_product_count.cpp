vector<long long> maxProductCount(vector<int> &arr, int n) 
{
	unordered_map<long long int,long long int> mp;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			long long int product=arr[i];
			product=product*arr[j];
			// cout<<product<<endl;
			mp[product]+=1;
		}
	}
	// for(auto itr=mp.begin();itr!=mp.end();itr++)
	// {
		// cout<<itr->first<<" "<<itr->second<<endl;
	// }
	long long int count=LLONG_MIN;
	long long int product=LLONG_MIN;
	for(auto itr=mp.begin();itr!=mp.end();itr++)
	{
		if(itr->second>count)
		{
			count=itr->second;
			product=itr->first;
		}
		else if(itr->second==count)
		{
			product=min(itr->first,product);
		}
	}
	// cout<<count<<endl;
	if(count==1)
	{
		return {0};
	}
	return {product,(count*(count-1))/2};
}
