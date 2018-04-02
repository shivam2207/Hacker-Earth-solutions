#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
double invese=400000003.0;
double root=2.236068;
double golden_ratio=1.6180;
double func(double,long long int);
int main()
{
	// int t;
	// cin >> t;
	// while(t--)
	// {
	// 	long long int n;
	// 	//scanf("%lli %lli",&l,&r);
	// 	cin >> n;

	// }
	//int n=5;
	cout << func(golden_ratio,1000)*root/5<<endl;
	cout << ((long long int)round(func(golden_ratio,5)*root/5))%mod<<endl;
	return 0;
}

double func(double x,long long int y)
{
	double res=1.0;
	while(y>0)
	{
		if(y & 1)
			res=fmod(res*x,mod);
		y=y>>1;
		x=fmod(x*x,mod);
	}
	return res;
}