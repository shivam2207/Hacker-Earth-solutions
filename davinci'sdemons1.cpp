#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	ios_base::sync_with_stdio(false);
	long long cnt=0,total=0,a,b,c,d,e,f,g;
	int n,m,i,j,k;
	cin >> n >> m;
	string str[n];
	for(i=0;i<n;i++)
		cin >> str[i];
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			cnt=0;
			for(k=0;k<m;k++)
			{
				if(str[i][k]=='0' && str[j][k]=='0')
					cnt++;
			}
			total+=(cnt*(cnt-1))/2;
		}
	}
	if(total==0)
		cout << "1 1" <<endl;
	// else if(total==1)
	// 	cout << "5 6"<<endl;
	else
	{
		a=5;
		// if(total%5==0)
		// {
		// 	b=6*(total/5);
		// 	a=1;
		// }
		// else
		b=6*total;
		c=total-1;
		d=total;
		e=a*d+b*c;
		f=b*d;
		g=gcd(e,f);

		cout << e/g <<" "<< f/g << endl;
	}
	return 0;
}