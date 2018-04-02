#include <iostream>
#include <string.h>

using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char s[201];
		cin >> s;
		int len=strlen(s),i,count=0,temp;
		for(i=4;i<len-4;i++)
		{
			if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
				count++;
		}
		temp= len-4;
		cout<<temp-count<<"/"<<len<<endl;
	}
	return 0;
}