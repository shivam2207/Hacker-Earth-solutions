#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[100001];
	cin >>s;
	long int t,len;
	cin >> t;
	len=strlen(s);
	while(t--)
	{
		long long int a,b;
		long int temp1,temp2;
		cin>>a>>b;
		if(a%len==0)
			temp1=len;
		else
			temp1=a%len;
		if(b%len==0)
			temp2=len;
		else
			temp2=b%len;

		if(s[temp1-1]==s[temp2-1])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}