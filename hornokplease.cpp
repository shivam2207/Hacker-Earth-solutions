#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
string decimal_to_binary(int);
int binary_to_decimal(string);
bool is_prime(int);
int gcd(int,int);
int main()
{
	int t,i,j;
	bool seive[1000001]={false};
	for(i=2;i<=1000;i++)
	{
		if(seive[i]==false)
		{
			for(j=i*i;j<=1000000;j+=i)
			{
				seive[j]=true;
			}
		}
	}
	vector <int> prime;
	for(i=2;i<=1000000;i++)
	{
		if(seive[i]==false)
			prime.push_back(i);
	}
	cin >> t;
	while(t--)
	{
		map <int,int> mp;
		map <int,int> :: iterator it;
		int m,n,sum=0,ans=1;
		cin >> m;
		n=m;
		i=0;
		while(n>0 && prime[i]<=n)
		{
			while(n%prime[i]==0)
			{
				n=n/prime[i];
				mp[prime[i]]++;
			}
			i++;
		}
		for(it=mp.begin();it!=mp.end();it++)
		{
			i=0;
			sum=0;
			while(i<=it->second)
			{
				sum+=pow(it->first,i);
				i++;
			}
			ans*=sum;
		}
		if(ans==2*m)
			cout <<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}

string decimal_to_binary(int n)
{
	int i=0;
	string binary=bitset<32>(n).to_string();
	while(i<32 && binary[i]=='0') i++;
	return binary.substr(i);
}
int binary_to_decimal(string s)
{
	int n=bitset<32>(s).to_ulong();
	return n;
}
int gcd(int a,int b)
{
	if(a==0 && b==0) return -1;else if(a==0) return b;else if(b==0) return a;
	else return	gcd(b%a,a);
}
bool is_prime(int n)//return true if prime
{
	if(n<2) return false; else if(n==2) return true; else if(n%2==0) return false;
	else
	{
		for(int i=3;i*i<=n;i+=2) 
			if(n%i==0) return false;
		return true;
	}
}