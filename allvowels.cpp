#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	int a[5]={0},i,flag=0;
	for(i=0;i<int(s.size());i++)
	{
		if(s[i]=='a' )
			a[0]=1;
		else if(s[i]=='e')
			a[1]=1; 
		else if(s[i]=='i')
			a[2]=1;
		else if(s[i]=='o')
			a[3]=1;
		else if(s[i]=='u')
			a[4]=1;
		if(a[0]+a[1]+a[2]+a[3]+a[4]==5)
		{	
			flag=1;
			break;
		}
	}
	if(flag==1)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}