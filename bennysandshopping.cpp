#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	//cin >> n;
	scanf("%d",&n);
	while(n--)
	{
		char c;
		scanf("%c",&c);
		char s[10001],out[1000];
		cin.getline(s,sizeof(s));
		//cout << s <<endl;
		int i,len=strlen(s),flag=0,j=0;
		char ch;
		for(i=0;i<len;i++)
		{
			//cout << "hello" << endl;
			if(s[i]=='$')
			{
				flag=1;
				continue;
				//cout << "hello" << endl;
			}
			if(flag==1)
			{
				if(s[i]==' ')
					continue;
				if(s[i]-'0' > 9 || s[i]-'0'<0)
				{
					//cout << "hello1" << endl;
					//cout << i << endl;
					flag=0;
				}
			}
			if(flag==1)
			{
				ch=s[i];
				out[j]=ch;
				j++;
			}
		}
		out[j]='\0';
		//cout << out << endl;
		cout <<"$";
		i=0;
		while(i<(int)strlen(out))
		{
			if(out[i]!='0')
			{
				break;
			}
			//else
			//	break;
			i++;
		}
		if(i==((int)strlen(out)))
			cout <<"0" << endl;
		else
		{
			for(;i<(int)strlen(out);i++)
				cout << out[i];
			cout <<"\n";
		}
	}
	return 0;
}