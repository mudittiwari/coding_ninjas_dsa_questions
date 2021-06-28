#include<bits/stdc++.h>
using namespace std;

int checkunique(vector<int> arr)
{
	int toreturn=0;
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i])
		{
			toreturn++;
		}
	}
	return toreturn;
}

int getLengthofLongestSubstring(string s, int k) 
{
	vector<int> arr(26);
	int start=0;
	int i;
	for(i=0;i<s.length();i++)
	{
		arr[s[i]-'a']++;
		if(checkunique(arr)>k)
		{
			arr[s[i]-'a']--;
			break;
		}
	}
	int ans=i;
	for(int j=i;j<s.length();j++)
	{
		arr[s[j]-'a']++;
		while(checkunique(arr)>k)
		{
			arr[s[start]-'a']--;
			start++;
		}
		ans=max(ans,j-start+1);
	}
	return ans;
}


void solve()
{
	string str;
	int k;
	cin>>k>>str;
	int ans=getLengthofLongestSubstring(str,k);
	cout<<ans<<endl;
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
