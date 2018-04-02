#include <iostream>
using namespace std;

long int reverse(long int);
int seive[1000001]={0};
int repeat[1000001]={0};
int main()
{
	
	long int i,j;
	for(i=2;i<1000;i++)
	{
		if(seive[i]==0)
		{
			for(j=i*i;j<1000001;j+=i)
			{
				seive[j]=1;
			}
		}
	}
	for (i = 2; i < 1000001; ++i)
	{
		if(seive[i]==0 )//&& seive[reverse(i)]==0 && repeat[i]==0)
		{
			j=reverse(i);
			if(seive[j]==0 && i!=j && repeat[i]==0)
			{
				repeat[i]++;
				repeat[j]++;
				cout<<i<<endl;
			}
		}
	}
}

long int reverse(long int n)
{
	long int m=0;
	while(n>0)
	{
		m=m*10+(n%10);
		n=n/10;
	}
	return m;
}