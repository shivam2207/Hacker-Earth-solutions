#include <bits/stdc++.h>
using namespace std;
#define ipi(n) scanf("%d",&n); 
#define ipl(n) scanf("%lld",&n);
#define pfi(n) printf("%d\n",n);
#define pfl(n) printf("%lld\n",n);
#define pfiw(n) printf("%d ",n);
#define pflw(n) printf("%lld ",n);
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
map <int,int> mapp;
set <int> st;
int main()
{
	int n;
	ipi(n);
	int arr[n],i,total,j=0;
	ll cnt=0;
	for(i=0;i<n;i++)
	{
		ipi(arr[i]);
		st.insert(arr[i]);
	}
	total=st.size();
	// cout << "total: "<<total << endl;
	if(total==1)
	{
		cnt=(ll)(n*(n+1))/2;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			mapp[arr[i]]++;
			if((int)mapp.size()==total)
			{
				cnt+=n-i;
				// cout <<"cnt1: "<<cnt<<endl;
				while(j<i)
				{
					mapp[arr[j]]--;
					if(mapp[arr[j]]==0)
					{
						mapp.erase(arr[j]);
						j++;
						break;
					}
					else
					{
						j++;
						// cout<<"j: "<<j<<endl;
						cnt+=n-i;
						// cout<<"cnt2: "<<cnt<<endl;
					}
				}
			}
		}
	}
	pfl(cnt);
	return 0;
}