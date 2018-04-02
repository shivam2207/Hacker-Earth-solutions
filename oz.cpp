#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char s[1000001];
		cin >> s;
		int flag1=0,flag2=0;
		long int len,i;
		long long int count1=0,count2=0,count3=0,count4=0;
		len=strlen(s);
		
		for(i=0;i<len;i++)
		{
			if(s[i]=='Z')
			{
				flag1=1;
				count1++;
			}
			if(s[i]=='O' && flag1==1)
			{
				count2+=count1;
			}
			if(s[i]=='O')
			{
				flag2=1;
				count3++;
			}
			if(s[i]=='Z' && flag2==1)
			{
				count4+=count3;
			}
		}
		if(count2<=count4)
			cout<<count2<<endl;
		else
			cout<<count4<<endl;	
	}
	return 0;
}