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
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--)
	{
		ll n,i,j,mid,time1,time2,ans1;
		cin >> n;
		i=1;
		j=n;
		int flag=0;
		if(n==1)
		{
			cout <<"1"<<endl; 
		}
		else
		{	
			while(i<=j)
			{
				mid=(i+j)/2;
				time1=(mid*(mid+1))/2;
				time2=n-mid;
				if(time1==time2)
				{
					i=mid;
					flag=1;
					break;
				}
				else if(time1<time2)
				{
					i=mid+1;
				}
				else
				{
					j=mid-1;
				}
			}
			if(flag==0)
				j=i-1;
			else
				j=i;
			ans1=max(j*(j+1)/2,n-j)+n-j;
			cout << ans1<<endl;
		}
	}
	return 0;
}