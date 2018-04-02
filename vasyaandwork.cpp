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
	int n,q,t1,i,t2;
	cin >> n;
	string food_type,sleep_type;
	cin >> food_type >> sleep_type >> q;
	int prsum[2][n+1];
	int food_index[53][n+1];
	memset(food_index,0,sizeof(food_index));
	prsum[0][0]=0;
	prsum[1][0]=0;
	for(i=1;i<=n;i++)
	{
		t1=food_type[i-1]-'a';
		t2=sleep_type[i-1]-'0';
		if(t2==0)
		{
			for(int j=1;j<=52;j++)
			{
				
				food_index[j][i]=food_index[j][i-1];
			}
			food_index[2*t1+1][i]=food_index[2*t1+1][i]+1;
		}
		else
		{

			for(int j=1;j<=52;j++)
			{
				
				food_index[j][i]=food_index[j][i-1];
			}
			food_index[2*t1+2][i]=food_index[2*t1+2][i-1]+1;
			//food_index[2*t1+t2+1][i]=food_index[2*t1+t2+1][i-1]+1;
		}
		if(t2==0)
		{
			prsum[0][i]=prsum[0][i-1]+1;
			prsum[1][i]=prsum[1][i-1];
		}
		else
		{
			prsum[0][i]=prsum[0][i-1];
			prsum[1][i]=prsum[1][i-1]+1;
		}
	}
	// for(i=1;i<=52;i++)
	// {
	// 	// for(int j=1;j<=n;j++)
	// 		cout << food_index[i][n]<<" ";	
	// 	//cout << endl;

	// }

	while(q--)
	{
		int l,r;
		cin >> l >> r;
		// l;r--;
		ll ans=0;
		for(i=1;i<53;i+=2)
		{
			ans=(ans+((food_index[i][r]-food_index[i][l-1])*(food_index[i+1][r]-food_index[i+1][l-1]))%mod)%mod;
			// cout<<"i:"<<i<<" "<<(food_index[i][r]-food_index[i][l-1])<<" "<<(food_index[i+1][r]-food_index[i+1][l-1])<<endl;
		}
		// cout<<"ans: "<<ans	<<endl;
		ll temp=(prsum[0][r]-prsum[0][l-1]);
		ans=(ans+((temp*(temp-1))/2))%mod;
		temp=(prsum[1][r]-prsum[1][l-1]);
		ans=(ans+((temp*(temp-1))/2))%mod;
		cout << ans%mod << endl;
	}
	return 0;
}