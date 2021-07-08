#include<bits/stdc++.h>
using namespace std;


vector<int> scanvector(int n)
{
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	return arr;
}
void printvector(vector<int> arr)
{
	int n=arr.size();
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int lengthOfLongestSubstring(string &str) 
{
	int maxlen=INT_MIN;
	int start=0;
	unordered_map<char,int> st;
	for(int i=0;i<str.length();i++)
	{
		if(st.find(str[i])==st.end())
		{
			st[str[i]]++;
		}
		else
		{
			while(st.find(str[i])!=st.end())
			{
				st.erase(str[start]);
				start++;
			}
			st[str[i]]++;
		}
		maxlen=max(maxlen,i-start+1);
	}
	maxlen=max(maxlen,int(str.length())-start);
	return maxlen;
}


void solve()
{
	string str;
	cin>>str;
	cout<<lengthOfLongestSubstring(str)<<endl;
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
