#include <iostream>
#include <string.h>

using namespace std;
void reverse(char *,int);
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char s[31];
		cin >> s;
		int len=strlen(s);
		reverse(s,len);
		cout<<s<<endl;
	}
	return 0;
}

void reverse(char *s,int len)
{
	if(len<1)
		return;
	else
	{
		char temp=s[0];
		s[0]=s[len-1];
		s[len-1]=temp;
		reverse(s+1,len-2);
	}
}