#include<bits/stdc++.h>
using namespace std;

string removeVowels(string inputString) 
{
	for(int i=0;i<inputString.length();i++)
	{
		if(inputString[i]=='a' || inputString[i]=='A' || inputString[i]=='e' || inputString[i]=='E' || inputString[i]=='i' || inputString[i]=='I' || inputString[i]=='o' || inputString[i]=='O' || inputString[i]=='u' || inputString[i]=='U' )
		{
			inputString.erase(inputString.begin()+i);
			i--;
		}
	}
	return inputString;
}

void solve()
{
	string str;
	cin>>str;
	string ans=removeVowels(str);
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
