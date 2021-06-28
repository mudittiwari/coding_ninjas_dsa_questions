#include<bits/stdc++.h>
using namespace std;

int minimumOperations(string &a, string &b)
{
	if(a.size()!=b.size())
	{
		return -1;
	}
	int ans=0;
	unordered_set<int> st;
	int n=a.size();
    for(int i=0;i<(n/2);i++)
	{
		if(a[i]==b[i])
		{
			ans=ans;
		}
		else if((b[i]==a[n-i-1]) && (a[i]==b[n-i-1]))
		{
			st.insert(i);
			ans=ans;
		}
		else if((a[i]==a[n-i-1]) && (b[i]==b[n-i-1]))
		{
			st.insert(i);
			ans=ans;
		}
		else
		{
			// cout<<i<<endl;
			if(b[i]==b[n-i-1])
			{
				// a[i]=a[n-i-1];
				// i--;
				st.insert(i);
			}
			else if(b[i]==a[n-i-1])
			{
				// a[i]=b[n-i-1];
				// i--;
				st.insert(i);
			}
			else if(a[i]==b[n-i-1])
			{
				// a[n-i-1]=b[i];
				// i--;
				st.insert(i);
			}
			// i--;
			ans++;
		}
	}
	for(int i=n/2;i<n;i++)
	{
		if(a[i]!=b[i])
		{
			if(st.find(n-i-1)==st.end())
			{
				ans++;
			}
		}
	}
	return ans;
}

void solve()
{
	string strone;
	string strtwo;
	cin>>strone>>strtwo;
	int ans=minimumOperations(strone,strtwo);
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
