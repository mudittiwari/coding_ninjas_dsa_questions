#include<bits/stdc++.h>
using namespace std;

bool checkValidString(string &str)
{
	stack<int> stk;
	stack<int> stkstar;
	for(int i=0;i<str.length();i++)
	{
		if(str[i]=='(')
		{
			stk.push(i);
		}
		else if(str[i]=='*')
		{
			stkstar.push(i);
		}
		else
		{
			if(stk.size()==0)
			{
				if(stkstar.size()==0)
				{
					return false;
				}
				stkstar.pop();
			}
			else
			{
				stk.pop();
			}
		}
	}
	if(stk.size()<=stkstar.size())
	{
		while(!stk.empty())
		{
			if(stk.top()<stkstar.top())
			{
				stk.pop();
				stkstar.pop();
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	return false;
}

void solve()
{
	string str;
	cin>>str;
	cout<<checkValidString(str)<<endl;
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
