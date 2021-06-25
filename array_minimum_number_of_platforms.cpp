#include<bits/stdc++.h>
int calculateMinPatforms(int at[], int dt[], int n) 
{
    vector<int> cumulativearray(2360);
	for(int i=0;i<n;i++)
	{
		cumulativearray[at[i]]++;
		cumulativearray[dt[i]+1]--;
	}
	for(int i=1;i<cumulativearray.size();i++)
	{
		cumulativearray[i]=cumulativearray[i]+cumulativearray[i-1];
	}
	return *max_element(cumulativearray.begin(),cumulativearray.end());
	
}
