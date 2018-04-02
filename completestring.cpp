#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		char s[101];
		cin >> s;
		int array[26]={0},len,i,flag=0;
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			array[s[i]-'a']++;
			//cout<<temp<<endl;
		}
		for(i=0;i<26;i++)
		{
			if(array[i]==0)
				flag=1;
		}
		if(flag==1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}