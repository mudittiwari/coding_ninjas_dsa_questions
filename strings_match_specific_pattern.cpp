#include<bits/stdc++.h>
using namespace std;

vector<string> matchSpecificPattern(vector<string> words, int n, string pattern)
{
	vector<string> ans;
	for(int i=0;i<n;i++)
	{
		if(words[i].length()==pattern.length())
		{
			unordered_map<char,char> mp;
			unordered_set<char> st;
			int j;
			for(j=0;j<pattern.length();j++)
			{
				if(mp.find(pattern[j])==mp.end())
				{
					if(st.find(words[i][j])!=st.end())
					{
						break;
					}
					mp.insert(make_pair(pattern[j],words[i][j]));
					st.insert(words[i][j]);
				}
				else
				{
					if(mp[pattern[j]]!=words[i][j])
					{
						break;
					}
				}
			}
			if(j==pattern.length())
			{
				ans.push_back(words[i]);
			}
		}
	}
	return ans;
}

void solve()
{
	int n;
	cin>>n;
	vector<string> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	string pattern;
	cin>>pattern;
	vector<string> ans=matchSpecificPattern(arr,n,pattern);
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}
