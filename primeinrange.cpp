#include <bits/stdc++.h>
using namespace std;
#define sz 1000000
int main()
{
	//cout << "Hello World!" << endl;
	bool prime[sz+1] = {false};
	int i,j,n,t,cnt=0;
	prime[0]=true;
	prime[1]=true;
	int pr_sum[sz+1];
	for(i=2;i*i<=sz;i++)
	{
		for(j=i*i;j<=sz;j+=i)
		{
			prime[j]=true;
		}
	}
	pr_sum[0]=0;
	pr_sum[1]=0;
	for(i=2;i<=sz;i++)
	{
		n=i;
		t=0;
		cnt = 0;
		pr_sum[i] = pr_sum[i-1];
		while(n)
		{
			t = t+(n%10)*pow(10,cnt);
			n = n/10;
			if(prime[t]==false)
			{
				pr_sum[i] += 1;
				break;
			}
			cnt++;
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		cout << pr_sum[r] - pr_sum[l-1] << endl;
		//cout << count << endl;
	}
	return 0;
}
