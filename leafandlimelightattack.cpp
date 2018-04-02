#include <bits/stdc++.h>
using namespace std;
#define mod 1000000009
string decimal_to_binary(int);
int binary_to_decimal(string);
bool is_prime(int);
int gcd(int,int);
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int n;
		cin >> n;
		long long int a,b,c,sol,temp;
		a=n;
		b=n+1;
		c=2*n+1;
		if(a%3==0)
			a=a/3;
		else if(b%3==0)
			b=b/3;
		else if(c%3==0)
			c=c/3;
		sol=(a*b)%mod;
		if(n%2!=0)
			sol=(sol*c-1)%mod;
		else
			sol=(sol*c)%mod;
		temp=((n*(n-1))/2)%mod;
		sol=(sol+n/2-temp)%mod;
		if(sol<0)
			sol=sol+mod;
		cout <<sol << endl;
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