#include<bits/stdc++.h>
using namespace std;

// traverse in strone and find first character of strone in strtwo
// now start second element search after that first element found index and so on

bool isSubSequence(string str1, string str2) 
{
	int j=0;
    for(int i=0;i<str1.size();i++)
	{
		while(j<str2.size())
		{
			if(str1[i]==str2[j])
			{
				break;
			}
			j++;
		}
		if(j==str2.size())
		{
			return false;
		}
	}
	return true;
}

void solve()
{
	string strone,strtwo;
	cin>>strone>>strtwo;
	cout<<isSubSequence(strone,strtwo)<<endl;
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
