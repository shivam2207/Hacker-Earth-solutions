#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char s[31];
		cin >> s;
		int len=strlen(s),i;
		cout<<s[0];
		for(i=1;i<len;i++)
		{
			if(s[i]!=s[i-1])
				cout<<s[i];
		}
		cout<<"\n";
	}
	return 0;
}