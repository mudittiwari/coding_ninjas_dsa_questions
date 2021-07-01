#include<bits/stdc++.h>
using namespace std;

string trim(string str)
{
	if(str.length()==1)
	{
		return str;
	}
	// int i=0;
	while(str[0]=='0')
	{
		str.erase(str.begin());
	}
	return str;
}

string multiplyStrings(string strone , string strtwo )
{
	bool toreturn=true;
	string a,b;
	if(strone[0]=='-' && strtwo[0]=='-')
	{
		strone.erase(strone.begin());
		strtwo.erase(strtwo.begin());
		toreturn=true;
	}
	else if(strone[0]=='-' || strtwo[0]== '-')
	{
		if(strone[0]=='-')
		{
			strone.erase(strone.begin());
		}
		else
		{
			strtwo.erase(strtwo.begin());
		}
		toreturn =false;
	}
	strone=trim(strone);
	strtwo=trim(strtwo);
	cout<<strone<<endl;
	cout<<strtwo<<endl;
	if(strone.length()>=strtwo.length())
	{
		a=strone;
		b=strtwo;
	}
	else
	{
		a=strtwo;
		b=strone;
	}
	long long int maxlen=-1;
	string ans;
	vector<string> arr;
	for(int i=b.length()-1;i>=0;i--)
	{
		string temp;
		int carry=0;
		int numtwo=b[i]-'0';
		for(int j=a.length()-1;j>=0;j--)
		{
			int numone=a[j]-'0';
			// cout<<numone<<" "<<numtwo<<endl;
			int ans=numone*numtwo+carry;
			carry=0;
			temp.insert(temp.begin(),char(ans%10+'0'));
			carry+=ans/10;
		}
		if(carry>0)
		{
			temp.insert(temp.begin(),char(carry+'0'));
		}
		temp.insert(temp.end(),(b.length()-1-i),'0');
		maxlen=max(maxlen,(long long int)(temp.length()));
		arr.push_back(temp);
	}
	for(int i=0;i<arr.size();i++)
	{
		if(arr[i].length()<maxlen)
		{
			// cout<<"mudit"<<endl;
			arr[i].insert(arr[i].begin(),maxlen-arr[i].length(),'0');
		}
		// cout<<arr[i]<<" ";
	}
	int carry=0;
	for(long long int i=maxlen-1;i>=0;i--)
	{
		int tempans=0;
		for(int j=0;j<arr.size();j++)
		{
			tempans+=(arr[j][i]-'0');
		}
		tempans+=carry;
		ans.insert(ans.begin(),char(tempans%10+'0'));
		carry=tempans/10;
	}
	if(carry>0)
	{
		ans.insert(ans.begin(),char(carry+'0'));
	}
	if(count(ans.begin(),ans.end(),'0')==ans.length())
	{
		return "0";
	}
	if(!toreturn)
	{
		return "-"+ans;
	}
	return ans;
}

void solve()
{
	string a,b;
	cin>>a>>b;
	string ans=multiplyStrings(a,b);
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
