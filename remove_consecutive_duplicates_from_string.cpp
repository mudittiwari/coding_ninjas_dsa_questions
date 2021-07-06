#include<bits/stdc++.h>
using namespace std;

string removeConsecutiveDuplicates(string str) 
{
	int len=str.length();
	string ans;
	int start=0;
	int i=1;
	while(i<len)
	{
		ans+=str[start];
		while(str[i]==str[start])
		{
			i++;
		}
		start=i;
	}
	return ans;
}

void solve()
{
	string str;
	cin>>str;
	cout<<removeConsecutiveDuplicates(str)<<endl;
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
