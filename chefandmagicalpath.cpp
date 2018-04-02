#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long n,m;
		cin >> n >> m;
		if(n==1 && m==1)
			cout <<"Yes"<<endl;
		else if(n==1 || m==1)
			cout<<"No"<<endl;
		else if(n%2!=0 && m%2!=0)
			cout<<"No"<<endl;
		else
			cout<<"Yes"<<endl;
	}
	return 0;
}