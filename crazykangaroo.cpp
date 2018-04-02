#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long double a,b,m,temp3;
		cin >> a>>b>>m;
		//temp1=(b-a+1)/m;
		//temp2=b/m-(a-1)/m;
		temp3=ceil((b-a+1)/m);
		//cout<<temp1<<" "<<temp2<<" "<<temp3<<endl;
		cout<<temp3<<endl;
	}
	return 0;
}