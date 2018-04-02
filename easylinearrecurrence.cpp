#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
#define mod 1000000007
long long int fvalue[1000001],gvalue[1000001],hvalue[1000001],hsum[1000001];
int main()
{
	long long int a,b,c,d,e,f;
	int i;
	cin >> a >> b >> c >> d >> e >> f >> fvalue[0] >> fvalue[1] >> gvalue[0] >> gvalue[1];
	a=a%mod;
	b=b%mod;
	c=c%mod;
	d=d%mod;
	e=e%mod;
	f=f%mod;
	fvalue[0]=fvalue[0]%mod;
	fvalue[1]=fvalue[1]%mod;
	gvalue[0]=gvalue[0]%mod;
	gvalue[1]=gvalue[1]%mod;
	hvalue[0]=((e*fvalue[0])%mod+(f*gvalue[0])%mod)%mod;
	hvalue[1]=((e*fvalue[1])%mod+(f*gvalue[1])%mod)%mod;
	hsum[0]=hvalue[0];
	hsum[1]=(hsum[0]+hvalue[1])%mod;
	for(i=2;i<=1000000;i++)
	{
		fvalue[i]=((a*fvalue[i-1])%mod+(b*gvalue[i-2])%mod)%mod;
		gvalue[i]=((c*gvalue[i-1])%mod+(d*fvalue[i-2])%mod)%mod;
		hvalue[i]=((e*fvalue[i])%mod+(f*gvalue[i])%mod)%mod;
		hsum[i]=(hsum[i-1]+hvalue[i])%mod;
	}
	int q;
	cin >> q;
	while(q--)
	{
		long long int n;
		cin >>n;
		cout <<hsum[n] << endl;
	}
	return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
long long int m=1000000007;
long long int ar[5][5]={0};
long long int a,b,c,d,e,f,f0,f1,g1,g0,h0,h1;
long long int store[32][5][5]={0};
void multiply(long long int a[5][5],long long int b[5][5],long long int c[5][5])
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			for(int k=0;k<5;k++)
				c[i][j]=(c[i][j]+(a[i][k]*b[k][j]))%m;
		}
	}
}
void multiply2(long long int a[5][5],long long int b[5][5],long long int c[5][5])
{
	int d[5][5];
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			d[i][j]=0;
			for(int k=0;k<5;k++)
				d[i][j]=(d[i][j]+(a[i][k]*b[k][j]))%m;
		}
	}
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			c[i][j]=d[i][j];
		}
	}
}
long long int func(long long int n)
{
	long long int base[5][5]={
								{1,0,0,0,0},
								{0,1,0,0,0},
								{0,0,1,0,0},
								{0,0,0,1,0},
								{0,0,0,0,1},		
							};
							int bit=0;
		while(n)
		{
			if(n&1)
			multiply2(store[bit],base,base);
			n=n/2;
			bit++;
		}
	
		return (base[4][0]*f1+base[4][1]*f0+base[4][2]*g1+base[4][3]*g0+h0+h1)%m;
}
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f,&f0,&f1,&g0,&g1);
	h0=(e*f0+f*g0)%m;
	h1=(e*f1+f*g1)%m;
	int q,i;
	scanf("%lld",&q);
	
			store[0][0][0]=a;
			store[0][0][3]=b;
			store[0][1][0]=1;
			store[0][2][1]=d;
			store[0][2][2]=c;
			store[0][3][2]=1;
			store[0][4][0]=a*e%m;
			store[0][4][1]=d*f%m;
			store[0][4][2]=c*f%m;
			store[0][4][3]=b*e%m;
			store[0][4][4]=1;
			
		for(int bit=1;bit<30;bit++)
		multiply(store[bit-1],store[bit-1],store[bit]);
		
	while(q--)
	{
		long long int n;
		scanf("%lld",&n);
		if(n==0)
		{
			printf("%lld\n",h0);
		}
		else if(n==1)
		{
			printf("%lld\n",h0+h1);
		}
		else
	{		long long int ans=func(n-1);
		printf("%lld\n",ans);}
	}
	return 0;
}
*/