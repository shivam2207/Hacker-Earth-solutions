#include <iostream>
using namespace std;
#define mod 1000000007
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long int a,d,ans;
		cin >> a >> d;
		a=a%mod;
		d=d%mod;
		ans=(d*a)%mod;
		cout << ans << endl;
	}
	return 0;
}