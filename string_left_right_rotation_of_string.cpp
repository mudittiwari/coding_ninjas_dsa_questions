#include<bits/stdc++.h>
using namespace std;

string leftRotate(string str, int d) 
{
    string substring=str.substr(0,d);
	str.erase(str.begin(),str.begin()+d);
	str+=substring;
	return str;
}

string rightRotate(string str, int d) 
{
    string substring=str.substr(str.length()-d,d);
	str.erase(str.begin()+str.length()-d,str.end());
	str.insert(str.begin(),substring.begin(),substring.end());
	return str;
}

void solve()
{
	string str;
	int d;
	cin>>str>>d;
	string ans=rightRotate(str,d%str.length());
	string ans2=leftRotate(str,d%str.length());
	cout<<ans2<<" "<<ans<<endl;
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
