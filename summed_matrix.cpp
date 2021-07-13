#include<bits/stdc++.h>
using namespace std;


long long int query(long long int n, long long int q) 
{
	if((n+1)-q>0)
	{
		return q-2+1;
	}
	else if((n+1)-q==0)
	{
		return n;
	}
	else
	{
		return n-(q-n-1);
	}
}
void solve()
{
	long long int n,q;
	cin>>n>>q;
	long long int ans=query(n,q);
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
}
