#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
long long int funct(int ); 
int a,b,c,d;
long long int k;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		//int a,b,c,d,k;
		long long int sol;
		cin >> a >> b >> c >> d >> k;
		int t=1;
		while(1)
		{
			sol=funct(t);
			if(sol>k)
			{
				break;
			}
			else
			{
				t=t*2;
				sol=funct(t);
			}
		}
		int t1,t2,mid;
		t2=t;
		t1=t/2;
		while(t2-t1>1)
		{
			mid=(t1+t2)/2;
			sol=funct(mid);
			if(sol<k)
			{
				t1=mid;
				t2=t2;
			}
			else
			{
				t1=t1;
				t2=mid;
			}
		}
		cout << t1 << endl;
	}
	return 0;
}
long long int funct(int t)
{
	return (a*pow(t,3)+b*pow(t,2)+c*t+d);
}