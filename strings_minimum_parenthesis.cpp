#include<bits/stdc++.h>
using namespace std;

int minimumParentheses(string str) 
{
	int ans=0;
	int opening=0;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(')
		{
			opening++;
		}
		else
		{
			if(opening==0)
			{
				ans++;
			}
			else
			{
				opening--;
			}
		}
	}
	ans+=opening;
	return ans;
}

void solve()
{
	string str;
	cin>>str;
	int ans=minimumParentheses(str);
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
