#include <bits/stdc++.h>
using namespace std;
#define sz 100000
int no_digit(int);
int main()
{
	int i,j,k,prsum[sz+1],count,q,t;
	bool seive[sz+1]={false};
	vector <int> prime(sz,0);
	for(i=2;i*i<=sz;i++)
	{
		if(seive[i]==false)
		{
			for(j=i*i;j<=sz;j+=i)
			{
				seive[j]=true;
			}
		}
	}
	j=0;
	for(i=2;i<=sz;i++)
	{
		if(seive[i]==false)
		{
			prime[j]=i;
			j++;
		}
	}
	prime.resize(j);
	t=j;
	//cout <<prime.size()<<endl;
	prsum[0]=0;
	prsum[1]=1;
	for(k=2;k<=sz;k++)
	{
		i=k;
		count=0;
		j=0;
		while(prime[j]<=i && j<t)
		{
			if(i%prime[j]==0)
			{
				count++;
				while(i%prime[j]==0)
				{
					i=i/prime[j];
				}
			}
			j++;
		}
		if(count==no_digit(k))
		{
			prsum[k]=prsum[k-1]+1;
		}
		else
			prsum[k]=prsum[k-1];
	}
	//cout << "done"<<endl;
	cin >> q;
	while(q--)
	{
		int a,b;
		cin >> a >> b;
		cout << prsum[b]-prsum[a-1]<<endl;
	}
	return 0;
}
int no_digit(int n)
{
	if(n<=9)
		return 1;
	else if(n>=10 && n<=99)
		return 2;
	else if(n>=100 && n<=999)
		return 3;
	else if(n>=1000 && n<=9999)
		return 4;
	else if(n>=10000 && n<=99999)
		return 5;
	else if(n>=100000 && n<=999999)
		return 6;
	return 0;
}
