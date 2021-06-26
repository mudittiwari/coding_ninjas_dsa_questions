#include<bits/stdc++.h>
using namespace std;

string encode(string &message)
{
	string ans;
	int count=1;
	int character=message[0];
    for(int i=1;i<message.length();i++)
	{
		if(message[i]==character)
		{
			count++;
		}
		else
		{
			ans+=character;
			ans+=to_string(count);
			count=1;
			character=message[i];
		}
	}
	ans+=character;
	ans+=to_string(count);
	return ans;
}

void solve()
{
	string str;
	cin>>str;
	string ans=encode(str);
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
