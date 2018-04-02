#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define ll long long int
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppi pair<int,pi>
#define ppl pair<ll,pl>
#define mp make_pair
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pi>
#define sz (int)1e6
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	bool seive[sz+1]={false};
	int prsum[sz+1]={0};
	int t,i,j;
	seive[0]=true;
	seive[1]=true;
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
	prsum[0]=0;
	for(i=1;i<=sz;i++)
	{
		if(seive[i]==false)
			prsum[i]=prsum[i-1]+1;
		else
			prsum[i]=prsum[i-1];
	}
	cin >> t;
	while(t--)
	{
		int a , b, num,sum=0,n1,n2;
		double minn=1000000000,temp;
		cin >> a >> b;
		if(a==b)
			cout << a << endl;
		else if(prsum[b]-prsum[a-1]!=0)
		{
			for(i=b;i>=a;i--)
			{
				if(seive[i]==false)
				{
					break;
				}
			}
			cout << i << endl;
		}
		else
		{
			for(i=a;i<=b;i++)
			{
				sum=1;
				cout<<i<<" ";
				for(j=2;j*j<=b;j++)
				{
					if(i%j==0)
					{
						n1=j;
						n2=i/j;
						cout << n1 <<"+" << n2 <<" ";
						if(n1 != n2)
							sum+=n1+n2;
						else
							sum+=n1;
					}
				}
				temp=(double)sum/i;
				cout <<"sum: "<<sum<<" "<<"temp: "<<temp << endl;  
				if(temp<minn)
				{
					minn=temp;
					num=i;
				}
			}
			cout << num << endl;
		}
	}
	return 0;
}