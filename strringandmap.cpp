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
#define PI 3.142
int main()
{
	string s;
	cin >> s;
	map < pair<int,int>, char > hash_map;
	int i,count=1,t,num;
	char c;
	pi p;
	for(i=0;i<(int)s.size();i++)
	{
		t = s[i]-'a';
		if( t >= 0 && t<26)
		{
			c=s[i];
			num = 0;
			i++;
			while(i<(int)s.size() && s[i]-'a'< 0)
			{
				num = num *10+s[i]-'0';
				i++;
			}
			i--;
			p=mp(count,count+num);
			count = count+num+1;
			hash_map[p]=c;
		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int n;
		cin >> n;
		for (auto it = hash_map.begin();it!= hash_map.end();it++)
		{
			if(it->first.first <= n and it->first.second>=n)
			{
				cout << it->second << endl;
			}
		}
	}
	return 0;
}