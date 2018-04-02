#include <bits/stdc++.h>
using namespace std;
#define max_size 100000
set <long long int > st;
int main()
{
	bool prime[max_size]={false};
	int i,j;
	for(i=2;i*i<max_size;i++)
	{
		if(prime[i]==false)
		{
			for(j=i*i;j<max_size;j+=i)
			{
				prime[j]=true;
			}
		}
	}
	for(i=2;i<max_size;i++)
	{
		if(prime[i]==false)
			st.insert(i);
	}
	int t;
	cin >> t;
	while(t--)
	{
		set <long long int > :: iterator it;
		long long int n,count=0;
		scanf("%lld",&n);
		if(prime[n]==false)
		{
			cout << "Yes" << endl;
		}
		else
		{
			for(it=st.begin();it!=st.end();it++)
			{
				if(*it>n)
					break;
				if(n%*it==0)
				{
					count++;
				}
			}
			if(count%2==0)
			{
				cout << "Yes" << endl;
				st.insert(n);
			}
			else
				cout << "No" << endl;
		}
	}
	return 0;
}