#include<bits/stdc++.h>
using namespace std;

bool isValidIPv4(string str) 
{
	int countdot=count(str.begin(),str.end(),'.');
	if(countdot!=3)
	{
		return false;
	}
	string temp;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='.')
		{
			if(temp.length()==0)
			{
				return false;
			}
			if(stoi(temp)<0 || stoi(temp)>255)
			{
				return false;
			}
			temp="";
		}
		else
		{
			if(int(str[i])>=48 && int(str[i])<=57)
			{
				temp+=str[i];
			}
			else
			{
				return false;
			}
		}
	}
	if(temp.length()==0 || stoi(temp)<0 || stoi(temp)>255)
	{
		return false;
	}
	return true;
}

void solve()
{
	string str;
	cin>>str;
	bool ans=isValidIPv4(str);
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
	// cout<<int('k');
	return 0;
}
