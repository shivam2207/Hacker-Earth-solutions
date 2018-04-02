#include <iostream>
#include <string.h>
using namespace std;

void reverse(char*);
char s[100][15],s1[100][15];
int n,m=0;
int main()
{
	cin >> n;
	int i,j,count,len;
	
	for(i=0;i<n;i++)
	{
		cin>>s[i];
		reverse(s[i]);
		m++;
		for(j=0;j<m;j++)
		{
			if(strcmp(s[i],s1[j])==0)
			{
				count=i;
			}
		}
	}
	len=strlen(s[count]);
	cout<<len<<" "<<s[count][len/2]<<endl;
	return 0;
}

void reverse(char *s)
{
	int len=strlen(s),i,j;
	for(j=0,i=len-1;i>=0;i--,j++)
	{
		s1[m][j]=s[i];
	}
	s1[m][j]='\0';
}