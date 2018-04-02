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
unordered_set <string> st;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		st.clear();
		int n=s.size(),count=0,flag=0;
		st.insert(s);
		while(count<n-1)
		{
			rotate(s.begin(),s.begin()+1,s.end());
			if(st.find(s)==st.end())
				st.insert(s);
			else
				break;
			if(count>n/2)
			{
				flag=1;
				break;
			}
			count++;
		}
		if(flag==0)
			cout << st.size()<<endl;
		else
			cout<<n<<endl;
	}
	return 0;
}