#include<bits/stdc++.h>
using namespace std;

int compareVersions(string a, string b) 
{
	int i=0;
	int j=0;
	while(i<a.length() && j<b.length())
	{
		string strone;
		string strtwo;
		while(i<a.length() && a[i]!='.')
		{
			strone+=a[i];
			i++;
		}
		i++;
		while(j<b.length() && b[j]!='.')
		{
			strtwo+=b[j];
			j++;
		}
		j++;
		// cout<<strone<<" "<<strtwo<<endl; 
		if(strone!=strtwo)
		{
			if(strone.length()>strtwo.length())
			{
				return 1;
			}
			else if(strone.length()<strtwo.length())
			{
				return -1;
			}
			int i=0;
			while(i<strone.length())
			{
				if(int(strone[i]-'0')<int(strtwo[i]-'0'))
				{
					return -1;
				}
				else if(int(strone[i]-'0')>int(strtwo[i]-'0'))
				{
					return 1;
				}
				i++;
			}			
			
			// long long int a=stoi(strone);
			// long long int b=stoi(strtwo);
			// if(a>b)
			// {
				// return 1;
			// }
			// if(a<b)
			// {
				// return -1;
			// }
		}
	}
	// cout<<i<<" "<<j<<endl; 
	if(i==a.length()+1 && j==b.length()+1)
	{
		return 0;
	}
	else if(i==a.length()+1 && j!=b.length()+1)
	{
		// return -1;
		while(j<b.length())
		{
			if(b[j]!='0' && b[j]!='.')
			{
				return -1;
			}
			j++;
		}
		return 0;
	}
	else
	{
		while(i<a.length())
		{
			if(a[i]!='0' && a[i]!='.')
			{
				return 1;
			}
			i++;
		}
		return 0;
	}
}

void solve()
{
	string a,b;
	cin>>a>>b;
	int ans=compareVersions(a,b);
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
