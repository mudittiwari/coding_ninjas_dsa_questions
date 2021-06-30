#include<bits/stdc++.h>
using namespace std;

char kThCharaterOfDecryptedString(string s, long long k)
{
	int i=0;
    while(true)
	{
		string temp;
		string number;
		while(s[i]>=97 && s[i]<=122)
		{
			temp+=s[i];
			i++;
		}
		while(s[i]>=48 && s[i]<=57)
		{
			number+=s[i];
			i++;
		}
		long long num=stoll(number);
		long long length=num*temp.length();
		if(k<=length)
		{
			return temp[(((k-1)%temp.length()))%temp.length()];
		}
		else
		{
			k=k-length;
		}
		// cout<<length<<endl;
		// cout<<k<<endl;
	}
}
void solve()
{
	string a;
	long long int k;
	cin>>a>>k;
	char ans=kThCharaterOfDecryptedString(a,k);
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
	// string s="12345678912345678";
	// cout<<stoll(s);
	return 0;
}
