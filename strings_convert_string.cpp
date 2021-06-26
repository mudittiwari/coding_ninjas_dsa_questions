#include<bits/stdc++.h>
using namespace std;


string convertString(string str) 
{
	if(str[0]>=97 && str[0]<=122)
	{
		str[0]=str[0]-32;
	}
	for(int i=1;i<str.length();i++)
	{
		if(str[i-1]==' ' && (str[i-1]>=97 && str[i-1]<=122))
		{
			str[i]=str[i]-32;
		}
	}
	return str;
}

void solve()
{
	string str;
	getline(cin,str);
	cout<<str.length()<<endl;
	string ans=convertString(str);
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
	// string str;
	// getline(cin,str);
	// for(int i=0;i<str.length();i++)
	// {
		// if(str[i]!=' ')
		// {
			// str[i]=int(str[i])-32;
		// }
	// }
	// cout<<str;
	// cout<<char('a'-32);
	return 0;
}
