#include <iostream>
#include <string.h>

using namespace std;
int main()
{
	char s[10001];
	cin >>s;
	int len=strlen(s),i,temp,count=0;
	for(i=0;i<len;i++)
	{
		temp=s[i]-'0';
		if(temp%2==0)
			count++;
	}
	for(i=0;i<len;i++)
	{
		cout<<count<<" ";
		if((s[i]-'0')%2==0)
		{
			count--;
		}
	}
	cout<<"\n";
	return 0;
}