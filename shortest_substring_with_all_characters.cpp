#include<bits/stdc++.h>
using namespace std;

int checkdistinct(vector<int> arr)
{
	int ans=0;
	for(int i=0;i<26;i++)
	{
		if(arr[i])
		{
			ans++;
		}
	}
	return ans;
}

string shortestSubstring(string s)
{
	vector<int> arr(26);
	int start=0;
	int end;
	unordered_set<char> st;
	for(int i=0;i<s.length();i++)
	{
		st.insert(s[i]);
	}
	int chars=st.size();
	// cout<<chars<<endl;
	// fill(arr.begin(),arr.end(),0);
	string ans;
	int len=INT_MAX;
	for(int i=0;i<s.length();i++)
	{
		end=i;
		arr[s[i]-97]++;
		while(checkdistinct(arr)==chars)
		{
			if(arr[s[start]-97]==1)
			{
				break;
			}
			arr[s[start]-97]--;
			start++;
		}
		if((end-start+1)<len && checkdistinct(arr)==chars)
		{
			len=end-start+1;
			ans=s.substr(start,len);
		}
	}
	while(checkdistinct(arr)==chars)
	{
		if(arr[s[end]-97]==1)
		{
			break;
		}
		arr[s[end]-97]--;
		end--;
	}
	if((end-start+1)<len && checkdistinct(arr)==chars)
	{
		len=end-start+1;
		ans=s.substr(start,len);
	}
	return ans;
}

void solve()
{
	string str;
	cin>>str;
	cout<<shortestSubstring(str)<<endl;
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
